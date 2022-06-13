#include <iostream>
#include <math.h>
using namespace std;

void BubbleSort(int* arr, int size)
{
	//가장 끝 원소가 각 단계에서 초기화 된다.
	//즉 가장 마지막 원소는 비교하지 않아도 된다.
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void InsertSort(int* arr, int size)
{

}

int main()
{
	srand(time(0));
	int arr[10] = { 0 };
	cout << arr << endl;
	cout << arr[0] << endl;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 - 50;
		cout << arr[i] << " ";
	}
	cout << endl;

	BubbleSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}