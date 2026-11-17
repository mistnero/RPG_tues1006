#include "Enemy.h"

Enemy::Enemy(const EnemyData& sdata)
	:data(sdata), critical(false),avoid(false),move(true)
{

}

int Enemy::Attack()
{
	int rand = GameRandom::GetI().GetR(1, 100);
	std::cout << data.name << "の攻撃！" << std::endl;
	if (rand > 90)
	{
		critical = true;
	}

	if (critical)
	{
		std::cout << "クリティカルヒットした！" << std::endl;
		const float C = 1.5f;
		critical = false;
		return (int)((float)data.atk * C);
	}
	return data.atk;
}

int Enemy::Damage(int patk, int pspd)
{
	int rand = GameRandom::GetI().GetR(1, 100);
	if (rand > 90)
	{
		avoid = true;
	}
	else if (pspd < data.spd)
	{
		if (rand > 75)
		{
			avoid = true;
		}
	}

	if (avoid)
	{
		std::cout << data.name << "は攻撃を回避した！" << std::endl;
		avoid = false;
		return data.hp;
	}

	int drand = rand = GameRandom::GetI().GetR(1, data.def);
	if (patk <= data.def)
	{
		drand = GameRandom::GetI().GetR(1, (int)((float)data.def * 0.8f));
	}
	rand = GameRandom::GetI().GetR(1, 3);
	std::cout << data.name << "に" << (patk - drand) / rand << "のダメージ！" << std::endl;
	data.hp -= (patk - drand) / rand;
	if (data.hp <= 0)
	{
		move = false;
		data.hp = 0;
	}
	return data.hp;
}

int Enemy::Damage2(int patk)
{
	if (patk < 0)
	{
		std::cout << "０ダメージ！" << std::endl;
		return data.hp;
	}
	if (data.hp - (patk - data.def) < 0)
	{
		std::cout << data.name << "に" << data.hp << "のダメージ！" << std::endl;
		data.hp = 0;
		return 0;
	}
	if (patk-data.def > 100)
	{
		data.hp -= 100;
		std::cout << data.name << "に" << 100 << "のダメージ！" << std::endl;
		if (data.hp < 0)
		{
			data.hp = 0;
		}
		return data.hp;
	}
	
	data.hp -= patk - data.def;
	std::cout << data.name << "に" << patk - data.def << "のダメージ！" << std::endl;
	return data.hp;
}

int Enemy::LookSPD()
{
	return data.spd;
}
int Enemy::LookHP()
{
	return data.hp;
}
std::string Enemy::LookName()
{
	return data.name;
}