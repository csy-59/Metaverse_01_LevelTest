/*
* 코드 구현 문제2: 1000미만의 3의 승수 출력하기
* >> 반복문과 출력문에 대한 이해
* >> for문 or while문 or do-while문을 사용하여 3의 승수를 출력한다.
*	|반복 횟수가 정해져있기 때문에 for문을 사용함
*/
#include <iostream>
using namespace std;

int main(void)
{
	cout << "##3의 승수: ";
	for (int i = 1; i < 1000; i *= 3)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
