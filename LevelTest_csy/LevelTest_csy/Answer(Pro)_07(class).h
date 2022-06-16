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
	/// ������ �ʱ�ȭ
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
	/// �������� ����Ѵ�.
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
		cout << "���� " << _bingoCount << "���� ���� �ϼ��Ǿ����ϴ�.\n";
	}

	/// <summary>
	/// ���� �������� �Ǻ��Ѵ�.
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
	/// ���� ������Ʈ�Ѵ�.
	/// </summary>
	/// <param name="input">�Է°�</param>
	void Update(int input)
	{
		//3-1: ���Է� ó��
		if (input < 0 || input > BOARD_SIZE* BOARD_SIZE)
		{
			return;
		}

		//4. ������ ������Ʈ >> �ش� ���� �����ֱ�(�Է� ��ȿ)
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

		//5. ���� ���� ����		
		int count = countHorizontalBingo();
		count += countVerticalBingo();
		count += countDiagonalBingo();

		_bingoCount = count;
	}
private:
	/// <summary>
	/// ������ ����
	/// </summary>
	int countHorizontalBingo() const
	{
		int count = 0;
		// �����?
		//	- ������ ��� ���ڸ� ���� �� => �ش� ���� ��� ��Ұ� ��� �ִ��� Ȯ��
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
	/// ������ ����
	/// </summary>
	int countVerticalBingo() const
	{
		int count = 0;
		//	- ������ ��� ���ڸ� ���� ��
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
	/// �밢�� ����
	/// </summary>
	int countDiagonalBingo() const
	{
		int count = 0;
		//	- �밢���� ��� ���ڸ� ���� ��
		{
			bool isBingo = true;
			for (int i = 0; i < BOARD_SIZE; i++) // ���� �밢��
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
			for (int i = 0; i < BOARD_SIZE; i++) //������ �밢��
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