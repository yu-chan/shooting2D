#include "GV.h"


/*プレイするときに、
  敵や自機の情報など
  さまざまな情報を初期化する
*/
void ini() {
	//ステージのカウント
	stage_count=0;

	//自機(バランス)
	blc.x=320;
	blc.y=440;
	blc.cnt=0;
	blc.hp_max=100;
	blc.hp=blc.hp_max;
	blc.power=10;
	blc.num=2;
	blc.index=0;
	blc.shot_cnt=0;

	//自機のショットモード
	shot_mode=0;

	//自機のショット
	memset(ms, 0, sizeof(mc_shot_info)*MC_SHOT_MAX);

	//自機のレーザー
	memset(ml, 0, sizeof(mc_laser_info)*MC_LASER_MAX);

	//敵
	memset(eny_info, 0, sizeof(enemy)*ENEMY_MAX);
	memset(eny, 0, sizeof(enemy)*ENEMY_MAX);

	//敵のショット
	memset(eny_shot, 0, sizeof(enemy_shot_info)*ENY_SHOT_MAX);

	//爆発エフェクト
	memset(eps, 0, sizeof(explosion)*EPS_MAX);
	memset(b_eps, 0, sizeof(explosion)*EPS_MAX);
	eps_count=0;
	b_eps_count=0;

	//ボス
	memset(boss_load, 0, sizeof(boss_info)*BACK_MAX);
	memset(boss, 0, sizeof(boss_info)*BACK_MAX);

	//ボスショット
	memset(boss_shot, 0, sizeof(boss_shot_info)*BACK_MAX);

	//ボスビーム
	memset(boss_beam, 0, sizeof(boss_shot_info)*BACK_MAX);

	//bgm
	memset(&area, 0, sizeof(area_info)*BACK_MAX);
	//memset(&area, 0, sizeof(area_info));
	area[0].bgm.knd[0]=0;//通常bgmをどういうタイミングで再生するか
	area[0].bgm.knd[1]=0;//ボスbgmをどういうタイミングで再生するか
	area[0].bgm.loop_pos[0]=26672;//通常bgmのループ位置
	area[0].bgm.loop_pos[1]=27010;//ボスbgmのループ位置

	//ゲームオーバーorクリアー
	memset(&g_over, 0, sizeof(game_clear_or_over));
	memset(&g_clear, 0, sizeof(game_clear_or_over));
}