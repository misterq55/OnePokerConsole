#include "Character.h"
#include "Card.h"

Character::Character()
	: Life(0), CardCount(0)
{
}

Character::Character(int life)
	: Life(life), CardCount(0)
{
}

Character::~Character()
{
}

void Character::addCard(Card* card)
{
	Cards.push_back(card);
	CardCount++;
}

Card* Character::selectCard()
{
	return nullptr;
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
