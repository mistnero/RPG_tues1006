#pragma once
#include <iostream>
#include <string>

//敵データ
struct EnemyData
{
	int id;
	std::string name;
	int hp;
	int atk;
	int def;
	int spd;
	int exp;
	int gold;
};

//職業補正値データ
struct PlayerJobData
{
	int id;
	std::string job;
	float hp;
	float atk;
	float def;
	float spd;
	float exp;
	float gold;
};
//プレイヤーデータ
struct PlayerData
{
	int p;
	std::string name;
	std::string job;
	int hp;
	int atk;
	int def;
	int spd;
	int exp;
	int gold;
	int level;
};