/*
* 코드 구현 문제4: 배열의 값 정렬하기
* >> 정렬에 대한 이해
* >> 버블 정렬을 사용했다.
*/
#include <iostream>
using namespace std;

int arr[5] = { 5, 2, 4, 1, 3 };

void sortArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	//기존의 arr 출력
	cout << "array: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//정렬
	sortArray(arr, 5);

	//정렬 이후의 arr 출력
	cout << "array: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}