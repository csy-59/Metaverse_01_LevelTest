/*
* �ڵ� ���� ����2: 1000�̸��� 3�� �¼� ����ϱ�
* >> �ݺ����� ��¹��� ���� ����
* >> for�� or while�� or do-while���� ����Ͽ� 3�� �¼��� ����Ѵ�.
*	|�ݺ� Ƚ���� �������ֱ� ������ for���� �����
*/
#include <iostream>
using namespace std;

int main(void)
{
	cout << "##3�� �¼�: ";
	for (int i = 1; i < 1000; i *= 3)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
