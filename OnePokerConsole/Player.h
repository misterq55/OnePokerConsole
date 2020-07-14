#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	Player(int life);
	~Player();

	virtual Card *Play();

	bool setToken();
};

