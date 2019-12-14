//
// Created by Aigul on 05.12.2019.
//
#ifndef STRUCTCOURSE_TEXT_H
#define STRUCTCOURSE_TEXT_H

#include "Sentence.h"
//описание структуры - динамический вектор
struct TVectorList {
	TTextDList* text = nullptr;
	TVectorList *next = nullptr;
	TTextDList *tmpText = nullptr;
};

//меню для текста
int TextChooseOperation() {
	//выделение памяти под ответ
	char *answerStr = (char*)malloc(sizeof(char)*2);
	//проверка выделилась ли память
	if(!answerStr) {
		cout << "Can not found memory" << endl;
		return 0;
	}
	cout << "//--------------------Menu for Text List--------------------//" << endl;
	cout << "1 - start work with list" << endl;
	cout << "2 - clean list" << endl;
	cout << "3 - list is empty?" << endl;
	cout << "4 - pointer to head" << endl;
	cout << "5 - pointer to end" << endl;
	cout << "6 - is pointer at the head of list?" << endl;
	cout << "7 - is pointer at the end of list?" << endl;
	cout << "8 - pointer to the next" << endl;
	cout << "9 - pointer to the back" << endl;
	cout << "10 - print next elem from pointer" << endl;
	cout << "11 - print back elem after pointer" << endl;
	cout << "12 - delete next elem from pointer" << endl;
	cout << "13 - delete back elem after pointer" << endl;
	cout << "14 - take next elem from pointer" << endl;
	cout << "15 - take back elem after pointer" << endl;
	cout << "16 - change next elem from pointer" << endl;
	cout << "17 - change back elem after pointer" << endl;
	cout << "18 - add next elem from pointer" << endl;
	cout << "19 - add back elem after pointer" << endl;
	cout << "20 - print list" << endl;
	cout << "21 - finish work with text" << endl;
	cout << "22 - go to the vector" << endl;
	cout << "23 - exit and delete structure" << endl;
	//считывание выбора операции
	scanf("%s", answerStr);
	int answer = atoi(answerStr);
	getchar();
	return answer;
}

//проверка доступа к работе с текстом
bool TextIsStart(bool start) {
	if(start) {
		return true;
	} else {
		cout << "No access. Start work with text!" << endl;
		return false;
	}
}

//функция возвращения рабочего указателя в структуру вектора
TTextDList *TextTmp(TVectorList *vector) {
	if(vector->text == nullptr) {
		return nullptr;
	} else if(vector->tmpText) {
		return vector->tmpText;
	} else return vector->text;
}

//функция очищения текста
bool TextToNull(TVectorList *vector) {
	TTextDList *help;
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty already" << endl;
		return false;
	}
	//очищение вектора
	TTextDList *head = vector->text;
	while(head != nullptr) {
		help = head;
		head = head->next;
		free(help);
	}
	vector->text = nullptr;
	vector->tmpText= nullptr;
	cout << "Text is empty now" << endl;
	return true;
}

//функция проверки текста на наличие предложений
bool TextIsEmpty(TTextDList *head) {
	if(head == nullptr) {
		cout << "Text is empty" << endl;
		return true;
	} else {
		cout << "Text is not empty" << endl;
		return false;
	}
}

//функция перемещения рабочего указателя в начало текста
bool TextToHead(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't push pointer" << endl;
		return false;
	}
	vector->tmpText = vector->text;
	cout << "Pointer is at the head of text" << endl;
	return true;
}

//функция перемещение рабочего указателя в конец текста
bool TextToEnd(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't push pointer" << endl;
		return false;
	}
	TTextDList *head = vector->text;
	while(head->next) {
		head = head->next;
	}
	vector->tmpText = head;
	cout << "Pointer is at the end of text" << endl;
	return true;
}

//функция вывода текста
bool PrintText(TVectorList *vector ) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't print text" << endl;
		return false;
	}
	TTextDList *tmp = vector->text;
	while(tmp) {
		//вывод рабочего указателя
		if(tmp == vector->tmpText) {
			cout << "-->";
		}
		PrintSentence(tmp);
		tmp = tmp->next;
		cout << '.' << endl;
	}
	cout << endl;
	return true;
}

//функция проверки нахождения рабочего указателя в начале текста
bool TextIsHead(TTextDList *tmp) {
	//проверка текста на пустоту
	if(tmp == nullptr) {
		cout << "Text is empty " << endl;
		return false;
	}
	if(tmp->back == nullptr) {
		cout << "Pointer is at the head of text" << endl;
		return true;
	} else {
		cout << "Pointer is not at the head of text" << endl;
		return false;
	}
}

//функция проверки нахождения рабочего указателя в конце текста
bool TextIsEnd(TTextDList *tmp) {
	//проверка текста на пустоту
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of text" << endl;
		return true;
	} else {
		cout << "Pointer is not at the end of text" << endl;
		return false;
	}
}

//функция передвижения рабочего указателя на следующий элемент текста
bool TextNext(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	//проверка существования следующего элемента текста
	if(vector->tmpText->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	//передвижения рабочего указателя на следующий элемент текста
	vector->tmpText = vector->tmpText->next;
	cout << "Pointer is at the next" << endl;
	return true;
}

//функция передвижения рабочего указателя на предыдущий элемент текста
bool TextBack(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	//проверка существования предыдущего элемента текста
	if(vector->tmpText->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	//передвижение рабочего указателя на предыдущий элемент текста
	vector->tmpText = vector->tmpText->back;
	cout << "Pointer is at the back" << endl;
	return true;
}

//функция вывода следующего от рабочего указателя элемента текста
bool TextPrintNextElem(TTextDList *tmp) {
	//проверка текста на пустоту
	if(tmp == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	//проверка существования слудующего элемента текста
	if(tmp->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	//вывод следующего от рабочего указателя элемента текста
	cout << "Next sentence is:" << endl;
	PrintSentence(tmp->next);
	cout << endl;
	return true;
}

//функция вывода предыдущего от рабочего указателя элемента текста
bool TextPrintBackElem(TTextDList *tmp) {
	//проверка текста на пустоту
	if(tmp == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	//проверка на существование предыдущего элемента текста
	if(tmp->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	//вывод предыдущего от рабочего указателя элемента текста
	cout << "Back sentence is:" << endl;
	PrintSentence(tmp->back);
	cout << endl;
	return true;
}

//функция удаления следующего от рабочего указателя элемента текста
bool TextDeleteNextElem(TTextDList *head, TTextDList *tmp) {
	//проверка текста на пустоту
	if(head == nullptr) {
		cout << "Text is empty. You can't delete elem" << endl;
		return false;
	}
	//проверка на существование следующего элемента текста
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of text" << endl;
		return true;
	}
	//удаление следующего от рабочего указателя элемента текста
	TTextDList *help = tmp->next->next;
	free(tmp->next);
	//установление связей после удаления элемента текста
	tmp->next = help;
	if(tmp->next) {
		tmp->next->back = tmp;
	}
	cout << "Next Sentence was deleted" << endl;
	return true;
}

//функция удаления предыдущего от рабочего указателя элемента текста
bool TextDeleteBackElem(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't delete elem" << endl;
		return false;
	}
	//проверка на существование предыдущего элемента текста
	if(vector->tmpText->back == nullptr) {
		cout << "Pointer is at the head of text" << endl;
		return true;
	}
	//удаление предыдущего от рабочего указателя элемента текста
	TTextDList *help = (vector->tmpText)->back->back;
	free((vector->tmpText)->back);
	//установление связей после удаления элемента текста
	(vector->tmpText)->back = help;
	if((vector->tmpText)->back) {
		(vector->tmpText)->back->next = vector->tmpText;
	} else {
		vector->text = vector->tmpText;
	}
	cout << "Back Sentence was deleted" << endl;
	return true;
}

//функция взятия следующего от рабочего указателя элемента текста
TTextDList* TextTakeNextElem(TTextDList *head, TTextDList *tmp) {
	//проверка текста на пустоту
	if(head == nullptr) {
		cout << "Text is empty. You can't take elem" << endl;
		return nullptr;
	}
	//проверка на существование следующего элемента текста
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of text" << endl;
		return nullptr;
	}
	//взятие следующего от рабочего указателя элемента текста
	TTextDList * taken = nullptr;
	taken = tmp->next;
	//вывод взятого элемента текста
    PrintSentence(taken);
	cout << endl << "Next Sentence was taken" << endl;
	//удаление взятого элемента текста
	TextDeleteNextElem(head,tmp);
	return taken;
}

//функция взятия предыдущего от рабочего указателя элемента текста
TTextDList* TextTakeBackElem(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't take elem" << endl;
		return nullptr;
	}
	//проверка на существование предыдущего элемента текста
	if((vector->tmpText)->back == nullptr) {
		cout << "Pointer is at the head of text" << endl;
		return nullptr;
	}
	//взятие предыдущего от рабочего указателя элемента текста
	TTextDList * taken = nullptr;
	taken = (vector->tmpText)->back;
	//вывод взятого элемента текста
	PrintSentence(taken);
	cout << endl <<"Back Sentence was taken" << endl;
	//удаление взятого элемента текста
	TextDeleteBackElem(vector);
	return taken;
}

//функция изменения следующего от рабочего указателя элемента текста
bool TextChangeNextElem(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't change elem" << endl;
		return false;
	}
	//проверка на существование следующего элемента текста
	if(vector->tmpText->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	//вывод элемента текста до изменений
	cout << "Next Sentence now :" << endl;
	PrintSentence(vector->tmpText->next);
	cout << endl;
	//проверка на пустоту измененного элемента текста
	if(!((vector->tmpText)->next->tmpSentence = SentenceWork(vector->tmpText->next))) {
		cout << "Sentence is empty" << endl;
		//удаление пустого элемента текста
		TextDeleteNextElem(vector->text,vector->tmpText);
	} else {
		cout << "Next Sentence was changed" << endl;
	}
	return true;
}

//функция изменения предыдущего от рабочего указателя элемента текста
bool TextChangeBackElem(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't change elem" << endl;
		return false;
	}
	//проверка на существование предыдущего элемента текста
	if((vector->tmpText)->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	//вывод элемента текста до изменений
	cout << "Back Sentence now :" << endl;
	PrintSentence((vector->tmpText)->back);
	cout << endl;
	//проверка на пустоту измененного элемента текста
	if(!((vector->tmpText)->back->tmpSentence = SentenceWork((vector->tmpText)->back))) {
		cout << "Sentence is empty" << endl;
		//удаление пустого элемента текста
		TextDeleteBackElem(vector);
	} else {
		cout << "Back Sentence was changed" << endl;
	}
	return true;
}

//функция создания нового элемента текста
TTextDList* TextCreateNew() {
	//выделение памяти под новый элемент текста
	TTextDList* newSentence = nullptr;
	newSentence = (TTextDList*)malloc(sizeof(TTextDList));
	//проверка выделилась ли память под новый элемент текста
	if(!newSentence) {
		cout << "Memory is not found" << endl;
		return nullptr;
	}
	//обнуление данных элемента текста
	newSentence->next = nullptr;
	newSentence->sentence = nullptr;
	newSentence->back = nullptr;
	newSentence->tmpSentence = nullptr;
	return newSentence;
}

//функция проверки на пустоту созданного элемента текста
TTextDList* TextConnect() {
	TTextDList *newObj = TextCreateNew();
	newObj->tmpSentence = SentenceWork(newObj);
	if(!newObj->tmpSentence) {
		return nullptr;
	} else {
		return newObj;
	}
}

//функция добавления созданного элемента текста следующим от рабочего указателя
bool TextAddNextElem(TVectorList *vector) {
	//проверка на пустоту созданного элемента текста
	TTextDList *newObj = TextConnect();
	if(!newObj) {
		cout << "Sentence is empty" << endl;
		cout << "Sentence was deleted" << endl;
		return true;
	}
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		//добавление первого элемента текста
		vector->text = newObj;
		vector->tmpText = newObj;
		cout << "First sentence was added" << endl;
		return true;
	}
	//добавление нового элемента текста следующим от рабочего указателя
	TTextDList *help = vector->tmpText->next;
	vector->tmpText->next = newObj;
	vector->tmpText->next->back = vector->tmpText;
	vector->tmpText->next->next = help;
	if(help) {
		vector->tmpText->next->next->back = vector->tmpText->next;
	}
	cout << "Next sentence was added" << endl;
	return true;
}

//функция добавления созданного элемента предыдущим от рабочего указателя
bool TextAddBackElem(TVectorList *vector) {
	//проверка на пустоту созданного элемента текста
	TTextDList *newObj = TextConnect();
	if(!newObj) {
		cout << "Sentence is empty" << endl;
		cout << "Sentence was deleted" << endl;
		return true;
	}
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		//добавление первого элемента текста
		vector->text = newObj;
		vector->tmpText = vector->text;
		cout << "First sentence was added" << endl;
		return true;
	} else if(vector->tmpText->back == nullptr) {
		//добавление элемента прерыдущим от рабочего указателя на место первого
		vector->text = newObj;
		(vector->text)->back = nullptr;
		(vector->text)->next = vector->tmpText;
		vector->tmpText->back = vector->text;
		cout << "Sentence was added to the first position" << endl;
		return true;
	}
	//добавление нового элемента предыдущим от рабочего указателя
	TTextDList *help = vector->tmpText->back;
	vector->tmpText->back = newObj;
	vector->tmpText->back->next = vector->tmpText;
	vector->tmpText->back->back = help;
	vector->tmpText->back->back->next = vector->tmpText->back;
	cout << "Back sentence was added" << endl;
	return true;
}

//функция вывода текста в обычном и обратном порядке
bool TextToPrint(TVectorList *vector) {
	//проверка текста на пустоту
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't print elem" << endl;
		return false;
	}
	//вывод текста в обычном виде
	PrintText(vector);
	//вывод текста в обратном порядке
	cout << "Revers print:" << endl;
	TTextDList *tmp = vector->text;
	while(tmp->next) {
		tmp = tmp->next;
	}
	while(tmp) {
		//вывод рабочего указателя
		if(tmp == vector->tmpText) {
			cout << "-->";
		}
		PrintSentence(tmp);
		tmp = tmp->back;
		cout << '.' << endl;
	}
	cout << endl;
	return true;
}

//функция работы с текстом
TTextDList* TextWork(TVectorList *vector) {
	bool loop = true;
	bool start = false;
	TTextDList *takenText = nullptr;
	TTextDList *headText = vector->text;
	TTextDList *tmp = vector->tmpText;

	while (loop) {
		headText = vector->text;
		tmp = vector->tmpText;
		//выбор необходимой операции над текстом
		switch (TextChooseOperation()) {
			case 1: {
				cout << "Let's start work with text" << endl;
				start = true;
				break;
			}
			case 2: TextIsStart(start) ? TextToNull(vector) : 0; break;
			case 3:	TextIsStart(start) ? TextIsEmpty(vector->text) : 0; break;
			case 4: TextIsStart(start) ? TextToHead(vector) : 0; break;
			case 5: TextIsStart(start) ? TextToEnd(vector) : 0; break;
			case 6: TextIsStart(start) ? TextIsHead(tmp) : 0; break;
			case 7: TextIsStart(start) ? TextIsEnd(tmp) : 0; break;
			case 8: TextIsStart(start) ? TextNext(vector) : 0; break;
			case 9: TextIsStart(start) ? TextBack(vector) : 0; break;
			case 10: TextIsStart(start) ? TextPrintNextElem(tmp) : 0; break;
			case 11: TextIsStart(start) ? TextPrintBackElem(tmp) : 0; break;
			case 12: TextIsStart(start) ? TextDeleteNextElem(headText, tmp) : 0; break;
			case 13: TextIsStart(start) ? TextDeleteBackElem(vector) : 0; break;
			case 14: TextIsStart(start) ? takenText = TextTakeNextElem(headText, tmp) : 0; break;
			case 15: TextIsStart(start) ? takenText = TextTakeBackElem(vector) : 0; break;
			case 16: TextIsStart(start) ? TextChangeNextElem(vector) : 0; break;
			case 17: TextIsStart(start) ? TextChangeBackElem(vector) : 0; break;
			case 18: TextIsStart(start) ? TextAddNextElem(vector) : 0; break;
			case 19: TextIsStart(start) ? TextAddBackElem(vector) : 0; break;
			case 20: TextIsStart(start) ? TextToPrint(vector) : 0; break;
			case 21: {
				if (TextIsStart(start)) {
					cout << "Work with text is over" << endl;
					start = false;
				}
				break;
			}
			case 22:
				loop = false;
				break;
			case 23: {
				//вывод взятого элемента текста
				if (takenText != nullptr) {
					cout << "Sentence that you took is :" << endl;
					PrintSentence(takenText);
				}
				//очищение текста
				TextToNull(vector);
				cout << "Good Bye";
				exit(0);
			}
			default: {
				cout << "Isn't correct operation" << endl;
				break;
			}
		}
		//вывод не пустого текста после каждой операции
		if (vector->text) {
			cout << "Your Text now : \t" << endl;
			PrintText(vector);
		}
	}
	return TextTmp(vector);
}

#endif