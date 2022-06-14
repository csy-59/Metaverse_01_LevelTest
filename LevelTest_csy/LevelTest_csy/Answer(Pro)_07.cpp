#include <iostream>
using namespace std;

#define BLANK 0

int main()
{
	//1. 빙고 판을 초기화
	srand(time(nullptr));
	bool isUsed[26] = { false };
	int board[5][5];
	for (int r = 0; r < 5; ++r)
	{
		for (int c = 0; c < 5; ++c)
		{
			int n = 0;
			do
			{
				n = 1 + rand() % 25;
			} while (isUsed[n]);

			board[r][c] = n;
			isUsed[n] = true;
		}
	}

	//데이터와 그 데이터를 출력하는 것을 따로 생각하자

	int bingoCount = 0;
	while (true)
	{
		system("cls");

		//2.빙고판 출력
		for (int r = 0; r < 5; ++r)
		{
			for (int c = 0; c < 5; ++c)
			{
				if (board[r][c] == BLANK)
				{
					cout << "[ ]\t";
				}
				else
				{
					cout << board[r][c] << "\t";
				}
			}
			cout << endl;
		}
		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다.\n";

		if (bingoCount == 12)
		{
			cout << "가능한 모든 빙고를 완성하셨습니다!\n축하합니다!!";
			break;
		}

		//3. 사용자로부터 입력 받기
		cout << "숫자를 입력해주세요: ";
		int input;
		cin >> input;

		//3-1: 오입력 처리
		if (input < 0 || input > 25)
		{
			continue;
		}

		//4. 빙고판 업데이트 >> 해당 숫자 지워주기(입력 유효)
		for (int r = 0; r < 5; ++r)
		{
			bool isFound = false;
			for (int c = 0; c < 5; ++c)
			{
				if (input == board[r][c])
				{
					board[r][c] = BLANK;
					isFound = true;
				}
			}

			if (isFound)
			{
				break;
			}
		}

		//5. 빙고 개수 세기
		int count = 0;
		// 빙고란?
		//	- 가로의 모든 숫자를 지운 것 => 해당 줄의 모든 요소가 비어 있는지 확인
		for (int r = 0; r < 5; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; ++c)
			{
				if (board[r][c] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}

		//	- 세로의 모든 숫자를 지운 것
		for (int c = 0; c < 5; ++c)
		{
			bool isBingo = true;
			for (int r = 0; r < 5; ++r)
			{
				if (board[r][c] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}

		//	- 대각선의 모든 숫자를 지운 것
		{
			bool isBingo = true;
			for (int i = 0; i < 5; i++) // 왼쪽 대각선
			{
				if (board[i][i] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}

		{
			bool isBingo = true;
			for (int i = 0; i < 5; i++) //오른쪽 대각선
			{
				if (board[4 - i][i] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}
		bingoCount = count;

		//6. 2번부터 다시 반복
	}
}