//
// Created by Aigul on 05.12.2019.
//
#ifndef STRUCTCOURSE_TEXT_H
#define STRUCTCOURSE_TEXT_H

#include "Sentence.h"
struct TTextDList {
	TTextDList *next = nullptr;
	TSentenceList *sentence = nullptr;
	TTextDList *back = nullptr;
};

int TextChooseOperation() {
	int answer = 0;
	cout << "//--------------------Menu for Text List--------------------//" << endl;
	cout << "1 - start work with list" << endl;
	cout << "2 - list to null" << endl;
	cout << "3 - list is null?" << endl;
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
	cin >> answer;
	return answer;
}

bool TextIsStart(bool start) {
	if(start) {
		return true;
	} else {
		cout << "No access. Start work with text!" << endl;
		return false;
	}
}

bool TextToNull(TTextDList **head) {
	TTextDList *help;
	if(head == nullptr) {
		cout << "Text does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	while(*head != nullptr) {
		help = *head;
		*head = (*head)->next;
		free(help);
	}
	*head = nullptr;
	return true;
}

bool TextIsEmpty(TTextDList *head) {
	if(head == nullptr) {
		cout << "Text is empty" << endl;
		return true;
	} else {
		cout << "Text is not empty" << endl;
		return false;
	}
}

bool TextToHead(TTextDList *head, TTextDList **tmp) {
	if(head == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	*tmp = head;
	cout << "Pointer is at the head of text" << endl;
	return true;
}

bool TextToEnd(TTextDList *head, TTextDList **tmp) {
	if(head == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	while(head->next) {
		head = head->next;
	}
	*tmp = head;
	cout << "Pointer is at the end of text" << endl;
	return true;
}

bool PrintText(TTextDList *head) {
	if(head == nullptr) {
		cout << "Text is empty" << endl;
		return false;
	}
	while(head) {
		//PrintSentence(head->sentence);
		head = head->next;
	}
	return true;
}

bool TextIsHead(TTextDList *tmp) {
	if(tmp->back == nullptr) {
		cout << "Pointer is at the head" << endl;
		return true;
	} else {
		cout << "Pointer is not at the head" << endl;
		return false;
	}
}

bool TextIsEnd(TTextDList *tmp) {
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end" << endl;
		return true;
	} else {
		cout << "Pointer is not at the end" << endl;
		return false;
	}
}

bool TextNext(TTextDList **tmp) {
	if(*tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if((*tmp)->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	*tmp = (*tmp)->next;
	cout << "Pointer is at the next" << endl;
	return true;
}

bool TextBack(TTextDList **tmp) {
	if(*tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if((*tmp)->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	*tmp = (*tmp)->back;
	cout << "Pointer is at the back" << endl;
	return true;
}

bool TextPrintNextElem(TTextDList *tmp) {
	112222
}

bool TextWork(TTextDList **headText) {
	bool loop = true;
	bool start = false;
	TTextDList *tmpText = nullptr;

	while(loop) {
		switch(TextChooseOperation()) {
			case 1: {
				start = true; break;
			}
			case 2: TextIsStart(start) ? TextToNull(headText) : 0; break;
			case 3: TextIsStart(start) ? TextIsEmpty(*headText) : 0; break;
			case 4: TextIsStart(start) ? TextToHead(*headText, &tmpText) : 0; break;
			case 5: TextIsStart(start) ? TextToEnd(*headText, &tmpText) : 0; break;
			case 6: TextIsStart(start) ? TextIsHead(tmpText) : 0; break;
			case 7: TextIsStart(start) ? TextIsEnd(tmpText) : 0; break;
			case 8: TextIsStart(start) ? TextNext(&tmpText) : 0; break;
			case 9: TextIsStart(start) ? TextBack(&tmpText) : 0; break;
//			case 10: TextIsStart(start) ? TextPrintNextElem(tmp) : 0; break;
//			case 11: TextIsStart(start) ? TextPrintBackElem(tmp) : 0; break;
//			case 12: TextIsStart(start) ? TextDeleteNextElem(tmp, &head) : 0; break;
//			case 13: TextIsStart(start) ? TextDeleteBackElem(tmp, &head) : 0; break;
//			case 14: TextIsStart(start) ? TextTakeNextElem(tmp, &elem) : 0; break;
//			case 15: TextIsStart(start) ? TextTakeBackElem(tmp, &elem) : 0; break;
//			case 16: TextIsStart(start) ? TextChangeNextElem(tmp) : 0; break;
//			case 17: TextIsStart(start) ? TextChangeBackElem(tmp) : 0; break;
//			case 18: TextIsStart(start) ? TextAddNextElem(&tmp, &head, CreatNew()) : 0; break;
//			case 19: TextIsStart(start) ? TextAddBackElem(tmp, &head, CreatNew()) : 0; break;
			case 20: TextIsStart(start) ? PrintText(*headText) : 0; break;
			case 21: {
				if (TextIsStart(start)) {
					loop = false;
					break;
				}
			}
			default: {
				cout << "Isn't correct operation" << endl; break;
			}
		}
	}
	return true;
}

#endif //STRUCTCOURSE_TEXT_H
