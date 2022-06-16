#pragma once
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class Bingo 
{
	static const int BOARD_SIZE = 5;
	static const int BLANK = 0;

public:
	/// <summary>
	/// 빙고판 초기화
	/// </summary>
	void Init()
	{
		srand(time(nullptr));

		bool isUsed[26] = { false };
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				int n = 0;
				do
				{
					n = 1 + rand() % (BOARD_SIZE * BOARD_SIZE);
				} while (isUsed[n]);

				_board[r][c] = n;
				isUsed[n] = true;
			}
		}
	}

	/// <summary>
	/// 빙고판을 출력한다.
	/// </summary>
	void Print() const
	{
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				if (_board[r][c] == BLANK)
				{
					cout << "[ ]\t";
				}
				else
				{
					cout << _board[r][c] << "\t";
				}
			}
			cout << endl;
		}
		cout << "현재 " << _bingoCount << "줄의 빙고가 완성되었습니다.\n";
	}

	/// <summary>
	/// 빙고가 끝났는지 판별한다.
	/// </summary>
	/// <returns></returns>
	bool IsCompleted() const
	{
		if (_bingoCount == BOARD_SIZE * 2 + 2)
		{
			return true;
		}

		return false;
	}

	/// <summary>
	/// 빙고를 업데이트한다.
	/// </summary>
	/// <param name="input">입력값</param>
	void Update(int input)
	{
		//3-1: 오입력 처리
		if (input < 0 || input > BOARD_SIZE* BOARD_SIZE)
		{
			return;
		}

		//4. 빙고판 업데이트 >> 해당 숫자 지워주기(입력 유효)
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			bool isFound = false;
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				if (input == _board[r][c])
				{
					_board[r][c] = BLANK;
					isFound = true;
				}
			}

			if (isFound)
			{
				break;
			}
		}

		//5. 빙고 개수 세기		
		int count = countHorizontalBingo();
		count += countVerticalBingo();
		count += countDiagonalBingo();

		_bingoCount = count;
	}
private:
	/// <summary>
	/// 가로줄 빙고
	/// </summary>
	int countHorizontalBingo() const
	{
		int count = 0;
		// 빙고란?
		//	- 가로의 모든 숫자를 지운 것 => 해당 줄의 모든 요소가 비어 있는지 확인
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				if (_board[r][c] != BLANK)
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

		return count;
	}

	/// <summary>
	/// 세로줄 빙고
	/// </summary>
	int countVerticalBingo() const
	{
		int count = 0;
		//	- 세로의 모든 숫자를 지운 것
		for (int c = 0; c < BOARD_SIZE; ++c)
		{
			bool isBingo = true;
			for (int r = 0; r < BOARD_SIZE; ++r)
			{
				if (_board[r][c] != BLANK)
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

		return count;
	}

	/// <summary>
	/// 대각선 빙고
	/// </summary>
	int countDiagonalBingo() const
	{
		int count = 0;
		//	- 대각선의 모든 숫자를 지운 것
		{
			bool isBingo = true;
			for (int i = 0; i < BOARD_SIZE; i++) // 왼쪽 대각선
			{
				if (_board[i][i] != BLANK)
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
			for (int i = 0; i < BOARD_SIZE; i++) //오른쪽 대각선
			{
				if (_board[BOARD_SIZE - 1 - i][i] != BLANK)
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

		return count;
	}

private:
	int _board[BOARD_SIZE][BOARD_SIZE] = { 0 };
	int _bingoCount = 0;
};