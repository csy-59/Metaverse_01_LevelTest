#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

bool isUsedCard[53] = { false };

/// <summary>
/// 카드를 7장 뽑는다.
/// </summary>
/// <param name="deck"> 플레이어의 덱 </param>
void PickCard(int* deck) //deck is out prameter
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

int* PickCard(void)
{
	int* deck = new int[7];

	PickCard(deck);

	return deck;
}

std::string ConvertCardToString(int cardIndex);

void PrintDeck(int* deck)
{
	for (int i = 0; i < 7; ++i)
	{
		cout << ConvertCardToString(deck[i]) << " ";
	}
}

std::string ConvertCardToString(int cardIndex)
{
	static const string CARD_TYPE[5] = {"♠" , "♣" ,"♥" ,"◆" ,"Joker"};
	static const string CARD_NUMBER[] = { "A", "2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	
	if (cardIndex == 32)
	{
		return "Joker";
	}
	else
	{
		return CARD_TYPE[cardIndex / 13] + CARD_NUMBER[cardIndex % 13];
	}
}

int main() 
{
	// 총 53정의 카드가 있음 >> 14개를 뽑아야한다.
	// 두 명의 플레이어에게 각각 7장을 배부

	//int deck1[7];
	//int deck2[7];
	//
	//PickCard(deck1);
	//PickCard(deck2);

	int* deck1 = PickCard();
	int* deck2 = PickCard();

	cout << "Player 1: ";
	PrintDeck(deck1);
	cout << "\nPlayer 2: ";
	PrintDeck(deck2);


	return 0;
}

