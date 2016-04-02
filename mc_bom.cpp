#include "GV.h"

//ボムのフラグを確認する
int is_bom_flag() {
	for(int i=0; i<MC_BOM_MAX; i++)
		if(mb[i].flag==0) return i;
	return -1;
}

//ボムのキーが押されているならボムの情報を登録する
void mc_bom_regist() {
	int f;
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		if((f=is_bom_flag())!=-1) {
			mb[f].flag=1;
			mb[f].cnt=0;
			mb[f].power=10;
			mb[f].spd=5;
			if(mc_num==0)      { mb[f].x=blc.x; mb[f].y=blc.y-15; }
			else if(mc_num==1) { mb[f].x=atk.x; mb[f].y=atk.y-15; }
			else               { mb[f].x=dfc.x; mb[f].y=dfc.y-15; }
			se_flag[4]=1;
		}
	}
}

//ヒットしたかどうかを調べる
int is_enemy_hit_b(int i, int j) {
	int r=eny[j].xSize/2;
	float x=mb[i].x-eny[j].x;
	float y=mb[i].y-eny[j].y;
	if(x * x + y * y < r * r) {//画像内なら
			return 1;
	}
	return 0;
}

//ボスにヒットしたかどうかを調べる
int is_boss_hit_b(int i, int j) {
	int h;
	int r;
	float x, y, bx, by;
	switch(j) {
		case 0:
			bx=boss[j].x;
			by=boss[j].y;
			if(mb[i].x>bx-13 && mb[i].x<bx+13 &&
				mb[i].y>by-57 && mb[i].y<by+76) {
					h=1;
			} else {
				h=0;
			}
			break;
		case 1:
			bx=boss[j].x;
			by=boss[j].y-15;
			x=mb[i].x-bx;
			y=mb[i].y-by;
			r=8;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		case 2:
			bx=boss[j].x;
			by=boss[j].y;
			x=mb[i].x-bx;
			y=mb[i].y-by;
			r=65;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		case 3:
			bx=boss[j].x;
			by=boss[j].y-10;
			x=mb[i].x-bx;
			y=mb[i].y-by;
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
void explosion_regist_b(float x, float y) {
	b_eps[b_eps_count].flag=1;
	b_eps[b_eps_count].x=x;
	b_eps[b_eps_count].y=y;
	se_flag[9]=1;
	b_eps_count++;
	if(b_eps_count==EPS_MAX) b_eps_count=0;
}

//アイテム確認
int is_item_b(int j) {
	for(int i=0; i<ITEM_KND; i++) {
		if(eny[j].item_knd[i]==1) {
			eny[j].item_flag[i]=1;
			return i;
		}
	}
	return 0;
}

//アイテムを登録
void item_regist_b(int j, int knd) {
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
int eny_death_judge_b(int j) {
	int knd;
	//敵のHPが0以下になったら、敵を消す
	if(eny[j].hp<=0) {
		eny[j].flag=0;
		score[rank][stage]+=5;
		//消えたときアイテムを持っているか調べる
		//持っていれば登録
		if((knd=is_item_b(j))!=-1) {
			item_regist_b(j, knd);
		}
		return 1;
	}
	return 0;
}

//ボスの生存判定
int boss_death_judge_b(int j) {
	if(boss[j].hp<=0) {
		boss[j].flag=0;
		return 1;
	}
	return 0;
}

//ボムの移動制御
void mc_bom_calc() {
	for(int i=0; i<MC_BOM_MAX; i++) {
		if(mb[i].flag==1) {
			mb[i].y-=mb[i].spd;
			mb[i].cnt++;
			//ボムを打った後の当たり判定
			//敵の当たり判定
			for(int j=0; j<ENEMY_MAX; j++) {
				//当たったら消す
				if(eny[j].flag==1 && is_enemy_hit_b(i, j)==1) {
					mb[i].flag=0;
					eny[j].hp-=mb[i].power;
					if(eny_death_judge_b(j)==1) //敵が死んだかどうか判定する
						explosion_regist_b(mb[i].x, mb[i].y);//爆発エフェクトを呼び出す
				}
			}
			//ボスの当たり判定
			if(boss[stage].flag==1 && is_boss_hit_b(i, stage)) {
				mb[i].flag=0;
				boss[stage].hp-=mb[i].power;
				if(boss_death_judge_b(stage)==1) {
					explosion_regist_b(mb[i].x, mb[i].y);
					clear_regist();
				}
			}
			if(mb[i].y<0) mb[i].flag=0;//ボムが画面外なら消す
		}
	}
}

//自機ボムの関数を呼び出す
void mc_bom() {
	mc_bom_regist();
	mc_bom_calc();
}