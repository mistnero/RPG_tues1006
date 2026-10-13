#include "EnemyF.h"


const EnemyData EnemyF::data[] =
{
	{1,"Slime",5,1,1,5,5,3},
	{2,"Goblin",5,3,3,3,7,5},
	{3,"Orc",10,5,5,1,10,10},
	{4,"Kobold",12,5,2,7,15,10},
	{5,"Cockatrice",20,10,5,8,20,20},
	{6,"Golem",25,15,20,5,30,35}
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
			return std::make_unique<Enemy>(data[e]);
		}
	}
	return nullptr;
}