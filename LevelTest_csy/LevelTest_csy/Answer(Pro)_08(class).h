#pragma once

class Snail
{
	static const int NOT_VISITIED = 0;
	enum Direction // ���� ����(DIR_MAX ����)
	{
		DIR_RIGHT,
		DIR_DOWN,
		DIR_LEFT,
		DIR_UP,
		DIR_MAX
	};

public:
	/// <summary>
	/// ������ �迭�� �����.
	/// </summary>
	/// <param name="ground">���ڱ��� ������ �迭</param>
	/// <param name="size">�迭�� ũ��</param>
	void MoveOn(int* ground, int size)
	{
		_trail = 1;
		_r = 0;
		_c = 0;

		for (int i = 0; i < size * size; ++i)
		{
			//2-2. ������ ������.
			ground[_r * size + _c] = _trail;
			++_trail;

			//�̵� ����(lookup table)
			static const int deltaR[5] = { 0,1,0,-1 };
			static const int deltaC[5] = { 1,0,-1,0 };

			//2-3. ���� ĭ���� �̵�.
			int newR = _r + deltaR[(int)_direction];
			int newC = _c + deltaC[(int)_direction];

			//2-4. �̵��� �������� �Ǻ�.
			//2-4-1. ���� ����� ��.
			//2-4-2. �̹� ������ ���� ��
			if (newR < 0 || newR >= size || newC < 0 || newC >= size || ground[size * newR + newC] != NOT_VISITIED)
			{
				//2-5. �̵����� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
				_direction = (Direction)((_direction + 1) % DIR_MAX); //����ȯ

				//2-6. ��ġ�� �ٽ� ���
				newR = _r + deltaR[(int)_direction];
				newC = _c + deltaC[(int)_direction];
			}

			//2-7. �̵�
			_r = newR;
			_c = newC;
		}
	}

private:
	//2-1. ������ ������ �ʱ�ȭ
	int _r = 0;
	int _c = 0;

	int _trail = 1;

	enum Direction _direction = DIR_RIGHT; //�����̰� �̵��ϴ� ����

};