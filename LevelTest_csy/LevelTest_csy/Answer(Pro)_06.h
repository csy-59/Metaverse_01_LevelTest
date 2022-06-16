#pragma once
#include <cmath>
#include <string>
class Deck
{
	static bool isUsedCard[53]; //������ ������ ����(�ʱ�ȭ ���� ������ 0���� �ڵ����� �ʱ�ȭ ��)
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
	bool Move() //���� �� ��������ٸ� true �ƴϸ� false
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
	
	//���� ī�带 string���� �������ִ� ��
	std::string toString()
	{
		if (unUsedCardCound == 7)
		{
			return "The deck is Enpty.\n";
		}

		std::string result;

		//1. ���� �� ī�带 ���ϴ� ����(���� + ����)�� ��ȯ��Ų��.
		//2. �� ī�带 , �� �Բ� result�� �����Ѵ�.
		// >> ���� 7�� �ݺ��Ѵ�.
		//3. ��ȯ�� result�� ��ȯ�Ѵ�.

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

const std::string Deck::CARD_TYPE[4] = { "��" , "��" ,"��" ,"��" };
const std::string Deck::CARD_NUMBER[13] = { "A", "2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
