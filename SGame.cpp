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
	//敵１～３ランダムに決める
	int ene_num = GameRandom::GetI().GetR(1, ENE_MAX);
	//バトルクラスのポインタ
	std::unique_ptr<GameBattle> battle = std::make_unique<GameBattle>(name, 1, ene_num);
	//ターンクラスにキャラクター数を渡す
	GameTurn::GetI().SetTurnM(ene_num + 1);
	std::unique_ptr<Enemy> ene = EnemyF::CreateE(id);
	int bt = 0;
	bool test_turn = true;
	int php = pl->LookHP();
	int nhp = ene->LookHP();
	int spd_rank;
	int record_r = 1;

	while (true)
	{
		//誰が速いかで順番を決める
		for (int c = 0; c < ene_num + 1; c++)
		{
			spd_rank = battle->GetRankWhoFast(c + 1);
			//c+1番目のキャラクターの速さ順が今探している順番に一致したら
			if (record_r == spd_rank)
			{
				//倒されたりなどでターン設定できないときはターンにならない
				if (GameTurn::GetI().judgeTurnNext(c + 1))
				{
					//そこをターンに設定
					GameTurn::GetI().SetTurnTrue(c + 1);
				}
				//次の順番
				record_r++;
				//数字が最後の準まで行ったら
				if (record_r > ene_num + 1)
				{
					//次のラウンド
					GameTurn::GetI().NextRound();
					record_r = 1;
				}
			}
		}

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