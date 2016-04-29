#include "GV.h"

//敵の攻撃パターンの関数宣言
extern void enemy_atk0(int); extern void enemy_atk1(int); extern void enemy_atk2(int);
extern void enemy_atk3(int); extern void enemy_atk4(int); extern void enemy_atk5(int);
extern void enemy_atk6(int); extern void enemy_atk7(int); extern void enemy_atk8(int);
extern void enemy_atk9(int); extern void enemy_atk10(int); extern void enemy_atk11(int);
extern void enemy_atk12(int); extern void enemy_atk13(int); extern void enemy_atk14(int);
extern void enemy_atk15(int); extern void enemy_atk16(int); extern void enemy_atk17(int);
extern void enemy_atk18(int);

//敵の攻撃パターンの配列宣言
void (*eny_atk_pattern[ENY_ATK_PATTERN_MAX])(int)={
	enemy_atk0, enemy_atk1, enemy_atk2,
	enemy_atk3, enemy_atk4, enemy_atk5,
	enemy_atk6, enemy_atk7, enemy_atk8,
	enemy_atk9, enemy_atk10, enemy_atk11,
	enemy_atk12, enemy_atk13, enemy_atk14,
	enemy_atk15, enemy_atk16, enemy_atk17,
	enemy_atk18,
};

//i番目のショットを登録した敵と自機との角度を返す
double shotatan2(int i) {
	int n=eny_shot[i].num;
	double ang;
	/*
	if(mc_num==0)
		ang=atan2(blc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang),
					blc.x-eny[n].x+eny[n].xSize/2*cos((float)eny[n].ang));
	else if(mc_num==1)
		ang=atan2(atk.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang),
					atk.x-eny[n].x+eny[n].xSize/2*cos((float)eny[n].ang));
	else
		ang=atan2(dfc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang),
					dfc.x-eny[n].x+eny[n].xSize/2*cos((float)eny[n].ang));
					*/

	if(mc_num==0)
		ang=atan2(blc.y-eny[n].y, blc.x-eny[n].x);
	/*else if(mc_num==1)
		ang=atan2(atk.y-eny[n].y, atk.x-eny[n].x);
	else
		ang=atan2(dfc.y-eny[n].y, dfc.x-eny[n].x);*/
	return ang;
	/*
	ang=atan2f(blc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
												blc.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
												*/
}

//ショットのフラグを確認する
int is_eny_shot_flag(int i) {
	for(int j=0; j<ENY_SHOT_MAX; j++)
		if(eny_shot[i].bullet[j].flag==0) return j;
	return -1;
}

//ヒットしたかどうか調べる
int is_mc_hit(int i, int j) {
	float r=22.3f;
	float x, y;
	if(mc_num==0) {
		x=eny_shot[i].bullet[j].x-blc.x;
		y=eny_shot[i].bullet[j].y-blc.y;
		if(x * x + y * y < r * r)
			return 1;
	} /*else if(mc_num==1) {
		x=eny_shot[i].bullet[j].x-atk.x;
		y=eny_shot[i].bullet[j].y-atk.y;
		if(x * x + y * y < r * r)
			return 1;
	} else {
		x=eny_shot[i].bullet[j].x-dfc.x;
		y=eny_shot[i].bullet[j].y-dfc.y;
		if(x * x + y * y < r * r)
			return 1;
	}*/
	return 0;
}

//弾の移動計算
void eny_bullet_calc(int i) {
	//敵が倒されていたら、ショットを登録しないフラグにする
	if(eny[eny_shot[i].num].flag!=1) eny_shot[i].flag=2;

	for(int j=0; j<ENY_SHOT_MAX; j++) {
		//弾のフラグがオンなら、弾情報を計算する
		if(eny_shot[i].bullet[j].flag>0) {
			eny_shot[i].bullet[j].x+=eny_shot[i].bullet[j].vx;
			eny_shot[i].bullet[j].y+=eny_shot[i].bullet[j].vy;
			eny_shot[i].bullet[j].cnt++;
			//画面外なら消す
			if(eny_shot[i].bullet[j].x<-20 || eny_shot[i].bullet[j].x>WND_WID+20 ||
				eny_shot[i].bullet[j].y<-20 || eny_shot[i].bullet[j].y>WND_HET+20)
				eny_shot[i].bullet[j].flag=0;//フラグをオフにする
			//自機に当たったら消す
			if(is_mc_hit(i, j)==1) {
				se_flag[12]=1;
				eny_shot[i].bullet[j].flag=0;
				if(mc_num==0)      blc.hp-=eny[i].power;
				//else if(mc_num==1) atk.hp-=eny[i].power;
				//else               dfc.hp-=eny[i].power;
				if(blc.hp<=0) {
					over_regist();
					display_mode = 2;
				}
			}
		}
	}
}

//ショットの処理
void eny_shot_calc() {
	for(int i=0; i<ENEMY_MAX; i++) {
		if(eny_shot[i].flag!=0 && 0<=eny_shot[i].knd && eny_shot[i].knd<ENY_ATK_PATTERN_MAX) {
			eny_atk_pattern[eny_shot[i].knd](i);
			eny_bullet_calc(i);
			//eny_shot[i].x+=eny_shot[i].vx;
			//eny_shot[i].y+=eny_shot[i].vy;
			//eny_shot[i].y+=eny_shot[i].spd;
			eny_shot[i].cnt++;
			/*
			//画面外なら消す
			if(eny_shot[i].x<-20 || eny_shot[i].x>WND_WID+20 || 
				eny_shot[i].y<-20 || eny_shot[i].y>WND_HET+20)
				eny_shot[i].flag=0;
			//自機に当たったら消す
			if(is_mc_hit(i)==1) {
				se_flag[12]=1;
				eny_shot[i].flag=0;
				if(mc_num==0)      blc.hp-=eny[i].power;
				else if(mc_num==1) atk.hp-=eny[i].power;
				else               dfc.hp-=eny[i].power;
			}
			*/
		}
	}
}

//敵ショットの関数を呼び出す
void enemy_shot() {
	eny_shot_calc();
}