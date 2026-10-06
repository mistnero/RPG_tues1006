#include "STitle.h"

void STitle::Init(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Title" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
void STitle::Update(GameManager* manager)
{
	char c = std::cin.get();
	std::cout << c << std::endl;
	manager->ChangeCS(manager->GetS(manager->SGAME));
}
void STitle::Exit(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "next" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}