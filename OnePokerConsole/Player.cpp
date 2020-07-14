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
	char c = -1;

	while (c != '1' && c != '2') {
		printf("���� ���θ� �����ϼ���\n");
		printf("1: ���� 2: �İ�\n");
		scanf_s("%c", &c);
	}

	if (c == 2) {
		return false;
	}

	return true;
}
