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
//GLOBAL atk_mc atk;
//GLOBAL dfc_mc dfc;

//プレイしてないときの背景画像を格納
GLOBAL int start_back;

//プレイ中の背景画像(ステージ)を格納
GLOBAL int img_back[BACK_MAX];

//ステージ選択用の画像
//GLOBAL int s_back_select[BACK_MAX];//小さい画像
//GLOBAL int b_back_select[BACK_MAX];//大きい画像

//効果音を取り込む
GLOBAL int se[SE_MAX];
GLOBAL int se_flag[SE_MAX];//サウンドフラグ

//スタート画面のモード
GLOBAL int start_mode;//0:選択しているとき　1:選択していないとき

//スタート画面でメニューを選択したときの画面のモード
/*0～3はEnterを押したときの画面
  0:Play 1:操作方法 2:自機の種類 3:exit
*/
GLOBAL int start_select_mode;

//画面のモード
/*
  0:スタート画面
  1:ステージ選択
  2:難易度選択
  3:自機選択
  4:プレイ中
  5:ゲームオーバー
  6:クリアー
*/
GLOBAL int display_mode;

//プレイ中の画面のモード
GLOBAL int play_mode;//0:プレイ中 1:プレイ中断

//プレイ中断時の画面のモード
//GLOBAL int play_stop;//0:continue 1:操作方法 2:exit

//ステージ番号を格納
GLOBAL int stage;

//難易度番号を格納
//GLOBAL int rank;

//自機番号を格納
GLOBAL int mc_num;

//自機ショット
GLOBAL int mS[MC_SHOT_KIND];//画像
GLOBAL mc_shot_info ms[MC_SHOT_MAX];//ショットの情報
GLOBAL int shot_mode;//自機のショットモード

//自機ボム
//GLOBAL int mB[MC_BOM_KIND];//画像
//GLOBAL mc_bom_info mb[MC_BOM_MAX];//ボムの情報

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

//ステージタイトル
//GLOBAL stage_title st_ti[BACK_MAX];//タイトルの情報
//GLOBAL int stage_title_count[BACK_MAX];//何カウント目でタイトルを表示させるか
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

//アイテム
/*
  0:ボム
  1:シルバーリング（回復）
  2:ゴールドリング（回復）
  3:リカバー（全回復）
  4:パワーアップ（ボム）
  5:パワーアップ（レーザー）
  6:パワーアップ（ショット）
*/
//GLOBAL int item_img[ITEM_KND];//画像
//GLOBAL item_info item[ITEM_MAX];//情報
//GLOBAL int item_count;

//スコア
//GLOBAL int score_img[10];//画像
//GLOBAL int score[3][4];//各ステージのスコア

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
