/*
* �ڵ� ���� ����6: Ʈ���� ī�� ���
* >> rand() �Լ��� �ߺ� �˻�, ��¿� ���� ����
* >> Solution_05���� �ߴ� ��İ� �����ϰ� �ۼ��ߴ�.
*	<�޶��� ��>
*	| ��� ����� ����
*/
#include <iostream>
#include <math.h>
using namespace std;

//���� ���� �ڵ�
int RandomIntInRange(int max, int min)
{
	float normalized = (float)rand() / RAND_MAX;
	int range = max - min + 1;
	int random = min + range * normalized;

	return random;
}

//ī�� ���
void PrintCard(int rand)
{
	int sign = rand / 13;
	int num = rand % 13;

	//����
	switch (sign)
	{
	case 0:
		cout << "��";
		break;
	case 1:
		cout << "��";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "Joker, ";
		return;
	}

	//����
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

	//������ ������ �̹� ���Դ��� Ȯ���ϴ� bool �迭
	bool* isPrinted = new bool[max];

	//�迭 �ʱ�ȭ
	for (int i = 0; i < max; i++)
	{
		isPrinted[i] = false;
	}

	//���� ����
	srand(time(NULL));
	for (int i = 0; i < count ; ++i)
	{
		//���� ����
		int rand = RandomIntInRange(max, 1) - 1;

		if (isPrinted[rand] == false)
		{
			isPrinted[rand] = true;

			//�÷��̾ ���� ���� ���
			if (i == 0)
			{
				cout << "Player 1: ";
			}
			else if (i == count / 2)
			{
				cout << "\nPlayer 2: ";
			}

			//���¿� �°� ���
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