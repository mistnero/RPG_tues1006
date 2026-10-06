#include "GameManager.h"

GameManager& GameManager::GetI()
{
	static GameManager instance;
	return instance;
}
std::unique_ptr<GameBase> GameManager::GetS(int gs)
{
	switch (gs)
	{
	case STITLE:
		return std::make_unique<STitle>();
		break;
	case SGAME:
		return std::make_unique<SGame>();
		break;
	case SRESULT:
		return std::make_unique<SResult>();
		break;
	}
	return nullptr;
}
void GameManager::ChangeCS(std::unique_ptr<GameBase> next)
{
	current_s->Exit(this);
	current_s = std::move(next);
	current_s->Init(this);
}
void GameManager::Init()
{
	run = true;
	current_s = std::move(std::make_unique<STitle>());
	current_s->Init(this);
}
void GameManager::Update()
{
	current_s->Update(this);
}
void GameManager::LoopExit()
{
	run = false;
}