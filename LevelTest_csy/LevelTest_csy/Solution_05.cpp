/*
* 코드 구현 문제5: 로또 번호 생성기
* >> rand()함수와 랜덤 정수 값 생성에 대한 이해
* >> 다음과 같은 알고리즘을 짜보았다.
*	1. 난수를 생성.
*	2. 생성한 난수가 중복인지 확인한다.
*		2-1. 중복이 아닌 유효한 수라면 출력
*		2-2. 중복이라면 다시 난수를 생성한다.
* >> 개선해야 하는 방향: 
*	| 주어진 최대 번호값보다 생성 숫자가 큰 경우 무한 반복된다.
*	| 해당 경우에 대한 예외 처리 필요
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

int main(void)
{
	int max;
	int count;
	cout << "최대값: ";
	cin >> max;
	cout << "개수: ";
	cin >> count;

	//생성한 난수가 이미 나왔는지 확인하는 bool 배열
	bool* isPrinted = new bool[max];

	//배열 초기화
	for (int i = 0; i < max; i++)
	{
		isPrinted[i] = false;
	}

	//난수 생성
	srand(time(NULL));
	for (int i = 0; i < count; ++i)
	{
		//난수 생성
		int rand = RandomIntInRange(max, 1);

		if (isPrinted[rand - 1] == false)
		{
			isPrinted[rand - 1] = true;
			cout << rand << " ";
		}
		else
		{
			--i;
		}
	}

	delete[] isPrinted;

	return 0;
}