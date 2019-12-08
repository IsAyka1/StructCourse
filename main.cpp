//
// Created by Aigul on 05.12.2019.
//
using namespace std;
#include <iostream>
#include "Text.h"
#include <cstring>

struct TVectorList {
	TTextDList* text = nullptr;
	TVectorList *next = nullptr;
};
int ChooseOperationVector() {
	//system("cls");
	int answer = 0;
	cout << "//--------------------Menu for Vector List--------------------//" << endl;
	cout << "1 - start work with vector" << endl;
	cout << "2 - vector to null" << endl;
	cout << "3 - vector is null?" << endl;
	cout << "4 - how elements in vector?" << endl;
	cout << "5 - print elem with index" << endl;
	cout << "6 - delete last elem " << endl;
	cout << "7 - take elem with index" << endl;
	cout << "8 - change elem with index" << endl;
	cout << "9 - add elem to the end" << endl;
	cout << "10 - print vector" << endl;
	cout << "11 - finish work with vector" << endl;
	cout << "12 - Exit and delete vector" << endl;
	cin >> answer;
	return answer;
}

bool VectorIsStart(bool start) {
	if(start) {
		return true;
	} else {
		cout << "No access. Start work with vector!" << endl;
		return false;
	}
}

bool VectorIsEmpty(TVectorList *head) {
	if(head == nullptr) {
		cout << "Vector is empty" << endl;
		return true;
	} else {
		cout << "Vector is not empty" << endl;
		return false;
	}
}

bool VectorToNull(TVectorList**head) {
	TVectorList *help;
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Vector is empty" << endl;
		return true;
	}
	while(*head != nullptr) {
		help = *head;
		*head = (*head)->next;
		free(help);
	}
	*head = nullptr;
	cout << "Vector is null" << endl;
	return true;
}

int VectorHowElem(TVectorList *head) {
	if(head == nullptr) {
		cout << "Vector is empty" << endl;
		return 0;
	}
	int count{};
	TVectorList *tmp = head;
	while(tmp != nullptr) {
		tmp = tmp->next;
		count++;
	}
	cout << "In this vector " << count << " elem" << endl;
	return count;
}

bool VectorPrintElem(TVectorList *head) {
	if(head == nullptr) {
		cout << "Vector is empty" << endl;
		return false;
	}
	int index = 0;
	int sizeVector = VectorHowElem(head);
	cout << "Input index elem you want to print:";
	cin >> index;
	if(index >= sizeVector) {
		cout << "Index is bigger than vector's size" << endl;
		return false;
	}
	for(int i = 0; i != index; ++i) {
		head = head->next;
	}
	cout << "Elem[" << index << "] :" << endl;
	PrintText(head->text, nullptr);
	return true;
}

bool VectorDeleteLastElem(TVectorList **head) {
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Vector is empty" << endl;
		return false;
	}
	if((*head)->next == nullptr) {
		cout << "Vector has only first elem" << endl;
		*head = nullptr;
		return true;
	}
	while((*head)->next->next != nullptr) {
		*head = (*head)->next;
	}
	(*head)->next = nullptr;
	cout << "Last elem was deleted" << endl;
	return true;
}

TVectorList* VectorTakeElem(TVectorList **head) {
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return nullptr;
	} else if(*head == nullptr) {
		cout << "Vector is empty" << endl;
		return nullptr;
	}
	int index = 0;
	int sizeVector = VectorHowElem(*head);
	TVectorList *taken = nullptr;
	cout << "Input index elem you want to take:";
	cin >> index;
	if(index >= sizeVector) {
		cout << "Index is bigger than vector's size" << endl;
		return nullptr;
	}
	if(index == 0) {
		taken = *head;
		*head = (*head)->next;
		taken->next = nullptr;
		cout << "Elem with index " << index << " was taken" << endl;
		return taken;
	}
	for(int i = 0; i != index - 1; ++i) {
		*head = (*head)->next;
	}
	taken = (*head)->next;
	(*head)->next = (*head)->next->next;
	taken->next = nullptr;
	cout << "Elem with index " << index << " was taken" << endl;
	return taken;
}

bool VectorChangeElem(TVectorList **head) {
	if(*head == nullptr) {
		cout << "Vector is empty" << endl;
		return false;
	}
	int index = 0;
	int sizeVector = VectorHowElem(*head);
	cout << "Input index elem you want to change:";
	cin >> index;
	if(index >= sizeVector) {
		cout << "Index is bigger than vector's size" << endl;
		return false;
	}
	if(index == 0) {
		cout << "Elem with index " << index << " now :" << endl;
		PrintText((*head)->text, nullptr);
		if(TextWork(&((*head)->text))) { // if is empty
			cout << "Text is empty" << endl;
			*head = (*head)->next;
			cout << "Text was deleted" << endl;
		} else {
			cout << "Elem with index " << index << " was changed" << endl;
		}
		return  true;
	}
	TVectorList *tmp = *head;
	for(int i = 0; i != index - 1; ++i) {
		tmp = tmp->next;
	}
	cout << "Elem with index " << index << " now :" << endl;
	PrintText(tmp->next->text, nullptr);
	if(TextWork(&(tmp->next->text))) { // if is empty
		cout << "Text is empty" << endl;
		tmp->next = tmp->next->next;
		cout << "Text was deleted" << endl;
	} else {
		cout << "Elem with index " << index << " was changed" << endl;
	}
	return true;
}

TVectorList* VectorCreateNew() {
TVectorList* newText = nullptr;
		newText = (TVectorList *)malloc(sizeof(TVectorList));
		if (!newText) {
			cout << "Memory is not found" << endl;
			return nullptr;
		}
		newText->next = nullptr;
		newText->text = nullptr;
		return newText;
}

bool VectorAddLastElem(TVectorList **head) {
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Vector is empty" << endl;
		*head = VectorCreateNew();
		if(TextWork(&(*head)->text)) { //if is empty
			cout << "Text is empty" << endl;
			*head = nullptr;
			return true;
		}
		cout << "First elem was added" << endl;
		return true;
	}
	TVectorList *tmp = *head;
	while(tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = VectorCreateNew();
	if(TextWork(&tmp->next->text)) { //if is empty
		cout << "Text is empty" << endl;
		tmp->next = nullptr;
		return true;
	}
	cout << "Last elem was added" << endl;
	return true;
}

bool PrintVector(TVectorList *head) {
	if(head == nullptr) {
		cout << "Vector is empty" << endl;
		return false;
	}
	int i = 0;
	while(head) {
		cout << "[" << i << "] " << endl;
		PrintText(head->text, nullptr);
		head = head->next;
		++i;
		//cout << endl;
	}
	return true;
}

int main() {
	TVectorList *headVector = nullptr;
	TVectorList *takenVector = nullptr;
	bool loop = true;
	bool start = false;
	while(loop) {
		switch (ChooseOperationVector()) {
			case 1:{
				cout << "Let's start work with vector" << endl;
				start = true; break;
			}
			case 2: VectorIsStart(start) ? VectorToNull(&headVector) : 0 ; break;
			case 3: VectorIsStart(start) ? VectorIsEmpty(headVector) : 0 ; break;
			case 4: VectorIsStart(start) ? VectorHowElem(headVector) : 0 ; break;
			case 5: VectorIsStart(start) ? VectorPrintElem(headVector) : 0 ; break;
			case 6: VectorIsStart(start) ? VectorDeleteLastElem(&headVector) : 0 ; break;
			case 7: VectorIsStart(start) ? takenVector = VectorTakeElem(&headVector) : 0 ; break;
			case 8: VectorIsStart(start) ? VectorChangeElem(&headVector) : 0 ; break;
			case 9: VectorIsStart(start) ? VectorAddLastElem(&headVector) : 0 ; break;
			case 10: VectorIsStart(start) ? PrintVector(headVector) : 0 ; break;
			case 11:{
				if(VectorIsStart(start)) {
					cout << "Work with vector is over" << endl;
					start = false;
				}
				break;
			}
			case 12: {

				if(takenVector != nullptr) {
					cout << "Text that you took is :" << endl;
					PrintText(takenVector->text, nullptr);
				}
				cout << "Good Bye";
				return 0;
			}
			default: {
				printf("isn't correct, try again");
				break;
			}
		}
		cout << "Your Vector now : \t" << endl;
		PrintVector(headVector);
	}
	return 0;
}
