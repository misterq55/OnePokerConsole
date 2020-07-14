#pragma once

class Deck;
class Player;
class Character;

class GameManager
{
private:
	Deck* GameDeck;
	Deck* UsedDeck;

	bool Token;

	Character *First;
	Character *Second;

	Player* PlayerInstance;

	Character* characters[2];

public:
	GameManager();
	~GameManager();

	bool Init();
	bool MainLoop();
	bool ShowInfo();

private:
	bool InitDeck();
};

