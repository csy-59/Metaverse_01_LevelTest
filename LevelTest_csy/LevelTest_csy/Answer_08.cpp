#include <iostream>
using namespace std;

/*
int main()
{
	cout << "���� ����: ";
	int n;
	cin >> n;

	int** snailMap = new int* [n];
	for (int i = 0; i < n; i++)
	{
		snailMap[i] = new int[n];
	}

	int x = 0, addX = 0;
	int y = -1, addY = 0;

	int printCount = n;
	int currentPrintCount = 0;
	
	int way = 0;
	int num = 0;
	while (num < n*n)
	{
		if (currentPrintCount <= 0)
		{
			currentPrintCount = printCount;
			
			switch (way % 4)
			{
			case 0: //������
				addX = 0;
				addY = 1;
				--printCount;
				break;
			case 1: //�Ʒ�
				addX = 1;
				addY = 0;
				break;
			case 2: //����
				addX = 0;
				addY = -1;
				--printCount;
				break;
			case 3: //��
				addX = -1;
				addY = 0;
				break;
			}

			++way;
		}

		x += addX;
		y += addY;
		snailMap[x][y] = ++num;
		--currentPrintCount;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << snailMap[i][j] << "\t";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
	{
		delete[] snailMap[i];
	}
	delete[] snailMap;

	return 0;
}
*/

class Snail
{
	static const int BLANK = 0;
	static const int DeltaR[4];
	static const int DeltaC[4];
	static enum Direction {
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		DIR_UP,
		DIR_MAX
	};

public:

	~Snail()
	{
		delete[] arr;
		arr = nullptr;

		n = 0;
	}

	void Make(int N)
	{
		arr = new int[N * N];

		n = N;

		int r = 0, c = 0;
		Direction direction = DIR_RIGHT;

		for (int num = 1; num <= N * N; ++num)
		{
			arr[r * N + c] = num;

			int newR = r + DeltaR[direction];
			int newC = c + DeltaC[direction];

			//�Ǻ�
			if (newR < 0 || newR >= N || newC < 0 || newC >= N || arr[newR * N + newC] == BLANK)
			{
				//���� ��ȯ
				direction = (Direction)((direction + 1) % DIR_MAX);

				newR = r + DeltaR[direction];
				newC = c + DeltaC[direction];
			}

			r = newR;
			c = newC;
		}
	}

	void Print()
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << arr[i * n + j] << "\t";
			}
			cout << "\n";
		}
	}
private:
	int* arr = nullptr;
	int n = 0;
};

const int Snail::DeltaR[4] = { 0, 1, 0, -1 };
const int Snail::DeltaC[4] = { 1, 0, -1, 0 };


int main()
{
	int n;
	cin >> n;

	Snail snail;
	snail.Make(n);

	snail.Print();

	return 0;
}