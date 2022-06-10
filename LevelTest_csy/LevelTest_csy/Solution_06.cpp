/*
* 코드 구현 문제6: 트럼프 카드 배분
* >> rand() 함수와 중복 검사, 출력에 대한 이해
* >> Solution_05에서 했던 방식과 유사하게 작성했다.
*	<달라진 점>
*	| 출력 방식의 차이
*/
#include <iostream>
#include <math.h>
using namespace std;

//난수 생성 코드
int RandomIntInRange(int max, int min)
{
	float normalized = (float)rand() / RAND_MAX;
	int range = max - min + 1;
	int random = min + range * normalized;

	return random;
}

//카드 출력
void PrintCard(int rand)
{
	int sign = rand / 13;
	int num = rand % 13;

	//문양
	switch (sign)
	{
	case 0:
		cout << "♠";
		break;
	case 1:
		cout << "♣";
		break;
	case 2:
		cout << "♥";
		break;
	case 3:
		cout << "◆";
		break;
	case 4:
		cout << "Joker, ";
		return;
	}

	//숫자
	switch (num)
	{
	case 0: 
		cout << "A, ";
		return;
	case 10:
		cout << "J, ";
		return;
	case 11:
		cout << "Q, ";
		return;
	case 12:
		cout << "K, ";
		return;
	default:
		cout << num << ", ";
		return;
	}
}

int main(void)
{
	int max = 53;
	int count = 14;

	//생성한 난수가 이미 나왔는지 확인하는 bool 배열
	bool* isPrinted = new bool[max];

	//배열 초기화
	for (int i = 0; i < max; i++)
	{
		isPrinted[i] = false;
	}

	//난수 생성
	srand(time(NULL));
	for (int i = 0; i < count ; ++i)
	{
		//난수 생성
		int rand = RandomIntInRange(max, 1) - 1;

		if (isPrinted[rand] == false)
		{
			isPrinted[rand] = true;

			//플래이어에 대한 정보 출력
			if (i == 0)
			{
				cout << "Player 1: ";
			}
			else if (i == count / 2)
			{
				cout << "\nPlayer 2: ";
			}

			//형태에 맞게 출력
			PrintCard(rand);
		}
		else
		{
			--i;
		}
	}

	delete[] isPrinted;

	return 0;
}