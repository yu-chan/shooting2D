#include "GV.h"

//自機の攻撃パターンの関数宣言
extern void mc_atk0(); extern void mc_atk1(); extern void mc_atk2();

//自機の攻撃パターンの配列宣言
void (*mc_atk_pattern[MC_ATK_PATTERN_MAX])()={
	mc_atk0, mc_atk1, mc_atk2,
};

//ショットのフラグを確認する
int is_shot_flag() {
	for(int i=0; i<MC_SHOT_MAX; i++)
		if(ms[i].flag==0) return i;
	return -1;
}

//ショットのキーが押されているならショット情報を登録する
void mc_shot_regist() {
	
	//int f;
	if((checkKey(KEY_INPUT_RETURN)>0 && checkKey(KEY_INPUT_RETURN)<=10)||
	   (checkKey(KEY_INPUT_SPACE)>0 && checkKey(KEY_INPUT_SPACE)<=10)||
	   (checkKey(KEY_INPUT_J)>0 && checkKey(KEY_INPUT_J)<=10)) {
		   mc_atk_pattern[shot_mode]();
		   /*
		   if(mc_num==0)      blc.shot_cnt++;
		   else if(mc_num==1) atk.shot_cnt++;
		   else               dfc.shot_cnt++;
		 
			

		   if((f=is_shot_flag())!=-1 && 
			   (blc.shot_cnt%3==0 || atk.shot_cnt%3==0 || dfc.shot_cnt%3==0)) {
			   ms[f].flag=1;
			   ms[f].cnt=0;
			   ms[f].power=5;
			   ms[f].spd=10;
			   if(mc_num==0)      { ms[f].x=blc.x; ms[f].y=blc.y-20; }
			   else if(mc_num==1) { ms[f].x=atk.x; ms[f].y=atk.y-20; }
			   else               { ms[f].x=dfc.x; ms[f].y=dfc.y-20; }
			   se_flag[3]=1;
		   }*/
	}
	
	//NキーかCキーを押せばショットが変わる
	if(checkKey(KEY_INPUT_N)==1)
		shot_mode=(shot_mode+1)%MC_ATK_PATTERN_MAX;
	else if(checkKey(KEY_INPUT_C)==1)
	    shot_mode=(shot_mode+MC_ATK_PATTERN_MAX-1)%MC_ATK_PATTERN_MAX;
}

//ヒットしたかどうかを調べる
int is_enemy_hit_s(int i, int j) {
	int r=eny[j].xSize/2;
	float x=ms[i].x-eny[j].x;
	float y=ms[i].y-eny[j].y;
	if(x * x + y * y <r * r) {//画像内なら
			return 1;
	}
	return 0;
}

//ボスにヒットしたかどうかを調べる
int is_boss_hit_s(int i, int j) {
	int h;
	int r;
	float x, y, bx, by;
	switch(j) {
		case 0:
			bx=boss[j].x;
			by=boss[j].y;
			if(ms[i].x>bx-13 && ms[i].x<bx+13 &&
				ms[i].y>by-57 && ms[i].y<by+76) {
					h=1;
			} else {
				h=0;
			}
			break;
		case 1:
			bx=boss[j].x;
			by=boss[j].y-15;
			x=ms[i].x-bx;
			y=ms[i].y-by;
			r=8;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		case 2:
			bx=boss[j].x;
			by=boss[j].y;
			x=ms[i].x-bx;
			y=ms[i].y-by;
			r=65;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		case 3:
			bx=boss[j].x;
			by=boss[j].y-10;
			x=ms[i].x-bx;
			y=ms[i].y-by;
			r=15;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		default:
			h=0;
			break;
	}
	return h;
}

//爆発エフェクト情報を登録
void explosion_regist_s(float x, float y) {
	if(eps_count==EPS_MAX) eps_count=0;
	eps[eps_count].flag=1;
	eps[eps_count].x=x;
	eps[eps_count].y=y;
	se_flag[9]=1;
	eps_count++;
	if(eps_count==EPS_MAX) eps_count=0;
}

//アイテム確認
int is_item_s(int j) {
	for(int i=0; i<ITEM_KND; i++) {
		if(eny[j].item_knd[i]==1) {
			eny[j].item_flag[i]=1;
			return i;
		}
	}
	return -1;
}

//アイテムを登録
void item_regist_s(int j, int knd) {
	item[item_count].flag=1;
	item[item_count].knd=knd;
	item[item_count].x=eny[j].x;
	item[item_count].y=eny[j].y;
	item[item_count].xSize=30;
	item[item_count].ySize=30;
	item[item_count].sp=2;
	item_count++;
}

//敵の生存判定
int eny_death_judge_s(int j) {
	int knd;
	//敵のHPが0以下になったら、敵を消す
	if(eny[j].hp<=0) {
		eny[j].flag=0;
		score[rank][stage]+=5;
		//消えたときアイテムを持っているか調べる
		//持っていれば登録
		if((knd=is_item_s(j))!=-1) {
			item_regist_s(j, knd);
		}
		return 1;
	}
	return 0;
}

//ボスの生存判定
int boss_death_judge_s(int j) {
	if(boss[j].hp<=0) {
		boss[j].flag=0;
		return 1;
	}
	return 0;
}

//ショットの移動計算
void mc_shot_calc() {
	for(int i=0; i<MC_SHOT_MAX; i++) {
		if(ms[i].flag==1) {
			ms[i].x-=ms[i].vx;
			ms[i].y-=ms[i].vy;
			ms[i].cnt++;
			//ショットを打った後の当たり判定
			//敵の当たり判定
			for(int j=0; j<ENEMY_MAX; j++) {
				//当たったら消す
				if(eny[j].flag==1 && is_enemy_hit_s(i, j)==1) {
					ms[i].flag=0;
					eny[j].hp-=ms[i].power;
					if(eny_death_judge_s(j)==1)//敵が死んだかどうか判定する
						explosion_regist_s(ms[i].x, ms[i].y);//爆発エフェクトを呼び出す
				}
			}
			//ボスの当たり判定
			if(boss[stage].flag==1 && is_boss_hit_s(i, stage)) {
				ms[i].flag=0;
				boss[stage].hp-=ms[i].power;
				if(boss_death_judge_s(stage)==1) {
					explosion_regist_s(ms[i].x, ms[i].y);
					clear_regist();
				}
			}

			if(ms[i].x<-20 || ms[i].x>WND_WID+20 ||
				ms[i].y<-20 || ms[i].y>WND_HET+20) {
				ms[i].flag=0;//ショットが画面外なら消す
				ms[i].cnt=0;
			}
		}
	}
}

//自機ショットの関数を呼び出す
void mc_shot() {
	mc_shot_regist();
	mc_shot_calc();
}