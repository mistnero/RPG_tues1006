#include "PlayerF.h"

const PlayerData PlayerF::pdata =
{
	1,"NAME","村人",80,30,20,30,0,50,1
};

const PlayerJobData PlayerF::jdata[] =
{
	{0,"村人",1.0f,1.0f,1.0f,1.0f,1.0f,1.0f},
	{1,"剣士",1.2f,1.5f,1.5f,1.2f,1.5f,1.0f},
	{2,"武闘家",1.0f,1.8f,1.2f,1.5f,1.2f,1.2f},
	{3,"盗賊",1.0f,1.2f,1.0f,2.0f,1.2f,1.8f},
	{4,"騎士",1.2f,1.2f,2.0f,1.0f,1.5f,1.0f}
};
const int PlayerF::jds = sizeof(jdata) / sizeof(PlayerJobData);


PlayerF::PlayerF()
{

}


std::unique_ptr<Player> PlayerF::CreateP(const std::string& NAME, int jID)
{
	for (int p = 0; p < jds; ++p)
	{
		if (jdata[p].id == jID)
		{
			return std::make_unique<Player>(NAME, pdata, jdata[p]);
		}
	}
	return nullptr;
}

/*
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
*/