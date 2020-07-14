#include "Computer.h"

Computer::Computer()
	: Character()
{
}

Computer::Computer(int life)
	: Character(life)
{
}

Computer::~Computer()
{
}

bool Computer::Play()
{
	return true;
}