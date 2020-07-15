#pragma once

class Deck;
class Player;
class Computer;
class Character;
class Card;

class GameManager
{
private:
	Deck* GameDeck;
	Deck* UsedDeck;

	bool Token;

	Character *First;
	Character *Second;

	Player* PlayerInstance;
	Computer* ComputerInstance;

	Character* Characters[2];

public:
	GameManager();
	~GameManager();

	bool Init();
	bool MainLoop();
	bool ShowInfo();

private:
	bool InitDeck();
	int Battle(Card* card1, Card* card2);
};

