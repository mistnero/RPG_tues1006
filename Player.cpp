#include "Player.h"

Player::Player(const std::string& na, const PlayerData& pd, const PlayerJobData& jd)
	:data(pd), jdata(jd), critical(false), avoid(false)
{
	data.name = na;
	data.job = jdata.job;
	data.hp = (int)((float)data.hp * jdata.hp);
	data.atk = (int)((float)data.atk * jdata.atk);
	data.def = (int)((float)data.def * jdata.def);
	data.spd = (int)((float)data.spd * jdata.spd);
}

int Player::Attack()
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

int Player::Damage(int eatk, int espd)
{
	int rand = GameRandom::GetI().GetR(1, 100);
	
	if (rand > 90)
	{
		avoid = true;
	}
	else if (espd < data.spd)
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

	int drand = rand = GameRandom::GetI().GetR(10, data.def);
	if (eatk <= data.def)
	{
		drand = GameRandom::GetI().GetR(10, (int)((float)data.def * 0.8f));
	}
	rand = GameRandom::GetI().GetR(1, 3);
	std::cout << data.name << "に" << (eatk - drand) / rand << "のダメージ！" << std::endl;
	data.hp -= (eatk - drand) / rand;
	if (data.hp <= 0)
	{
		data.hp = 0;
	}
	return data.hp;
}

int Player::Damage2(int eatk) {
	if (eatk < 0)
	{
		std::cout <<  "０ダメージ！" << std::endl;
		return data.hp;
	}
	if (data.hp - (eatk - data.def) < 0)
	{
		std::cout << data.name << "に" << data.hp << "のダメージ！" << std::endl;
		data.hp = 0;
		return 0;
	}
	if (eatk-data.def > 100)
	{
		
		data.hp -= 100;
		std::cout << data.name << "に" << 100 << "のダメージ！" << std::endl;
		return data.hp;
	}
	
	data.hp -= eatk-data.def;
	std::cout<<data.name<<"に"<<eatk-data.def<<"のダメージ！"<<std::endl;
	return data.hp;
}

int Player::LookSPD()
{
	return data.spd;
}
int Player::LookHP()
{
	return data.hp;
}
std::string Player::LookName()
{
	return data.name;
}