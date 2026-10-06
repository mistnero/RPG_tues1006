#include "STitle.h"

void STitle::Init(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Title" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
void STitle::Update(GameManager* manager)
{
	std::cout << "Press Enter key" << std::endl;
	while (true)
	{
		if (_kbhit())
		{
			if (_getch() == '\r')
			{
				break;
			}
		}
	}
	manager->ChangeCS(manager->GetS(manager->SGAME));
}
void STitle::Exit(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "next" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}