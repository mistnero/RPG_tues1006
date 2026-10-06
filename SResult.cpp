#include "SResult.h"

void SResult::Init(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Result" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
void SResult::Update(GameManager* manager)
{
	char c = std::cin.get();
	std::cout << c << std::endl;
	manager->ChangeCS(manager->GetS(manager->STITLE));
}
void SResult::Exit(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "next" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}