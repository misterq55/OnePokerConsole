#include "GameManager.h"
#include "Deck.h"
#include "Player.h"
#include "Computer.h"
#include <conio.h>

GameManager::GameManager()
	: Token(false)
{
	GameDeck = new Deck();
	UsedDeck = new Deck();

	First = NULL;
	Second = NULL;

	PlayerInstance = new Player(1);
	ComputerInstance = new Computer(1);

	Characters[0] = PlayerInstance;
	Characters[1] = ComputerInstance;
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
		for (int i = 0; i < 2; i++) {
			Characters[i]->checkCards();
		}

		// race
		int racePlayer = 1;
		int raceComputer = 1;

		// 정보 전달하기
		Characters[0]->setEnemyCardInfo(Characters[1]->getMyCardInfo());
		Characters[1]->setEnemyCardInfo(Characters[0]->getMyCardInfo());

		// 정보 출력하기
		printf("Player Life = %d\n", PlayerInstance->getLife());
		printf("Computer Life = %d\n", ComputerInstance->getLife());

		printf("\n");

		ComputerInstance->printInfo();
		// ComputerInstance->printCards();

		// 플레이
		Card* card1 = Characters[0]->Play();
		Card* card2 = Characters[1]->Play();

		int result = Battle(card1, card2);

		printf("플레이어 카드\n");
		card1->printCard();
		printf("\n");
		printf("com 카드\n");
		card2->printCard();
		printf("\n");

		switch (result) {
		case -1:
			printf("com의 승리\n");
			Token = false;
			PlayerInstance->setLife(PlayerInstance->getLife() - racePlayer);
			break;

		case 1:
			printf("플레이어의 승리\n");
			ComputerInstance->setLife(ComputerInstance->getLife() - raceComputer);
			Token = true;
			break;

		case 0:
			printf("무승부\n");
			break;
		}

		if (PlayerInstance->getLife() <= 0) {
			printf("Game Over\n");
			break;
		}
		else if (ComputerInstance->getLife() <= 0) {
			printf("Player Wins\n");
			break;
		}

		printf("Press Any Keys...\n");
		_getch();
		system("cls");
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

int GameManager::Battle(Card* card1, Card* card2)
{
	if (card1->getNumber() <= 7) {
		if (card2->getNumber() > 7) {
			return -1;
		}
		else {
			if (card1->getNumber() < card2->getNumber()) {
				return -1;
			}
			else if (card1->getNumber() < card2->getNumber()) {
				return 0;
			}
		}
	}
	else {
		if (card2->getNumber() > 7) {
			char hCh = card1->getNumber();
			char lCh = card2->getNumber();

			if (hCh == 'K') { hCh += 10; }
			if (lCh == 'K') { lCh += 10; }

			if (hCh == 'A') { hCh = 100; }
			if (lCh == 'A') { lCh = 100; }

			if (hCh < lCh) {
				return -1;
			}
			else if (hCh == lCh) {
				return 0;
			}
		}
	}

	return 1;
}
