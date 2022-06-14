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
	//1. 빙고게임 판을 생성.
	//1-1. 2차원 배열로 데이터를 담는다.
	int board[MAP_SIZE][MAP_SIZE] = { 0 };
	//1-2. 랜덤하게 수를 배치해야함
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
			cout << "가능한 모든 빙고를 찾으셨습니다!\n축하합니다!";
			break;
		}

		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다.\n";
		cout << "숫자를 입력해주세요: ";
		int input;
		cin >> input;

		//올바른 입력일 경우 빙고 진행
		if (input >= 1 && input <= (MAP_SIZE * MAP_SIZE))
		{ 
			int inputX = -1, inputY = -1;
			//지우기
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

			//빙고 판별
			if (inputX != -1) //새로 추가된 input이라면 판별
			{
				bool isBingo = true;
				//가로
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

				//세로
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

				//대각선 판별
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