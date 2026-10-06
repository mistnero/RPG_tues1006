#pragma once
#include <iostream>

#include "GameManager.h"
#include "GameBase.h"

class GameManager;

class STitle :public GameBase
{


public:
	STitle()
	{
		std::cout << "test" << std::endl;
	}
	void Init(GameManager* manager);
	void Update(GameManager* manager);
	void Exit(GameManager* manager);
};