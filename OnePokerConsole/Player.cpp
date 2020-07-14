#include "Player.h"

Player::Player()
	: Character()
{
}

Player::Player(int life)
	: Character(life)
{
}

Player::~Player()
{
}

Card *Player::Play()
{
	printCards();

	int choice = -1;

	while (choice != 1 && choice != 2) {
		printf("카드를 선택하세요: ");
		scanf_s("%d", &choice);
		scanf_s("%*c", choice);
	}

	Card* card = selectCard(choice - 1);

	return card;
}

bool Player::setToken()
{
	int c = -1;

	while (c != 1 && c != 2) {
		printf("선공 여부를 결정하세요\n");
		printf("1: 선공 2: 후공\n");
		scanf_s("%d", &c);
		scanf_s("%*c", c);

		system("cls");
	}

	if (c == 2) {
		return false;
	}

	return true;
}
