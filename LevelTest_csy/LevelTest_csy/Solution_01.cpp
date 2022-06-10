/*
* 코드 구현 문제1: 포인터와 레퍼런스를 이용하여 Swap 함수 만들기
* >> 간접참조 방식의 차이
* >> 포인터는 *으로 역참조 하여 값을 바꾸고,
*	 레퍼런스는 그냥 값을 바꾸면 된다.
*	 (포인터의 단점을 보완하기 위해 만들었기 때문에 가능하다)
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b);
void swap(int& a, int& b);

int main(void)
{
	//테스트 코드
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