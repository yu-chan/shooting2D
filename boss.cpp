#include "GV.h"

//ボスの行動パターンの関数宣言
extern void boss_pattern0(int); extern void boss_pattern1(int); extern void boss_pattern2(int);
extern void boss_pattern3(int); extern void boss_pattern4(int); extern void boss_pattern5(int);
extern void boss_pattern6(int); extern void boss_pattern7(int); extern void boss_pattern8(int);
extern void boss_pattern9(int); extern void boss_pattern10(int); extern void boss_pattern11(int);

//ボスの行動パターンの配列宣言
void (*boss_act_pattern[BOSS_PATTERN_MAX])(int)={
	boss_pattern0, boss_pattern1, boss_pattern2,
	boss_pattern3, boss_pattern4, boss_pattern5,
	boss_pattern6, boss_pattern7, boss_pattern8,
	boss_pattern9, boss_pattern10, boss_pattern11,
};
//void regist_phy2(int t);
//ボスの出現時間が来たら、フラグを立てる
void boss_flag() {
	if(boss_load[stage].cnt==stage_count) boss_load[stage].flag=1;
}
void regist_phy(float pos_x, float pos_y, int t);
//ボス情報を登録
void boss_regist() {
	if(boss_load[stage].cnt==stage_count) {
		boss[stage].flag=1;
		boss[stage].cnt=0;
		boss[stage].x=boss_load[stage].x;
		boss[stage].y=boss_load[stage].y;
		boss[stage].sp=boss_load[stage].sp;
		boss[stage].wait=boss_load[stage].wait;
		boss[stage].hp=boss_load[stage].hp;
		boss[stage].hp_max=boss[stage].hp;
		boss[stage].power=boss_load[stage].power;
		for(int i=0; i<BOSS_PATTERN_MAX; i++) {
			boss[stage].mv_ptn[i] =boss_load[stage].mv_ptn[i];
			boss[stage].mv_cnt[i] =boss_load[stage].mv_cnt[i];
			boss[stage].mv_cnt2[i]=0;
		}
		for(int i=0; i<BOSS_ATK_PATTERN_MAX; i++)
			boss[stage].atk_ptn[i]=boss_load[stage].atk_ptn[i];
		boss[stage].ang=PI/2;
		boss[stage].vx=0;
		boss[stage].vy=0;
		//ボスが上から降りてくるor定位置から出現
		boss[stage].mv_state=-1;
		regist_phy(X_BOSS, Y_BOSS, 120);
		//regist_phy2(25);
	}
}

//弾幕をセット
void boss_shot_regist(int i) {
	memset(&boss_shot[i], 0, sizeof(boss_shot_info));
	boss_shot[i].flag=1;
	boss_shot[i].cnt=0;
}

//ビームをセット
void boss_beam_regist(int i) {
	memset(&charge, 0, sizeof(beam_charge_info)*CHARGE_MAX);
	memset(&boss_beam[i], 0, sizeof(boss_shot_info));
	boss_beam[i].flag=1;
	boss_beam[i].cnt=0;
}

//ボスの出現
void boss_appear() {
}

//物理的計算をさせるために、phy構造体に情報を登録する関数
//pos_x:指定x座標, pos_y:指定y座標, t:指定座標までにかかる指定時間
void regist_phy(float pos_x, float pos_y, int t) {
	float ymax_x, ymax_y;
	if(t==0) t=1;
	boss[stage].phy.flag=1;//物理的計算のオン
	boss[stage].phy.cnt=0;//カウント初期化
	boss[stage].phy.set_t=t;//移動にかける時間をセット
	ymax_x=boss[stage].x-pos_x;//移動したい水平距離
	boss[stage].phy.v0x=2*ymax_x/t;//水平成分の初速度
	boss[stage].phy.ax =2*ymax_x/(t*t);//水平線分の加速度
	boss[stage].phy.prex=boss[stage].x;//初期x座標
	ymax_y=boss[stage].y-pos_y;//移動したい鉛直距離
	boss[stage].phy.v0y=2*ymax_y/t;//鉛直成分の初速度
	boss[stage].phy.ay =2*ymax_y/(t*t);//鉛直成分の加速度
	boss[stage].phy.prey=boss[stage].y;//初期y座標
}

void regist_phy2(int t) {
	float ymax_x, ymax_y;
	if(t==0) t=1;
	boss[stage].phy.flag=1;//物理的計算のオン
	boss[stage].phy.cnt=0;//カウント初期化
	boss[stage].phy.set_t=t;//移動にかける時間をセット
	ymax_x=boss[stage].x-X_BOSS;//移動したい水平距離
	boss[stage].phy.v0x=2*ymax_x/t;//水平成分の初速度
	boss[stage].phy.ax =2*ymax_x/(t*t);//水平線分の加速度
	boss[stage].phy.prex=boss[stage].x;//初期x座標
	ymax_y=boss[stage].y-Y_BOSS;//移動したい鉛直距離
	boss[stage].phy.v0y=2*ymax_y/t;//鉛直成分の初速度
	boss[stage].phy.ay =2*ymax_y/(t*t);//鉛直成分の加速度
	boss[stage].phy.prey=boss[stage].y;//初期y座標
}

//物理的移動計算
void calc_phy() {
	double t=boss[stage].phy.cnt;
	//現在いるべきx座標計算
	boss[stage].x=boss[stage].phy.prex-(float)((boss[stage].phy.v0x*t)-0.5*boss[stage].phy.ax*t*t);
	//現在いるべきy座標計算
	boss[stage].y=boss[stage].phy.prey-(float)((boss[stage].phy.v0y*t)-0.5*boss[stage].phy.ay*t*t);
	boss[stage].phy.cnt++;
	if(boss[stage].phy.cnt>=boss[stage].phy.set_t) {//移動にかける時間分になったらオフ
		if(boss[stage].mv_state==-1) {
			boss[stage].mv_state=0;
			boss_shot_regist(stage);
			boss_beam_regist(stage);
		}
		boss[stage].phy.flag=0;
	}
}

//ボスの行動制御
void boss_move() {
	if(boss[stage].flag==1) { //フラグがオンになっている間、出現する

		if(boss[stage].mv_state!=-1) { //ボスの出現後の行動
			boss_act_pattern[boss[stage].mv_ptn[boss[stage].mv_state]](stage);
			boss[stage].x+=boss[stage].vx;
			boss[stage].y+=boss[stage].vy;
			boss[stage].cnt++;
			boss[stage].mv_cnt2[boss[stage].mv_state]++;

			//boss[stage].mv_state番目の行動が終わったら、次の行動へ移す
			if(boss[stage].mv_cnt2[boss[stage].mv_state]==boss[stage].mv_cnt[boss[stage].mv_state]) {
				int mv_ptn;
				int atk_ptn;
				boss[stage].mv_cnt2[boss[stage].mv_state]=0;//カウントを0に戻す
				boss[stage].mv_state++;//次の行動に移す
				mv_ptn=boss[stage].mv_ptn[boss[stage].mv_state];

				//行動パターンを最初に戻す(行動を循環させる)
				if(mv_ptn==-1 || boss[stage].mv_state==BOSS_PATTERN_MAX) {
					boss[stage].mv_state=0;
				}

				atk_ptn=boss[stage].atk_ptn[boss[stage].mv_state];
				if(atk_ptn==2 || atk_ptn==7) {		 //攻撃パターンがビームなら
					boss_beam_regist(stage);		 //ビームを登録
				} else if(atk_ptn!=2 && atk_ptn!=7){ //それ以外なら
					boss_shot_regist(stage);		 //ショットを登録
				}

				//ボスのHPが0以下になったら消す
				if(boss[stage].hp<=0) boss[stage].flag=0;
			}
		}

		//物理計算
		if(boss[stage].phy.flag==1) calc_phy();
	}
}

//ボスのメイン処理
void boss_main() {
	boss_flag();
	boss_regist();
	boss_move();
	//if(boss[stage].cnt==0 && boss[stage].mv_state==-1) regist_phy(X_BOSS, Y_BOSS, 25);
	//if(boss[stage].cnt==0) regist_phy2(25);
	//if(boss[stage].phy.flag==1) calc_phy();
}