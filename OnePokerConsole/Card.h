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
};

