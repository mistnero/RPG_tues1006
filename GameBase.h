#pragma once

class GameManager;

class GameBase
{
public:
	virtual ~GameBase() = default;
	virtual void Init(GameManager* manager) = 0;
	virtual void Update(GameManager* manager) = 0;
	virtual void Exit(GameManager* manager) = 0;
};
