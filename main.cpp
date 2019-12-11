//
// Created by Aigul on 05.12.2019.
//
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Text.h"
#include <cstring>

int ChooseOperationVector() {
	char *answerStr = (char*)malloc(sizeof(char)*2);
	cout << "//--------------------Menu for Vector List--------------------//" << endl;
	cout << "1 - start work with vector" << endl;
	cout << "2 - clean vector" << endl;
	cout << "3 - vector is empty?" << endl;
	cout << "4 - how many elements in vector?" << endl;
	cout << "5 - print elem with index" << endl;
	cout << "6 - delete last elem " << endl;
	cout << "7 - take elem with index" << endl;
	cout << "8 - change elem with index" << endl;
	cout << "9 - add elem to the end" << endl;
	cout << "10 - print vector" << endl;
	cout << "11 - finish work with vector" << endl;
	cout << "12 - Exit and delete vector" << endl;
	scanf("%s", answerStr);
	int answer = atoi(answerStr);
	getchar();
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
		cout << "Vector is empty already" << endl;
		return true;
	}
	while(*head != nullptr) {
		help = *head;
		*head = (*head)->next;
		free(help);
	}
	*head = nullptr;
	cout << "Vector is empty" << endl;
	return true;
}

int VectorHowElem(TVectorList *head) {
	if(head == nullptr) {
		cout << "Vector is empty. Zero elements in this vector" << endl;
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
		cout << "Vector is empty. You can't print elem" << endl;
		return false;
	}
	int index = 0;
	int sizeVector = VectorHowElem(head);
	cout << "Input index elem you want to print:";
	cin >> index;
	if(index <= 0) {
		cout << "Isn't correct index" << endl;
		return false;
	}
	if(index > sizeVector) {
		cout << "Index is bigger than vector's size. Elem with this index does not exist" << endl;
		return false;
	}
	for(int i = 1 ;i != index; ++i) {
		head = head->next;
	}
	cout << "Elem[" << index << "] :" << endl;
	PrintText(head);
	return true;
}

bool VectorDeleteLastElem(TVectorList **head) {
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Vector is empty. You can't delete elem" << endl;
		return false;
	}
	if((*head)->next == nullptr) {
		cout << "Vector has only first elem" << endl;
		*head = nullptr;
		cout << "Vector is empty now" << endl;
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
		cout << "Vector is empty. You can't take elem" << endl;
		return nullptr;
	}
	int index = 0;
	int sizeVector = VectorHowElem(*head);
	TVectorList *taken = nullptr;
	cout << "Input index elem you want to take:";
	cin >> index;
	if(index <= 0) {
		cout << "Isn't correct index" << endl;
		return nullptr;
	}
	if(index > sizeVector) {
		cout << "Index is bigger than vector's size. Elem with this index does not exist" << endl;
		return nullptr;
	}
	if(index == 1) {
		taken = *head;
		*head = (*head)->next;
		taken->next = nullptr;
		PrintText(taken);
		cout << "Elem with index " << index << " was taken" << endl;
		return taken;
	}
	for(int i = 1; i != index - 1; ++i) {
		*head = (*head)->next;
	}
	taken = (*head)->next;
	(*head)->next = (*head)->next->next;
	taken->next = nullptr;
	PrintText(taken);
	cout << "Elem with index " << index << " was taken" << endl;
	return taken;
}

bool VectorChangeElem(TVectorList **head) {
	if(*head == nullptr) {
		cout << "Vector is empty. You can't change elem" << endl;
		return false;
	}
	int index = 0;
	int sizeVector = VectorHowElem(*head);
	cout << "Input index elem you want to change:";
	cin >> index;
	if(index <= 0) {
		cout << "Isn't correct index" << endl;
		return false;
	}
	if(index > sizeVector) {
		cout << "Index is bigger than vector's size. Elem with this index does not exist" << endl;
		return false;
	}
	if(index == 1) {
		cout << "Elem with index " << index << " now :" << endl;
		PrintText(*head);
		if(!TextWork(*head)) { // if is empty
			cout << "Text is empty" << endl;
			*head = (*head)->next;
			cout << "Empty Text was deleted" << endl;
		} else {
			cout << "Elem with index " << index << " was changed" << endl;
		}
		return  true;
	}
	TVectorList *tmp = *head;
	for(int i = 1; i != index - 1; ++i) {
		tmp = tmp->next;
	}
	cout << "Elem with index " << index << " now :" << endl;
	PrintText(tmp->next);
	if(!TextWork(tmp->next)) { // if is empty
		cout << "Text is empty" << endl;
		tmp->next = tmp->next->next;
		cout << "Empty Text was deleted" << endl;
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
	newText->tmpText = nullptr;
	return newText;
}

TVectorList* VectorConnect() {
	TVectorList *newObj = VectorCreateNew();
	newObj->tmpText = TextWork(newObj);
	if(!newObj->tmpText) {
		return nullptr;
	} else {
		return newObj;
	}
}

bool VectorAddLastElem(TVectorList **head) {
	TVectorList *newObj = VectorConnect();
	if(!newObj) {
		cout << "Text is empty" << endl;
		cout << "Text was deleted" << endl;
		return true;
	}
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		*head = newObj;
		cout << "First elem was added" << endl;
		return true;
	}
	TVectorList *tmp = *head;
	while(tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = newObj;
	cout << "Last elem was added" << endl;
	return true;
}

bool PrintVector(TVectorList *head) {
	if(head == nullptr) {
		cout << "Vector is empty. You can't print Vector" << endl;
		return false;
	}
	int i = 1;
	while(head) {
		cout << "[" << i << "] " << endl;
		PrintText(head);
		head = head->next;
		++i;
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
				} break;
			}
			case 12: {
				if(takenVector != nullptr) {
					cout << "Text that you took is :" << endl;
					PrintText(takenVector);
				}
				cout << "Good Bye";
				return 0;
			}
			default: cout << "isn't correct, try again" << endl; break;
		}
		if(headVector) {
			cout << "Your Vector now : \t" << endl;
			PrintVector(headVector);
		}
	}
	return 0;
}