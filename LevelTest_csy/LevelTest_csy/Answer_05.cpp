#include <iostream>
#include <math.h>
using namespace std;

/// <summary>
/// 로또 번호를 만든다
/// </summary>
/// <param name="maxValue">최대 번호값</param>
/// <param name="digitCount">생성 숫자 개수</param>
/// <returns>로또 번호들 (동적 할당) </returns>
int* GenerateLottoNumber(int maxValue, int digitCount)
{
	//처리: 로또 생성
	// 1~maxValue 사이의 값 중 중복되지 않게 digitCount만큼 뽑음.
	int* lotto = new int[digitCount];

	//로또 번호 정하기
	//1. [1, maxValue] 사이의 값을 무작위로 뽑는다.(n)
	//2. 생성한 n이 중복인지 확인한다.
	//2-1. n이 중복이면 다시 뽑는다.
	//2-2. n이 중복이 아니면 다음 값을 뽑는다.
	//>>위를 digitCount만큼 반복한다.
	srand(time(nullptr));

	int candidate = 0;
	int lottoPosition = 0;
	while (lottoPosition < digitCount)
	{
		bool isValid = false;
		do {
			isValid = false;
			candidate = rand() % maxValue + 1;

			for (int i = 0; i < lottoPosition; i++)
			{
				if (candidate == lotto[i])
				{
					isValid = true;
					break;
				}
			}
		} while (isValid);

		lotto[lottoPosition] = candidate;
		++lottoPosition;
	}

	return lotto;
}

int main() 
{
	//입력: 최대 번호값과 생성 숫자 개수 입력 받는다.
	cout << "최대값: ";
	int maxValue;
	cin >> maxValue;

	cout << "생성 숫자 개수: ";
	int digitCount;
	cin >> digitCount;

	//처리: 로또 번호 생성
	int* lotto = GenerateLottoNumber(maxValue, digitCount);

	//출력: 로또 번호 출력
	for (int i = 0; i < digitCount; i++)
	{
		cout << lotto[i] << " ";
	}

	//마무리: 동적할당 반환
	delete[] lotto;
}