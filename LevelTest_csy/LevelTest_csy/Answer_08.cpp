#include <iostream>
using namespace std;

int main()
{
	cout << "´ŞÆØ ´ŞÆØ: ";
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
			case 0: //¿À¸¥ÂÊ
				addX = 0;
				addY = 1;
				--printCount;
				break;
			case 1: //¾Æ·¡
				addX = 1;
				addY = 0;
				break;
			case 2: //¿ŞÂÊ
				addX = 0;
				addY = -1;
				--printCount;
				break;
			case 3: //À§
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