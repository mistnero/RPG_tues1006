#pragma once

#include "CharaData.h"
#include "GameRandom.h"

class Player
{
	PlayerData data;
	PlayerJobData jdata;

	bool critical;
	bool avoid;

public:
	Player(const std::string& na, const PlayerData& pd, const PlayerJobData& jd);

	int Attack();

	int Damage(int eatk,int espd);
	int Damage2(int eatk);

	int LookSPD();
	int LookHP();
	std::string LookName();
};
