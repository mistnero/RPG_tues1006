#pragma once
#include <iostream>
#include <conio.h>

#include "GameManager.h"
#include "GameBase.h"

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