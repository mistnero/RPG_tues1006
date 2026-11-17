#include "GameBattle.h"

GameBattle::GameBattle(const std::string& name, int pjID, int en)
	:ene_n(en),pl(PlayerF::CreateP(name,pjID)),chara_state{ 0,0,0,0 },last_damage(0)
{
	for (int i = 0; i < ENE_MAX; i++)
	{
		
		if(i<ene_n)
		{
			ene_id[i] = GameRandom::GetI().GetR(1, EnemyIDLimit(pl->LookLevel()));
			ene[i] = EnemyF::CreateE(ene_id[i]);
		}
		else
		{
			ene_id[i] = -1;
			ene[i] = nullptr;
			chara_state[i + 1] = -1;
		}
	}
}

int GameBattle::EnemyIDLimit(int pl_level)
{
	if (pl_level <= 1)
	{
		return 1;
	}
	else if (pl_level <= 5)
	{
		return 3;
	}
	else if (pl_level <= 10)
	{
		return 5;
	}
	else
	{
		return 6;
	}

	return 0;
}

bool GameBattle::OneBattle(int whoturn, int whotarget,bool atk_or_damageTF)
{
	switch (whoturn)
	{
		//プレイヤーのターン
	case 1:
		//攻撃処理
		if (atk_or_damageTF)
		{
			last_damage = pl->Attack();
		}
		//ダメージ処理
		else
		{
			if (whotarget == 1 || whotarget - 1 > ene_n)
			{
				return true;
			}
			else
			{
				ene[whotarget - 2]->Damage(last_damage, pl->LookSPD());
				if (ene[whotarget - 2]->LookHP() <= 0)
				{
					chara_state[whotarget - 1] = 1;
				}

			}
		}
		break;

		//以降敵のターン
	case 2:
		//攻撃処理
		if (atk_or_damageTF)
		{

		}
		//ダメージ処理
		else
		{

		}
		break;

	case 3:
		//攻撃処理
		if (atk_or_damageTF)
		{

		}
		//ダメージ処理
		else
		{

		}
		break;

	case 4:
		//攻撃処理
		if (atk_or_damageTF)
		{

		}
		//ダメージ処理
		else
		{

		}
		break;
	}
}