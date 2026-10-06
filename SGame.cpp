#include "SGame.h"

void SGame::Init(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Game" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
void SGame::Update(GameManager* manager)
{
	while (true)
	{
		if(_kbhit())
		{
			if (_getch() == '\r')
			{
				break;
			}
		}
	}
	manager->ChangeCS(manager->GetS(manager->SRESULT));
}
void SGame::Exit(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "next" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}