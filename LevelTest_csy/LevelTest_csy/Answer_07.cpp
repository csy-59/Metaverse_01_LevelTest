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
		//3-1: 오입력 처리
		if (input < 0 || input > N * N)
		{
			return false;
		}

		//4. 빙고판 업데이트 >> 해당 숫자 지워주기(입력 유효)
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
		// 빙고란?
		//	- 가로의 모든 숫자를 지운 것 => 해당 줄의 모든 요소가 비어 있는지 확인
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

		//	- 세로의 모든 숫자를 지운 것
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

		//	- 대각선의 모든 숫자를 지운 것
		{
			bool isBingo = true;
			for (int i = 0; i < N; i++) // 왼쪽 대각선
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
			for (int i = 0; i < N; i++) //오른쪽 대각선
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

//내가 한 버전
/*
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
*/

//교수님 버전(Answer(Pro)_07.cpp 참고)
#define BLANK 0

int main()
{
	//1. 빙고 판을 초기화
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

	//데이터와 그 데이터를 출력하는 것을 따로 생각하자

	//int bingoCount = 0;
	while (true)
	{
		system("cls");

		//2.빙고판 출력
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

		cout << "현재 " << bingo.GetBingoCount() << "줄의 빙고가 완성되었습니다.\n";

		if (bingo.GetBingoCount() == 12)
		{
			cout << "가능한 모든 빙고를 완성하셨습니다!\n축하합니다!!";
			break;
		}

		//3. 사용자로부터 입력 받기
		cout << "숫자를 입력해주세요: ";
		int input;
		cin >> input;

		////3-1: 오입력 처리
		//if (input < 0 || input > 25)
		//{
		//	continue;
		//}
		//
		////4. 빙고판 업데이트 >> 해당 숫자 지워주기(입력 유효)
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

		//5. 빙고 개수 세기
		//int count = 0;
		//// 빙고란?
		////	- 가로의 모든 숫자를 지운 것 => 해당 줄의 모든 요소가 비어 있는지 확인
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
		////	- 세로의 모든 숫자를 지운 것
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
		////	- 대각선의 모든 숫자를 지운 것
		//{
		//	bool isBingo = true;
		//	for (int i = 0; i < 5; i++) // 왼쪽 대각선
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
		//	for (int i = 0; i < 5; i++) //오른쪽 대각선
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

		//6. 2번부터 다시 반복
	}
}