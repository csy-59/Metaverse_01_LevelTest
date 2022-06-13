#include <iostream>
#include <math.h>
using namespace std;


void CreateMap(int(*arr)[5])
{
	bool isNumUsed[25] = { false };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int randomNum = 0;
			do {
				randomNum = rand() % 25;
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
	int board[5][5] = { 0 };
	//1-2. �����ϰ� ���� ��ġ�ؾ���
	CreateMap(board);

	bool isGameOver = false;
	int bingoCount = 0;
	do {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i][j] != 0)
				{
					cout << board[i][j];
				}
				cout << "\t";
			}
			cout << endl;
		}

		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�.\n";
		cout << "���ڸ� �Է����ּ���: ";
		int input;
		cin >> input;

		//�ùٸ� �Է��� ��� ���� ����
		if (input >= 1 && input <= 25)
		{ 
			//�����
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (board[i][j] == input)
					{
						board[i][j] = 0;
					}
				}
			}

			//���� �Ǻ�
			bingoCount = 0;
			//����
			for (int i = 0; i < 5; i++)
			{
				bool isRowBingo = true;
				bool isColumBingo = false;
				for (int j = 0; j < 5; j++)
				{
					if (board[i][j] != 0)
					{
						isRowBingo = false;
					}

					if (board[j][i] != 0)
					{
						isColumBingo = false;
					}
				}

				if (isRowBingo)
				{
					bingoCount++;
				}

				if (isColumBingo)
				{
					bingoCount++;
				}
			}

			bool isLeftBingo = true;
			for (int i = 0; i < 5; i++)
			{
				if (board[i][i] != 0)
				{
					isLeftBingo = false;
					break;
				}
			}

			if (isLeftBingo)
			{
				bingoCount++;
			}

			bool isRightBingo = true;
			for (int i = 0; i < 5; i++)
			{
				if (board[4 - i][i] != 0)
				{
					isRightBingo = false;
					break;
				}
			}

			if (isRightBingo)
			{
				bingoCount++;
			}
		}

		system("cls");
	} while (!isGameOver);
	

	return 0;
}