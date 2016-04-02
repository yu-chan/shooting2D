#include "GV.h"

//難易度選択画面
void rank_display() {
	static int num=0;
	rank_explanation exp[3]={
		{180, 60, "Cランク:一番簡単でクリアしやすい"},
		{200, 220, "Bランク:少し難しくなる"},
		{200, 380, "Aランク:一番難しくなる"},
	};
	char name[256]="難易度選択";
	int nx=50, ny=25;

	if(checkKey(KEY_INPUT_UP)==1 || checkKey(KEY_INPUT_F)==1) {//upキーまたはfキーが押されていれば
			num=(num+2)%3;
			se_flag[0]=1;//効果音をオン
		} else if(checkKey(KEY_INPUT_DOWN)==1 ||checkKey(KEY_INPUT_A)==1) {//downキーまたはaキーが押されていれば
			num=(num+1)%3;
			se_flag[0]=1;//効果音をオン
	}

	for(int i=0; i<3; i++) {
			if(i==num) exp[i].x=180;
			else       exp[i].x=200;
	}

	//難易度描画
	for(int i=0; i<3; i++) {
			DrawFormatString(exp[i].x, exp[i].y, GetColor(255,255,255), exp[i].name);
			//Enterまたはスペースキーが押されたら、画面を切り替える
			if(exp[i].x==180 && (checkKey(KEY_INPUT_RETURN)==1 || 
								  checkKey(KEY_INPUT_SPACE)==1  ||
								  checkKey(KEY_INPUT_J)==1)) {
				se_flag[1]=1;//効果音をオン
				rank=i;//ランク番号を格納
				display_mode=3;//次の画面に移る
			}
	}

	//キャンセルボタンが押されていたら
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//効果音をオン
		start_mode=0;
		display_mode=1;//前の画面に戻る
		num=0;//最初の選択肢にする
	}
}