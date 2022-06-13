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
	//1. 빙고게임 판을 생성.
	//1-1. 2차원 배열로 데이터를 담는다.
	int board[5][5] = { 0 };
	//1-2. 랜덤하게 수를 배치해야함
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

		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다.\n";
		cout << "숫자를 입력해주세요: ";
		int input;
		cin >> input;

		//올바른 입력일 경우 빙고 진행
		if (input >= 1 && input <= 25)
		{ 
			//지우기
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

			//빙고 판별
			bingoCount = 0;
			//세로
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