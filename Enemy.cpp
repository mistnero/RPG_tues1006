#include "Enemy.h"

Enemy::Enemy(const EnemyData& sdata)
	:data(sdata), critical(false),avoid(false),move(true)
{

}

int Enemy::Attack()
{
	int rand = GameRandom::GetI().GetR(1, 100);
	if (rand > 90)
	{
		critical = true;
	}

	if (critical)
	{
		const float C = 1.5f;
		critical = false;
		return (int)((float)data.atk * C);
	}
	return data.atk;
}

int Enemy::Damage(int fatk)
{
	int rand = GameRandom::GetI().GetR(1, 100);
	if (rand > 80)
	{
		avoid = true;
	}

	if (avoid)
	{
		avoid = false;
		return data.hp;
	}

	int drand = rand = GameRandom::GetI().GetR(1, data.def);
	if (fatk <= data.def)
	{
		drand = GameRandom::GetI().GetR(1, (int)((float)data.def * 0.8f));
	}
	rand = GameRandom::GetI().GetR(1, 3);

	data.hp -= (fatk - drand) / rand;
	if (data.hp <= 0)
	{
		move = false;
		data.hp = 0;
	}
	return data.hp;
}