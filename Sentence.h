//
// Created by Aigul on 05.12.2019.
//

#ifndef STRUCTCOURSE_SENTENCE_H
#define STRUCTCOURSE_SENTENCE_H

#include <cstdlib>
using namespace std;

//описание структуры - односвязный список
struct TSentenceList {
	TSentenceList *next = nullptr;
	char *word = NULL;
};
//описание структуры - двусвязный список
struct TTextDList {
	TTextDList *next = nullptr;
	TSentenceList *sentence = nullptr;
	TTextDList *back = nullptr;
	TSentenceList *tmpSentence = nullptr;
};

//меню для предложения
int SentenceChooseOperation() {
	//выделение памяти под ответ
	char *answerStr = (char*)malloc(sizeof(char)*2);
	//проверка выделилась ли память
	if(!answerStr) {
		cout << "Can not found memory" << endl;
		return 0;
	}
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
	//считывание выбора операции
	scanf("%s", answerStr);
	int answer = atoi(answerStr);
	getchar();
	return answer;
}

//проверка доступа к работе с предложением
bool SentenceIsStart (bool start) {
	if(start) {
		return true;
	} else {
		cout << "No access. Start work with list!" << endl;
		return false;
	}
}

//функция проверки предложения на наличие слов
bool SentenceIsEmpty(TSentenceList *head) {
	//проверка предложения на пустоту
	if (head == nullptr) {
		cout << "Sentence is empty" << endl;
		return true;
	} else {
		cout << "Sentence is not empty" << endl;
		return false;
	}
}

//функция возвращения рабочего указателя в структуру текста
TSentenceList* SentenceTmp(TTextDList* text) {
	if(text->sentence == nullptr) {
		return nullptr;
	} else if(text->tmpSentence) {
		return text->tmpSentence;
	} else return text->sentence;
}

//функция очищения предложения
bool SentenceToNull(TTextDList* text) {
	TSentenceList *help;
	//проверка предложения на пустоту
	if(text->sentence == nullptr) {
		cout << "Sentence is empty already" << endl;
		return false;
	}
	//очищение предложения
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

//функция перемещения рабочего указателя в начало предложения
bool SentenceToHead(TTextDList* text) {
	//проверка предложения на пустоту
	if (text->sentence == nullptr) {
		cout << "Sentence is empty. You can't push pointer" << endl;
		return false;
	}
	text->tmpSentence = text->sentence;
	cout << "Pointer is at the head of text" << endl;
	return true;
}

//функция проверки нахождения рабочего указателя в конце предложения
bool SentenceIsEnd(TSentenceList *tmp) {
	//проверка предложения на пустоту
	if(tmp == nullptr) {
		cout << "Sentence is empty " << endl;
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

//функция передвижения рабочего указателя на следующий элемент предложения
bool SentenceToNext(TTextDList *text) {
	//проверка предложения на пустоту
	if(text->sentence == nullptr) {
		cout << "Sentence is empty " << endl;
		return false;
	}
	//проверка на существование следующего элемента предложения
	if(text->tmpSentence->next == nullptr) {
		cout << "Pointer at the end of sentence" << endl;
		return  false;
	}
	//передвижение рабочего указателя на следующий элемент предложения
	text->tmpSentence = text->tmpSentence->next;
	cout << "Pointer is at the next" << endl;
	return true;
}

//функция вывода следующего от рабочего указателя элемента предложения
bool SentencePrintNext(TSentenceList *tmp) {
	//проверка предложения на пустоту
	if(tmp == nullptr) {
		cout << "Sentence is empty" << endl;
		return false;
	}
	//проверка на существование следующего элемента предложения
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence" << endl;
		return true;
	}
	//вывод следующего от рабочего указателя элемента предложения
	cout << "Next word is \"" << tmp->next->word  << "\"" << endl;
	return true;
}

//функция удаления следующего от рабочего указателя элемента предложения
bool SentenceDeleteNext(TSentenceList *tmp) {
	if(tmp == nullptr) {
		//проверка предложения на пустоту
		cout << "Sentence is empty" << endl;
		return false;
	}
	//проверка на существование следующего элемента предложения
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence." << endl;
		return true;
	}
	//удаление следующего от рабочего указателя элемента предложения
	TSentenceList *help =  tmp->next->next;
	free(tmp->next);
	//установление связей после удаления элемента предложения
	tmp->next = help;
	cout << "Next Word was deleted" << endl;
	return true;
}

//функция взятия следующего от рабочего указателя элемента предложения
TSentenceList* SentenceTakeNext(TSentenceList *tmp) {
	//проверка предложения на пустоту
	if(tmp == nullptr) {
		cout << "Sentence is empty" << endl;
		return nullptr;
	}
	//проверка на существование следующего элемента предложения
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence" << endl;
		return nullptr;
	}
	//взятие следующего от рабочего указателя элемента предложения
	TSentenceList *taken = tmp->next;
	//вывод взятого элемента предложения
	cout << "Next word is \"" << tmp->next << "\" was taken" << endl;
	//удаление взтого элемента предложения
	SentenceDeleteNext(tmp);
	return taken;
}

//функция создания нового элемента предложения
TSentenceList* SentenceCreateNew() {
	//выделение памяти под новый элемент предложения
	TSentenceList* newWord = nullptr;
	newWord = (TSentenceList*)malloc(sizeof(TSentenceList));
	//проверка выделилась ли память под новый элемент предложения
	if(!newWord) {
		cout << "Memory is not found" << endl;
		return nullptr;
	}
	//обнуление данных элемента
	newWord->next = nullptr;
	cout << "Input new word :";
	char* inputWord;
	char c;
	int size = 5;
	//выделение памяти под новое слово
	inputWord =(char*)calloc(5, sizeof(char));
	//проверка выделилась ли память под новое слово
	if(!inputWord) {
		cout << "Memory is not found" << endl;
		return nullptr;
	}
	int end = 0;
	inputWord[0] = (char)getchar();
	//считывание нового слова из консоли
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
	//добавление нового слова в созданный элемент предложения
	newWord->word = inputWord;
	return newWord;
}

//функция изменения следующего от рабочего указателя элемента предложения
bool SentenceChangeNext(TSentenceList *tmp) {
	//проверка предложения на пустоту
	if(tmp == nullptr) {
		cout << "Sentence is empty" << endl;
		return false;
	}
	//проверка на существование следующего элемента предложения
	if(tmp->next == nullptr) {
		cout << "Pointer is at the end of sentence" << endl;
		return true;
	}
	//вывод значения элемента предложения до изменений
	cout << "Next word now :" << tmp->next->word << endl;
	//удаление старого значения элемента предложения
	free(tmp->next->word);
	//добавление нового слова в элемент предложения
	TSentenceList *newWord = SentenceCreateNew();
	tmp->next->word = newWord->word;
	cout << "Next word was changed" << endl;
	return true;
}

//функция добавления созданного элемента предложения следующим от рабочего указателя
bool SentenceAddNextElem(TTextDList *text) {
	//проверка предложения на пустоту
	if(text->sentence == nullptr) {
		//добавление первого элемента предложения
		text->sentence = SentenceCreateNew();
		text->tmpSentence = text->sentence;
		cout << "First word was added" << endl;
		return true;
	}
	//добавление нового элемента предложения следующим от рабочего указателя
	TSentenceList *help = text->tmpSentence->next;
	text->tmpSentence->next = SentenceCreateNew();
	text->tmpSentence->next->next = help;
	cout << "Next word was added" << endl;
	return true;
}

//функция вывода предложения
bool PrintSentence(TTextDList *text) {
	//проверка предложения на пустоту
	if(text->sentence == nullptr) {
		cout << "Sentence is empty. You can't print sentence" << endl;
		return false;
	}
	//вывод предложения
	TSentenceList *tmp = text->sentence;
	while(tmp) {
		if(tmp == text->tmpSentence) {
			//вывод рабочего указателя
			cout << " \" " << tmp->word << " \" ";
			tmp = tmp->next;
			continue;
		}
		cout << tmp->word << " ";
		tmp = tmp->next;
	}
	return true;
}

//функция работы с предложением
TSentenceList* SentenceWork(TTextDList *text) {
	bool loop = true;
	bool start = false;
	TSentenceList* takenSentence = nullptr;
	TSentenceList *tmp = nullptr;
	TSentenceList *headSentence = nullptr;

	while(loop) {
		headSentence = text->sentence;
		tmp = text->tmpSentence;
		//выбор необходимой операции над предложением
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
				//вывод взятого элемента предложения
				if(takenSentence != nullptr) {
					cout << "Word that you took is : " << takenSentence->word << endl;
				}
				//очищение предложения
				SentenceToNull(text);
				cout << "Good Bye" << endl;
				exit(0);
			}
			default: cout << "Isn't correct operation" << endl; break;
		}
		//вывод не пустого предложения после каждой операции
		if(text->sentence) {
			cout << "Your Sentence now : " << endl;
			PrintSentence(text);
			cout << endl;
		}
	}
	return SentenceTmp(text);
}

#endif //STRUCTCOURSE_SENTENCE_H