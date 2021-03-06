#include "GV.h"

//攻撃パターン0
//上から下にまっすぐに打つ
void enemy_atk0(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//弾幕が始まる
		//敵が倒されてなく、弾を撃つことができるなら、弾を登録する
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//弾の種類
			eny_shot[i].bullet[s].naname=0;//画像の角度
			eny_shot[i].bullet[s].flag=1;//フラグをオンにする
			eny_shot[i].bullet[s].x=eny[n].x;//弾のｘ座標
			eny_shot[i].bullet[s].y=eny[n].y;//弾のｙ座標
			eny_shot[i].bullet[s].cnt=0;//カウンタ
			eny_shot[i].bullet[s].sp=10;//スピード
			eny_shot[i].bullet[s].vx=0;//ｘ速度
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp;//ｙ速度
			se_flag[11]=1;//発射音のフラグをオンにする
		}
	}
	/*
	eny_shot[i].vy=eny_shot[i].spd;
	eny_shot[i].naname=0;
	*/
}

//攻撃パターン1
//下から上にまっすぐに打つ
void enemy_atk1(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//弾幕が始まる
		//敵が倒されてなく、弾を撃つことができるなら、弾を登録する
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//弾の種類
			eny_shot[i].bullet[s].naname=PI;//画像の角度
			eny_shot[i].bullet[s].flag=1;//フラグをオンにする
			eny_shot[i].bullet[s].x=eny[n].x;//弾のｘ座標
			eny_shot[i].bullet[s].y=eny[n].y;//弾のｙ座標
			eny_shot[i].bullet[s].cnt=0;//カウンタ
			eny_shot[i].bullet[s].sp=10;//スピード
			eny_shot[i].bullet[s].vx=0;//ｘ速度
			eny_shot[i].bullet[s].vy=-eny_shot[i].bullet[s].sp;//ｙ速度
			se_flag[11]=1;//発射音のフラグをオンにする
		}
	}
	/*
	eny_shot[i].vy=-eny_shot[i].spd;
	eny_shot[i].naname=PI;
	*/
}

//攻撃パターン2
//右から左にまっすぐに打つ
void enemy_atk2(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//弾幕が始まる
		//敵が倒されてなく、弾を撃つことができるなら、弾を登録する
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//弾の種類
			eny_shot[i].bullet[s].naname=PI/2;//画像の角度
			eny_shot[i].bullet[s].flag=1;//フラグをオンにする
			eny_shot[i].bullet[s].x=eny[n].x;//弾のｘ座標
			eny_shot[i].bullet[s].y=eny[n].y;//弾のｙ座標
			eny_shot[i].bullet[s].cnt=0;//カウンタ
			eny_shot[i].bullet[s].sp=10;//スピード
			eny_shot[i].bullet[s].vx=-eny_shot[i].bullet[s].sp;//ｘ速度
			eny_shot[i].bullet[s].vy=0;//ｙ速度
			se_flag[11]=1;//発射音のフラグをオンにする
		}
	}
	/*
	eny_shot[i].vx=-eny_shot[i].spd;
	eny_shot[i].naname=PI/2;
	*/
}

//攻撃パターン3
//左から右にまっすぐに打つ
void enemy_atk3(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//弾幕が始まる
		//敵が倒されてなく、弾を撃つことができるなら、弾を登録する
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//弾の種類
			eny_shot[i].bullet[s].naname=-PI/2;//画像の角度
			eny_shot[i].bullet[s].flag=1;//フラグをオンにする
			eny_shot[i].bullet[s].x=eny[n].x;//弾のｘ座標
			eny_shot[i].bullet[s].y=eny[n].y;//弾のｙ座標
			eny_shot[i].bullet[s].cnt=0;//カウンタ
			eny_shot[i].bullet[s].sp=10;//スピード
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp;//ｘ速度
			eny_shot[i].bullet[s].vy=0;//ｙ速度
			se_flag[11]=1;//発射音のフラグをオンにする
		}
	}
	/*
	eny_shot[i].vx=eny_shot[i].spd;
	eny_shot[i].naname=-PI/2;
	*/
}

//攻撃パターン4
//自機に向かって打つ
void enemy_atk4(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//弾幕が始まる
		//敵が倒されてなく、弾を撃つことができるなら、弾を登録する
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].ang=shotatan2(i);
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//弾の種類
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;//画像の角度
			eny_shot[i].bullet[s].flag=1;//フラグをオンにする
			eny_shot[i].bullet[s].x=eny[n].x;//弾のｘ座標
			eny_shot[i].bullet[s].y=eny[n].y;//弾のｙ座標
			eny_shot[i].bullet[s].cnt=0;//カウンタ
			eny_shot[i].bullet[s].sp=10;//スピード
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);//ｘ速度
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);//ｙ速度
			se_flag[11]=1;//発射音のフラグをオンにする
		}
	}
	/*
	int t=eny_shot[i].cnt;
	if(t==0) {
		if(mc_num==0)
			eny_shot[i].ang=atan2f(eny_shot[i].y-blc.y, eny_shot[i].x-blc.x);
		else if(mc_num==1)
			eny_shot[i].ang=atan2f(eny_shot[i].y-atk.y, eny_shot[i].x-atk.x);
		else
			eny_shot[i].ang=atan2f(eny_shot[i].y-dfc.y, eny_shot[i].x-dfc.x);
		eny_shot[i].naname=eny_shot[i].ang-PI/2;
		eny_shot[i].vx=eny_shot[i].spd*cos((float)eny_shot[i].ang);
		eny_shot[i].vy=eny_shot[i].spd*sin((float)eny_shot[i].ang);
	}
	*/
}

//攻撃パターン5
//100カウント中に10発、自機に向かって直線発射(角度記憶)
void enemy_atk5(int i) {
	int n=eny_shot[i].num;
	int t=eny_shot[i].cnt;
	int s;
	if(t>=0 && t<100 && t%10==0) {
		if(t==0) {//角度を記憶する
			eny_shot[i].ang=shotatan2(i);
		}
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}

	}
}

//攻撃パターン6
//異なる角度から同時に速い弾を５発打つ
void enemy_atk6(int i) {
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(eny_shot[i].cnt==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=10;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//攻撃パターン7
//異なる角度から同時に遅い弾を５発打つ
void enemy_atk7(int i) {
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(eny_shot[i].cnt==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//攻撃パターン8
//100カウント中10発、自機に向かってスピード変化して打つ
void enemy_atk8(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<100 && t%10==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].ang=shotatan2(i);
			/*
			if(mc_num==0)
				eny_shot[i].ang=atan2f(blc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													blc.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
			else if(mc_num==1)
				eny_shot[i].ang=atan2f(atk.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													atk.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
			else
				eny_shot[i].ang=atan2f(dfc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													dfc.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
													*/
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].ang-PI/2;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}
	}
}

//攻撃パターン9
//0.5秒ずつ円形発射
void enemy_atk9(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%20==0) {
		double ang=shotatan2(i);
		for(int j=0; j<20; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=ang+2*PI/20*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//攻撃パターン10
//ばら撒きショット
void enemy_atk10(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double ang=shotatan2(i);

	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=ang+rang(PI/4);
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=(float)(3+rang(1.5));
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//攻撃パターン11
//ばら撒きショット(減速)
void enemy_atk11(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double ang=shotatan2(i);

	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=ang+rang(PI/4);
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=(float)(4+rang(2.0));
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
	for(int j=0; j<ENY_SHOT_MAX; j++) {
		if(eny_shot[i].bullet[j].sp>1.5) {//速度が1.5より大きいものがあれば減速
			eny_shot[i].bullet[j].sp-=0.04f;
			eny_shot[i].bullet[j].vx=eny_shot[i].bullet[j].sp*cos((float)eny_shot[i].bullet[j].ang);
			eny_shot[i].bullet[j].vy=eny_shot[i].bullet[j].sp*sin((float)eny_shot[i].bullet[j].ang);
		}
	}
}

//攻撃パターン12
//斜めからまっすぐ打つ
void enemy_atk12(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny[n].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=10;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//攻撃パターン13
//0.5秒ずつ異なる角度から同時に速い弾を５発打つ
void enemy_atk13(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(t>=0 && t<100 && t%10==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=10;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//攻撃パターン14
//0.5秒ずつ異なる角度から同時に遅い弾を５発打つ
void enemy_atk14(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(t>=0 && t<100 && t%10==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//攻撃パターン15
//上から下へまっすぐ連続で打つ
void enemy_atk15(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=PI;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=0;
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp;
			se_flag[11]=1;
		}
	}
}

//攻撃パターン16
//下から上へまっすぐ連続で打つ
void enemy_atk16(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=0;
			eny_shot[i].bullet[s].vy=-eny_shot[i].bullet[s].sp;
			se_flag[11]=1;
		}
	}
}

//攻撃パターン17
//右から左へまっすぐ連続で打つ
void enemy_atk17(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=-eny_shot[i].bullet[s].sp;
			eny_shot[i].bullet[s].vy=0;
			se_flag[11]=1;
		}
	}
}

//攻撃パターン18
//左から右へまっすぐ連続で打つ
void enemy_atk18(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp;
			eny_shot[i].bullet[s].vy=0;
			se_flag[11]=1;
		}
	}
}

//攻撃パターン19
//行動パターン113〜120に対応した攻撃
void enemy_atk19(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0 || t==20 || t==40) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].ang=shotatan2(i);
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].ang-PI/2;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}
	}
}