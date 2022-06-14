#include <iostream>
#include <math.h>
using namespace std;
#define MAP_SIZE 5

template<size_t N>
class BingoMap
{
	static const int BLANK = 0;
public:

	BingoMap() = default;
	~BingoMap() = default;
	BingoMap(const BingoMap& other) = default;
	BingoMap& operator=(const BingoMap& other) = default;

	void CreateMap()
	{
		srand(time(NULL));
		bool isNumUsed[N * N] = { false };
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int randomNum = 0;
				do {
					randomNum = rand() % (N * N);
				} while (isNumUsed[randomNum]);

				board[i][j] = randomNum + 1;
				isNumUsed[randomNum] = true;
			}
		}
	}

	void PrintMap()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != BLANK)
				{
					cout << board[i][j] << "\t";
				}
				else
				{
					cout << "O\t";
				}
			}
			cout << endl;
		}
	}

	bool EraseNum(int input)
	{
		//3-1: ���Է� ó��
		if (input < 0 || input > N * N)
		{
			return false;
		}

		//4. ������ ������Ʈ >> �ش� ���� �����ֱ�(�Է� ��ȿ)
		for (int r = 0; r < N; ++r)
		{
			bool isFound = false;
			for (int c = 0; c < N; ++c)
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

		CountBingo();

		return true;
	}

	void CountBingo()
	{
		int count = 0;
		// �����?
		//	- ������ ��� ���ڸ� ���� �� => �ش� ���� ��� ��Ұ� ��� �ִ��� Ȯ��
		for (int r = 0; r < N; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < N; ++c)
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
		for (int c = 0; c < N; ++c)
		{
			bool isBingo = true;
			for (int r = 0; r < N; ++r)
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
			for (int i = 0; i < N; i++) // ���� �밢��
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
			for (int i = 0; i < N; i++) //������ �밢��
			{
				if (board[N - 1 - i][i] != BLANK)
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
	}

	int GetBingoCount()
	{
		return bingoCount;
	}

private:
	int board[N][N] = { BLANK };
	int bingoCount = 0;
};

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

//���� �� ����
/*
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
*/

//������ ����(Answer(Pro)_07.cpp ����)
#define BLANK 0

int main()
{
	//1. ���� ���� �ʱ�ȭ
	BingoMap<7> bingo;
	bingo.CreateMap();
	
	//srand(time(nullptr));
	//bool isUsed[26] = { false };
	//int board[5][5];
	//for (int r = 0; r < 5; ++r)
	//{
	//	for (int c = 0; c < 5; ++c)
	//	{
	//		int n = 0;
	//		do
	//		{
	//			n = 1 + rand() % 25;
	//		} while (isUsed[n]);
	//
	//		board[r][c] = n;
	//		isUsed[n] = true;
	//	}
	//}

	//�����Ϳ� �� �����͸� ����ϴ� ���� ���� ��������

	//int bingoCount = 0;
	while (true)
	{
		system("cls");

		//2.������ ���
		//for (int r = 0; r < 5; ++r)
		//{
		//	for (int c = 0; c < 5; ++c)
		//	{
		//		if (board[r][c] == BLANK)
		//		{
		//			cout << "[ ]\t";
		//		}
		//		else
		//		{
		//			cout << board[r][c] << "\t";
		//		}
		//	}
		//	cout << endl;
		//}
		bingo.PrintMap();

		cout << "���� " << bingo.GetBingoCount() << "���� ���� �ϼ��Ǿ����ϴ�.\n";

		if (bingo.GetBingoCount() == 12)
		{
			cout << "������ ��� ���� �ϼ��ϼ̽��ϴ�!\n�����մϴ�!!";
			break;
		}

		//3. ����ڷκ��� �Է� �ޱ�
		cout << "���ڸ� �Է����ּ���: ";
		int input;
		cin >> input;

		////3-1: ���Է� ó��
		//if (input < 0 || input > 25)
		//{
		//	continue;
		//}
		//
		////4. ������ ������Ʈ >> �ش� ���� �����ֱ�(�Է� ��ȿ)
		//for (int r = 0; r < 5; ++r)
		//{
		//	bool isFound = false;
		//	for (int c = 0; c < 5; ++c)
		//	{
		//		if (input == board[r][c])
		//		{
		//			board[r][c] = BLANK;
		//			isFound = true;
		//		}
		//	}
		//
		//	if (isFound)
		//	{
		//		break;
		//	}
		//}
		if (bingo.EraseNum(input) == false)
		{
			continue;
		}

		bingo.CountBingo();

		//5. ���� ���� ����
		//int count = 0;
		//// �����?
		////	- ������ ��� ���ڸ� ���� �� => �ش� ���� ��� ��Ұ� ��� �ִ��� Ȯ��
		//for (int r = 0; r < 5; ++r)
		//{
		//	bool isBingo = true;
		//	for (int c = 0; c < 5; ++c)
		//	{
		//		if (board[r][c] != BLANK)
		//		{
		//			isBingo = false;
		//			break;
		//		}
		//	}
		//
		//	if (isBingo)
		//	{
		//		++count;
		//	}
		//}
		//
		////	- ������ ��� ���ڸ� ���� ��
		//for (int c = 0; c < 5; ++c)
		//{
		//	bool isBingo = true;
		//	for (int r = 0; r < 5; ++r)
		//	{
		//		if (board[r][c] != BLANK)
		//		{
		//			isBingo = false;
		//			break;
		//		}
		//	}
		//
		//	if (isBingo)
		//	{
		//		++count;
		//	}
		//}
		//
		////	- �밢���� ��� ���ڸ� ���� ��
		//{
		//	bool isBingo = true;
		//	for (int i = 0; i < 5; i++) // ���� �밢��
		//	{
		//		if (board[i][i] != BLANK)
		//		{
		//			isBingo = false;
		//			break;
		//		}
		//	}
		//
		//	if (isBingo)
		//	{
		//		++count;
		//	}
		//}
		//
		//{
		//	bool isBingo = true;
		//	for (int i = 0; i < 5; i++) //������ �밢��
		//	{
		//		if (board[4 - i][i] != BLANK)
		//		{
		//			isBingo = false;
		//			break;
		//		}
		//	}
		//
		//	if (isBingo)
		//	{
		//		++count;
		//	}
		//}
		//bingoCount = count;

		//6. 2������ �ٽ� �ݺ�
	}
}