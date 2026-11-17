#pragma once

#include <iostream>
#include <memory>

#include "CharaData.h"
#include "Enemy.h"

class EnemyF
{

	static const EnemyData data[];
	static const int dsize;
public:
	EnemyF();
	static std::unique_ptr<Enemy> CreateE(int ID);
};
