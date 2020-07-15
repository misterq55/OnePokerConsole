#pragma once
#include <list>
class Card;

using std::list;

class Character
{
protected:
	Card* Cards[2];
	char MyCardInfo[2];
	char EnemyCardInfo[2];
	int CardCount;
	int Life;

public:
	Character();
	Character(int life);
	~Character();

	virtual void addCard(Card* card);
	virtual Card *selectCard(int selection);

	virtual int getCardCount();

	virtual void setLife(int life);
	virtual int getLife();

	virtual void setEnemyCardInfo(char enemyCardInfo[2]);
	virtual char* getMyCardInfo();

	virtual void printInfo();
	virtual void printCards();

	virtual void checkCards();

	virtual Card *Play();
};

