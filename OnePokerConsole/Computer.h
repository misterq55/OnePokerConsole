#pragma once
#include "Character.h"

class Computer : public Character
{
public:
	Computer();
	Computer(int life);
	~Computer();

	virtual Card *Play();
};

