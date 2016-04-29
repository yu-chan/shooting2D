#include "GV.h"

//アタックタイプの計算
//void atk_calc() {
//	atk.cnt++;
//	if(atk.cnt%5==0) atk.index=atk.cnt%2;
//}

//移動制御
	/*
void atk_move() {
	float naname=1;
	int ud_flag=0, rl_flag=0;
	//x,y座標のスピード{上,下,右,左}
	float sp_x[4]={0, 0, 4.0, -4.0}, sp_y[4]={-4.0, 4.0, 0, 0};
	unsigned char allow_key[4]={KEY_INPUT_UP,
								KEY_INPUT_DOWN,
								KEY_INPUT_RIGHT,
								KEY_INPUT_LEFT};
	unsigned char char_key[4]={KEY_INPUT_F,
							   KEY_INPUT_A,
							   KEY_INPUT_D,
							   KEY_INPUT_S};

	for(int i=0; i<2; i++)//上下キーまたはf・aきーがおされているなら、フラグを立てる
		if(checkKey(allow_key[i])>0 || checkKey(char_key[i])>0) ud_flag=1;

	for(int i=2; i<4; i++)//左右キーまたはd・sキーが押されているなら、フラグを立てる
		if(checkKey(allow_key[i])>0 || checkKey(char_key[i])>0) rl_flag=1;

	//斜めの入力があれば移動スピードをルート２で割る
	if(ud_flag==1 && rl_flag==1) naname=(float)sqrt(2.0);
	
	//入力の可否で移動する
	for(int i=0; i<4; i++) {
		//i方向キーが入力されているなら
		if(checkKey(allow_key[i])>0 || checkKey(char_key[i])>0) {
			atk.x+=sp_x[i]/naname; atk.y+=sp_y[i]/naname;
			//自機が画面外に配置されないようにする
			if(atk.y<HET_MIN) atk.y=HET_MIN;
			if(atk.y>HET_MAX) atk.y=HET_MAX;
			if(atk.x<WID_MIN) atk.x=WID_MIN;
			if(atk.x>WID_MAX) atk.x=WID_MAX;
		}
	}
}*/