//
// Created by Aigul on 05.12.2019.
//
#ifndef STRUCTCOURSE_TEXT_H
#define STRUCTCOURSE_TEXT_H

#include "Sentence.h"

struct TVectorList {
	TTextDList* text = nullptr;
	TVectorList *next = nullptr;
	TTextDList *tmpText = nullptr;
};

int TextChooseOperation() {
	char *answerStr = (char*)malloc(sizeof(char)*2);
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

TTextDList *TextTmp(TVectorList *vector) {
	if(vector->text == nullptr) {
		return nullptr;
	} else if(vector->tmpText) {
		return vector->tmpText;
	} else return vector->text;
}

bool TextToNull(TVectorList *vector) {
	TTextDList *help;
	if(vector->text == nullptr) {
		cout << "Text is empty already" << endl;
		return false;
	}
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

bool TextIsEmpty(TTextDList *head) {
	if(head == nullptr) {
		cout << "Text is empty" << endl;
		return true;
	} else {
		cout << "Text is not empty" << endl;
		return false;
	}
}

bool TextToHead(TVectorList *vector) {
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't push pointer" << endl;
		return false;
	}
	vector->tmpText = vector->text;
	cout << "Pointer is at the head of text" << endl;
	return true;
}

bool TextToEnd(TVectorList *vector) {
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

bool PrintText(TVectorList *vector ) {
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't print text" << endl;
		return false;
	}
	TTextDList *tmp = vector->text;
	while(tmp) {
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

bool TextNext(TVectorList *vector) {
	if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(vector->tmpText->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	vector->tmpText = vector->tmpText->next;
	cout << "Pointer is at the next" << endl;
	return true;
}

bool TextBack(TVectorList *vector) {
	if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(vector->tmpText->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	vector->tmpText = vector->tmpText->back;
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
	PrintSentence(tmp->next);
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
	PrintSentence(tmp->back);
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

bool TextDeleteBackElem(TVectorList *vector) {
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't delete elem" << endl;
		return false;
	}
	if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(vector->tmpText->back == nullptr) {
		cout << "Pointer is at the head of text" << endl;
		return true;
	}
	(vector->tmpText)->back = (vector->tmpText)->back->back;
	if((vector->tmpText)->back) {
		(vector->tmpText)->back->next = vector->tmpText;
	} else {
		vector->text = vector->tmpText;
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
    PrintSentence(taken);
	cout << endl << "Next Sentence was taken" << endl;
	TextDeleteNextElem(head,tmp);
	return taken;
}

TTextDList* TextTakeBackElem(TVectorList *vector) {
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't take elem" << endl;
		return nullptr;
	}
	if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return nullptr;
	}
	if((vector->tmpText)->back == nullptr) {
		cout << "Pointer is at the head of text" << endl;
		return nullptr;
	}
	TTextDList * taken = nullptr;
	taken = (vector->tmpText)->back;
	PrintSentence(taken);
	cout << endl <<"Back Sentence was taken" << endl;
	TextDeleteBackElem(vector);
	return taken;
}

bool TextChangeNextElem(TVectorList *vector) {
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't change elem" << endl;
		return false;
	}
	if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if(vector->tmpText->next == nullptr) {
		cout << "Pointer at the end of text" << endl;
		return  false;
	}
	cout << "Next Sentence now :" << endl;
	PrintSentence(vector->tmpText->next);
	cout << endl;
	if(!((vector->tmpText)->next->tmpSentence = SentenceWork(vector->tmpText->next))) { // if is empty
		cout << "Sentence is empty" << endl;
		TextDeleteNextElem(vector->text,vector->tmpText);
	} else {
		cout << "Next Sentence was changed" << endl;
	}
	return true;
}

bool TextChangeBackElem(TVectorList *vector) {
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't change elem" << endl;
		return false;
	}
	if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}
	if((vector->tmpText)->back == nullptr) {
		cout << "Pointer at the head of text" << endl;
		return  false;
	}
	cout << "Back Sentence now :" << endl;
	PrintSentence((vector->tmpText)->back);
	cout << endl;
	if(!((vector->tmpText)->back->tmpSentence = SentenceWork((vector->tmpText)->back))) { // if is empty
		cout << "Sentence is empty" << endl;
		TextDeleteBackElem(vector);
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
	newSentence->tmpSentence = nullptr;
	return newSentence;
}

TTextDList* TextConnect() {
	TTextDList *newObj = TextCreateNew();
	newObj->tmpSentence = SentenceWork(newObj);
	if(!newObj->tmpSentence) {
		return nullptr;
	} else {
		return newObj;
	}
}

bool TextAddNextElem(TVectorList *vector) {
	TTextDList *newObj = TextConnect();
	if(!newObj) {
		cout << "Sentence is empty" << endl;
		cout << "Sentence was deleted" << endl;
		return true;
	}

	if(vector->text == nullptr) {
		vector->text = newObj;
		vector->tmpText = newObj;
		cout << "First sentence was added" << endl;
		return true;
	} else if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	}

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

bool TextAddBackElem(TVectorList *vector) {
	TTextDList *newObj = TextConnect();
	if(!newObj) { //if is empty
		cout << "Sentence is empty" << endl;
		cout << "Sentence was deleted" << endl;
		return true;
	}

	if(vector->text == nullptr) {
		vector->text = newObj;
		vector->tmpText = vector->text;
		cout << "First sentence was added" << endl;
		return true;
	} else if(vector->tmpText == nullptr) {
		cout << "Text is empty or Pointer does not put" << endl;
		return false;
	} else if(vector->tmpText->back == nullptr) {
		vector->text = newObj;
		(vector->text)->back = nullptr;
		(vector->text)->next = vector->tmpText;
		vector->tmpText->back = vector->text;
		cout << "Sentence was added to the first position" << endl;
		return true;
	}
	TTextDList *help = vector->tmpText->back;
	vector->tmpText->back = newObj;
	vector->tmpText->back->next = vector->tmpText;
	vector->tmpText->back->back = help;
	vector->tmpText->back->back->next = vector->tmpText->back;
	cout << "Back sentence was added" << endl;
	return true;
}

bool TextToPrint(TVectorList *vector) {
	if(vector->text == nullptr) {
		cout << "Text is empty. You can't change elem" << endl;
		return false;
	}
	PrintText(vector);
	cout << "Revers print:" << endl;
	TTextDList *tmp = vector->text;
	while(tmp->next) {
		tmp = tmp->next;
	}
	while(tmp) {
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

TTextDList* TextWork(TVectorList *vector) {
	bool loop = true;
	bool start = false;
	TTextDList *takenText = nullptr;
	TTextDList *headText = vector->text;
	TTextDList *tmp = vector->tmpText;

	while (loop) {
		headText = vector->text;
		tmp = vector->tmpText;
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
				if (takenText != nullptr) {
					cout << "Sentence that you took is :" << endl;
					PrintSentence(takenText);
				}
				cout << "Good Bye";
				exit(0);
			}
			default: {
				cout << "Isn't correct operation" << endl;
				break;
			}
		}
		if (vector->text) {
			cout << "Your Text now : \t" << endl;
			PrintText(vector);
		}
	}
	return TextTmp(vector);
}

#endif