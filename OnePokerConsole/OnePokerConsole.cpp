#include <iostream>
#include "GameManager.h"

using namespace std;

int main() {
	GameManager* motherSophie = new GameManager();

	motherSophie;
	motherSophie->Init();

	motherSophie->MainLoop();

	delete motherSophie;

	return 0;
}