/*
* 코드 구현 문제3: 피라미드 꼴 별찍기
* >> 반복문에 대한 이해
* >> 이중 for문으로 활용하여 피라미드 꼴로 별을 출력한다.
*/
#include <iostream>
using namespace std;

int main(void)
{
	for (int i = 1; i <= 5; i++)
	{
		//공백 찍기
		for (int j = 0; j < 5 - i; j++)
		{
			cout << " ";
		}

		//별 찍기
		for (int j = 0; j < i * 2 - 1; j++)
		{
			cout << "*";
		}

		//줄 바꿈
		cout << endl;
	}
}
