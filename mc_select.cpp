#include "GV.h"

//自機選択画面
void mc_select() {
	static int num=0;
	char name[256]="自機の種類を選択";
	int nx=50, ny=25;
	mc_explanation epl[3]={
		{180, 60, 300, 60, 300, 80, "バランスタイプ", "平均的な戦闘機"},
		{200, 220, 300, 220, 300, 240, "アタックタイプ", "攻撃が高く、防御が低い"},
		{200, 380, 300, 380, 300, 400, "ディフェンスタイプ", "防御が高く、攻撃が低い"},
	};

	if(checkKey(KEY_INPUT_UP)==1 || checkKey(KEY_INPUT_F)==1) {//upキーまたはfキーが押されていれば
		num=(num+2)%3;
		se_flag[0]=1;//効果音をオン
	} else if(checkKey(KEY_INPUT_DOWN)==1 ||checkKey(KEY_INPUT_A)==1) {//downキーまたはaキーが押されていれば
		num=(num+1)%3;
		se_flag[0]=1;//効果音をオン
	}

	for(int i=0; i<3; i++) {
		if(i==num) epl[i].ix=180;
		else       epl[i].ix=200;
	}

	DrawFormatString(nx, ny, GetColor(255,255,255), name);
	for(int i=0; i<3; i++) {
		DrawFormatString(epl[i].nx, epl[i].ny, GetColor(255,255,255), epl[i].name);
		if(i==0)      DrawGraph(epl[i].ix, epl[i].iy, blc.img[0], TRUE);
		else if(i==1) DrawGraph(epl[i].ix, epl[i].iy, atk.img[0], TRUE);
		else          DrawGraph(epl[i].ix, epl[i].iy, dfc.img[0], TRUE);
		DrawFormatString(epl[i].sx, epl[i].sy, GetColor(255,255,255), epl[i].sentence);
		//Enterまたはスペースキーが押されたら、画面を切り替える
		if(epl[i].ix==180 && (checkKey(KEY_INPUT_RETURN)==1 || 
						     checkKey(KEY_INPUT_SPACE)==1  ||
							 checkKey(KEY_INPUT_J)==1)) {
				se_flag[1]=1;//効果音をオン
				mc_num=i;//ランク番号を格納
				display_mode=4;//次の画面に移る
		}
	}

	//キャンセルボタンが押されていたら
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//効果音をオン
		start_mode=0;
		display_mode=2;//前の画面に戻る
		num=0;//最初の選択肢にする
	}
}