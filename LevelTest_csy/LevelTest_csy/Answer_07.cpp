#include <iostream>
#include <math.h>
using namespace std;
#define MAP_SIZE 5

void CreateMap(int(*arr)[MAP_SIZE])
{
	srand(time(NULL));
	bool isNumUsed[MAP_SIZE * MAP_SIZE] = { false };
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			int randomNum = 0;
			do {
				randomNum = rand() % (MAP_SIZE * MAP_SIZE);
			} while (isNumUsed[randomNum]);

			arr[i][j] = randomNum + 1;
			isNumUsed[randomNum] = true;
		}
	}
}

int main()
{
	//1. ������� ���� ����.
	//1-1. 2���� �迭�� �����͸� ��´�.
	int board[MAP_SIZE][MAP_SIZE] = { 0 };
	//1-2. �����ϰ� ���� ��ġ�ؾ���
	CreateMap(board);

	bool isGameOver = false;
	int bingoCount = 0;
	do {
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < MAP_SIZE; j++)
			{
				if (board[i][j] != 0)
				{
					cout << board[i][j];
				}
				else
				{
					cout << "[ ]";
				}
				cout << "\t";
			}
			cout << "\n\n";
		}

		if (bingoCount == MAP_SIZE * 2 + 2)
		{
			cout << "������ ��� ���� ã���̽��ϴ�!\n�����մϴ�!";
			break;
		}

		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�.\n";
		cout << "���ڸ� �Է����ּ���: ";
		int input;
		cin >> input;

		//�ùٸ� �Է��� ��� ���� ����
		if (input >= 1 && input <= (MAP_SIZE * MAP_SIZE))
		{ 
			int inputX = -1, inputY = -1;
			//�����
			for (int i = 0; i < MAP_SIZE; i++)
			{
				for (int j = 0; j < MAP_SIZE; j++)
				{
					if (board[i][j] == input)
					{
						board[i][j] = 0;
						inputX = i;
						inputY = j;
					}  
				}
				
				if (inputX != -1)
				{
					break;
				}
			}

			//���� �Ǻ�
			if (inputX != -1) //���� �߰��� input�̶�� �Ǻ�
			{
				bool isBingo = true;
				//����
				for (int i = 0; i < MAP_SIZE; i++)
				{
					if (board[inputX][i] != 0)
					{
						isBingo = false;
						break;
					}
				}

				if (isBingo)
				{
					bingoCount++;
				}

				//����
				isBingo = true;
				for (int i = 0; i < MAP_SIZE; i++)
				{
					if (board[i][inputY] != 0)
					{
						isBingo = false;
						break;
					}
				}

				if (isBingo)
				{
					bingoCount++;
				}

				//�밢�� �Ǻ�
				if (inputX == inputY)
				{
					isBingo = true;
					for (int i = 0; i < MAP_SIZE; i++)
					{
						if (board[i][i] != 0)
						{
							isBingo = false;
							break;
						}
					}

					if (isBingo)
					{
						bingoCount++;
					}
				}

				if (MAP_SIZE - 1 - inputX == inputY)
				{
					isBingo = true;
					for (int i = 0; i < MAP_SIZE; i++)
					{
						if (board[MAP_SIZE - 1 - i][i] != 0)
						{
							isBingo = false;
							break;
						}
					}

					if (isBingo)
					{
						++bingoCount;
					}
				}
			}
		}

		::system("cls");
	} while (!isGameOver);
	

	return 0;
}