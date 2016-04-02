#include "GV.h"

//爆発エフェクト
void explosion_calc() {
	for(int i=0; i<EPS_MAX; i++) {
		if(eps[i].flag==1) eps[i].cnt++;
		if(eps[i].cnt%2==0) eps[i].index=eps[i].cnt%17;
		if(eps[i].index==16) eps[i].flag=0;
	}
}

//ボムを打ったときの爆発エフェクト
void b_explosion_calc() {
	for(int i=0; i<EPS_MAX; i++) {
		if(b_eps[i].flag==1) b_eps[i].cnt++;
		if(b_eps[i].cnt%2==0) b_eps[i].index=b_eps[i].cnt%17;
		if(b_eps[i].index==16) b_eps[i].flag=0;
	}
}

//チャージエフェクトのランダムなx座標を返す
int rang_x_place() {
	return GetRand(40)-20;
}

//チャージエフェクトのランダムなy座標を返す
int rang_y_place() {
	return GetRand(20);
}

//チャージエフェクトとボスとの角度を返す
double chargeatan2(float x, float y) {
	double ang;
	ang=atan2(boss_shot_y_place(stage)-y, boss_shot_x_place(stage)-x);
	return ang;
}

//チャージが完了したかどうかを確認する
int is_charge_end() {
	for(int i=0; i<CHARGE_MAX; i++) {
		if(charge[i].end_flag==0) return -1;
	}
	//全てのend_flagが1ならチャージが完了している
	return 1;
}

//チャージエフェクトのフラグを確認する
int is_charge_flag() {
	for(int i=0; i<CHARGE_MAX; i++) {
		if(charge[i].flag==0 && charge[i].end_flag==0) return i;
	}
	return -1;
}

//ビームチャージエフェクトを登録する
void beam_charge_regist(int i) {
	charge[i].flag=1;
	charge[i].x=boss_shot_x_place(stage)+(float)rang_x_place();
	charge[i].y=boss_shot_y_place(stage)+(float)rang_y_place();
	charge[i].ang=chargeatan2(charge[i].x, charge[i].y);
	charge[i].sp=2.5;
	charge[i].vx=charge[i].sp*cos((float)charge[i].ang);
	charge[i].vy=charge[i].sp*sin((float)charge[i].ang);
}

//ビームチャージ
void beam_charge() {
	for(int i=0; i<CHARGE_MAX; i++) {
		//1つのエフェクトのフラグがオンなら、チャージしている
		if(charge[i].end_flag==0) {
			if(charge[i].flag==1) {
				charge[i].x=boss_shot_x_place(stage)+boss[stage].vx+charge[i].vx;
				charge[i].y+=charge[i].vy;
				
				if(charge[i].y<=boss_shot_y_place(stage)) { //ボスの発射口にチャージしたら
					charge[i].flag=0;                       //フラグをオフにし、
					charge[i].end_flag=1;                   //終了フラグをオンにする
				}
			}
		}
	}
}

//エフェクトメイン
void effect() {
	explosion_calc();
	b_explosion_calc();
	beam_charge();
}