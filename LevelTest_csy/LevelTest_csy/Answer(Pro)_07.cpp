#include <iostream>
#include "Answer(Pro)_07(class).h"
using namespace std;

#define BLANK 0

int main()
{
	//1. ���� ���� �ʱ�ȭ
	Bingo bingo;
	bingo.Init();

	//�����Ϳ� �� �����͸� ����ϴ� ���� ���� ��������

	while (true)
	{
		system("cls");

		//2.������ ���
		bingo.Print();

		if (bingo.IsCompleted())
		{
			cout << "������ ��� ���� �ϼ��ϼ̽��ϴ�!\n�����մϴ�!!";
			break;
		}

		//3. ����ڷκ��� �Է� �ޱ�
		cout << "���ڸ� �Է����ּ���: ";
		int input;
		cin >> input;

		//���⿡ ���� ī��� ���� �͵� ����::����� ���� �Ǽ��ϱ� ���� ������~!(���� ���� �Լ��� �� ȣ���ؾ� �ϴµ�, �װ� ���� ���� ����)
		bingo.Update(input);

		//6. 2������ �ٽ� �ݺ�
	}
}