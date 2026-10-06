#include "SGame.h"

void SGame::Init(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Game" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
void SGame::Update(GameManager* manager)
{
	char c = std::cin.get();
	std::cout << c << std::endl;
	manager->ChangeCS(manager->GetS(manager->SRESULT));
}
void SGame::Exit(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "next" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}