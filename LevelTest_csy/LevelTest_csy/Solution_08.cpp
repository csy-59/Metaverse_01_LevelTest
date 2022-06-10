/*
* �ڵ� ���� ����8: ������ �迭
* >> ���� ����
* >> ���ڰ� Ŀ���� ���⿡ ���� �ٸ��� �����Ѵ�.
*	1. ���⿡ ���� ���� ��ġ�� ��� �����ؾ� �ϴ��� ���Ѵ�.
*	2. �����ؾ��ϴ� ������ŭ �����Ѵ�.
*	3. ������ �ؾ��ϴ� ��ŭ ������ ������ �ٽ� Ȯ���Ѵ�.
*	>> �����Ϸ��� ���� �־��� ��*�־��� �� ���� ũ�� ���� ������ �ݺ��Ѵ�.
*/
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cout << "�迭�� ũ�⸦ �Է��ϼ���: ";
	cin >> n;

	//���� �迭 �ʱ�ȭ
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	//���� ����
	int x = 0;					//���� ���� x��ġ
	int y = -1;					//���� ���� y��ġ

	int addX = 0;				//x��ġ�� ���� ��
	int	addY = 0;				//y��ġ�� ���� ��

	int printCount = n;			//�Է��ؾ� �ϴ� ����
	int currentPrintCount = 0;	//���� ���� �Է� Ƚ��

	int num = 0;				//�Է��� ����

	//���� �Է� ����
	enum NumWay
	{
		WAY_UP,
		WAY_RIGHT,
		WAY_DOWN,
		WAY_LEFT
	} nextWay = WAY_RIGHT;

	//���� ä���
	while (num < n*n)
	{
		//�� ����ߴٸ�
		if (currentPrintCount <= 0)
		{
			currentPrintCount = printCount;	//���� �Է� ������ �ʱ�ȭ

			//���� �Է� ���⿡ ���� ���� ����
			switch (nextWay)
			{
			case WAY_UP:	//��������
				addX = -1;
				addY = 0;
				nextWay = WAY_RIGHT;
				break;
			case WAY_RIGHT:	//����������
				addX = 0;
				addY = 1;
				--printCount;
				nextWay = WAY_DOWN;
				break;
			case WAY_DOWN:	//�Ʒ���
				addX = 1;
				addY = 0;
				nextWay = WAY_LEFT;
				break;
			case WAY_LEFT:	//��������
				addX = 0;
				addY = -1;
				--printCount;
				nextWay = WAY_UP;
				break;
			}
		}

		//���� �Է�
		x += addX;
		y += addY;
		array[x][y] = ++num;
		--currentPrintCount;
	}
	
	//���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	//���� �迭 ��ȯ
	for (int i = 0; i < n; i++)
	{
		delete[] array[i];
		array[i] = nullptr;
	}
	delete[] array;
	array = nullptr;

	return 0;
}