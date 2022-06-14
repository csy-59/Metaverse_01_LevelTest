#pragma once
#include <math.h>
class Deck
{
public:
	/*
	bool Move() //덱이 잘 만들어졌다면 true 아니면 false
	{
		int candidate = 0;
		for (int i = 0; i < 7; i++)
		{
			do {
				candidate = rand() % 53;
			} while (isUsedCard[candidate] != false);

			isUsedCard[candidate] = true;
			deck[i] = candidate;
		}
	}
	*/

private:
	int* deck;
};

