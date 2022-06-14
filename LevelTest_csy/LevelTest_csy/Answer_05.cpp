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
	int* lotto = GenerateLottoNumber(maxValue, digitCount);

	//���: �ζ� ��ȣ ���
	for (int i = 0; i < digitCount; i++)
	{
		cout << lotto[i] << " ";
	}

	//������: �����Ҵ� ��ȯ
	delete[] lotto;
}