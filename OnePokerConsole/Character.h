#pragma once
#include <list>
class Card;

using std::list;

class Character
{
private:
	Card* Cards[2];
	char MyCardInfo[2];
	char EnemyCardInfo[2];
	int CardCount;
	int Life;

public:
	Character();
	Character(int life);
	~Character();

	void addCard(Card* card);
	Card *selectCard(int selection);

	int getCardCount();

	void setLife(int life);
	int getLife();

	void setEnemyCardInfo(char enemyCardInfo[2]);
	char* getMyCardInfo();

	bool Play();
};

