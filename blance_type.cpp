#include "GV.h"

//バランスタイプの計算
void blc_calc() {
	blc.cnt++;
	if(blc.cnt%5==0) blc.index=blc.cnt%2;
}

//移動制御
void blc_move() {
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
			blc.x+=sp_x[i]/naname; blc.y+=sp_y[i]/naname;
			//自機が画面外に配置されないようにする
			if(blc.y<HET_MIN) blc.y=HET_MIN;
			if(blc.y>HET_MAX) blc.y=HET_MAX;
			if(blc.x<WID_MIN) blc.x=WID_MIN;
			if(blc.x>WID_MAX) blc.x=WID_MAX;
		}
	}
}