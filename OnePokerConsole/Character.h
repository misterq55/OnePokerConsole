#pragma once
#include <list>
class Card;

using std::list;

class Character
{
private:
	list<Card*> Cards;
	int CardCount;
	int Life;

public:
	Character();
	Character(int life);
	~Character();

	void addCard(Card* card);
	Card *selectCard();

	void setLife(int life);
	int getLife();

	bool Play();
};

