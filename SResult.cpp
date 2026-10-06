#include "SResult.h"

void SResult::Init(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Result" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
void SResult::Update(GameManager* manager)
{
	std::cout << "Enter : Go to Title\nq     : Close Game" << std::endl;
	while (true)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'q')
			{
				GameManager::GetI().LoopExit();
				break;
			}
			if (c == '\r')
			{
				manager->ChangeCS(manager->GetS(manager->STITLE));
				break;
			}
		}
	}
	
}
void SResult::Exit(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "next" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}