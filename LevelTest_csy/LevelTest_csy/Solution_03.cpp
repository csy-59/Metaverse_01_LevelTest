/*
* �ڵ� ���� ����3: �Ƕ�̵� �� �����
* >> �ݺ����� ���� ����
* >> ���� for������ Ȱ���Ͽ� �Ƕ�̵� �÷� ���� ����Ѵ�.
*/
#include <iostream>
using namespace std;

int main(void)
{
	for (int i = 1; i <= 5; i++)
	{
		//���� ���
		for (int j = 0; j < 5 - i; j++)
		{
			cout << " ";
		}

		//�� ���
		for (int j = 0; j < i * 2 - 1; j++)
		{
			cout << "*";
		}

		//�� �ٲ�
		cout << endl;
	}
}
