#include "Character.h"
#include "Card.h"

Character::Character()
	: Life(0), CardCount(0)
{
	memset(Cards, 0, sizeof(Cards));
}

Character::Character(int life)
	: Life(life), CardCount(0)
{
	memset(Cards, 0, sizeof(Cards));
}

Character::~Character()
{
}

void Character::addCard(Card* card)
{
	for (int i = 0; i < 2; i++) {
		if (Cards[i] == NULL) {
			Cards[i] = card;

			CardCount++;
			break;
		}
	}
}

Card* Character::selectCard(int selection)
{
	Card* selected = Cards[selection];
	Cards[selection] = NULL;

	CardCount--;

	return selected;
}

int Character::getCardCount()
{
	return CardCount;
}

void Character::setLife(int life)
{
	Life = life;
}

int Character::getLife()
{
	return Life;
}

void Character::setEnemyCardInfo(char enemyCardInfo[2])
{
	for (int i = 0; i < 2; i++) {
		EnemyCardInfo[i] = enemyCardInfo[i];
	}
}

char* Character::getMyCardInfo()
{
	return MyCardInfo;
}

void Character::printInfo()
{
	printf("%c%c\n", MyCardInfo[0], MyCardInfo[1]);
}

void Character::printCards()
{
	printf("----------------------------------------\n");
	printf("소유 카드\n");
	for (int i = 0; i < 2; i++) {
		Cards[i]->printCard();
	}
	printf("\n");
	printf("----------------------------------------\n");
}

void Character::checkCards()
{
	for (int i = 0; i < 2; i++) {

		if (Cards[i]->getNumber() <= 7) {
			MyCardInfo[i] = 'L';
		}
		else {
			MyCardInfo[i] = 'H';
		}
	}
}

Card* Character::Play()
{
	return NULL;
}
