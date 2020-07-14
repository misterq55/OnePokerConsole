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

bool Player::Play()
{
	return true;
}

bool Player::setToken()
{
	printf("선공 여부를 결정하세요\n");
	printf("1: 선공 2: 후공\n");
	char c = -1;

	while (c == 1 || c == 2) {
		scanf("%c", &c);
	}

	if (c == 2) {
		return false;
	}

	return true;
}
