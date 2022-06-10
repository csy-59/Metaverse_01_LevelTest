/*
* �ڵ� ���� ����7: ������ ���
* >> ���� ������ ���� ����
* >> �������� ����ϰ�, �Է��� �޾� ó���Ͽ� ������ �����Ѵ�.
*	1. ������ ���
*	2. �Է� �ޱ�
*	3. �Էµ� ���� �����ǿ� ǥ���ϱ�
*	4. �Էµ� ���ڷ� ���� �Ǿ����� Ȯ���ϱ�
*	>> ���� ��� ������ ��� ���� �ɶ����� �ݺ��Ѵ�.
* >> �����ؾ� �ϴ� ����: 
*	|��ü�������� �ڵ� �ٽ� ¥��
*/
#include <iostream>
#include <math.h>
using namespace std;

//���� ���� �ڵ�
int RandomIntInRange(const int max, const int min)
{
	float normalized = (float)rand() / RAND_MAX;
	int range = max - min + 1;
	int random = min + range * normalized;

	return random;
}

//�ߺ� ���� ������ ����� �ִ� �Լ�
void GetBingoMap(int** map, const int mapSize)
{
	//������ ������ �̹� ���Դ��� Ȯ���ϴ� bool �迭(���� �Ҵ�)
	bool* isPrinted = new bool[mapSize * mapSize];

	//�迭 �ʱ�ȭ
	for (int i = 0; i < mapSize * mapSize; i++)
	{
		isPrinted[i] = false;
	}

	//map ����
	srand(time(NULL));
	for (int i = 0; i < mapSize; ++i)
	{
		int j = 0;
		while (j < mapSize) {
			int rand = RandomIntInRange(mapSize * mapSize, 1);

			if (isPrinted[rand - 1] == false)
			{
				isPrinted[rand - 1] = true;
				map[i][j] = rand;
				j++;
			}
		}
	}

	//���� �Ҵ��� �迭 ��ȯ
	delete[] isPrinted;
	isPrinted = nullptr;
}

int main()
{
	int size = 5;

	/*
	//���� ũ�� �Է�
	cout << "�������� ũ�⸦ �Է����ּ���: ";
	cin >> size;
	system("cls");
	*/

	//���� ��(���� �Ҵ�����)
	int** map = new int* [size];
	for (int i = 0; i < size + 1; i++)
	{
		if (i < size) 
		{
			map[i] = new int[size];
		}
	}

	//���� Ȯ����(���� �Ҵ�����): ǥ���� ���ڸ� true, �� ������ ���� ���� �Ǵ��Ѵ�.
	bool** mapCheck = new bool* [size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		mapCheck[i] = new bool [size + 1];
		for (int j = 0; j < size + 1; j++)
		{
			mapCheck[i][j] = false;
		}
	}

	//map �����
	GetBingoMap(map, size);

	//���� ���� ����
	int bingoCount = 0;					//���� ����
	int maxBingoCount = size * 2 + 2;	//�ִ� ���� ����

	int isBingoCross[2] = { false };	//�밢�� ���� üũ

	int inputX = 0;						//�Է��� ������ X��ǥ
	int inputY = 0;						//�Է��� ������ Y��ǥ
	
	//���� ����
	do {
		//##### ���
#pragma region preprint
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				//�̹� üũ�� ���ڶ�� X�� ��� ���
				if (mapCheck[i][j] == false)
				{
					cout << map[i][j] << "\t";
				}
				else
				{
					cout << "X\t";
				}
			}
			cout << endl;
		}
		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�.\n";
		
		//������ ��� ���� �� ���� ���
		if (bingoCount == maxBingoCount)
		{
			cout << "������ ��� ���� �ϼ��ϼ̽��ϴ�.\n�����մϴ�!\n";
			break;
		}
#pragma endregion

		//#####�Է�
#pragma region input
		int input;
		cout << "���ڸ� �Է��� �ּ���: ";
		cin >> input;
		
		//�ùٸ� �Է��� �� �ֵ��� ó��
		while (input > size*size || input < 1)
		{
			cout << "�ùٸ� �Է��� ���ּ���(1~" << size * size << "): ";
			cin >> input;
		}
#pragma endregion

		//#####����
		//���� üũ
#pragma region check
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (map[i][j] == input)
				{
					//�ߺ� �Է� ����
					if (mapCheck[i][j] == false)
					{
						mapCheck[i][j] = true;
						inputX = i;
						inputY = j;
						break;
					}
					else
					{
						//�ߺ� �Է�����, ���� ���� �ʿ� ������ �ǹ�
						inputX = -1;
					}
				}
			}
		}
#pragma endregion
		//���� ���
#pragma region bingo
		if (inputX != -1) //���� ������ �ʿ��ϴٸ�
		{
			//���� ����
			if (mapCheck[inputX][size] == false)
			{
				bool isBingo = true;

				for (int i = 0; i < size; i++)
				{
					//�ش� �ٿ� ǥ�ð� ���� ���� �κ��� �ִ� �� Ȯ��
					if (mapCheck[inputX][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				//������ ���� ������ ������Ų��.
				if (isBingo)
				{
					mapCheck[inputX][size] = true;
					bingoCount++;
				}
			}

			//���� ����
			if (mapCheck[size][inputY] == false)
			{
				bool isBingo = true;

				//�ش� �ٿ� ǥ�ð� ���� ���� �κ��� �ִ� �� Ȯ��
				for (int i = 0; i < size; i++)
				{
					if (mapCheck[i][inputY] == false)
					{
						isBingo = false;
						break;
					}
				}

				//������ ���� ������ ������Ų��.
				if (isBingo)
				{
					mapCheck[size][inputY] = true;
					bingoCount++;
				}
			}

			//�밢�� ����
			if (inputX == inputY) //������ ����
			{
				bool isBingo = true;

				//�ش� �ٿ� ǥ�ð� ���� ���� �κ��� �ִ� �� Ȯ��
				for (int i = 0; i < size; i++)
				{
					if (mapCheck[i][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				//������ ���� ������ ������Ų��.
				if (isBingo)
				{
					isBingoCross[0] = true;
					bingoCount++;
				}
			}
			else if (inputY == (size - 1 - inputX)) //���� ����
			{
				bool isBingo = true;

				//�ش� �ٿ� ǥ�ð� ���� ���� �κ��� �ִ� �� Ȯ��
				for (int i = 0; i < size; i++)
				{
					if (mapCheck[size - 1 - i][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				//������ ���� ������ ������Ų��.
				if (isBingo)
				{
					isBingoCross[1] = true;
					bingoCount++;
				}
			}
		}
#pragma endregion
		
		//ȭ�� �ʱ�ȭ
		system("cls");
	} while (true);

	

	//������ �޸� ��ȯ
	for (int i = 0; i < size+1; i++)
	{
		if (i < size)
		{
			delete[] map[i];
			map[i] = nullptr;
		}

		delete[] mapCheck[i];
		mapCheck[i] = nullptr;
	}
	delete[] map;
	map = nullptr;

	delete[] mapCheck;
	mapCheck = nullptr;

	return 0;
}