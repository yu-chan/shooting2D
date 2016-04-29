#include "DxLib.h"
#include "define.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"


#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

#include "function.h"

//自機の構造体宣言
GLOBAL blc_mc blc;

//プレイしてないときの背景画像を格納
GLOBAL int start_back;

//プレイ中の背景画像(ステージ)を格納
GLOBAL int img_back[BACK_MAX];

//効果音を取り込む
GLOBAL int se[SE_MAX];
GLOBAL int se_flag[SE_MAX];//サウンドフラグ

//スタート画面のモード
GLOBAL int start_mode;//0:選択しているとき　1:選択していないとき

//スタート画面でメニューを選択したときの画面のモード
/*0～3はEnterを押したときの画面
  0:Play 1:操作方法 2:exit
*/
GLOBAL int start_select_mode;

//画面のモード
/*
  0:スタート画面
  1:プレイ中
  2:ゲームオーバー
*/
GLOBAL int display_mode;

//プレイ中の画面のモード
GLOBAL int play_mode;//0:プレイ中 1:プレイ中断

//ステージ番号を格納
GLOBAL int stage;

//自機番号を格納
GLOBAL int mc_num;

//自機ショット
GLOBAL int mS[MC_SHOT_KIND];//画像
GLOBAL mc_shot_info ms[MC_SHOT_MAX];//ショットの情報
GLOBAL int shot_mode;//自機のショットモード

//自機レーザー
GLOBAL int mL[MC_LASER_KIND];//画像
GLOBAL mc_laser_info ml[MC_LASER_MAX];//レーザーの情報

//敵
GLOBAL int es0_img[2];//画像戦艦０
GLOBAL int es1_img[2];//画像戦艦１
GLOBAL int es2_img[2];//画像戦艦２
GLOBAL int es3_img[2];//画像戦艦３
GLOBAL int ed0_img[4];//画像モンスター０
GLOBAL int ed1_img[4];//画像モンスター１
GLOBAL int ed2_img[4];//画像モンスター２
GLOBAL int eny_xs[7], eny_ys[7];//画像のサイズ
GLOBAL enemy eny_info[ENEMY_MAX];//ファイルから読み込んだデータ格納する
GLOBAL enemy eny[ENEMY_MAX];//読み込んだものを格納

//敵の攻撃
GLOBAL int eny_shot_img[ENY_SHOT_KIND];//ショットの画像
GLOBAL enemy_shot_info eny_shot[ENEMY_MAX];

//ステージのカウント
GLOBAL int stage_count;

//エフェクト情報
//爆発
GLOBAL int eps_img[16];//画像
GLOBAL int b_eps_img[16];//ボム打ったときの画像
//ショットまたはレーザーを打ったときの情報
GLOBAL explosion eps[EPS_MAX];
GLOBAL int eps_count;
//ボムを打ったときの情報
GLOBAL explosion b_eps[EPS_MAX];
GLOBAL int b_eps_count;
//ビームをチャージする光
GLOBAL int img_charge;//画像
GLOBAL beam_charge_info charge[CHARGE_MAX];//エフェクト

//ボス
GLOBAL boss_info boss_load[BACK_MAX];//読み込み専用
GLOBAL boss_info boss[BACK_MAX];//ボスの情報
GLOBAL boss_shot_info boss_shot[BACK_MAX];//ボスの弾情報
GLOBAL int img_beam;//ビーム画像
GLOBAL boss_shot_info boss_beam[BACK_MAX];//ボスのビーム情報
GLOBAL int boss_img[BACK_MAX];//画像

//ゲームクリアーorオーバー
GLOBAL int gameover;//画像
GLOBAL int game_over_back;//ゲームオーバー時の背景
GLOBAL int gameclear;//画像
GLOBAL game_clear_or_over g_clear;//ゲームクリア
GLOBAL game_clear_or_over g_over;//ゲームオーバー

//そのエリアが持っているデータ
//GLOBAL area_info area;
GLOBAL area_info area[BACK_MAX];
