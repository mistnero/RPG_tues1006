#pragma once

#include <memory>

#include "PlayerF.h"
#include "EnemyF.h"
#include "GameRandom.h"

#define ENE_MAX 3

//戦闘の処理
class GameBattle
{
	//プレイヤー
	std::unique_ptr<Player> pl;
	//敵
	std::unique_ptr<Enemy> ene[ENE_MAX];
	//敵の数
	int ene_n;

public:
	GameBattle(const std::string& name, int pjID, int en);
	~GameBattle();
	//戦闘開始
	void StartBattle(const std::string& name, int jID, int eID);
};
