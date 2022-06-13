#include <iostream>
using namespace std;

void Swap(int* a, int* b)
{
	if (a == NULL || b == NULL)
	{
		return;
	}

	int temp = *a;
	*a = *b;
	*b = temp;
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

