/*
* 코드 구현 문제7: 빙고판 출력
* >> 게임 구현에 대한 이해
* >> 빙고판을 출력하고, 입력을 받아 처리하여 게임을 진행한다.
*	1. 빙고판 출력
*	2. 입력 받기
*	3. 입력된 숫자 빙고판에 표시하기
*	4. 입력된 숫자로 빙고가 되었는지 확인하기
*	>> 위를 모든 가능한 모든 빙고가 될때까지 반복한다.
* >> 개선해야 하는 방향: 
*	|객체지향으로 코드 다시 짜기
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
	//생성한 난수가 이미 나왔는지 확인하는 bool 배열(동적 할당)
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

	//동적 할당한 배열 반환
	delete[] isPrinted;
	isPrinted = nullptr;
}

int main()
{
	int size = 5;

	/*
	//빙고 크기 입력
	cout << "빙고판의 크기를 입력해주세요: ";
	cin >> size;
	system("cls");
	*/

	//빙고 판(동적 할당으로)
	int** map = new int* [size];
	for (int i = 0; i < size + 1; i++)
	{
		if (i < size) 
		{
			map[i] = new int[size];
		}
	}

	//빙고 확인판(동적 할당으로): 표시한 숫자면 true, 각 마지막 줄은 빙고를 판단한다.
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
		//##### 출력
#pragma region preprint
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				//이미 체크한 숫자라면 X를 대신 출력
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

		//#####연산
		//숫자 체크
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
		//빙고 계산
#pragma region bingo
		if (inputX != -1) //빙고 연산이 필요하다면
		{
			//가로 빙고
			if (mapCheck[inputX][size] == false)
			{
				bool isBingo = true;

				for (int i = 0; i < size; i++)
				{
					//해당 줄에 표시가 되지 않은 부분이 있는 지 확인
					if (mapCheck[inputX][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				//빙고라면 빙고 개수를 증가시킨다.
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

				//해당 줄에 표시가 되지 않은 부분이 있는 지 확인
				for (int i = 0; i < size; i++)
				{
					if (mapCheck[i][inputY] == false)
					{
						isBingo = false;
						break;
					}
				}

				//빙고라면 빙고 개수를 증가시킨다.
				if (isBingo)
				{
					mapCheck[size][inputY] = true;
					bingoCount++;
				}
			}

			//대각선 빙고
			if (inputX == inputY) //오른쪽 빙고
			{
				bool isBingo = true;

				//해당 줄에 표시가 되지 않은 부분이 있는 지 확인
				for (int i = 0; i < size; i++)
				{
					if (mapCheck[i][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				//빙고라면 빙고 개수를 증가시킨다.
				if (isBingo)
				{
					isBingoCross[0] = true;
					bingoCount++;
				}
			}
			else if (inputY == (size - 1 - inputX)) //왼쪽 빙고
			{
				bool isBingo = true;

				//해당 줄에 표시가 되지 않은 부분이 있는 지 확인
				for (int i = 0; i < size; i++)
				{
					if (mapCheck[size - 1 - i][i] == false)
					{
						isBingo = false;
						break;
					}
				}

				//빙고라면 빙고 개수를 증가시킨다.
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