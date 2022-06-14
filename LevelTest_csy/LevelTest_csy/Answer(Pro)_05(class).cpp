#include <iostream>
#include <stdlib.h>
#include <math.h>

//동적 할당의 문제점 >> 메모리를 수동으로 관리할 때의 문제점.
// 1. 할당은 하고, 해9제를 안 할 수도 있다. (메모리 누수)
// 2. 이미 해제한 메모리에 대해 또 해제 했다. (이중 해제 | Double Free)
//		- 이미 해제한 메모리를 가리키는 포인터 >> 댕글링 포인터(Dangling Pointer)
// 3. 너무 빨리 해제했다. (조숙한 해제 | Premature free)
// >> 해제 후 nullptr를 사용하면 적어도 2번은 방지 할 수 있다(nullptr은 해제해도 아무렇지 않다. 데이터에 영향을 주지 않는다.)

class LimitedLotto
{
public:
	//생성자 / 소멸자/ 복사 생성자 / 복사 할당 연산자
	LimitedLotto() = default;
	LimitedLotto(const LimitedLotto& other) = delete;
	LimitedLotto& operator=(const LimitedLotto& other) = delete;
	~LimitedLotto()
	{
		Clear();
	}

	/// <summary>
	/// 데이터를 지운다
	/// </summary>
	void Clear()
	{
		delete[] _lotto; //_lotto가 nullptr이면?? >> 상관 없음. 그래서 nullptr로 변환 해주는 것.
		_lotto = nullptr;

		_digitCount = 0;
	}

	void Make(int maxValue, int digitCount) //자율성에 따라 자신이 만든 로또 번호는 자신이 관리해야함. 따라서 반환타입 void
	{
		//새로 만들기(기존의 것은 삭제)
		Clear();

		_lotto = new int[digitCount];
		this->_digitCount = digitCount;

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
					if (candidate == _lotto[i])
					{
						isValid = true;
						break;
					}
				}
			} while (isValid);

			_lotto[lottoPosition] = candidate;
			++lottoPosition;
		}

	}

	void Print() //로또 번호 출력. 반환할 데이터도 없고, 받을 데이터도 없다.
	{
		for (int i = 0; i < _digitCount; i++)
		{
			std::cout << _lotto[i] << " ";
		}
		std::cout << "\n";
	}

private:
	int* _lotto = nullptr;
	int _digitCount = 0;
};

