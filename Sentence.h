//
// Created by Aigul on 05.12.2019.
//

#ifndef STRUCTCOURSE_SENTENCE_H
#define STRUCTCOURSE_SENTENCE_H
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
	cin >> answer;
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

bool SentenceIsEmpty(TSentenceList *headSentence) {
	if(headSentence != nullptr) {
		if(headSentence->next == nullptr) {
			cout << "Sentence is empty" << endl;
			return true;
		} else {
			cout << "Sentence is not empty" << endl;
			return true;
		}
	} else {
		cout << "Pointer on this sentence is null" << endl;
		return false;
	}
}

bool SentenceToHead(TSentenceList **headSentence, TSentenceList **tmpSentence) {
	if (!headSentence) {
		tmpSentence = headSentence;
		return true;
	} else {
		cout << "Pointer on this sentence is null" << endl;
		return false;
	}
}

bool SentenceWork(TSentenceList **headSentence) {
	bool loop = true;
	bool start = false;
	TSentenceList* tmpSentence = nullptr;

	while(loop) {
		switch (SentenceChooseOperation()) {
			case 1: {
				start = true;
				break;
			}
//			case 2: SentenceIsStart(start) ? SentenceDeleteList(headSentence,tmp) : 0; break;
			case 3:
				SentenceIsStart(start) ? SentenceIsEmpty(*headSentence) : 0;
				break;
			case 4:
				SentenceIsStart(start) ? SentenceToHead(headSentence, &tmpSentence) : 0;
				break;
//			case 5: SentenceIsStart(start) ? SentenceIsEnd() : 0; break;
//			case 6: SentenceIsStart(start) ? SentenceToNext() : 0; break;
//			case 7: SentenceIsStart(start) ? SentencePrintNext() : 0; break;
//			case 8: SentenceIsStart(start) ? SentenceDeleteNext() : 0; break;
//			case 9: SentenceIsStart(start) ? SentenceTakeNext() : 0; break;
//			case 10: SentenceIsStart(start) ? SentenceChangeNext() : 0; break;
//			case 11: SentenceIsStart(start) ? SentenceAddNextElem() : 0; break;
//			case 12 : SentenceIsStart(start) ? PrintSentence() : 0; break;
//			case 13 : {
				if (SentenceIsStart(start)) {
					loop = false;
					break;
				}
//		}
			default: {
				cout << "Isn't correct operation" << endl; break;
			}
		}
	}
}

#endif //STRUCTCOURSE_SENTENCE_H
