//
// Created by Aigul on 05.12.2019.
//

#ifndef STRUCTCOURSE_SENTENCE_H
#define STRUCTCOURSE_SENTENCE_H

#include <stdlib.h>
using namespace std;
struct TSentenceList {
	TSentenceList *next = nullptr;
	char *word = NULL;
};

int SentenceChooseOperation() {
	int answer = 0;
	cout << "//--------------------Menu for Sentence List--------------------//" << endl;
	cout << "1 - start work with list" << endl;
	cout << "2 - list to null" << endl;
	cout << "3 - list is null?" << endl;
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
	cin >> answer;
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
	if(head == nullptr) {
			return true;
	} else {
		return false;
	}
}

bool SentenceToNull(TSentenceList **head, TSentenceList **tmp) {
	TSentenceList *help;
	if(head == nullptr) {
		cout << "Sentence does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		cout << "Sentence is empty" << endl;
		return false;
	}
	while(*head != nullptr) {
		help = *head;
		*head = (*head)->next;
		free(help);
	}
	*head = nullptr;
	*tmp = nullptr;
	cout << "Sentence is null now" << endl;
	return true;
}

bool SentenceToHead(TSentenceList *head, TSentenceList **tmp) {
	if (head == nullptr) {
		cout << "Sentence is empty" << endl;
		return false;
	}
	*tmp = head;
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

bool SentenceToNext(TSentenceList **tmp) {
	if(*tmp == nullptr) {
		cout << "Sentence is empty or Pointer does not put" << endl;
		return false;
	}
	if((*tmp)->next == nullptr) {
		cout << "Pointer at the end of sentence" << endl;
		return  false;
	}
	*tmp = (*tmp)->next;
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
		cout << "Pointer is at the end of sentence" << endl;
		return true;
	}
	tmp->next = tmp->next->next;
	cout << "Next word was deleted" << endl;
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
		printf("Memory is not found");
		return nullptr;
	}
	int end = 0;
	inputWord[0] = (char)getchar();
	for(int i = 1; inputWord[i - 1] != '\n'; ++i) {
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

bool SentenceAddNextElem(TSentenceList **head, TSentenceList *tmp) {
	if(head == nullptr) {
		cout << "Sentence does not exist" << endl;
		return false;
	} else if(*head == nullptr) {
		*head = SentenceCreateNew();
		cout << "First word was added" << endl;
		return true;
	}
	if(tmp == nullptr) {
		cout << "Pointer is not pushed" << endl;
		return false;
	}
	TSentenceList *help = tmp->next;
	tmp->next = SentenceCreateNew();
	tmp->next->next = help;
	cout << "Next word was added" << endl;
	return true;
}

bool PrintSentence(TSentenceList *head, TSentenceList *tmp) {
	if(head == nullptr) {
		cout << "Sentence is empty" << endl;
		return false;
	}
	while(head) {
		if(head == tmp) {
			cout << "->" << head->word << "<- ";
			head = head->next;
			continue;
		}
		cout << head->word << " ";
		head = head->next;
	}
	return true;
}

bool SentenceWork(TSentenceList **headSentence) {
	bool loop = true;
	bool start = false;
	TSentenceList* tmpSentence = nullptr;
	TSentenceList* takenSentence = nullptr;

	while(loop) {
		switch (SentenceChooseOperation()) {
			case 1: {
				cout << "Let's start work with sentence" << endl;
				start = true; break;
			}
			case 2: SentenceIsStart(start) ? SentenceToNull(headSentence,&tmpSentence) : 0; break;
			case 3:
				if (SentenceIsStart((start))) {
					if (SentenceIsEmpty(*headSentence)) {
						cout << "Sentence is empty" << endl;
					} else {
						cout << "Sentence is not empty" << endl;
					}
				} break;
			case 4: SentenceIsStart(start) ? SentenceToHead(*headSentence, &tmpSentence) : 0; break;
			case 5: SentenceIsStart(start) ? SentenceIsEnd(tmpSentence) : 0; break;
			case 6: SentenceIsStart(start) ? SentenceToNext(&tmpSentence) : 0; break;
			case 7: SentenceIsStart(start) ? SentencePrintNext(tmpSentence) : 0; break;
			case 8: SentenceIsStart(start) ? SentenceDeleteNext(tmpSentence) : 0; break;
			case 9: SentenceIsStart(start) ? takenSentence = SentenceTakeNext(tmpSentence) : 0; break;
			case 10: SentenceIsStart(start) ? SentenceChangeNext(tmpSentence) : 0; break;
			case 11: SentenceIsStart(start) ? SentenceAddNextElem(headSentence, tmpSentence) : 0; break;
			case 12 : SentenceIsStart(start) ? PrintSentence(*headSentence, tmpSentence) : 0; cout << endl; break;
			case 13 : {
				if (SentenceIsStart(start)) {
					start = false;
					break;
				}
			}
			case 14: {
				loop = false;
				break;
			}
			case 15: {
				if(takenSentence != nullptr) {
					cout << "Word that you took is : " << takenSentence->word << endl;
				}
				cout << "Good Bye";
				exit(0);
			}
			default: {
				cout << "Isn't correct operation" << endl; break;
			}
		}
		cout << "Your Sentence now : " << endl;
		PrintSentence(*headSentence, tmpSentence);
		cout << endl;
	}
	return SentenceIsEmpty(*headSentence);
}

#endif //STRUCTCOURSE_SENTENCE_H
