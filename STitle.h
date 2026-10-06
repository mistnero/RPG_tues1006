#pragma once
#include <iostream>
#include <conio.h>

#include "GameManager.h"
#include "GameBase.h"

class GameManager;

class STitle :public GameBase
{


public:
	STitle()
	{
	}
	void Init(GameManager* manager);
	void Update(GameManager* manager);
	void Exit(GameManager* manager);
};