#include "GV.h"

unsigned int Key[256];

//キーの入力状態を取得
int getKey() {
	char buf[256];//全てのキーの入力状態を格納するためのバッファ
	GetHitKeyStateAll(buf);
	for(int i=0; i<256; i++) {
		if(buf[i]==1) Key[i]++;
		else          Key[i]=0;
	}
	return 0;
}

//キーが押されているかチェックする
int checkKey(unsigned char Handle) {
	return Key[Handle];
}