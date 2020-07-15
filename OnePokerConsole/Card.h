#pragma once
class Card
{
private:
	char Number;
	char Mark;
public:
	Card()
		: Number(0), Mark(0)
	{}

	Card(char number, char mark)
		: Number(number), Mark(mark)
	{}

	void setNumber(char number) { Number = number; }
	char getNumber() { return Number; }
	void setMark(char mark) { Mark = mark; }
	char getMark() { return Mark; }

	void printCard() {
		char number = Number;

		if (number == 10) {
			printf("%d%c ", number, Mark);
			return;
		}

		if (number < 10) {
			number += '0';
		}

		printf("%c%c ", number, Mark);
	}
};

