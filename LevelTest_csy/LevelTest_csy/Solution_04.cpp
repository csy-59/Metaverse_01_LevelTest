/*
* �ڵ� ���� ����4: �迭�� �� �����ϱ�
* >> ���Ŀ� ���� ����
* >> ���� ������ ����ߴ�.
*	1. �迭�� �� ��ҿ� �� ���� ��Ҹ� ��
*		1-1. Ư�� ��Ұ� �� Ŭ ��� �� ��� �ڸ��� �ٲ�
*	>> ���� �迭 ��Ҹ�ŭ �ݺ�
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
			//�� ��
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
	//������ arr ���
	cout << "array: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//����
	sortArray(arr, 5);

	//���� ������ arr ���
	cout << "array: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}