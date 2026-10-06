#pragma once

#include "GameManager.h"
#include "GameBase.h"

class GameManager;

class SGame :public GameBase
{
public:
	void Init(GameManager* manager);
	void Update(GameManager* manager);
	void Exit(GameManager* manager);
};