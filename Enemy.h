#pragma once

#include <iostream>

#include "CharaData.h"
#include "GameRandom.h"

class Enemy
{
	EnemyData data;

	bool critical;
	bool avoid;
	
	bool move;

public:
	Enemy(const EnemyData& sdata);
	
	int Attack();

	int Damage(int fatk);
	
};
