#include <iostream>
using namespace std;

int arr[9] = { 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

void sortArray(int* arr, int n)
{
	//���� ��Ʈ�� ���� ������� �̷�����,
	// �� ����� ���� �� �� �� ���Һ��� ���ĵȴ�.

	//������: �迭 ũ�� - 1��ŭ �ݺ�
	//	>> �� ������ ���� ����� �ϴ� ��
	//		| ���簡 �� �������� Ŭ �� ����.
	//		| �̰� size - 1  - i ��ŭ �ݺ�

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			//if���� �ε�ȣ�� �ٲٸ� ���������� �ȴ�.
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