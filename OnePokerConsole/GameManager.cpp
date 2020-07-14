#include "GameManager.h"
#include "Deck.h"
#include "Player.h"
#include "Computer.h"

GameManager::GameManager()
{
	GameDeck = new Deck();
	UsedDeck = new Deck();

	First = NULL;
	Second = NULL;

	PlayerInstance = new Player();

	characters[0] = PlayerInstance;
	characters[1] = new Computer();
}

GameManager::~GameManager()
{
	delete GameDeck;
	delete UsedDeck;
}

bool GameManager::Init()
{
	InitDeck();

	for (int i = 0; i < 2; i++) {
		characters[i]->setLife(4);
	}

	return true;
}

bool GameManager::MainLoop()
{
	while (true) {
		if (First == NULL && Second == NULL) {
			// 최초 플레이시 선후공 정하기
			Token = PlayerInstance->setToken();
		}
		
		if (Token == true) {
			First = characters[0];
			Second = characters[1];
		}
		else {
			First = characters[1];
			Second = characters[0];
		}

		// 카드 배분
		while (First->getCardCount() < 2 && Second->getCardCount() < 2) {
			First->addCard(GameDeck->getCard());
			Second->addCard(GameDeck->getCard());
		}

		// 정보 전달하기

		// 플레이
		for (int i = 0; i < 2; i++) {
			characters[i]->Play();
		}

	}

	return true;
}

bool GameManager::ShowInfo()
{

	return true;
}

bool GameManager::InitDeck()
{
	char numberBuffer[13] = { 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' };
	char markBuffer[4] = { 'C', 'D', 'H', 'S' };

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				GameDeck->addCard(new Card(numberBuffer[j], markBuffer[i]));
			}
		}
	}

	GameDeck->shuffle();

	return true;
}
