#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		//��ĭ�� 4 > 3 > 2 > 1 > 0
		for (int j = 0; j < 5 - i; j++)
		{
			cout << " ";
		}

		//���� 1 > 3 > 5 > 7 > 9
		for (int j = 0; j < i * 2 - 1; j++)
		{
			cout << "*";
		}

		//�ٹٲ�
		cout << endl;
	}
}