#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	Player(int life);
	~Player();

	bool Play();

	bool setToken();
};

