#include <iostream>
#include <vector>
using namespace std;

#define NOT_VISITED 0

int main()
{
	//1. �迭 �����
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	int size;
	cin >> size;

	//�����Ͱ� ���������� �Ҵ� �Ǵ� ���� �ƴ�, ���� �ܼ��ϰ� �����ͷ� ������ �� �����̴�. >> ����ȭ �߻�
	//*����ȭ: �޸� ������ ������ �ո��� ��. ������ �������� �־ �ٸ� �۾��� �ϱ� ���� �޸𸮿� ���������� �ø� �� ����.
	//			(ex. 50¥�� ���� 2���� ����ȭ�� �Ǿ� ���� ��, �� ������ ����ϴ��� 80¥�� ���μ����� �ö� �� ����.)
	// >> �׷��� ������ �޸𸮸� ���������� �Ҵ��ؾ� �Ѵ�!! >> �� �׳� 1���� �迭�� �Ҵ��ض�
	/*
	int** arr = new int* [size]; 
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}*/
	int* arr = new int[size * size];
	//�޸� �ʱ�ȭ
	memset(arr, 0, sizeof(int) * size * size);

	//2. ������ �迭 ����
	//2-1. ������ ������ �ʱ�ȭ
	int r = 0;
	int c = 0;

	int trail = 1;

	enum Direction // ���� ����(DIR_MAX ����)
	{
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		DIR_UP,
		DIR_MAX
	} direction = DIR_RIGHT; //�����̰� �̵��ϴ� ����

	//�̵� ����(lookup table)
	static const int deltaR[5] = { 0,1,0,-1 };
	static const int deltaC[5] = { 1,0,-1,0 };

	for (int i = 0; i < size * size; ++i)
	{
		//2-2. ������ ������.
		arr[r * size + c] = trail;
		++trail;

		//2-3. ���� ĭ���� �̵�.
		int newR = r + deltaR[(int)direction];
		int newC = c + deltaC[(int)direction];
		//switch (direction)
		//{
		////2-3-1. ���������� �� �� >> c�� �ϳ� ����
		//case DIR_RIGHT:
		//	++c;
		//	break;
		//
		////2-3-2. ������ �� �� >> r�� �ϳ� ����
		//case DIR_DOWN:
		//	++r;
		//	break;
		//
		////2-3-3. �������� �� �� >> c�� �ϳ� ����
		//case DIR_LEFT:
		//	--c;
		//	break;
		//
		////2-3-4. ���� �� �� >> r�� �ϳ� ����
		//case DIR_UP:
		//	--r;
		//	break;
		//
		//case DIR_MAX:
		//	break;
		//
		//default:
		//	break;
		//}

		//2-4. �̵��� �������� �Ǻ�.
		//2-4-1. ���� ����� ��.
		//2-4-2. �̹� ������ ���� ��
		if (newR < 0 || newR >= size || newC < 0 || newC >= size || arr[size * newR + newC] != NOT_VISITED)
		{
			//2-5. �̵����� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
			direction = (Direction) ((direction + 1) % DIR_MAX); //����ȯ

			//2-6. ��ġ�� �ٽ� ���
			newR = r + deltaR[(int)direction];
			newC = c + deltaC[(int)direction];
		}

		//2-7. �̵�
		r = newR;
		c = newC;
	}


	//3. ���
	for (int r = 0; r < size; ++r)
	{
		for (int c = 0; c < size; ++c)
		{
			cout << arr[size * r + c] << "\t";
		}
		cout << "\n";
	}

	delete[] arr;
}

