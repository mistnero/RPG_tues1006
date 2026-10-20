#include "PlayerF.h"

const PlayerData PlayerF::pdata =
{
	1,"NAME","‘ºl",8,3,2,3,0,50,1
};

const PlayerJobData PlayerF::jdata[] =
{
	{0,"‘ºl",1.0f,1.0f,1.0f,1.0f,1.0f,1.0f},
	{1,"Œ•m",1.2f,1.5f,1.5f,1.2f,1.5f,1.0f},
	{2,"•“¬‰Æ",1.0f,1.8f,1.2f,1.5f,1.2f,1.2f},
	{3,"“‘¯",1.0f,1.2f,1.0f,2.0f,1.2f,1.8f},
	{4,"‹Rm",1.2f,1.2f,2.0f,1.0f,1.5f,1.0f}
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
	j
	int id;
	std::string job;
	int hp;
	int atk;
	int def;
	int spd;
	int exp;
	int gold;

	p
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
*/