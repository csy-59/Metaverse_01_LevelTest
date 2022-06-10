/*
* 코드 구현 문제8: 달팽이 배열
* >> 달팽 달팽
* >> 숫자가 커지는 방향에 따라 다르게 연산한다.
*	1. 방향에 따라 저장 위치를 어떻게 연산해야 하는지 정한다.
*	2. 저장해야하는 개수만큼 저장한다.
*	3. 저장을 해야하는 만큼 했으면 방향을 다시 확인한다.
*	>> 저장하려는 수가 주어진 수*주어진 수 보다 크지 않을 때까지 반복한다.
*/
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cout << "배열의 크기를 입력하세요: ";
	cin >> n;

	//동적 배열 초기화
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	//달팽 달팽
	int x = 0;					//현재 숫자 x위치
	int y = -1;					//현재 숫자 y위치

	int addX = 0;				//x위치의 증감 값
	int	addY = 0;				//y위치의 증감 값

	int printCount = n;			//입력해야 하는 번수
	int currentPrintCount = 0;	//현재 남은 입력 횟수

	int num = 0;				//입력할 숫자

	//숫자 입력 방향
	enum NumWay
	{
		WAY_UP,
		WAY_RIGHT,
		WAY_DOWN,
		WAY_LEFT
	} nextWay = WAY_RIGHT;

	//숫자 채우기
	while (num < n*n)
	{
		//다 출력했다면
		if (currentPrintCount <= 0)
		{
			currentPrintCount = printCount;	//다음 입력 갯수로 초기화

			//숫자 입력 방향에 따른 연산 차이
			switch (nextWay)
			{
			case WAY_UP:	//위쪽으로
				addX = -1;
				addY = 0;
				nextWay = WAY_RIGHT;
				break;
			case WAY_RIGHT:	//오른쪽으로
				addX = 0;
				addY = 1;
				--printCount;
				nextWay = WAY_DOWN;
				break;
			case WAY_DOWN:	//아래로
				addX = 1;
				addY = 0;
				nextWay = WAY_LEFT;
				break;
			case WAY_LEFT:	//왼쪽으로
				addX = 0;
				addY = -1;
				--printCount;
				nextWay = WAY_UP;
				break;
			}
		}

		//숫자 입력
		x += addX;
		y += addY;
		array[x][y] = ++num;
		--currentPrintCount;
	}
	
	//출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	//동적 배열 반환
	for (int i = 0; i < n; i++)
	{
		delete[] array[i];
		array[i] = nullptr;
	}
	delete[] array;
	array = nullptr;

	return 0;
}