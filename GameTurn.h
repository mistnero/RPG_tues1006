#pragma once

#define MEMBER_MAX 4	//プレイヤー１と敵最大３
//キャラのターンを記録しておくクラス
class GameTurn
{
	//メンバーの数
	int member_num;
	//状態番号
	enum
	{
		TURN_NO_DATA,	//配列にメンバーがいない
		TURN_TRUE,		//メンバーのターン（常に１つだけ）
		TURN_TRUE_END,	//メンバーのターン終了
		TURN_FALSE,		//ターンではない
		TURN_FALSE_END,	//倒されたのでターンではない
	};
	//ターンを記録
	int turn_state[MEMBER_MAX];

	//コンストラクター
	GameTurn();

public:

	//禁止
	GameTurn(const GameTurn&) = delete;	//コピー禁止
	GameTurn& operator=(const GameTurn&) = delete;	//代入禁止

	//デストラクター
	~GameTurn();
	//インスタンスの取得
	static GameTurn& GetI();

	//メンバーの数を設定
	void SetTurnM(int num);
	//指定メンバーのターンにする
	void SetTurnTrue(int mn);
	//指定メンバーが倒されたことを設定
	void SetTurnEnd(int mn);
	//次のターンに設定可能か
	bool judgeTurnNext(int mn);
	//ラウンドリセット
	void NextRound();
	//ターン中のメンバー番号を返す（１～max４）
	int GetTurn();

};