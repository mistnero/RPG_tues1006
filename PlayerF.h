#pragma once

#include <iostream>
#include <memory>

#include "CharaData.h"
#include "Player.h"

class PlayerF
{
public:
	static const PlayerData pdata;
	static const PlayerJobData jdata[];
	static const int jds;

	PlayerF();
	static std::unique_ptr<Player> CreateP(const std::string& NAME, int jID);
};