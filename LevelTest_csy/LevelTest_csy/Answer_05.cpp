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

class LimitedLotto
{
public:
	LimitedLotto() = default;
	
	void Make(int maxValue, int digitCount) //로또 번호 생성, 이미 생성된 번호가 있다면 지우고 새로 만든다.
	{
		if (this->digitCount != 0)
		{
			delete[] this->lotto;
		}

		//처리: 로또 생성
		// 1~maxValue 사이의 값 중 중복되지 않게 digitCount만큼 뽑음.
		this->lotto = new int[digitCount];

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

		this->maxValue = maxValue;
		this->digitCount = digitCount;
	}

	void Print() //로도 번호 출력, 만약 생성된 번호가 없다면 아무것도 생성하지 않는다.
	{
		if (digitCount == 0)
		{
			return;
		}

		for (int i = 0; i < digitCount; i++)
		{
			cout << lotto[i] << " ";
		}
	}

	~LimitedLotto()
	{
		delete[] lotto;
		lotto = nullptr;
		maxValue = 0;
		digitCount = 0;
	}

private:
	int* lotto = nullptr;
	int maxValue = 0;
	int digitCount = 0;
};

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
	//int* lotto = GenerateLottoNumber(maxValue, digitCount); //생성자
	// Lotto lotto(maxValue, digitCount);

	//강건성과 유연성 때문에 다음과 같이 기본생성자 버전을 많이 사용한다.
	// Lotto lotto; //생성자에서는 가능한 오류가 없어야 한다.(동적 할당은 오류가 일어날 가능성이 많다.
	// lotto.MakeNumbers(maxValue, digitCount);

	LimitedLotto lotto;
	lotto.Make(maxValue, digitCount);
	lotto.Print();

}