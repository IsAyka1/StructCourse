//
// Created by Aigul on 05.12.2019.
//
using namespace std;
#include <iostream>
#include <cstdlib>
#include "Text.h"

//меню для структуры - динамический вектор
int ChooseOperationVector() {
	//выделение памяти под ответ
	char *answerStr = (char*)malloc(sizeof(char)*2);
	//проверка выделилась ли память
    if(!answerStr) {
        cout << "Can not found memory" << endl;
        return 0;
    }
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
	//считывание выбора операции
	scanf("%s", answerStr);
	int answer = atoi(answerStr);
	getchar();
	return answer;
}

//проверка доступа к работе с вектором
bool VectorIsStart(bool start) {
	if(start) {
		return true;
	} else {
		cout << "No access. Start work with vector!" << endl;
		return false;
	}
}

//проверка вектора на наличие элементов
bool VectorIsEmpty(TVectorList *head) {
	if(head == nullptr) {
		cout << "Vector is empty" << endl;
		return true;
	} else {
		cout << "Vector is not empty" << endl;
		return false;
	}
}

//функция очищения вектора
bool VectorToNull(TVectorList**head) {
	TVectorList *help;
	//проверка вектора на существование
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	}
	//проверка вектора на пустоту
	if(*head == nullptr) {
		cout << "Vector is empty already" << endl;
		return true;
	}
	//очищение вектора
	while(*head != nullptr) {
		help = *head;
		*head = (*head)->next;
		free(help);
	}
	*head = nullptr;
	cout << "Vector is empty now" << endl;
	return true;
}

//функция подсчета элементов
int VectorHowElem(TVectorList *head) {
	//проверка вектора на пустоту
	if(head == nullptr) {
		cout << "Vector is empty. Zero elements in this vector" << endl;
		return 0;
	}
	//подсчет количества элементов в векторе
	int count{};
	TVectorList *tmp = head;
	while(tmp != nullptr) {
		tmp = tmp->next;
		count++;
	}
	cout << "In this vector " << count << " elem" << endl;
	return count;
}

//функция ввода индекса необходимого элемента вектора
int indexInput(TVectorList *head) {
	//сколько всего элементов в векторе
	int sizeVector = VectorHowElem(head);
	cout << "Input index elem you want to change:";
	//считывание индекса необходимого элемента вектора
	char *answer = (char*)malloc(sizeof(char)*2);
	if(!answer) {
		cout << "Can not found memory" << endl;
		return 0;
	}
	scanf("%s", answer);
	int index = atoi(answer);
	getchar();
	//обработка неподходящих ответов
	if(index <= 0) {
		cout << "Isn't correct index" << endl;
		return 0;
	}
	if(index > sizeVector) {
		cout << "Index is bigger than vector's size. Elem with this index does not exist" << endl;
		return 0;
	}
	return index;
}

//функция вывода элемента
bool VectorPrintElem(TVectorList *head) {
	//проверка вектора на пустоту
	if(head == nullptr) {
		cout << "Vector is empty. You can't print elem" << endl;
		return false;
	}
	//считывание индекса необходимого элемента
	int index = indexInput(head);
	//проверка на правильность ввода индекса
	if(index == 0) {
		return false;
	}
	//поиск необходимого элемента в векторе
	for(int i = 1 ;i != index; ++i) {
		head = head->next;
	}
	//вывод необходимого элемента вектора
	cout << "Elem[" << index << "] :" << endl;
	PrintText(head);
	return true;
}

//функция удаления последнего элемента вектора
bool VectorDeleteLastElem(TVectorList **head) {
	//проверка вектора на существование
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	}
	//проверка вектора на пустоту
	if(*head == nullptr) {
		cout << "Vector is empty. You can't delete elem" << endl;
		return false;
	}
	//удаление первого элемента вектора
	if((*head)->next == nullptr) {
		cout << "Vector has only first elem" << endl;
		free(*head);
		*head = nullptr;
		cout << "Vector is empty now" << endl;
		return true;
	}
	//удаление последнего элемента вектора
	TVectorList *tmp = *head;
	while(tmp->next->next != nullptr) {
		tmp = tmp ->next;
	}
	free(tmp->next);
	tmp->next = nullptr;
	cout << "Last elem was deleted" << endl;
	return true;
}

//функция взятия элемента вектора
TVectorList* VectorTakeElem(TVectorList **head) {
	//проверка на существование вектора
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return nullptr;
	}
	//проверка вектора на пустоту
	if(*head == nullptr) {
		cout << "Vector is empty. You can't take elem" << endl;
		return nullptr;
	}
	//считывание индекса необходимого элемента
	int index = indexInput(*head);
	//проверка на правильность ввода индекса
	if(index == 0) {
		return nullptr;
	}
	TVectorList *taken = nullptr;
	//взятие первого элемента вектора
	if(index == 1) {
		taken = *head;
		//вывод взятого элемента вектора
		PrintText(taken);
		cout << "Elem with index " << index << " was taken" << endl;
		return taken;
	}
	//взятие необходимого элемента вектора
	TVectorList *tmp = *head;
	for(int i = 1; i != index - 1; ++i) {
		tmp = tmp->next;
	}
	taken = tmp->next;
	//вывод взятого элемента вектора
	PrintText(taken);
	cout << "Elem with index " << index << " was taken" << endl;
	return taken;
}

//функция изменения элемента вектора
bool VectorChangeElem(TVectorList **head) {
	//проверка на существование вектора
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	}
	//проверка вектора на пустоту
	if(*head == nullptr) {
		cout << "Vector is empty. You can't change elem" << endl;
		return false;
	}
	//считывание индекса необходимого элемента
	int index = indexInput(*head);
	//проверка на правильность ввода индекса
	if(index == 0) {
		return false;
	}
	//обработка изменения первого элемента вектора
	if(index == 1) {
		cout << "Elem with index " << index << " now :" << endl;
		PrintText(*head);
		//проверка на пустоту измененного элемента вектора
		if(!TextWork(*head)) {
			//удаление первого элемента вектора
			cout << "Text is empty" << endl;
			free(*head);
			*head = (*head)->next;
			cout << "Empty Text was deleted" << endl;
		} else {
			cout << "Elem with index " << index << " was changed" << endl;
		}
		return  true;
	}
	//поиск необходимого элемента в векторе
	TVectorList *tmp = *head;
	for(int i = 1; i != index - 1; ++i) {
		tmp = tmp->next;
	}
	//вывод необходимого текста до изменений
	cout << "Elem with index " << index << " now :" << endl;
	PrintText(tmp->next);
	//обработка изменения необходимого элемента вектора
	//проверка на пустоту измененного элемента вектора
	if(!TextWork(tmp->next)) {
		//удаление пустого элемента вектора
		cout << "Text is empty" << endl;
		tmp->next = tmp->next->next;
		cout << "Empty Text was deleted" << endl;
	} else {
		cout << "Elem with index " << index << " was changed" << endl;
	}
	return true;
}

//функция создания нового элемента вектора
TVectorList* VectorCreateNew() {
	TVectorList* newText = nullptr;
	//выделение памяти под новый элемент вектора
	newText = (TVectorList *)malloc(sizeof(TVectorList));
	//проверка выделилась ли память под новый элемент вектора
	if (!newText) {
		cout << "Memory is not found" << endl;
		return nullptr;
	}
	//обнуление данных элемента вектора
	newText->next = nullptr;
	newText->text = nullptr;
	newText->tmpText = nullptr;
	return newText;
}

//функция проверки на пустоту созданного элемента вектора
TVectorList* VectorConnect() {
	TVectorList *newObj = VectorCreateNew();
	newObj->tmpText = TextWork(newObj);
	if(!newObj->tmpText) {
		return nullptr;
	} else {
		return newObj;
	}
}

//функция добавления созданного элемента в конец вектора
bool VectorAddLastElem(TVectorList **head) {
	//проверка на пустоту созданного элемента вектора
	TVectorList *newObj = VectorConnect();
	if(!newObj) {
		cout << "Text is empty" << endl;
		cout << "Text was deleted" << endl;
		return true;
	}
	//проверка на существование вектора
	if(head == nullptr) {
		cout << "Error. Vector does not exist" << endl;
		return false;
	}
	//проверка вектора на пустоту
	if(*head == nullptr) {
		//добавление первого элемента в вектор
		*head = newObj;
		cout << "First elem was added" << endl;
		return true;
	}
	//добавление нового элемента в конец вектора
	TVectorList *tmp = *head;
	while(tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = newObj;
	cout << "Last elem was added" << endl;
	return true;
}

//функция вывода вектора
bool PrintVector(TVectorList *head) {
	//проверка вектора на пустоту
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
		//выбор необходимой операции над вектором
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
				//вывод взятого элемента вектора
				if(takenVector != nullptr) {
					cout << "Text that you took is :" << endl;
					PrintText(takenVector);
				}
				//очищение вектора
				VectorToNull(&headVector);
				cout << "Good Bye";
				return 0;
			}
			default: cout << "isn't correct, try again" << endl; break;
		}
		//вывод не пустого вектора после каждой операции
		if(headVector) {
			cout << "Your Vector now : \t" << endl;
			PrintVector(headVector);
		}
	}
	return 0;
}