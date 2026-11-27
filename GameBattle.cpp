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

//誰が足早い（１（プレイヤー）～４で入力して順番を返す）
int GameBattle::GetRankWhoFast(int fastnum)
{
	//順位順
	int cfast[ENE_MAX + 1];

	if (fastnum > ene_n)
	{
		return -1;
	}
	//もう順位が出ていたら比較を禁止する
	bool nouse[ENE_MAX + 1] = { false,false,false,false };
	//仮最速(プレイヤー)
	int fast_num = 1;
	int fast_spd = pl->LookSPD();
	//順位だしループ
	for (int lc = 0; lc < ene_n + 1; lc++)
	{
		//禁止されてない仮最速候補を探す
		for (int ffc = 0; ffc < ene_n + 1; ffc++)
		{
			if (nouse[ffc])
			{
				continue;
			}
			fast_num = ffc + 1;
			if (ffc != 0)
			{
				fast_spd = ene[ffc - 1]->LookSPD();
				break;
			}
			fast_spd = pl->LookSPD();
		}

		//比較用ループ
		for (int c = 0; c < ene_n + 1; c++)
		{
			//自分と比較しない
			if (c + 1 == fast_num)
			{
				continue;
			}
			//禁止ナンバーは入らない
			if (nouse[c])
			{
				continue;
			}

			//一応-1が配列に入らないように
			if (c == 0)
			{
				continue;
			}
			//速ければ更新
			else if (fast_spd < ene[c-1]->LookSPD())
			{
				fast_num = c + 1;
				fast_spd = ene[c - 1]->LookSPD();
			}
			//同じでランダム判定
			else if (fast_spd == ene[c - 1]->LookSPD())
			{
				int per = GameRandom::GetI().GetR(1, 100);
				if (per <= 50)
				{
					fast_num = c + 1;
					fast_spd = ene[c - 1]->LookSPD();
				}
			}
		}
		//結果が出たら
		//順位を記録
		cfast[lc] = fast_num;
		//その番号を以降のループで使用禁止に
		nouse[lc] = true;
		//ここで指定番号と合致したら
		if (fastnum == cfast[lc])
		{
			//順番を返す
			return lc + 1;
		}
	}
	

	
	
}

//テスト