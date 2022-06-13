#include <iostream>
using namespace std;

int arr[9] = { 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

void sortArray(int* arr, int n)
{
	//버블 소트는 여러 페이즈로 이뤄지며,
	// 각 페이즈가 끝날 시 맨 끝 원소부터 정렬된다.

	//페이즈: 배열 크기 - 1만큼 반복
	//	>> 각 페이즈 마다 해줘야 하는 일
	//		| 현재가 그 다음보다 클 때 스왑.
	//		| 이걸 size - 1  - i 만큼 반복

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			//if문의 부등호를 바꾸면 내림차순이 된다.
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j + 1], arr[j]);
			}
		}
	}
}

int main()
{
	sortArray(arr, 9);

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
}