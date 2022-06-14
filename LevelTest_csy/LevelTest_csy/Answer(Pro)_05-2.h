#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

//���� �Ҵ��� ������ >> �޸𸮸� �������� ������ ���� ������.
// 1. �Ҵ��� �ϰ�, ��9���� �� �� ���� �ִ�. (�޸� ����)
// 2. �̹� ������ �޸𸮿� ���� �� ���� �ߴ�. (���� ���� | Double Free)
//		- �̹� ������ �޸𸮸� ����Ű�� ������ >> ��۸� ������(Dangling Pointer)
// 3. �ʹ� ���� �����ߴ�. (������ ���� | Premature free)
// >> ���� �� nullptr�� ����ϸ� ��� 2���� ���� �� �� �ִ�(nullptr�� �����ص� �ƹ����� �ʴ�. �����Ϳ� ������ ���� �ʴ´�.)

/// <summary>
/// �ִ� ���� ������ ������ Lotto
/// </summary>
template <size_t N>
class LimitLotto
{
	static const int MAX_DIGIT_COUNT = 100;
public:
	//������ / �Ҹ���/ ���� ������ / ���� �Ҵ� ������
	LimitLotto() = default;
	LimitLotto(const LimitLotto& other) = delete;
	LimitLotto& operator=(const LimitLotto& other) = delete;
	~LimitLotto()
	{
		Clear();
	}

	/// <summary>
	/// �����͸� �����
	/// </summary>
	void Clear()
	{
		_digitCount = 0;
	}

	void Make(int maxValue, int digitCount) //�������� ���� �ڽ��� ���� �ζ� ��ȣ�� �ڽ��� �����ؾ���. ���� ��ȯŸ�� void
	{
		if (digitCount < 1)
		{
			digitCount = 1;
		}
		if (digitCount > 100)
		{
			digitCount = 100;
		}

		//Ŭ����: Ư�� ������ �����ϴ� ��.
		digitCount = std::max(1, std::min(digitCount, MAX_DIGIT_COUNT));
		//digitCount�� �ּҰ����� ���� ��: std::min~�κп��� digitCount ����. std::max�� ����� ���� 1�� ����
		//digitCount�� �ִ밪���� Ŭ ��: std::min~�κп��� MAX_DIGIT_COUNT ����. std::max�� ����� MAX_DIGIT_COUNT�� ���´�.
		//digitCount�� �ּҰ��� �ִ밪 ���̿� ���� ��: std::min~�κп��� digitCount ����. std::max�� ����� digitCount�� ���´�.

		//���� �����(������ ���� ����)
		Clear();

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

	void Print() //�ζ� ��ȣ ���. ��ȯ�� �����͵� ����, ���� �����͵� ����.
	{
		for (int i = 0; i < _digitCount; i++)
		{
			std::cout << _lotto[i] << " ";
		}
		std::cout << "\n";
	}

private:
	int _lotto[N];
	int _digitCount = 0;
};

