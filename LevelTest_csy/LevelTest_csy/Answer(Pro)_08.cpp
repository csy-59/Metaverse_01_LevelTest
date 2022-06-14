#include <iostream>
#include <vector>
using namespace std;

#define NOT_VISITED 0

int main()
{
	//1. 배열 만들기
	cout << "배열의 크기를 입력하세요 : ";
	int size;
	cin >> size;

	//데이터가 연속적으로 할당 되는 것이 아닌, 정말 단순하게 포인터로 연결이 된 상태이다. >> 파편화 발생
	//*파편화: 메모리 상으로 공간이 뚫리는 것. 공간이 나누어져 있어서 다른 작업을 하기 위해 메모리에 정상적으로 올릴 수 없다.
	//			(ex. 50짜리 공간 2개가 파편화가 되어 있을 때, 그 공간이 충분하더라도 80짜리 프로세스는 올라갈 수 없다.)
	// >> 그래서 가능한 메모리를 연속적으로 할당해야 한다!! >> 즉 그냥 1차원 배열로 할당해라
	/*
	int** arr = new int* [size]; 
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}*/
	int* arr = new int[size * size];
	//메모리 초기화
	memset(arr, 0, sizeof(int) * size * size);

	//2. 달팽이 배열 세팅
	//2-1. 달팽이 데이터 초기화
	int r = 0;
	int c = 0;

	int trail = 1;

	enum Direction // 방향 종류(DIR_MAX 제외)
	{
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		DIR_UP,
		DIR_MAX
	} direction = DIR_RIGHT; //달팽이가 이동하는 방향

	//이동 방향(lookup table)
	static const int deltaR[5] = { 0,1,0,-1 };
	static const int deltaC[5] = { 1,0,-1,0 };

	for (int i = 0; i < size * size; ++i)
	{
		//2-2. 달팽이 움직임.
		arr[r * size + c] = trail;
		++trail;

		//2-3. 다음 칸으로 이동.
		int newR = r + deltaR[(int)direction];
		int newC = c + deltaC[(int)direction];
		//switch (direction)
		//{
		////2-3-1. 오른쪽으로 갈 때 >> c를 하나 증가
		//case DIR_RIGHT:
		//	++c;
		//	break;
		//
		////2-3-2. 밑으로 갈 때 >> r를 하나 증가
		//case DIR_DOWN:
		//	++r;
		//	break;
		//
		////2-3-3. 왼쪽으로 갈 때 >> c를 하나 감소
		//case DIR_LEFT:
		//	--c;
		//	break;
		//
		////2-3-4. 위로 갈 때 >> r를 하나 감소
		//case DIR_UP:
		//	--r;
		//	break;
		//
		//case DIR_MAX:
		//	break;
		//
		//default:
		//	break;
		//}

		//2-4. 이동이 가능한지 판별.
		//2-4-1. 벽에 닿았을 때.
		//2-4-2. 이미 지나온 곳일 때
		if (newR < 0 || newR >= size || newC < 0 || newC >= size || arr[size * newR + newC] != NOT_VISITED)
		{
			//2-5. 이동ㅇ이 불가능하므로 방향 전환을 한다.
			direction = (Direction) ((direction + 1) % DIR_MAX); //형변환

			//2-6. 위치값 다시 계산
			newR = r + deltaR[(int)direction];
			newC = c + deltaC[(int)direction];
		}

		//2-7. 이동
		r = newR;
		c = newC;
	}


	//3. 출력
	for (int r = 0; r < size; ++r)
	{
		for (int c = 0; c < size; ++c)
		{
			cout << arr[size * r + c] << "\t";
		}
		cout << "\n";
	}

	delete[] arr;
}

