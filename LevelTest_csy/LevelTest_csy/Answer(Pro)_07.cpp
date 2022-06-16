#include <iostream>
#include "Answer(Pro)_07(class).h"
using namespace std;

#define BLANK 0

int main()
{
	//1. 빙고 판을 초기화
	Bingo bingo;
	bingo.Init();

	//데이터와 그 데이터를 출력하는 것을 따로 생각하자

	while (true)
	{
		system("cls");

		//2.빙고판 출력
		bingo.Print();

		if (bingo.IsCompleted())
		{
			cout << "가능한 모든 빙고를 완성하셨습니다!\n축하합니다!!";
			break;
		}

		//3. 사용자로부터 입력 받기
		cout << "숫자를 입력해주세요: ";
		int input;
		cin >> input;

		//여기에 빙고 카운드 세는 것도 있음::사용자 입장 실수하기 쉽기 때문에~!(빙고 세는 함수를 꼭 호출해야 하는데, 그걸 안할 수도 있음)
		bingo.Update(input);

		//6. 2번부터 다시 반복
	}
}