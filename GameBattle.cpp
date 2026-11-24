#include "GameBattle.h"

GameBattle::GameBattle(const std::string& name, int pjID, int en)
	:ene_n(en),pl(PlayerF::CreateP(name,pjID)),chara_state{ B_NORMAL_DATA,B_NORMAL_DATA,B_NORMAL_DATA,B_NORMAL_DATA },
	last_damage(0),turn_num(0)
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
			chara_state[i + 1] = B_NO_DATA;
		}
	}
}
GameBattle::~GameBattle()
{

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

bool GameBattle::OneBattle(int whoturn, int whotarget, int atk_num, bool atk_or_damageTF)
{
	switch (whoturn)
	{
		//プレイヤーのターン
	case 1:
		//非存在、自傷になるので防ぐ
		if (whotarget == 1 || whotarget - 1 > ene_n)
		{
			last_damage = 0;
			return false;
		}

		//攻撃処理
		if (atk_or_damageTF)
		{
			for (int da = 0; da < atk_num; da++)
			{
				//ダメージを足す
				last_damage += pl->Attack();
			}
			return true;
		}
		//ダメージ処理
		else
		{
			//-プレイヤー、-配列で２引く
			//ダメージ
			ene[whotarget - 2]->Damage(last_damage, pl->LookSPD());
			//倒れたら状態を変更
			if (ene[whotarget - 2]->LookHP() <= 0)
			{
				chara_state[whotarget - 1] = B_END_DATA;
			}
			//ダメージをリセット
			last_damage = 0;
			//ダメージ時に１ターン経過
			turn_num++;
			return true;
		}
		break;

		//以降敵のターン
	case 2:
		//プレイヤー以外がターゲットにならないように
		if (whotarget != 1)
		{
			last_damage = 0;
			return false;
		}

		//攻撃処理
		if (atk_or_damageTF)
		{
			for (int da = 0; da < atk_num; da++)
			{
				//ダメージを足す
				last_damage += ene[whoturn - 2]->Attack();
			}
			return true;
		}
		//ダメージ処理
		else
		{
			//ダメージ
			pl->Damage(last_damage, ene[whoturn - 2]->LookSPD());
			//倒れたら状態を変更
			if (pl->LookHP() <= 0)
			{
				chara_state[whotarget - 1] = B_END_DATA;
			}
			//ダメージをリセット
			last_damage = 0;
			//ダメージ時に１ターン経過
			turn_num++;
			return true;
		}
		break;

	case 3:
		if (whotarget != 1)
		{
			last_damage = 0;
			return false;
		}

		//攻撃処理
		if (atk_or_damageTF)
		{
			for (int da = 0; da < atk_num; da++)
			{
				//ダメージを足す
				last_damage += ene[whoturn - 2]->Attack();
			}
			return true;
		}
		//ダメージ処理
		else
		{
			//ダメージ
			pl->Damage(last_damage, ene[whoturn - 2]->LookSPD());
			//倒れたら状態を変更
			if (pl->LookHP() <= 0)
			{
				chara_state[whotarget - 1] = B_END_DATA;
			}
			//ダメージをリセット
			last_damage = 0;
			//ダメージ時に１ターン経過
			turn_num++;
			return true;
		}
		break;

	case 4:
		if (whotarget != 1)
		{
			last_damage = 0;
			return false;
		}

		//攻撃処理
		if (atk_or_damageTF)
		{
			for (int da = 0; da < atk_num; da++)
			{
				//ダメージを足す
				last_damage += ene[whoturn - 2]->Attack();
			}
			return true;
		}
		//ダメージ処理
		else
		{
			//ダメージ
			pl->Damage(last_damage, ene[whoturn - 2]->LookSPD());
			//倒れたら状態を変更
			if (pl->LookHP() <= 0)
			{
				chara_state[whotarget - 1] = B_END_DATA;
			}
			//ダメージをリセット
			last_damage = 0;
			//ダメージ時に１ターン経過
			turn_num++;
			return true;
		}
		break;
	}


	return false;
}

//ターンを数える(trueで０にリセット)
int GameBattle::TurnCount(bool reset)
{
	if (reset)
	{
		turn_num = 0;
	}
	return turn_num;
}

//テスト