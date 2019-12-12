//
// Created by Aigul on 05.12.2019.
//

#ifndef STRUCTCOURSE_SENTENCE_H
#define STRUCTCOURSE_SENTENCE_H

#include <cstdlib>
using namespace std;
struct TSentenceList {
	TSentenceList *next = nullptr;
	char *word = NULL;
};
struct TTextDList {
	TTextDList *next = nullptr;
	TSentenceList *sentence = nullptr;
	TTextDList *back = nullptr;
	TSentenceList *tmpSentence = nullptr;
};

int SentenceChooseOperation() {
	char *answerStr = (char*)malloc(sizeof(char)*2);
	cout << "//--------------------Menu for Sentence List--------------------//" << endl;
	cout << "1 - start work with list" << endl;
	cout << "2 - clean list" << endl;
	cout << "3 - list is empty?" << endl;
	cout << "4 - pointer to head" << endl;
	cout << "5 - is pointer at the end of list?" << endl;
	cout << "6 - pointer to the next" << endl;
	cout << "7 - print next elem from pointer" << endl;
	cout << "8 - delete next elem from pointer" << endl;
	cout << "9 - take next elem from pointer" << endl;
	cout << "10 - change next elem from pointer" << endl;
	cout << "11 - add next elem from pointer" << endl;
	cout << "12 - print list" << endl;
	cout << "13 - finish work with list" << endl;
	cout << "14 - go to the text" << endl;
	cout << "15 - exit and delete structure" << endl;
	scanf("%s", answerStr);
	int answer = atoi(answerStr);
	getchar();
	return answer;
}

bool SentenceIsStart (bool start) {
	if(start) {
		return true;
	} else {
		cout << "No access. Start work with list!" << endl;
		return false;
	}
}
bool SentenceIsEmpty(TSentenceList *head) {
	if (head == nullptr) {
		cout << "Sentence is empty" << endl;
		return true;
	} else {
		cout << "Sentence is not empty" << endl;
		return false;
	}
}

TSentenceList* SentenceTmp(TTextDList* text) {
	if(text->sentence == nullptr) {
		return nullptr;
	} else if(text->tmpSentence) {
		return text->tmpSentence;
	} else return text->sentence;
}

bool SentenceToNull(TTextDList* text) {
	TSentenceList *help;
	if(text->sentence == nullptr) {
		cout << "Sentence is empty already" << endl;
		return false;
	}
	TSentenceList *tmp = text->sentence;
	while(tmp != nullptr) {
		help = tmp;
		tmp = tmp->next;
		free(help);
	}
	text->sentence = nullptr;
	text->tmpSentence = nullptr;
	cout << "Sentence is empty now" << endl;
	return true;
}

bool SentenceToHead(TTextDList* text) {
	if (text->sentence == nullptr) {
		cout << "Sentence is empty. You can't push pointer" << endl;
		return false;
	}
	text->tmpSentence = text->sentence;
	cout << "Pointer is at the head of text" << endl;
	return true;
}

bool SentenceIsEnd(TSentenceList *tmp) {
	if(tmp == nullptr) {
		cout << "Sentence is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence" << endl;
		return true;
	} else {
		cout << "Pointer is not at the end of sentence" << endl;
		return false;
	}
}

bool SentenceToNext(TTextDList *text) {
	if(text->sentence == nullptr) {
		cout << "Sentence is empty or Pointer does not put" << endl;
		return false;
	}
	if(text->tmpSentence->next == nullptr) {
		cout << "Pointer at the end of sentence" << endl;
		return  false;
	}
	text->tmpSentence = text->tmpSentence->next;
	cout << "Pointer is at the next" << endl;
	return true;
}

bool SentencePrintNext(TSentenceList *tmp) {
	if(tmp == nullptr) {
		cout << "Sentence is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence" << endl;
		return true;
	}
	cout << "Next word is \"" << tmp->next->word  << "\"" << endl;
	return true;
}

bool SentenceDeleteNext(TSentenceList *tmp) {
	if(tmp == nullptr) {
		cout << "Sentence is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence." << endl;
		return true;
	}
	tmp->next = tmp->next->next;
	cout << "Next Word was deleted" << endl;
	return true;
}

TSentenceList* SentenceTakeNext(TSentenceList *tmp) {
	if(tmp == nullptr) {
		cout << "Sentence is empty or Pointer does not put" << endl;
		return nullptr;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence" << endl;
		return nullptr;
	}
	TSentenceList *taken = tmp->next;
	cout << "Next Word was taken" << endl;
	SentenceDeleteNext(tmp);
	return taken;
}

bool SentenceChangeNext(TSentenceList *tmp) {
	if(tmp == nullptr) {
		cout << "Sentence is empty or Pointer does not put" << endl;
		return false;
	}
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence" << endl;
		return true;
	}
	cout << "Next word now :" << tmp->next->word << endl;
	cout << "Input new word :";
	cin >> tmp->next->word;
	cout << "Next word was changed" << endl;
	return true;
}

TSentenceList* SentenceCreateNew() {
	TSentenceList* newWord = nullptr;
	newWord = (TSentenceList*)malloc(sizeof(TSentenceList));
	if(!newWord) {
		cout << "Memory is not found" << endl;
		return nullptr;
	}
	newWord->next = nullptr;
	cout << "Input new word :";
	char* inputWord;
	char c;
	int size = 5;
	inputWord =(char*)calloc(5, sizeof(char));
	if(!inputWord) {
		cout << "Memory is not found" << endl;
		return nullptr;
	}
	int end = 0;
	inputWord[0] = (char)getchar();
	for(int i = 1; inputWord[i - 1] != '\n' && inputWord[i - 1] != ' '; ++i) {
		if (i < size) {
			scanf("%c", &c);
			inputWord[i] = c;
		} else {
			inputWord = (char*)realloc(inputWord, size += 5);
			if (!inputWord) {
				free(inputWord);
				printf("Memory is not found");
				return nullptr;
			}
			--i;
		}
		end = i;
	}
	inputWord[end] = '\0';
	newWord->word = inputWord;
	return newWord;
}

bool SentenceAddNextElem(TTextDList *text) {
	if(text->sentence == nullptr) {
		text->sentence = SentenceCreateNew();
		text->tmpSentence = text->sentence;
		cout << "First word was added" << endl;
		return true;
	}
	if(text->tmpSentence == nullptr) {
		cout << "Pointer is not pushed" << endl;
		return false;
	}
	TSentenceList *help = text->tmpSentence->next;
	text->tmpSentence->next = SentenceCreateNew();
	text->tmpSentence->next->next = help;
	cout << "Next word was added" << endl;
	return true;
}


bool PrintSentence(TTextDList *text) {
	if(text->sentence == nullptr) {
		cout << "Sentence is empty. You can't print sentence" << endl;
		return false;
	}
	TSentenceList *tmp = text->sentence;
	while(tmp) {
		if(tmp == text->tmpSentence) {
			cout << " \" " << tmp->word << " \" ";
			tmp = tmp->next;
			continue;
		}
		cout << tmp->word << " ";
		tmp = tmp->next;
	}
	return true;
}

TSentenceList* SentenceWork(TTextDList *text) {
	bool loop = true;
	bool start = false;
	TSentenceList* takenSentence = nullptr;
	TSentenceList *tmp = nullptr;
	TSentenceList *headSentence = nullptr;

	while(loop) {
		headSentence = text->sentence;
		tmp = text->tmpSentence;
		switch (SentenceChooseOperation()) {
			case 1: {
				cout << "Let's start work with sentence" << endl;
				start = true; break;
			}
			case 2: SentenceIsStart(start) ? SentenceToNull(text) : 0; break;
			case 3: SentenceIsStart(start) ? SentenceIsEmpty(headSentence) : 0; break;
			case 4: SentenceIsStart(start) ? SentenceToHead(text) : 0; break;
			case 5: SentenceIsStart(start) ? SentenceIsEnd(tmp) : 0; break;
			case 6: SentenceIsStart(start) ? SentenceToNext(text) : 0; break;
			case 7: SentenceIsStart(start) ? SentencePrintNext(tmp) : 0; break;
			case 8: SentenceIsStart(start) ? SentenceDeleteNext(tmp) : 0; break;
			case 9: SentenceIsStart(start) ? takenSentence = SentenceTakeNext(tmp) : 0; break;
			case 10: SentenceIsStart(start) ? SentenceChangeNext(tmp) : 0; break;
			case 11: SentenceIsStart(start) ? SentenceAddNextElem(text) : 0; break;
			case 12: SentenceIsStart(start) ? PrintSentence(text) : 0; cout << endl; break;
			case 13: {
				if(SentenceIsStart(start)) {
					cout << "Work with sentence is over" << endl;
					start = false;
				} break;
			}
			case 14: loop = false; break;
			case 15: {
				if(takenSentence != nullptr) {
					cout << "Word that you took is : " << takenSentence->word << endl;
				}
				cout << "Good Bye";
				exit(0);
			}
			default: cout << "Isn't correct operation" << endl; break;
		}
		if(text->sentence) {
			cout << "Your Sentence now : " << endl;
			PrintSentence(text);
			cout << endl;
		}
	}
	return SentenceTmp(text);
}

#endif //STRUCTCOURSE_SENTENCE_H