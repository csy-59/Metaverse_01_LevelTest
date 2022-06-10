/*
* �ڵ� ���� ����1: �����Ϳ� ���۷����� �̿��Ͽ� Swap �Լ� �����
* >> �������� ����� ����
* >> �����ʹ� *���� ������ �Ͽ� ���� �ٲٰ�,
*	 ���۷����� �׳� ���� �ٲٸ� �ȴ�.
*	 (�������� ������ �����ϱ� ���� ������� ������ �����ϴ�)
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b);
void swap(int& a, int& b);

int main(void)
{
	//�׽�Ʈ �ڵ�
	int a = 10;
	int b = 20;

	swap(&a, &b);
	cout << "Swap using Pointer\t| a = " << a << " b = " << b << "\n";



	a = 10;
	b = 20;

	swap(a, b);
	cout << "Swap using Reference\t| a = " << a << " b = " << b << "\n";
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}