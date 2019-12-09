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
	char *answerStr = (char*)malloc(sizeof(char)*2);
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
	scanf("%s", answerStr);
	int answer = atoi(answerStr);
	getchar();
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

bool TextToNull(TTextDList **head, TTextDList **tmp) {
	TTextDList *help;
	if(head == nullptr) {
		cout << "Text does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Text is empty already" << endl;
		return false;
	}
	while(*head != nullptr) {
		help = *head;
		*head = (*head)->next;
		free(help);
	}
	*head = nullptr;
	*tmp = nullptr;
	cout << "Text is empty now" << endl;
	return true;
}

bool TextIsEmpty(TTextDList *head) {
	if(head == nullptr) {
		return true;
	} else {
		return false;
	}
}

bool TextToHead(TTextDList *head, TTextDList **tmp) {
	if(head == nullptr) {
		cout << "Text is empty. You can't push pointer" << endl;
		return false;
	}
	*tmp = head;
	cout << "Pointer is at the head of text" << endl;
	return true;
}

bool TextToEnd(TTextDList *head, TTextDList **tmp) {
	if(head == nullptr) {
		cout << "Text is empty. You can't push pointer" << endl;
		return false;
	}
	while(head->next) {
		head = head->next;
	}
	*tmp = head;
	cout << "Pointer is at the end of text" << endl;
	return true;
}

bool PrintText(TTextDList *head, TTextDList *tmp) {
	if(head == nullptr) {
		cout << "Text is empty. You can't print text" << endl;
		return false;
	}
	while(head) {
		if(head == tmp) {
			cout << "->";
		}
		PrintSentence(head->sentence, nullptr);
		head = head->next;
		cout << '.' << endl;
	}
	cout << endl;
	return true;
}

bool TextIsHead(TTextDList *tmp) {
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
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

bool TextIsEnd(TTextDList *tmp) {
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
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	cout << "Next sentence is:" << endl;
	PrintSentence(tmp->next->sentence, nullptr);
	cout << endl;
	return true;
}

bool TextPrintBackElem(TTextDList *tmp) {
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	cout << "Back sentence is:" << endl;
	PrintSentence(tmp->back->sentence, nullptr);
	cout << endl;
	return true;
}

bool TextDeleteNextElem(TTextDList *head, TTextDList *tmp) {
	if(head == nullptr) {
		cout << "Text is empty. You can't delete elem" << endl;
		return false;
	}
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of text" << endl;
		return true;
	}
	tmp->next = tmp->next->next;
	if(tmp->next) {
		tmp->next->back = tmp;
	}
	cout << "Next Sentence was deleted" << endl;
	return true;
}

bool TextDeleteBackElem(TTextDList **head, TTextDList *tmp) {
	if(head == nullptr) {
		cout << "Text does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Text is empty. You can't delete elem" << endl;
		return false;
	}
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->back == nullptr) {
		cout << "Pointer is at the head of text" << endl;
		return true;
	}
	tmp->back = tmp->back->back;
	if(tmp->back) {
		tmp->back->next = tmp;
	} else {
		*head = tmp;
	}
	cout << "Back Sentence was deleted" << endl;
	return true;
}

TTextDList* TextTakeNextElem(TTextDList *head, TTextDList *tmp) {
	if(head == nullptr) {
		cout << "Text is empty. You can't take elem" << endl;
		return nullptr;
	}
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return nullptr;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of text" << endl;
		return nullptr;
	}
	TTextDList * taken = nullptr;
	taken = tmp->next;
	cout << "Next Sentence was taken" << endl;
	TextDeleteNextElem(head,tmp);
	return taken;
}

TTextDList* TextTakeBackElem(TTextDList **head, TTextDList *tmp) {
	if(*head == nullptr) {
		cout << "Text is empty. You can't take elem" << endl;
		return nullptr;
	}
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return nullptr;
	}
	if(tmp->back == nullptr) {
		cout << "Pointer is at the head of text" << endl;
		return nullptr;
	}
	TTextDList * taken = nullptr;
	taken = tmp->back;
	cout << "Back Sentence was taken" << endl;
	TextDeleteBackElem(head,tmp);
	return taken;
}

bool TextChangeNextElem(TTextDList *head, TTextDList *tmp) {
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	cout << "Next Sentence now :" << endl;
	PrintSentence(tmp->next->sentence, nullptr);
	cout << endl;
	if(SentenceWork(&tmp->next->sentence)) { // if is empty
		cout << "Sentence is empty" << endl;
		TextDeleteNextElem(head,tmp);
	} else {
		cout << "Next Sentence was changed" << endl;
	}
	return true;
}

bool TextChangeBackElem(TTextDList **head, TTextDList *tmp) {
	if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	cout << "Back Sentence now :" << endl;
	PrintSentence(tmp->back->sentence, nullptr);
	cout << endl;
	if(SentenceWork(&tmp->back->sentence)) { // if is empty
		cout << "Sentence is empty" << endl;
		TextDeleteBackElem(head,tmp);
	} else {
		cout << "Back Sentence was changed" << endl;
	}
	return true;
}

TTextDList* TextCreateNew() {
	TTextDList* newSentence = nullptr;
	newSentence = (TTextDList*)malloc(sizeof(TTextDList));
	if(!newSentence) {
		cout << "Memory is not found" << endl;
		return nullptr;
	}
	newSentence->next = nullptr;
	newSentence->sentence = nullptr;
	newSentence->back = nullptr;
	return newSentence;
}

bool TextAddNextElem(TTextDList **head, TTextDList *tmp) {
	if(head == nullptr) {
		cout << "Text does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		*head = TextCreateNew();
		if(SentenceWork(&(*head)->sentence)) { //if is empty
			cout << "Sentence is empty" << endl;
			*head = nullptr;
			cout << "Sentence was deleted" << endl;
			return true;
		}
		cout << "First sentence was added" << endl;
		return true;
	} else if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	TTextDList *help = tmp->next;
	tmp->next = TextCreateNew();
	if(SentenceWork(&tmp->next->sentence)) { //if is empty
		cout << "Sentence is empty" << endl;
		TextDeleteNextElem(*head,tmp);
		return true;
	}
	tmp->next->back = tmp;
	tmp->next->next = help;
	if(help) {
		tmp->next->next->back = tmp->next;
	}
	cout << "Next sentence was added" << endl;
	return true;
}

bool TextAddBackElem(TTextDList **head, TTextDList *tmp) {
	if(head == nullptr) {
		cout << "Text does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		*head = TextCreateNew();
		if(SentenceWork(&(*head)->sentence)) { //if is empty
			cout << "Sentence is empty" << endl;
			*head = nullptr;
			cout << "Sentence was deleted" << endl;
			return true;
		}
		cout << "First sentence was added" << endl;
		return true;
	} else if(tmp == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	} else if(tmp->back == nullptr) {
		*head = TextCreateNew();
		if(SentenceWork(&(*head)->sentence)) { //if is empty
			cout << "Sentence is empty" << endl;
			*head = nullptr;
			cout << "Sentence was deleted" << endl;
			return true;
		}
		tmp->back = *head;
		(*head)->back = nullptr;
		(*head)->next = tmp;
		cout << "Sentence was added to the first position" << endl;
		return true;
	}
	TTextDList *help = tmp->back;
	tmp->back = TextCreateNew();
	if(SentenceWork(&tmp->back->sentence)) { //if is empty
		cout << "Sentence is empty" << endl;
		TextDeleteBackElem(head,tmp);
		return true;
	}
	tmp->back->next = tmp;
	tmp->back->back = help;
	tmp->back->back->next = tmp->back;
	cout << "Back sentence was added" << endl;
	return true;
}

bool TextWork(TTextDList **headText) {
	bool loop = true;
	bool start = false;
	TTextDList *tmpText = nullptr;
	TTextDList *takenText = nullptr;

	while(loop) {
		switch(TextChooseOperation()) {
			case 1: {
				cout << "Let's start work with text" << endl;
				start = true; break;
			}
			case 2: TextIsStart(start) ? TextToNull(headText, &tmpText) : 0; break;
			case 3: {
				if (TextIsStart((start))) {
					if (TextIsEmpty(*headText)) {
						cout << "Text is empty" << endl;
					} else {
						cout << "Text is not empty" << endl;
					}
				} break;
			}
			case 4: TextIsStart(start) ? TextToHead(*headText, &tmpText) : 0; break;
			case 5: TextIsStart(start) ? TextToEnd(*headText, &tmpText) : 0; break;
			case 6: TextIsStart(start) ? TextIsHead(tmpText) : 0; break;
			case 7: TextIsStart(start) ? TextIsEnd(tmpText) : 0; break;
			case 8: TextIsStart(start) ? TextNext(&tmpText) : 0; break;
			case 9: TextIsStart(start) ? TextBack(&tmpText) : 0; break;
			case 10: TextIsStart(start) ? TextPrintNextElem(tmpText) : 0; break;
			case 11: TextIsStart(start) ? TextPrintBackElem(tmpText) : 0; break;
			case 12: TextIsStart(start) ? TextDeleteNextElem(*headText, tmpText) : 0; break;
			case 13: TextIsStart(start) ? TextDeleteBackElem(headText, tmpText) : 0; break;
			case 14: TextIsStart(start) ? takenText = TextTakeNextElem(*headText, tmpText) : 0; break;
			case 15: TextIsStart(start) ? takenText = TextTakeBackElem(headText, tmpText) : 0; break;
			case 16: TextIsStart(start) ? TextChangeNextElem(*headText, tmpText) : 0; break;
			case 17: TextIsStart(start) ? TextChangeBackElem(headText, tmpText) : 0; break;
			case 18: TextIsStart(start) ? TextAddNextElem(headText, tmpText) : 0; break;
			case 19: TextIsStart(start) ? TextAddBackElem(headText, tmpText) : 0; break;
			case 20: TextIsStart(start) ? PrintText(*headText, tmpText) : 0; break;
			case 21: {
				if(TextIsStart(start)) {
					cout << "Work with text is over" << endl;
					start = false;
				} break;
			}
			case 22: loop = false; break;
			case 23: {
				if(takenText != nullptr) {
					cout << "Sentence that you took is :" << endl;
					PrintSentence(takenText->sentence, nullptr);
				}
				cout << "Good Bye";
				exit(0);
			}
			default: {
				cout << "Isn't correct operation" << endl; break;
			}
		}
		if(*headText) {
			cout << "Your Text now : \t" << endl;
			PrintText(*headText, tmpText);
		}
	}
	return TextIsEmpty(*headText);
}

#endif //STRUCTCOURSE_TEXT_H
