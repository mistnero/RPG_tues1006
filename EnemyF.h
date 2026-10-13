#pragma once

#include <iostream>
#include <memory>

#include "CharaData.h"
#include "Enemy.h"

class EnemyF
{
	EnemyF();
public:
	static const EnemyData data[];
	static const int dsize;
	
	EnemyF(const EnemyF&) = delete;
	EnemyF& operator=(const EnemyF&) = delete;

	EnemyF& GetI();

	static std::unique_ptr<Enemy> CreateE(int ID);
};
