#pragma once

class Snail
{
	static const int NOT_VISITIED = 0;
	enum Direction // 방향 종류(DIR_MAX 제외)
	{
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		DIR_UP,
		DIR_MAX
	};

public:
	/// <summary>
	/// 달팽이 배열을 만든다.
	/// </summary>
	/// <param name="ground">발자국을 저장할 배열</param>
	/// <param name="size">배열의 크기</param>
	void MoveOn(int* ground, int size)
	{
		_trail = 1;
		_r = 0;
		_c = 0;

		for (int i = 0; i < size * size; ++i)
		{
			//2-2. 달팽이 움직임.
			ground[_r * size + _c] = _trail;
			++_trail;

			//이동 방향(lookup table)
			static const int deltaR[5] = { 0,1,0,-1 };
			static const int deltaC[5] = { 1,0,-1,0 };

			//2-3. 다음 칸으로 이동.
			int newR = _r + deltaR[(int)_direction];
			int newC = _c + deltaC[(int)_direction];

			//2-4. 이동이 가능한지 판별.
			//2-4-1. 벽에 닿았을 때.
			//2-4-2. 이미 지나온 곳일 때
			if (newR < 0 || newR >= size || newC < 0 || newC >= size || ground[size * newR + newC] != NOT_VISITIED)
			{
				//2-5. 이동ㅇ이 불가능하므로 방향 전환을 한다.
				_direction = (Direction)((_direction + 1) % DIR_MAX); //형변환

				//2-6. 위치값 다시 계산
				newR = _r + deltaR[(int)_direction];
				newC = _c + deltaC[(int)_direction];
			}

			//2-7. 이동
			_r = newR;
			_c = newC;
		}
	}

private:
	//2-1. 달팽이 데이터 초기화
	int _r = 0;
	int _c = 0;

	int _trail = 1;

	enum Direction _direction = DIR_RIGHT; //달팽이가 이동하는 방향

};