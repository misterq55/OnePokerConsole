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
	printf("���� ���θ� �����ϼ���\n");
	printf("1: ���� 2: �İ�\n");
	char c = -1;

	while (c == 1 || c == 2) {
		scanf("%c", &c);
	}

	if (c == 2) {
		return false;
	}

	return true;
}
