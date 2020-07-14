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
	Card* selected = Cards[selection - 1];
	CardCount--;

	return selected;
}

int Character::getCardCount()
{
	return CardCount;
}

void Character::setLife(int life)
{
	life = life;
}

int Character::getLife()
{
	return Life;
}

bool Character::Play()
{
	return false;
}
