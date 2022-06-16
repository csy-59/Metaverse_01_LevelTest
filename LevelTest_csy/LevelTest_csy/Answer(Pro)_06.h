#pragma once
#include <cmath>
#include <string>
class Deck
{
	static bool isUsedCard[53]; //데이터 영역에 넣음(초기화 하지 않으면 0으로 자동으로 초기화 됨)
	static short unUsedCardCound;

	static const std::string CARD_TYPE[4];
	static const std::string CARD_NUMBER[13];

	std::string CardToString(int cardNumber)
	{
		if (cardNumber == 52)
		{
			return "Joker";
		}

		return CARD_TYPE[cardNumber / 13] + CARD_NUMBER[cardNumber % 13];
	}

public:
	bool Move() //덱이 잘 만들어졌다면 true 아니면 false
	{
		/*int leftCardCount = 0;
		for (int i = 0; i < 53; ++i)
		{
			if (isUsedCard[i] == false)
			{
				++leftCardCount;

				if (leftCardCount > 7)
				{
					break;
				}
			}
		}

		if (leftCardCount < 7)
		{
			return false;
		}*/

		if (unUsedCardCound < 7)
		{
			return false;
		}

		int candidate = 0;
		for (int i = 0; i < 7; i++)
		{
			do {
				candidate = rand() % 53;
			} while (isUsedCard[candidate] != false);

			isUsedCard[candidate] = true;
			deck[i] = candidate;
		}

		unUsedCardCound -= 7;

		return true;
	}
	
	//덱의 카드를 string으로 변경해주는 것
	std::string toString()
	{
		if (unUsedCardCound == 7)
		{
			return "The deck is Enpty.\n";
		}

		std::string result;

		//1. 덱의 각 카드를 원하는 형태(문양 + 숫자)로 변환시킨다.
		//2. 각 카드를 , 와 함께 result에 저장한다.
		// >> 위를 7번 반복한다.
		//3. 변환된 result를 반환한다.

		for (int i = 0; i < 7; i++)
		{
			result += CardToString(deck[i]) + ", ";
		}

		return result + "\n";
	}

private:
	int deck[7];
};

bool Deck::isUsedCard[53] = { false };
short Deck::unUsedCardCound = 53;

const std::string Deck::CARD_TYPE[4] = { "♠" , "♣" ,"♥" ,"◆" };
const std::string Deck::CARD_NUMBER[13] = { "A", "2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
