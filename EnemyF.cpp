#include "EnemyF.h"


const EnemyData EnemyF::data[] =
{
	{1,"Slime",50,10,10,50,5,3},
	{2,"Goblin",50,30,30,30,7,5},
	{3,"Orc",100,50,50,10,10,10},
	{4,"Kobold",120,50,20,70,15,10},
	{5,"Cockatrice",200,100,50,80,20,20},
	{6,"Golem",250,150,200,50,30,35}
};
const int EnemyF::dsize = sizeof(data) / sizeof(EnemyData);

EnemyF::EnemyF()
{

}


std::unique_ptr<Enemy> EnemyF::CreateE(int ID)
{
	for (int e = 0; e < dsize; ++e)
	{
		if (data[e].id == ID)
		{
			return std::make_unique<Enemy>(data[1]);
		}
	}
	return nullptr;
}

/*
	id
	std::string name;
	int hp;
	int atk;
	int def;
	int spd;
	int exp;
	int gold;
*/