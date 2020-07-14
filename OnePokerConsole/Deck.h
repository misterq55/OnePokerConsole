#pragma once
#include <list>
#include <random>
#include <chrono>
#include <iostream>
#include "Card.h"

using std::list;

class Deck
{
private:
	list<Card*> CardList;
	int Count;

public:
	Deck() {
		Count = 0;
	}

	~Deck() {
		for (list<Card*>::iterator iter = CardList.begin();
			iter != CardList.end();)
		{
			Card* card = *iter;

			CardList.erase(iter++);
			delete card;
		}
	}

	void addCard(Card* card) { CardList.push_back(card); Count++; }
	Card* getCard() { 
		Card *card = CardList.front();
		CardList.pop_front();
		Count--;
		return card;
	}

	void shuffle() {
		std::vector<Card*> vec(CardList.begin(), CardList.end());
		std::shuffle(vec.begin(), vec.end(), std::mt19937_64{ std::random_device{}() });

		std::list<Card*> shuffled_card_list{ vec.begin(), vec.end() };
		CardList.swap(shuffled_card_list);
	}

	void Print() {
		for (list<Card*>::iterator iter = CardList.begin();
			iter != CardList.end();
			iter++)
		{
			printf("%c%c\n", (*iter)->getNumber(), (*iter)->getMark());
		}
	}
};