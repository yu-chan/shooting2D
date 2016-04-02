#include "GV.h"


//ボスのショット発射口を返す(x座標)
float boss_shot_x_place(int i) {
	float x;
	switch(i) {
		case 0:
		case 1:
		case 2:
		case 3: x=boss[i].x; break;
		default:             break;
	}
	return x;
}

//ボスのショット発射口を返す(y座標)
float boss_shot_y_place(int i) {
	float y;
	switch(i) {
		case 0: y=boss[i].y+80; break;
		case 1:
		case 2: y=boss[i].y;    break;
		case 3: y=boss[i].y+45; break;
		default:                break;
	}
	return y;
}

//攻撃パターン0
//5カウントショット
void boss_atk0(int i) {
	int t=boss_shot[i].cnt;
	int s;
	if(t>=0 && t<300 && t%10==0) {
		if(boss_shot[i].flag!=2 && (s=is_boss_shot_flag(i))!=-1) {
			boss_shot[i].bullet[s].flag=1;
			boss_shot[i].bullet[s].cnt=0;
			boss_shot[i].bullet[s].x=boss_shot_x_place(i);
			boss_shot[i].bullet[s].y=boss_shot_y_place(i);
			boss_shot[i].bullet[s].ang=bossatan2(boss_shot[i].bullet[s].x, boss_shot[i].bullet[s].y);
			boss_shot[i].bullet[s].naname=boss_shot[i].bullet[s].ang-PI/2;
			boss_shot[i].bullet[s].sp=3.5;
			boss_shot[i].bullet[s].vx=boss_shot[i].bullet[s].sp*cos((float)boss_shot[i].bullet[s].ang);
			boss_shot[i].bullet[s].vy=boss_shot[i].bullet[s].sp*sin((float)boss_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//攻撃パターン1
//50回扇形ショット
void boss_atk1(int i) {
	int t=boss_shot[i].cnt;
	int s;
	const double r=PI/2;
	if(t>=0 && t<200 && t%10==0) {
		double ang=bossatan2(boss_shot_x_place(i), boss_shot_y_place(i));
		for(int j=0; j<=20; j++) {
			if(boss_shot[i].flag!=2 && (s=is_boss_shot_flag(i))!=-1) {
				boss_shot[i].bullet[s].flag=1;
				boss_shot[i].bullet[s].cnt=0;
				boss_shot[i].bullet[s].x=boss_shot_x_place(i);
				boss_shot[i].bullet[s].y=boss_shot_y_place(i);
				boss_shot[i].bullet[s].ang=ang-r+PI/20*j;
				boss_shot[i].bullet[s].naname=boss_shot[i].bullet[s].ang-PI/2;
				boss_shot[i].bullet[s].sp=3.5;
				boss_shot[i].bullet[s].vx=boss_shot[i].bullet[s].sp*cos((float)boss_shot[i].bullet[s].ang);
				boss_shot[i].bullet[s].vy=boss_shot[i].bullet[s].sp*sin((float)boss_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//攻撃パターン2
//ビーム
void boss_atk2(int i) {
	int t=boss_beam[i].cnt;
	int s, e, k;
	if(t>=0 && t<20 && (s=is_charge_flag())!=-1) {
		beam_charge_regist(s);
	}
	if(t>=30 && t<100 && (e=is_charge_end())==1) {
		if((k=is_boss_beam_flag(i))!=-1) {
			boss_beam[i].bullet[k].flag=1;
			boss_beam[i].bullet[k].cnt=0;
			boss_beam[i].bullet[k].x=boss_shot_x_place(i);
			boss_beam[i].bullet[k].y=boss_shot_y_place(i);
			boss_beam[i].bullet[k].sp=4;
			boss_beam[i].bullet[k].vy=boss_beam[i].bullet[k].sp;
			se_flag[11]=1;
		}
	}
}

//攻撃パターン3
//自機に向かって突進
void boss_atk3(int i) {
	int t=boss[stage].mv_cnt2[boss[stage].mv_state];
	if(t==110) {
		if(mc_num==0)      regist_phy(blc.x, blc.y, 40);
		else if(mc_num==1) regist_phy(atk.x, atk.y, 40);
		else               regist_phy(dfc.x, dfc.y, 40);
	} else if(t==170) {
		regist_phy(X_BOSS, Y_BOSS, 100);
	}
}

//攻撃パターン4
//ばら撒きショット
void boss_atk4(int i) {
	int t=boss_shot[i].cnt;
	int s;
	double ang=bossatan2(boss_shot_x_place(i), boss_shot_y_place(i));

	if(t>=0 && t<300 && t%2==0) {
		if(boss_shot[i].flag!=2 && (s=is_boss_shot_flag(i))!=-1) {
			boss_shot[i].bullet[s].flag=1;
			boss_shot[i].bullet[s].cnt=0;
			boss_shot[i].bullet[s].x=boss_shot_x_place(i);
			boss_shot[i].bullet[s].y=boss_shot_y_place(i);
			boss_shot[i].bullet[s].ang=ang+rang(PI/4);
			boss_shot[i].bullet[s].naname=boss_shot[i].bullet[s].ang-PI/2;
			boss_shot[i].bullet[s].sp=(float)(3+rang(1.5));
			boss_shot[i].bullet[s].vx=boss_shot[i].bullet[s].sp*cos((float)boss_shot[i].bullet[s].ang);
			boss_shot[i].bullet[s].vy=boss_shot[i].bullet[s].sp*sin((float)boss_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//攻撃パターン5
//円形ショット
void boss_atk5(int i) {
	int t=boss_shot[i].cnt;
	int s;
	if(t>=0 && t<200 && t%10==0) {
		double ang=bossatan2(boss_shot_x_place(i), boss_shot_y_place(i));
		for(int j=0; j<50; j++) {
			if(boss_shot[i].flag!=2 && (s=is_boss_shot_flag(i))!=-1) {
				boss_shot[i].bullet[s].flag=1;
				boss_shot[i].bullet[s].cnt=0;
				boss_shot[i].bullet[s].x=boss_shot_x_place(i);
				boss_shot[i].bullet[s].y=boss_shot_y_place(i);
				boss_shot[i].bullet[s].ang=ang+2*PI/50*j;
				boss_shot[i].bullet[s].naname=boss_shot[i].bullet[s].ang-PI/2;
				boss_shot[i].bullet[s].sp=2.5;
				boss_shot[i].bullet[s].vx=boss_shot[i].bullet[s].sp*cos((float)boss_shot[i].bullet[s].ang);
				boss_shot[i].bullet[s].vy=boss_shot[i].bullet[s].sp*sin((float)boss_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//攻撃パターン6
//恋の迷路弾幕
void boss_atk6(int i) {
	const int TM003=600;
	const int DF003=20;
	int h, j, k;
	int t=boss_shot[i].cnt%TM003;
	int t2=boss_shot[i].cnt;
	static int tcnt, cnt, cnum;
	double ang;
	if(t2==0) {
		//中央に行く
		regist_phy(320, 240, 50);
		cnum=0;
	}
	if(t==0) {
		boss_shot[i].base_ang[0]=bossatan2(boss[i].x, boss[i].y);
		cnt=0;
		tcnt=2;
	}
	if(t<540 && t%3) {
		ang=bossatan2(boss[i].x, boss[i].y);
		if(tcnt-2==cnt || tcnt-1==cnt) {
			if(tcnt-1==cnt) {
				boss_shot[i].base_ang[1]=boss_shot[i].base_ang[0]+PI2/DF003*cnt*(cnum?-1:1)-PI2/(DF003*6)*3;
				tcnt+=DF003-2;
			}
		} else {
			for(h=0; h<6; h++) {
				if(boss_shot[i].flag!=2 && (k=is_boss_shot_flag(i))!=-1) {
					boss_shot[i].bullet[k].x=boss[i].x;
					boss_shot[i].bullet[k].y=boss[i].y;
					boss_shot[i].bullet[k].ang=
						boss_shot[i].base_ang[0]+PI2/DF003*cnt*(cnum?-1:1)+PI2/(DF003*6)*h*(cnum?-1:1);
					boss_shot[i].bullet[k].naname=boss_shot[i].bullet[k].ang-PI/2;
					boss_shot[i].bullet[k].flag=1;
					boss_shot[i].bullet[k].cnt=0;
					boss_shot[i].bullet[k].sp=2;
					boss_shot[i].bullet[k].vx=boss_shot[i].bullet[k].sp*cos((float)boss_shot[i].bullet[k].ang);
					boss_shot[i].bullet[k].vy=boss_shot[i].bullet[k].sp*sin((float)boss_shot[i].bullet[k].ang);
					se_flag[11]=1;
				}
			}
		}
		cnt++;
	}
	if(40<t && t<540 && t%30==0) {
		for(j=0; j<3; j++) {
			ang=boss_shot[i].base_ang[1]-PI2/36*4;
			for(h=0; h<27; h++) {
				if(boss_shot[i].flag!=2 && (k=is_boss_shot_flag(i))!=-1) {
					boss_shot[i].bullet[k].x=boss[i].x;
					boss_shot[i].bullet[k].y=boss[i].y;
					boss_shot[i].bullet[k].ang=ang;
					boss_shot[i].bullet[k].naname=boss_shot[i].bullet[k].ang-PI/2;
					boss_shot[i].bullet[k].flag=1;
					boss_shot[i].bullet[k].cnt=0;
					boss_shot[i].bullet[k].sp=(float)(4-1.6/3*j);
					boss_shot[i].bullet[k].vx=boss_shot[i].bullet[k].sp*cos((float)boss_shot[i].bullet[k].ang);
					boss_shot[i].bullet[k].vy=boss_shot[i].bullet[k].sp*sin((float)boss_shot[i].bullet[k].ang);
					se_flag[11]=1;
				}
				ang-=PI2/36;
			}
		}
	}
	if(t==TM003-1) cnum++;
}

//何もしない
void boss_atk7(int i) {
}