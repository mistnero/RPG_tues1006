#pragma once

#include <iostream>
#include <memory>

#include "CharaData.h"
#include "Enemy.h"

class EnemyF
{
public:
	static const EnemyData data[];
	static const int dsize;

	EnemyF();
	static std::unique_ptr<Enemy> CreateE(int ID);
};
