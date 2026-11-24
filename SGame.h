#pragma once
#include <iostream>
#include <conio.h>
#include <memory>

#include "GameManager.h"
#include "GameBase.h"
#include "PlayerF.h"
#include "EnemyF.h"
#include "GameRandom.h"
#include "GameTurn.h"
#include "GameBattle.h"

class GameManager;

class SGame :public GameBase
{
	
public:
	SGame()
	{

	}
	void Init(GameManager* manager);
	void Update(GameManager* manager);
	void Exit(GameManager* manager);
};