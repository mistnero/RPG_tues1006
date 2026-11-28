#include "GameTurn.h"

GameTurn::GameTurn()
	:member_num(0)
{
	for (int ma = 0; ma < MEMBER_MAX; ma++)
	{
		turn_state[ma] = TURN_NO_DATA;
	}
}
GameTurn::~GameTurn()
{

}
//インスタンスの取得
GameTurn& GameTurn::GetI()
{
	static GameTurn instance;
	return instance;
}

//メンバーの数を設定
void GameTurn::SetTurnM(int num)
{
	member_num = num;
	for (int ma = 0; ma < MEMBER_MAX; ma++)
	{
		//指定人数-1まではデータのある配列
		if (ma < num)
		{
			turn_state[ma] = TURN_FALSE;
		}
		//それ以外にはデータがない
		else
		{
			turn_state[ma] = TURN_NO_DATA;
		}
	}
}

//指定メンバーのターンにする
void GameTurn::SetTurnTrue(int mn)
{
	//ターンになっていたメンバーを探す
	for (int ma = 0; ma < member_num; ma++)
	{
		//前のターンだったら
		if (turn_state[ma] == TURN_TRUE && ma != mn)
		{
			//ターン終了にする
			turn_state[ma] = TURN_TRUE_END;
		}
	}
	//次のターンにする
	turn_state[mn] = TURN_TRUE;
}

//指定メンバーが倒されたことを設定
void GameTurn::SetTurnEnd(int mn)
{
	turn_state[mn] = TURN_FALSE_END;
}

//次のターンに設定可能か
bool GameTurn::judgeTurnNext(int mn)
{
	//範囲外
	if (mn >= member_num)
	{
		return false;
	}
	//ターン終了済みか倒れていたら設定できない
	if (turn_state[mn] == TURN_TRUE_END || turn_state[mn] == TURN_FALSE_END)
	{
		return false;
	}

	//現在のターンが指定した数でなければ可能
	if (turn_state[mn] != TURN_TRUE)
	{
		return true;
	}

	return false;
}

//ラウンドリセット
void GameTurn::NextRound()
{
	//次のラウンドのためにデータを持つ生存した配列をすべて初期化する
	for (int ma = 0; ma < member_num; ma++)
	{
		//倒れていない
		if (turn_state[ma] != TURN_FALSE_END)
		{
			//ターン取り消し
			turn_state[ma] = TURN_FALSE;
		}
	}
}

//ターン中のメンバー番号を返す
int GameTurn::GetTurn()
{
	//ループ
	for (int ma = 0; ma < member_num; ma++)
	{
		//ターンだったら
		if (turn_state[ma] == TURN_TRUE)
		{
			return ma + 1;
		}
	}
}