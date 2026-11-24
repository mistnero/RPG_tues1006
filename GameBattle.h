#pragma once

#include <memory>

#include "PlayerF.h"
#include "EnemyF.h"
#include "GameRandom.h"

#define ENE_MAX 3

//戦闘の処理
class GameBattle
{
	//プレイヤー
	std::unique_ptr<Player> pl;
	//敵
	std::unique_ptr<Enemy> ene[ENE_MAX];
	//敵の数
	int ene_n;
	//敵のID保管
	int ene_id[ENE_MAX];
	//プレイヤー→敵１→敵２→敵３の順で状態判定する変数
	int chara_state[ENE_MAX + 1];

	int EnemyIDLimit(int pl_level);

	//最終的なダメージを記録
	int last_damage;

	//ターン数
	int turn_num;

	//状態
	enum
	{
		B_NO_DATA=-1,
		B_NORMAL_DATA=0,
		B_END_DATA=1,
	}; 

public:
	GameBattle(const std::string& name, int pjID, int en);
	~GameBattle();
	//戦闘開始
	void StartBattle(const std::string& name, int jID, int eID);

	//一体分の戦闘関数　１（プレイヤー）～４で指定、攻撃回数、攻撃モード、ダメージモード
	bool OneBattle(int whoturn,int whotarget,int atk_num,bool atk_or_damageTF);

};

//1.敵のIDをプレイヤーのレベルを参照して範囲を絞る→こっちでレベルをIDにする関数を用意 d
//2.かつ、絞られた範囲内からランダムにIDを決定する→↑を使う d
//3.IDを記録する変数がいる d
//4.ターンクラスを導入する→せっかくのターンクラスの分離なので外側で使う。引数でターンを取得して１体分のみ戦闘する関数を用意する
//5.１ターンのみの戦闘関数を外側で何度も回す。そのために攻撃かダメージの後に倒されたか判定したい。生存か否か変数で持つ。