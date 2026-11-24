#include "GameBattle.h"

GameBattle::GameBattle(const std::string& name, int pjID, int en)
	:ene_n(en), pl(PlayerF::CreateP(name, pjID)), chara_state{ B_NORMAL_DATA,B_NORMAL_DATA,B_NORMAL_DATA,B_NORMAL_DATA },
	footfast{ 0,0,0,0 }, last_damage(0), turn_num(0)
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
			footfast[i + 1] = -1;
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

//誰が足早い（１（プレイヤー）～４で返す）
int GameBattle::NextWhoFast(int fastnum)
{
	//仮
	int cfast[ENE_MAX + 1];
	//トーナメント式
	int tou_fast[2];
	int tou_slow[2];

	if (fastnum > ene_n)
	{
		return -1;
	}

	//順番に2人ペアで競う
	//プレイヤーが最初の敵より速い
	if (pl->LookSPD() > ene[0]->LookSPD())
	{
		tou_fast[0] = 1;
		tou_slow[0] = 2;
	}
	//逆
	else if (pl->LookSPD() < ene[0]->LookSPD())
	{
		tou_fast[0] = 2;
		tou_slow[0] = 1;
	}
	//同じ
	else
	{
		int per = GameRandom::GetI().GetR(1, 100);
		if (per <= 50)
		{
			tou_fast[0] = 1;
			tou_slow[0] = 2;
		}
		else
		{
			tou_fast[0] = 2;
			tou_slow[0] = 1;
		}
	}
	//次の敵がいない
	if (ene_n < 2)
	{
		tou_fast[1] = -1;
		tou_slow[1] = -1;
	}
	//いるがその次がいない
	else if (ene_n < 3)
	{
		tou_fast[1] = 3;
		tou_slow[1] = 3;
	}
	//いる
	else
	{
		if (ene[1]->LookSPD() > ene[2]->LookSPD())
		{
			tou_fast[1] = 3;
			tou_slow[1] = 4;
		}
		else if (ene[1]->LookSPD() < ene[2]->LookSPD())
		{
			tou_fast[1] = 4;
			tou_slow[1] = 3;
		}
		else
		{
			int per = GameRandom::GetI().GetR(1, 100);
			if (per <= 50)
			{
				tou_fast[1] = 3;
				tou_slow[1] = 4;
			}
			else
			{
				tou_fast[1] = 4;
				tou_slow[1] = 3;
			}
		}
	}
	//一番早い、一番遅いのを出して間を調べる
	//指定された順見て出力するのはそのあと


	////探す
	//for (int chara = 0; chara < ENE_MAX + 1; chara++)
	//{
	//	int spd = pl->LookSPD();
	//	if (chara % 2 == 1)
	//	{
	//		//こっちのが早い
	//		if (spd<ene[chara - 1]->LookSPD())
	//		{
	//			//３のときだけ配列１に入るように(１～４)
	//			tou_fast[chara % 3] = chara + 1;
	//			tou_slow[chara % 3] = chara;
	//		}
	//		else
	//		{
	//			tou_fast[chara % 3] = chara;
	//			tou_slow[chara % 3] = chara + 1;
	//		}
	//	}
	//	
	//}
	////一番早い奴と一番遅い奴を出す


	
}

//テスト