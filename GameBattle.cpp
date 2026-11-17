#include "GameBattle.h"

GameBattle::GameBattle(const std::string& name, int pjID, int en)
	:ene_n(en),pl(PlayerF::CreateP(name,pjID))
{
	for (int i = 0; i < ENE_MAX; i++)
	{
		if (i < ene_n)
		{
			ene[i] = EnemyF::CreateE(i);
		}
		else
		{
			ene[i] = nullptr;
		}
	}
}