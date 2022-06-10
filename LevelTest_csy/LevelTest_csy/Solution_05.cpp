/*
* �ڵ� ���� ����5: �ζ� ��ȣ ������
* >> rand()�Լ��� ���� ���� �� ������ ���� ����
* >> ������ �����ϰ� �ش� ������ �ߺ��� �ƴϸ� ����Ѵ�.
*	1. ������ ����.
*	2. ������ ������ �ߺ����� Ȯ���Ѵ�.
*		2-1. �ߺ��� �ƴ� ��ȿ�� ����� ���
*		2-2. �ߺ��̶�� �ٽ� ������ �����Ѵ�.
* >> �����ؾ� �ϴ� ����: 
*	| �־��� �ִ� ��ȣ������ ���� ���ڰ� ū ��� ���� �ݺ��ȴ�.
*	| �ش� ��쿡 ���� ���� ó�� �ʿ�
*/
#include <iostream>
#include <math.h>
using namespace std;

//���� ����
int RandomIntInRange(int max, int min)
{
	float normalized = (float)rand() / RAND_MAX;
	int range = max - min + 1;
	int random = min + range * normalized;

	return random;
}

int main(void)
{
	int max;
	int count;
	cout << "�ִ밪: ";
	cin >> max;
	cout << "����: ";
	cin >> count;

	//������ ������ �̹� ���Դ��� Ȯ���ϴ� bool �迭(���� �Ҵ�)
	bool* isPrinted = new bool[max];

	//�迭 �ʱ�ȭ
	for (int i = 0; i < max; i++)
	{
		isPrinted[i] = false;
	}

	//���� ����
	srand(time(NULL));
	int printCount = 0;
	while (printCount < count)
	{
		//���� ����
		int rand = RandomIntInRange(max, 1);
		//�ߺ� ��
		if (isPrinted[rand - 1] == false)
		{
			isPrinted[rand - 1] = true;
			cout << rand << " ";
			++printCount;
		}
	}

	//���� �Ҵ��� �迭 ��ȯ
	delete[] isPrinted;
	isPrinted = nullptr;

	return 0;
}