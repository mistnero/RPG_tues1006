#include "SGame.h"

void SGame::Init(GameManager* manager)
{
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "Game" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
}
void SGame::Update(GameManager* manager)
{
	std::string name;
	std::cout << "名前をつけてください" << std::endl;
	std::cin >> name;
	std::unique_ptr<Player> pl = PlayerF::CreateP(name, 1);
	int id = GameRandom::GetI().GetR(1, 3);
	std::unique_ptr<Enemy> ene = EnemyF::CreateE(id);
	int bt = 0;
	bool test_turn = true;
	int php = pl->LookHP();
	int nhp = ene->LookHP();

	while (true)
	{
		if(test_turn)
		{
			if (pl->LookSPD() > ene->LookSPD())
			{
				bt = 1;
				test_turn = false;
			}
			else if (ene->LookSPD() > pl->LookSPD())
			{
				bt = 2;
				test_turn = false;
			}
			else
			{
				bt = GameRandom::GetI().GetR(1, 2);
				test_turn = false;
			}
		}
		else {
			if(bt==1)
			{
				bt = 2;
				test_turn = true;
			}
			else
			{
				bt = 1;
				test_turn = true;
			}
		}

		//p
		if (bt == 1)
		{
			std::cout << pl->LookName() << "のターン" << std::endl;
			int atk = pl->Attack();
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
		//	nhp = ene->Damage(atk, pl->LookSPD());
			nhp = ene->Damage2(atk);
		}
		//n
		else if (bt == 2)
		{
			std::cout << ene->LookName() << "のターン" << std::endl;
			int atk = ene->Attack();
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
		//	php = pl->Damage(atk, ene->LookSPD());
			php = pl->Damage2(atk);
		}

		while(true)
		{
			if (_kbhit())
			{
				if (_getch() == '\r')
				{
					break;
				}
			}
		}

		if (pl->LookHP() <= 0)
		{
			std::cout << pl->LookName() << "は力尽きた" << std::endl;
			break;
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