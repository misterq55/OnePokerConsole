#include "Computer.h"
#include "Card.h"

template <typename T>
void Swap(T* a, T* b) { T temp = *a; *a = *b; *b = temp; }

Computer::Computer()
	: Character()
{
}

Computer::Computer(int life)
	: Character(life)
{
}

Computer::~Computer()
{
}

Card* Computer::Play()
{
	int choice = 0;

	int highNum = 0;
	int lowNum = 1;

	Card* High = Cards[0];
	Card* Low = Cards[1];
	Card* _2 = NULL;

	if (High->getNumber() <= 7) {
		if (Low->getNumber() > 7) {
			Swap(&High, &Low);
			Swap(&highNum, &lowNum);
		}
		else {
			if (High->getNumber() < Low->getNumber()) {
				Swap(&High, &Low);
				Swap(&highNum, &lowNum);
			}
		}
	}
	else {
		if (Low->getNumber() > 7) {
			char hCh = High->getNumber();
			char lCh = Low->getNumber();

			if (hCh == 'K') { hCh += 10; }
			if (lCh == 'K') { lCh += 10; }

			if (hCh == 'A') { hCh = 100; }
			if (lCh == 'A') { lCh = 100; }

			if (hCh < lCh) {
				Swap(&High, &Low);
				Swap(&highNum, &lowNum);
			}
		}
	}

	if (Low->getNumber() == 2) {
		_2 = Low;
	}

	int myCount = 0;
	int enemyCount = 0;

	for (int i = 0; i < 2; i++) {
		if (MyCardInfo[i] == 'H') {
			myCount++;
		}
		
		if (EnemyCardInfo[i] == 'H') {
			enemyCount++;
		}
	}

	// 카드 선택 로직
	switch (myCount)
	{
	case 2:
		if (enemyCount == 2) {
			choice = highNum;
		}
		else if (enemyCount < 2) {
			choice = lowNum;
		}
		break;

	case 1:
		if (enemyCount == 2) {
			choice = lowNum;
		}
		else if (enemyCount == 1) {
			if (_2 == NULL) {
				choice = highNum;
			}
			else {
				choice = lowNum;
			}
		}
		else {
			choice = lowNum;
		}

		break;

	default:
		if (enemyCount == 2) {
			choice = lowNum;
		}
		else if (enemyCount == 1) {
			choice = highNum;
		}
		else {
			choice = highNum;
		}

		break;
	}

	Card* card = selectCard(choice);

	return card;
}