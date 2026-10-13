#pragma once

#include <random>

class GameRandom
{
	std::random_device rd;
	std::mt19937 mt;
	GameRandom()
		:mt(rd())
	{ }
public:
	GameRandom(const GameRandom&) = delete;
	GameRandom& operator=(const GameRandom&) = delete;

	static GameRandom& GetI()
	{
		static GameRandom instance;
		return instance;
	}

	int GetR(int min, int max)
	{
		return std::uniform_int_distribution<int>(min, max)(mt);
	}
};
