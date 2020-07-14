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

	Characters[0] = PlayerInstance;
	Characters[1] = new Computer();
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
		Characters[i]->setLife(4);
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
			First = Characters[0];
			Second = Characters[1];
		}
		else {
			First = Characters[1];
			Second = Characters[0];
		}

		// 카드 배분
		while (First->getCardCount() < 2 && Second->getCardCount() < 2) {
			First->addCard(GameDeck->getCard());
			Second->addCard(GameDeck->getCard());
		}

		// 카드 판정

		// 정보 전달하기
		Characters[0]->setEnemyCardInfo(Characters[1]->getMyCardInfo());
		Characters[1]->setEnemyCardInfo(Characters[0]->getMyCardInfo());

		// 정보 출력하기


		// 플레이
		for (int i = 0; i < 2; i++) {
			Characters[i]->Play();
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
