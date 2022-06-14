#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

/*
* Deck 타입
*  > 모든 덱은 카드가 중복되지 않아야 한다.
*  - Make : 카드 7장 뽑아서 덱을 구성한다. 단, 카드가 충분하지 않은 경우, 만들어지지 못할 수 있다.
*  - ToString: 현재 덱의 카드를 출력한다. 카드가 없는 경우 "The Deck is Empty" 로 반환한다.
*/

class Deck
{
	static bool isCardUsed[53];
	static int leftCardCount;
	static const int MAX_CARD_COUNT = 53;
	static const string CARD_TYPE[5];
	static const string CARD_NUMBER[13];

	std::string ConvertCardToString(int cardIndex)
	{
		if (cardIndex == 52)
		{
			return "Joker";
		}
		else
		{
			return CARD_TYPE[cardIndex / 13] + CARD_NUMBER[cardIndex % 13];
		}
	}

public:
	Deck() = default;
	~Deck() = default;
	Deck(const Deck& other) = delete;
	Deck& operator=(const Deck& other) = delete;

	bool Make()
	{
		if (leftCardCount < 7)
		{
			cards[0] = -1;
			return false;
		}

		if (cards[0] != -1)
		{
			for (int i = 0; i < 7; i++)
			{
				isCardUsed[cards[i] - 1] = false;
			}
		}

		for (int i = 0; i < 7; i++)
		{
			int randNum = 0;
			do {
				randNum = rand() % MAX_CARD_COUNT;
			} while (isCardUsed[randNum]);

			cards[i] = randNum + 1;
			isCardUsed[randNum] = true;
		}

		leftCardCount -= 7;

		return true;
	}
	std::string ToString()
	{
		if (cards[0] == -1)
		{
			return "The Deck is Empty\n";
		}

		std::stringstream ss;

		for (int i = 0; i < 7; i++)
		{
			ss << ConvertCardToString(cards[i] - 1) << ",\t";
		}
		ss << "\n";
		
		return ss.str();
	}

private:
	int cards[7] = { -1 };
};
bool Deck::isCardUsed[53] = { false };
const string Deck::CARD_TYPE[5] = { "♠" , "♣" ,"♥" ,"◆" ,"Joker" };
const string Deck::CARD_NUMBER[13] = { "A", "2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
int Deck::leftCardCount = 53;

/*
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
*/

int main() 
{
	// 총 53정의 카드가 있음 >> 14개를 뽑아야한다.
	// 두 명의 플레이어에게 각각 7장을 배부

	//int deck1[7];
	//int deck2[7];
	//
	//PickCard(deck1);
	//PickCard(deck2);

	//int* deck1 = PickCard();
	//int* deck2 = PickCard();
	//
	//cout << "Player 1: ";
	//PrintDeck(deck1);
	//cout << "\nPlayer 2: ";
	//PrintDeck(deck2);

	Deck deck[7];

	for (int i = 0; i < 7; i++)
	{
		deck[i].Make();
		cout << "Player " << i << ":";
		cout << deck[i].ToString();
	}

	Deck deck1;
	deck1.Make();
	cout << "Player 8:";
	cout << deck1.ToString();

	return 0;
}

