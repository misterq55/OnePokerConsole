#include <iostream>
#include "GameManager.h"

using namespace std;

int main() {
	GameManager* motherSophie = new GameManager();

	motherSophie;
	motherSophie->Init();

	delete motherSophie;

	return 0;
}