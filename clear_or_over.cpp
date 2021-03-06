#include "GV.h"

//ゲームクリアの登録
void clear_regist() {
	g_clear.flag=1;
	g_clear.x=WND_WID/2;
	g_clear.y=-80;
	g_clear.vy=8;
}

//ゲームクリアの移動計算
void clear_calc() {
	if(g_clear.flag==1) {
		g_clear.y+=g_clear.vy;
		if(g_clear.y>=WND_HET/2) {
			g_clear.y = WND_HET / 2;
			if (checkKey(KEY_INPUT_RETURN) || checkKey(KEY_INPUT_SPACE) > 0) {
				g_over.flag = 0;
				delete_bgm();
				ini();
				start_mode = 0;
				display_mode = 0;
			}
		}
	}
}

//ゲームオーバーの登録
void over_regist() {
	g_over.flag=1;
	g_over.x=WND_WID/2;
	g_over.y=WND_HET/2;
	//g_over.brr=0;
}

//ゲームオーバー
void over_calc() {
	if(g_over.flag==1) {
		g_over.brr+=2;
		if(g_over.brr>=255) g_over.brr=255;
	}
	if (checkKey(KEY_INPUT_RETURN) || checkKey(KEY_INPUT_SPACE) > 0) {
		g_over.flag = 0;
		delete_bgm();
		ini();
		start_mode = 0;
		display_mode = 0;
	}
}

//メイン処理
void c_o_main() {
	if(display_mode==1)      clear_calc();
	else if(display_mode==2) over_calc();
}