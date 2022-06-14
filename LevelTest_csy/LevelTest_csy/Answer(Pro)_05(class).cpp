#include <iostream>
#include <stdlib.h>
#include <math.h>

//���� �Ҵ��� ������ >> �޸𸮸� �������� ������ ���� ������.
// 1. �Ҵ��� �ϰ�, ��9���� �� �� ���� �ִ�. (�޸� ����)
// 2. �̹� ������ �޸𸮿� ���� �� ���� �ߴ�. (���� ���� | Double Free)
//		- �̹� ������ �޸𸮸� ����Ű�� ������ >> ��۸� ������(Dangling Pointer)
// 3. �ʹ� ���� �����ߴ�. (������ ���� | Premature free)
// >> ���� �� nullptr�� ����ϸ� ��� 2���� ���� �� �� �ִ�(nullptr�� �����ص� �ƹ����� �ʴ�. �����Ϳ� ������ ���� �ʴ´�.)

class LimitedLotto
{
public:
	//������ / �Ҹ���/ ���� ������ / ���� �Ҵ� ������
	LimitedLotto() = default;
	LimitedLotto(const LimitedLotto& other) = delete;
	LimitedLotto& operator=(const LimitedLotto& other) = delete;
	~LimitedLotto()
	{
		Clear();
	}

	/// <summary>
	/// �����͸� �����
	/// </summary>
	void Clear()
	{
		delete[] _lotto; //_lotto�� nullptr�̸�?? >> ��� ����. �׷��� nullptr�� ��ȯ ���ִ� ��.
		_lotto = nullptr;

		_digitCount = 0;
	}

	void Make(int maxValue, int digitCount) //�������� ���� �ڽ��� ���� �ζ� ��ȣ�� �ڽ��� �����ؾ���. ���� ��ȯŸ�� void
	{
		//���� �����(������ ���� ����)
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

	void Print() //�ζ� ��ȣ ���. ��ȯ�� �����͵� ����, ���� �����͵� ����.
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

