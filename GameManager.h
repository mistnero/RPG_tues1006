#pragma once
#include <memory>


#include "GameBase.h"
#include "STitle.h"
#include "SGame.h"
#include "SResult.h"

class GameManager
{
private:
	std::unique_ptr<GameBase> current_s;
	GameManager();
public:
	bool run;
	

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	static GameManager& GetI();
	//
	enum
	{
		STITLE,
		SGAME,
		SRESULT,
	};
	std::unique_ptr<GameBase> GetS(int gs);
	void ChangeCS(std::unique_ptr<GameBase> next);
	void Init();
	void Update();
	void LoopExit();
};