#include "GV.h"

//ランダムな角度を返す
double rang(double ang) {
	return (-ang+ang*2*GetRand(10000)/10000.0);
}

//移動パターン0
//上からまっすぐ行く
void enemy_pattern0(int i) {
	eny[i].vx=0;
	eny[i].vy=eny[i].sp;
	eny[i].ang=0;
	eny[i].naname=0;
}

//移動パターン１
//右下に行く1
void enemy_pattern1(int i) {
	eny[i].naname=(-3)*PI/10;
	eny[i].ang=(float)(PI/5);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//移動パターン２
//左下に行く1
void enemy_pattern2(int i) {
	eny[i].naname=PI/3;
	eny[i].ang=(float)(5*PI/6);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//移動パターン３
//向きを２回変えて右下へ
void enemy_pattern3(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	} else if(t==30) {
		eny[i].naname=-PI/4;
		eny[i].ang=(float)(PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//移動パターン４
//向きを２回変えて左下へ
void enemy_pattern4(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	} else if(t==30) {
		eny[i].naname=PI/4;
		eny[i].ang=(float)(3*PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//移動パターン５
//右上へ行く1
void enemy_pattern5(int i) {
	eny[i].naname=5*PI/4;
	eny[i].ang=(float)(7*PI/4);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//移動パターン６
//左上へ行く1
void enemy_pattern6(int i) {
	eny[i].naname=3*PI/4;
	eny[i].ang=(float)(5*PI/4);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//移動パターン7
//自機の真下から来る
void enemy_pattern7(int i) {
	float x=eny[i].x;
	eny[i].naname=PI;
	eny[i].ang=3*PI/2;
	eny[i].vy=-eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].x=blc.x+x;
		else if(mc_num==1) eny[i].x=atk.x+x;
		else               eny[i].x=dfc.x+x;
	}
}

//移動パターン8
//自機の真上から来る
void enemy_pattern8(int i) {
	float x=eny[i].x;
	eny[i].naname=0;
	eny[i].ang=PI/2;
	eny[i].vy=eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].x=blc.x+x;
		else if(mc_num==1) eny[i].x=atk.x+x;
		else               eny[i].x=dfc.x+x;
	}
}

//移動パターン9
//自機の真右から来る
void enemy_pattern9(int i) {
	float y=eny[i].y;
	eny[i].naname=PI/2;
	eny[i].ang=PI;
	eny[i].vx=-eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].y=blc.y+y;
		else if(mc_num==1) eny[i].y=atk.y+y;
		else               eny[i].y=dfc.y+y;
	}
}

//移動パターン10
//自機の真左から来る
void enemy_pattern10(int i) {
	float y=eny[i].y;
	eny[i].naname=-PI/2;
	eny[i].ang=0;
	eny[i].vx=eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].y=blc.y+y;
		else if(mc_num==1) eny[i].y=atk.y+y;
		else               eny[i].y=dfc.y+y;
	}
}

//移動パターン11
//上からまっすぐ行って左カーブ
void enemy_pattern11(int i) {
	if(eny[i].cnt==0) eny[i].vy=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//左向きに加速
		eny[i].vy-=eny[i].sp/100;//減速
	}
}

//移動パターン12
//上からまっすぐ行って右カーブ
void enemy_pattern12(int i) {
	if(eny[i].cnt==0) eny[i].vy=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//右向きに加速
		eny[i].vy-=eny[i].sp/100;//減速
	}
}

//移動パターン13
//下からまっすぐ行って左カーブ
void enemy_pattern13(int i) {
	if(eny[i].cnt==0) eny[i].vy=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//左向きに加速
		eny[i].vy+=eny[i].sp/100;//減速
	}
}

//移動パターン14
//下からまっすぐ行って右カーブ
void enemy_pattern14(int i) {
	if(eny[i].cnt==0) eny[i].vy=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//右向きに加速
		eny[i].vy+=eny[i].sp/100;//減速
	}
}

//移動パターン15
//向きを２回変えて右上へ
void enemy_pattern15(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	} else if(t==30) {
		eny[i].naname=5*PI/4;
		eny[i].ang=(float)(7*PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//移動パターン16
//向きを２回変えて左上へ
void enemy_pattern16(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	} else if(t==30) {
		eny[i].naname=3*PI/4;
		eny[i].ang=(float)(5*PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//行動パターン17
//自機の上からまっすぐ行った後、右に移動
void enemy_pattern17(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=0;
		eny[i].vy=eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//行動パターン18
//自機の上からまっすぐ行った後、左に移動
void enemy_pattern18(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=0;
		eny[i].vy=eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//行動パターン19
//自機の下からまっすぐ行った後、右に移動
void enemy_pattern19(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI;
		eny[i].vy=-eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//行動パターン20
//自機の下からまっすぐ行った後、左に移動
void enemy_pattern20(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI;
		eny[i].vy=-eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//行動パターン21
//自機の右からまっすぐ行った後、上に移動
void enemy_pattern21(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=-PI;
	}
}

//行動パターン22
//自機の左からまっすぐ行った後、上に移動
void enemy_pattern22(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
}

//行動パターン23
//自機の右からまっすぐ行った後、下に移動
void enemy_pattern23(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//行動パターン24
//自機の左からまっすぐ行った後、下に移動
void enemy_pattern24(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//行動パターン25
//降りて、停滞して、降りる
void enemy_pattern25(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=0;
	if(t==0)    eny[i].vy=eny[i].sp;//降りる
	if(t==30)   eny[i].vy=0;//とまる
	if(t==30+w) eny[i].vy=eny[i].sp;//降りる
}

//行動パターン26
//上って、停滞して、上る
void enemy_pattern26(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=PI;
	if(t==0)    eny[i].vy=-eny[i].sp;//上る
	if(t==30)   eny[i].vy=0;//とまる
	if(t==30+w) eny[i].vy=-eny[i].sp;//上る
}

//行動パターン27
//左上から来た後、折り返して右上に行く
void enemy_pattern27(int i) {
	int t=eny[i].cnt;
	if(t==0) {//左上から降りる
		eny[i].naname=-PI/6;
		eny[i].ang=PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//折り返して、右上に行く
		eny[i].naname=-5*PI/6;
		eny[i].ang=-PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン28
//右上から来た後、折り返して左上に行く
void enemy_pattern28(int i) {
	int t=eny[i].cnt;
	if(t==0) {//右上から降りる
		eny[i].naname=PI/6;
		eny[i].ang=2*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//折り返して、左上に行く
		eny[i].naname=5*PI/6;
		eny[i].ang=4*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン29
//左下から来た後、折り返して右下に行く
void enemy_pattern29(int i) {
	int t=eny[i].cnt;
	if(t==0) {//左下から上る
		eny[i].naname=-5*PI/6;
		eny[i].ang=-PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//折り返して、右下に行く
		eny[i].naname=-PI/6;
		eny[i].ang=PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン30
//右下から来た後、折り返して左下に行く
void enemy_pattern30(int i) {
	int t=eny[i].cnt;
	if(t==0) {//右下から上る
		eny[i].naname=5*PI/6;
		eny[i].ang=4*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//折り返して、左下に行く
		eny[i].naname=PI/6;
		eny[i].ang=2*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン31
//下からまっすぐ行く
void enemy_pattern31(int i) {
	eny[i].vx=0;
	eny[i].vy=-eny[i].sp;
	eny[i].ang=0;
	eny[i].naname=PI;
}

//行動パターン32
//右からまっすぐ行く
void enemy_pattern32(int i) {
	eny[i].vx=-eny[i].sp;
	eny[i].vy=0;
	eny[i].ang=0;
	eny[i].naname=PI/2;
}

//行動パターン33
//左からまっすぐ行く
void enemy_pattern33(int i) {
	eny[i].vx=eny[i].sp;
	eny[i].vy=0;
	eny[i].ang=0;
	eny[i].naname=-PI/2;
}

//行動パターン34
//右上から降りて、右下で方向転換して左に行く
void enemy_pattern34(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(eny[i].y==WND_HET-35) {//方向転換して、左に行く
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//行動パターン35
//右上から左に行って、左上で方向転換して下に降りる
void enemy_pattern35(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(eny[i].x==35) {//方向転換して、下に行く
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//行動パターン36
//左上から降りて、左下で方向転換して右に行く
void enemy_pattern36(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(eny[i].y==WND_HET-35) {//方向転換して右に行く
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//行動パターン37
//左上から右に行って、右上で方向転換して下に降りる
void enemy_pattern37(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(eny[i].x==WND_WID-35) {//方向転換して下に行く
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//行動パターン38
//左下から上って、左上で方向転換して右に行く
void enemy_pattern38(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(eny[i].y==35) {//方向転換して右に行く
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//行動パターン39
//左下から右に行って、右下で方向転換して上に上る
void enemy_pattern39(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(eny[i].x==WND_WID-35) {//方向転換して上に行く
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
}

//行動パターン40
//右下から上って、右上で方向転換して左に行く
void enemy_pattern40(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(eny[i].y==35) {//方向転換して左に行く
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//行動パターン41
//右下から左に行って、左下で方向転換して上に上る
void enemy_pattern41(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(eny[i].x==35) {//方向転換して上に行く
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
}

//行動パターン42
//上から右Uターン
void enemy_pattern42(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].ang=PI/2;
		eny[i].naname=0;
	}
	if(t>=50) {//減速し始める
		eny[i].vx=eny[i].sp;
		eny[i].vy-=g*eny[i].sp;//0になれば、Uターンする
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy<=-eny[i].sp) {//まっすぐに増速する
			eny[i].vx=0;
			eny[i].vy=-eny[i].sp;
			eny[i].ang=3*PI/4;
			eny[i].naname=PI;
		}
	}
}

//行動パターン43
//上から左Uターン
void enemy_pattern43(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(t>=50) {//減速し始める
		eny[i].vx=-eny[i].sp;
		eny[i].vy-=g*eny[i].sp;//0になれば、Uターンする
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy<=-eny[i].sp) {//まっすぐに増速する
			eny[i].vx=0;
			eny[i].vy=-eny[i].sp;
			eny[i].ang=-PI/2;
			eny[i].naname=-PI;
		}
	}
}

//行動パターン44
//下から右Uターン
void enemy_pattern44(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=-PI;
	}
	if(t>=50) {//減速し始める
		eny[i].vx=eny[i].sp;
		eny[i].vy+=g*eny[i].sp;//0になれば、Uターンする
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy>=eny[i].sp) {//まっすぐに増速する
			eny[i].vx=0;
			eny[i].vy=eny[i].sp;
			eny[i].ang=PI/2;
			eny[i].naname=0;
		}
	}
}

//行動パターン45
//下から左Uターン
void enemy_pattern45(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=-PI;
	}
	if(t>=50) {//減速し始める
		eny[i].vx=-eny[i].sp;
		eny[i].vy+=g*eny[i].sp;//0になれば、Uターンする
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy>=eny[i].sp) {//まっすぐに増速する
			eny[i].vx=0;
			eny[i].vy=eny[i].sp;
			eny[i].ang=PI/2;
			eny[i].naname=0;
		}
	}
}

//行動パターン46
//右から上Uターン
void enemy_pattern46(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(t>=50) {//減速し始める
		eny[i].vx+=g*eny[i].sp;//0になれば、Uターンする
		eny[i].vy=-eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx>=eny[i].sp) {//まっすぐに増速する
			eny[i].vx=eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=0;
			eny[i].naname=-PI/2;
		}
	}
}

//行動パターン47
//右から下Uターン
void enemy_pattern47(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(t>=50) {//減速し始める
		eny[i].vx+=g*eny[i].sp;//0になれば、Uターンする
		eny[i].vy=eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx>=eny[i].sp) {//まっすぐに増速する
			eny[i].vx=eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=0;
			eny[i].naname=-PI/2;
		}
	}
}

//行動パターン48
//左から上Uターン
void enemy_pattern48(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(t>=50) {//減速し始める
		eny[i].vx-=g*eny[i].sp;//0になれば、Uターンする
		eny[i].vy=eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx<=-eny[i].sp) {//まっすぐに増速する
			eny[i].vx=-eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=PI/2;
			eny[i].naname=PI/2;
		}
	}
}

//行動パターン49
//左から下Uターン
void enemy_pattern49(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(t>=50) {//減速し始める
		eny[i].vx-=g*eny[i].sp;//0になれば、Uターンする
		eny[i].vy=eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx<=-eny[i].sp) {//まっすぐに増速する
			eny[i].vx=-eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=PI/2;
			eny[i].naname=PI/2;
		}
	}
}

//行動パターン50
//上から降りて、右旋回して降りる
void enemy_pattern50(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=eny[i].sp;
	if(t==0) { eny[i].naname=0; eny[i].ang=PI/2; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=0;
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
	}
}

//行動パターン51
//上から降りて、左旋回して降りる
void enemy_pattern51(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=eny[i].sp;
	if(t==0) { eny[i].naname=0; eny[i].ang=PI/2; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=0;
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
	}
}

//行動パターン52
//下から上り、右旋回して上る
void enemy_pattern52(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=-eny[i].sp;
	if(t==0) { eny[i].naname=PI; eny[i].ang=3*PI/2; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=PI;
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
	}
}

//行動パターン53
//下から上り、左旋回して上る
void enemy_pattern53(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=-eny[i].sp;
	if(t==0) { eny[i].naname=PI; eny[i].ang=3*PI/2; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=PI;
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
	}
}

//行動パターン54
//右から行って、上旋回して行く
void enemy_pattern54(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=-eny[i].sp;
	if(t==0) { eny[i].naname=PI/2; eny[i].ang=PI; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//行動パターン55
//右から行って、下旋回して行く
void enemy_pattern55(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=-eny[i].sp;
	if(t==0) { eny[i].naname=PI/2; eny[i].ang=PI; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//行動パターン56
//左から行って、上旋回して行く
void enemy_pattern56(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=eny[i].sp;
	if(t==0) { eny[i].naname=-PI/2; eny[i].ang=0; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//行動パターン57
//左から行って、下旋回して行く
void enemy_pattern57(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=eny[i].sp;
	if(t==0) { eny[i].naname=-PI/2; eny[i].ang=0; }
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//行動パターン58
//右上から斜めに降りて、上旋回して行く
void enemy_pattern58(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=PI/4; eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=PI/4;
		eny[i].ang=11*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン59
//右上から斜めに降りて、下旋回して行く
void enemy_pattern59(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=PI/4; eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=PI/4;
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン60
//左上から斜めに降りて、上旋回して行く
void enemy_pattern60(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-PI/4; eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=-PI/4;
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン61
//左上から斜めに降りて、下旋回して行く
void enemy_pattern61(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-PI/4; eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=-PI/4;
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン62
//右下から斜めに上って、上旋回して行く
void enemy_pattern62(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=3*PI/4; eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=3*PI/4;
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン63
//右下から斜めに上って、下旋回して行く
void enemy_pattern63(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=3*PI/4; eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=3*PI/4;
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン64
//左下から斜めに上って、上旋回して行く
void enemy_pattern64(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-3*PI/4; eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=-3*PI/4;
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン65
//左下から斜めに上って、下旋回して行く
void enemy_pattern65(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-3*PI/4; eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//ここから周りはじめる
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//１周したらまっすぐ行く
		eny[i].naname=-3*PI/4;
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン66
//上からギザギザに降りる(右)
void enemy_pattern66(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI/r;
	else if(t==30)eny[i].ang=PI/r+PI/2;//左向きに角度を変える
	else if(t==60)eny[i].ang=PI/r;//右向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン67
//上からギザギザに降りる(左)
void enemy_pattern67(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI/r+PI/2;
	else if(t==30)eny[i].ang=PI/r;//右向きに角度を変える
	else if(t==60)eny[i].ang=PI/r+PI/2;//左向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン68
//下からギザギザに降りる(右)
void enemy_pattern68(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=3*PI/2+PI/r;
	else if(t==30)eny[i].ang=3*PI/2-PI/r;//左向きに角度を変える
	else if(t==60)eny[i].ang=3*PI/2+PI/r;//右向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン69
//下からギザギザに降りる(左)
void enemy_pattern69(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=3*PI/2-PI/r;
	else if(t==30)eny[i].ang=3*PI/2+PI/r;//右向きに角度を変える
	else if(t==60)eny[i].ang=3*PI/2-PI/r;//左向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン70
//右からギザギザに降りる(上)
void enemy_pattern70(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI+PI/r;
	else if(t==30)eny[i].ang=PI-PI/r;//下向きに角度を変える
	else if(t==60)eny[i].ang=PI+PI/r;//上向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン71
//右からギザギザに降りる(下)
void enemy_pattern71(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI-PI/r;
	else if(t==30)eny[i].ang=PI+PI/r;//上向きに角度を変える
	else if(t==60)eny[i].ang=PI-PI/r;//下向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン72
//左からギザギザに降りる(上)
void enemy_pattern72(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=-PI/r;
	else if(t==30)eny[i].ang=PI/r;//下向きに角度を変える
	else if(t==60)eny[i].ang=-PI/r;//上向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン73
//左からギザギザに降りる(下)
void enemy_pattern73(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI/r;
	else if(t==30)eny[i].ang=-PI/r;//上向きに角度を変える
	else if(t==60)eny[i].ang=PI/r;//下向きに角度を変える
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//行動パターン74
//右からまっすぐ行って上カーブ
void enemy_pattern74(int i) {
	if(eny[i].cnt==0) eny[i].vx=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//減速
		eny[i].vy-=eny[i].sp/100;//上向きに加速
	}
}

//行動パターン75
//右からまっすぐ行って下カーブ
void enemy_pattern75(int i) {
	if(eny[i].cnt==0) eny[i].vx=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//減速
		eny[i].vy+=eny[i].sp/100;//下向きに加速
	}
}

//行動パターン76
//左からまっすぐ行って上カーブ
void enemy_pattern76(int i) {
	if(eny[i].cnt==0) eny[i].vx=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//減速
		eny[i].vy-=eny[i].sp/100;//上向きに加速
	}
}

//行動パターン77
//左からまっすぐ行って下カーブ
void enemy_pattern77(int i) {
	if(eny[i].cnt==0) eny[i].vx=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//減速
		eny[i].vy+=eny[i].sp/100;//下向きに加速
	}
}

//行動パターン78
//右から左に行って、停滞して、左に行く
void enemy_pattern78(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=PI/2;
	if(t==0)    eny[i].vx=-eny[i].sp;//左に行く
	if(t==30)   eny[i].vx=0;//とまる
	if(t==30+w) eny[i].vx=-eny[i].sp;//左に行く
}

//行動パターン79
//左から右に行って、停滞して、右に行く
void enemy_pattern79(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=-PI/2;
	if(t==0)    eny[i].vx=eny[i].sp;//右に行く
	if(t==30)   eny[i].vx=0;//とまる
	if(t==30+w) eny[i].vx=eny[i].sp;//右に行く
}

//行動パターン80
//右下に行く2
void enemy_pattern80(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン81
//左下に行く2
void enemy_pattern81(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(5*PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン82
//右上に行く2
void enemy_pattern82(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(-PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン83
//左上に行く2
void enemy_pattern83(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(7*PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン84
//下がって、とまって、右下に行く
void enemy_pattern84(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン85
//下がって、とまって、左下に行く
void enemy_pattern85(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=2*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン86
//上がって、とまって、右上に行く
void enemy_pattern86(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=-PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン87
//上がって、とまって、左上に行く
void enemy_pattern87(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=4*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン88
//右上から左下に行って、とまって、左下に行く
void enemy_pattern88(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=3*PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//行動パターン89
//左上から右下に行って、とまって、右下に行く
void enemy_pattern89(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//行動パターン90
//右下から左上に行って、とまって、左上に行く
void enemy_pattern90(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=5*PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//行動パターン91
//左下から右上に行って、とまって、右上に行く
void enemy_pattern91(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=-PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//行動パターン92
//右下に行って、少し回転して、左下に行く
void enemy_pattern92(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang+=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン93
//左下に行って、少し回転して、右下に行く
void enemy_pattern93(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=2*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang-=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン94
//右上に行って、少し回転して、左上に行く
void enemy_pattern94(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=-PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang-=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン95
//左上に行って、少し回転して、右上に行く
void enemy_pattern95(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=-2*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang+=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

/*
  (*)・・・画面中に突然出現する
*/

//行動パターン96
//とまって、上に行く(*)
void enemy_pattern96(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vy=-eny[i].sp;
}

//行動パターン97
//とまって、下に行く(*)
void enemy_pattern97(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vy=eny[i].sp;
}

//行動パターン98
//とまって、右に行く(*)
void enemy_pattern98(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vx=eny[i].sp;
}

//行動パターン99
//とまって、左に行く(*)
void enemy_pattern99(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vx=-eny[i].sp;
}

//行動パターン100
//とまって、右上に行く(*)
void enemy_pattern100(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン101
//とまって、左上に行く(*)
void enemy_pattern101(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン102
//とまって、右下に行く(*)
void enemy_pattern102(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン103
//とまって、左下に行く(*)
void enemy_pattern103(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン104
//降りて、とまって、上がる
void enemy_pattern104(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vy=eny[i].sp;
	if(t==30)   eny[i].vy=0;
	if(t==30+w)	eny[i].vy=-eny[i].sp;
}

//行動パターン105
//上がって、とまって、下がる
void enemy_pattern105(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vy=-eny[i].sp;
	if(t==30)   eny[i].vy=0;
	if(t==30+w)	eny[i].vy=eny[i].sp;
}

//行動パターン106
//左に行って、とまって、右に行く
void enemy_pattern106(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vx=-eny[i].sp;
	if(t==30)   eny[i].vx=0;
	if(t==30+w)	eny[i].vx=eny[i].sp;
}

//行動パターン107
//右に行って、とまって、左に行く
void enemy_pattern107(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vx=eny[i].sp;
	if(t==30)   eny[i].vx=0;
	if(t==30+w)	eny[i].vx=-eny[i].sp;
}

//行動パターン108
//左下に行って、とまって、右上に行く
void enemy_pattern108(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン109
//右下に行って、とまって、左上に行く
void enemy_pattern109(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン110
//左上に行って、とまって、右下に行く
void enemy_pattern110(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン111
//右上に行って、とまって、左下に行く
void enemy_pattern111(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//行動パターン112
//とまって、消える(*)
void enemy_pattern112(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==10+w) eny[i].flag=0;
}

//行動パターン113
//下がって、とまって、右に行って、とまって、
//左に行って、とまって、右に行く
void enemy_pattern113(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=eny[i].sp;//下がる
	if(t==30)          eny[i].vy=0;//とまる
	if(t==40 || t==80) eny[i].vx=eny[i].sp;//右に行く
	if(t==50 || t==70) eny[i].vx=0;//とまる
	if(t==60)          eny[i].vx=-eny[i].sp;//左に行く
}

//行動パターン114
//下がって、とまって、左に行って、とまって、
//右に行って、とまって、左に行く
void enemy_pattern114(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=eny[i].sp;//下がる
	if(t==30)          eny[i].vy=0;//とまる
	if(t==40 || t==80) eny[i].vx=-eny[i].sp;//左に行く
	if(t==50 || t==70) eny[i].vx=0;//とまる
	if(t==60)          eny[i].vx=eny[i].sp;//右に行く
}

//行動パターン115
//上がって、とまって、右に行って、とまって、
//左に行って、とまって、右に行く
void enemy_pattern115(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=-eny[i].sp;//上がる
	if(t==30)          eny[i].vy=0;//とまる
	if(t==40 || t==80) eny[i].vx=eny[i].sp;//右に行く
	if(t==50 || t==70) eny[i].vx=0;//とまる
	if(t==60)          eny[i].vx=-eny[i].sp;//左に行く
}

//行動パターン116
//上がって、とまって、左に行って、とまって、
//右に行って、とまって、左に行く
void enemy_pattern116(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=eny[i].sp;//上がる
	if(t==30)          eny[i].vy=0;//とまる
	if(t==40 || t==80) eny[i].vx=-eny[i].sp;//左に行く
	if(t==50 || t==70) eny[i].vx=0;//とまる
	if(t==60)          eny[i].vx=eny[i].sp;//右に行く
}

//行動パターン117
//左に行って、とまって、上がって、とまって、
//下がって、とまって、上がる
void enemy_pattern117(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vx=-eny[i].sp;//左に行く
	if(t==30)          eny[i].vx=0;//とまる
	if(t==40 || t==80) eny[i].vy=-eny[i].sp;//上がる
	if(t==50 || t==70) eny[i].vy=0;//とまる
	if(t==60)          eny[i].vy=eny[i].sp;//下がる
}

//行動パターン118
//左に行って、とまって、下がって、とまって、
//上がって、とまって、下がる
void enemy_pattern118(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) eny[i].vx=-eny[i].sp;//左に行く
	if(t==30) eny[i].vx=0;//とまる
	if(t==40 || t==80) eny[i].vy=eny[i].sp;//下がる
	if(t==50 || t==70) eny[i].vy=0;//とまる
	if(t==60) eny[i].vy=-eny[i].sp;//上がる
}

//行動パターン119
//右に行って、とまって、上がって、とまって、
//下がって、とまって、上がる
void enemy_pattern119(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) eny[i].vx=eny[i].sp;//右に行く
	if(t==30) eny[i].vx=0;//とまる
	if(t==40 || t==80) eny[i].vy=-eny[i].sp;//上がる
	if(t==50 || t==70) eny[i].vy=0;//とまる
	if(t==60) eny[i].vy=eny[i].sp;//下がる
}

//行動パターン120
//右に行って、とまって、下がって、とまって、
//上がって、とまって、下がる
void enemy_pattern120(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) eny[i].vx=eny[i].sp;//右に行く
	if(t==30) eny[i].vx=0;//とまる
	if(t==40 || t==80) eny[i].vy=eny[i].sp;//下がる
	if(t==50 || t==70) eny[i].vy=0;//とまる
	if(t==60) eny[i].vy=-eny[i].sp;//上がる
}