#include "GameBattle.h"

GameBattle::GameBattle(const std::string& name, int pjID, int en)
	:ene_n(en),pl(PlayerF::CreateP(name,pjID))
{

}