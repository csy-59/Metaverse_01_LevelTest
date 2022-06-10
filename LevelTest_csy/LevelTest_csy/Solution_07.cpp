/*
* 코드 구현 문제7: 빙고판 출력
* >> _getch() 함수에 대한 이해, 전반적인 게임 프로그래밍에 대한 이해
*/
#include <iostream>
#include <math.h>
using namespace std;

//난수 생성 코드
int RandomIntInRange(const int max, const int min)
{
	float normalized = (float)rand() / RAND_MAX;
	int range = max - min + 1;
	int random = min + range * normalized;

	return random;
}

//중복 없이 난수를 만들어 주는 함수
void GetBingoMap(int** map, const int mapSize)
{
	//생성한 난수가 이미 나왔는지 확인하는 bool 배열
	bool* isPrinted = new bool[mapSize * mapSize];

	//배열 초기화
	for (int i = 0; i < mapSize * mapSize; i++)
	{
		isPrinted[i] = false;
	}

	//map 생성
	srand(time(NULL));
	for (int i = 0; i < mapSize; ++i)
	{
		int j = 0;
		while (j < mapSize) {
			int rand = RandomIntInRange(mapSize * mapSize, 1);

			if (isPrinted[rand - 1] == false)
			{
				isPrinted[rand - 1] = true;
				map[i][j] = rand;
				j++;
			}
		}
	}

	delete[] isPrinted;
}

int main()
{
	int size = 5;

	//빙고 판(동적 할당으로)
	int** map = new int* [size];
	for (int i = 0; i < size + 1; i++)
	{
		if (i < size) 
		{
			map[i] = new int[size];
		}
	}

	//빙고 확인판(동적 할당으로): 표시한 숫자면 true, 각 마지막 줄은  빙고를 판단한다.
	bool** mapCheck = new bool* [size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		mapCheck[i] = new bool [size + 1];
		for (int j = 0; j < size + 1; j++)
		{
			mapCheck[i][j] = false;
		}
	}

	//map 만들기
	GetBingoMap(map, size);

	//게임 관련 변수
	int bingoCount = 0;					//빙고 개수
	int maxBingoCount = size * 2 + 2;	//최대 빙고 개수

	int isBingoCross[2] = { false };	//대각선 빙고 체크

	int inputX = 0;						//입력한 숫자의 X좌표
	int inputY = 0;						//입력한 숫자의 Y좌표
	
	//게임 시작
	do {
		//#####맵과 안내문 출력
#pragma region preprint
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (mapCheck[i][j] == false)
				{
					cout << map[i][j] << "\t";
				}
				else
				{
					cout << "X\t";
				}
			}
			cout << endl;
		}
		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다.\n";
		
		//가능한 모든 빙고를 다 했을 경우
		if (bingoCount == maxBingoCount)
		{
			cout << "가능한 모든 빙고를 완성하셨습니다.\n축하합니다!\n";
			break;
		}
#pragma endregion

		//#####입력
#pragma region input
		int input;
		cout << "숫자를 입력해 주세요: ";
		cin >> input;
		
		//올바른 입력일 수 있도록 처리
		while (input > size*size || input < 1)
		{
			cout << "올바른 입력을 해주세요(1~" << size * size << "): ";
			cin >> input;
		}
#pragma endregion

		//#####숫자 표시
#pragma region check
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (map[i][j] == input)
				{
					//중복 입력 방지
					if (mapCheck[i][j] == false)
					{
						mapCheck[i][j] = true;
						inputX = i;
						inputY = j;
						break;
					}
					else
					{
						//중복 입력으로, 빙고 연산 필요 없음을 의미
						inputX = -1;
					}
				}
			}
		}
#pragma endregion

		//#####빙고 계산
#pragma region bingo
		if (inputX != -1) //빙고 연산이 필요하다면
		{
			//가로 빙고
			if (mapCheck[inputX][size] == false)
			{
				bool isBingo = true;

				for (int i = 0; i < size; i++)
				{
					if (mapCheck[inputX][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				if (isBingo)
				{
					mapCheck[inputX][size] = true;
					bingoCount++;
				}
			}

			//세로 빙고
			if (mapCheck[size][inputY] == false)
			{
				bool isBingo = true;

				for (int i = 0; i < size; i++)
				{
					if (mapCheck[i][inputY] == false)
					{
						isBingo = false;
						break;
					}
				}

				if (isBingo)
				{
					mapCheck[size][inputY] = true;
					bingoCount++;
				}
			}

			//대각선 빙고
			if (inputX == inputY)
			{
				bool isBingo = true;

				for (int i = 0; i < size; i++)
				{
					if (mapCheck[i][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				if (isBingo)
				{
					isBingoCross[0] = true;
					bingoCount++;
				}
			}
			else if (inputY == (size - 1 - inputX))
			{
				bool isBingo = true;

				for (int i = 0; i < size; i++)
				{
					if (mapCheck[size - 1 - i][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				if (isBingo)
				{
					isBingoCross[1] = true;
					bingoCount++;
				}
			}
		}
#pragma endregion
		
		//화면 초기화
		system("cls");
	} while (true);

	

	//빙고판 메모리 반환
	for (int i = 0; i < size+1; i++)
	{
		if (i < size)
		{
			delete[] map[i];
			map[i] = nullptr;
		}

		delete[] mapCheck[i];
		mapCheck[i] = nullptr;
	}
	delete[] map;
	map = nullptr;

	delete[] mapCheck;
	mapCheck = nullptr;

	return 0;
}