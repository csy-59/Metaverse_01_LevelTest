#include <iostream>
#include <math.h>
using namespace std;

/// <summary>
/// �ζ� ��ȣ�� �����
/// </summary>
/// <param name="maxValue">�ִ� ��ȣ��</param>
/// <param name="digitCount">���� ���� ����</param>
/// <returns>�ζ� ��ȣ�� (���� �Ҵ�) </returns>
int* GenerateLottoNumber(int maxValue, int digitCount)
{
	//ó��: �ζ� ����
	// 1~maxValue ������ �� �� �ߺ����� �ʰ� digitCount��ŭ ����.
	int* lotto = new int[digitCount];

	//�ζ� ��ȣ ���ϱ�
	//1. [1, maxValue] ������ ���� �������� �̴´�.(n)
	//2. ������ n�� �ߺ����� Ȯ���Ѵ�.
	//2-1. n�� �ߺ��̸� �ٽ� �̴´�.
	//2-2. n�� �ߺ��� �ƴϸ� ���� ���� �̴´�.
	//>>���� digitCount��ŭ �ݺ��Ѵ�.
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
	
	void Make(int maxValue, int digitCount) //�ζ� ��ȣ ����, �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
	{
		if (this->digitCount != 0)
		{
			delete[] this->lotto;
		}

		//ó��: �ζ� ����
		// 1~maxValue ������ �� �� �ߺ����� �ʰ� digitCount��ŭ ����.
		this->lotto = new int[digitCount];

		//�ζ� ��ȣ ���ϱ�
		//1. [1, maxValue] ������ ���� �������� �̴´�.(n)
		//2. ������ n�� �ߺ����� Ȯ���Ѵ�.
		//2-1. n�� �ߺ��̸� �ٽ� �̴´�.
		//2-2. n�� �ߺ��� �ƴϸ� ���� ���� �̴´�.
		//>>���� digitCount��ŭ �ݺ��Ѵ�.
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

	void Print() //�ε� ��ȣ ���, ���� ������ ��ȣ�� ���ٸ� �ƹ��͵� �������� �ʴ´�.
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
	//�Է�: �ִ� ��ȣ���� ���� ���� ���� �Է� �޴´�.
	cout << "�ִ밪: ";
	int maxValue;
	cin >> maxValue;

	cout << "���� ���� ����: ";
	int digitCount;
	cin >> digitCount;

	//ó��: �ζ� ��ȣ ����
	//int* lotto = GenerateLottoNumber(maxValue, digitCount); //������
	// Lotto lotto(maxValue, digitCount);

	//���Ǽ��� ������ ������ ������ ���� �⺻������ ������ ���� ����Ѵ�.
	// Lotto lotto; //�����ڿ����� ������ ������ ����� �Ѵ�.(���� �Ҵ��� ������ �Ͼ ���ɼ��� ����.
	// lotto.MakeNumbers(maxValue, digitCount);

	LimitedLotto lotto;
	lotto.Make(maxValue, digitCount);
	lotto.Print();

}