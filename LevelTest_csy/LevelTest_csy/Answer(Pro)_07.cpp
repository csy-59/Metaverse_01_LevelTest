#include <iostream>
using namespace std;

#define BLANK 0

int main()
{
	//1. ���� ���� �ʱ�ȭ
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

	//�����Ϳ� �� �����͸� ����ϴ� ���� ���� ��������

	int bingoCount = 0;
	while (true)
	{
		system("cls");

		//2.������ ���
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
		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�.\n";

		if (bingoCount == 12)
		{
			cout << "������ ��� ���� �ϼ��ϼ̽��ϴ�!\n�����մϴ�!!";
			break;
		}

		//3. ����ڷκ��� �Է� �ޱ�
		cout << "���ڸ� �Է����ּ���: ";
		int input;
		cin >> input;

		//3-1: ���Է� ó��
		if (input < 0 || input > 25)
		{
			continue;
		}

		//4. ������ ������Ʈ >> �ش� ���� �����ֱ�(�Է� ��ȿ)
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

		//5. ���� ���� ����
		int count = 0;
		// �����?
		//	- ������ ��� ���ڸ� ���� �� => �ش� ���� ��� ��Ұ� ��� �ִ��� Ȯ��
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

		//	- ������ ��� ���ڸ� ���� ��
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

		//	- �밢���� ��� ���ڸ� ���� ��
		{
			bool isBingo = true;
			for (int i = 0; i < 5; i++) // ���� �밢��
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
			for (int i = 0; i < 5; i++) //������ �밢��
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

		//6. 2������ �ٽ� �ݺ�
	}
}