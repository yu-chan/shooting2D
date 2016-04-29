#include "GV.h"

//スタート画面のメニュー
int start() {
	if(start_mode==0) {
		static int num=0;
		sMenu sm[SM_MAX]={
			{80,100,"Play"},
			{100,150,"操作方法"},
			{100,200,"exit"},
		};
		if(checkKey(KEY_INPUT_UP)==1 || checkKey(KEY_INPUT_F)==1) {//upキーまたはfキーが押されていれば
			num=(num+SM_MAX-1)%SM_MAX;
			se_flag[0]=1;//効果音をオン
		} else if(checkKey(KEY_INPUT_DOWN)==1 ||checkKey(KEY_INPUT_A)==1) {//downキーまたはaキーが押されていれば
			num=(num+1)%SM_MAX;
			se_flag[0]=1;//効果音をオン
		}

		for(int i=0; i<SM_MAX; i++) {
			if(i==num) sm[i].x=80;
			else       sm[i].x=100;
		}

		//メニュー描画
		for(int i=0; i<SM_MAX; i++) {
			DrawFormatString(sm[i].x, sm[i].y, GetColor(255,255,255), sm[i].name);
			//Enterまたはスペースキーが押されたら、画面を切り替える
			if(sm[i].x==80 && (checkKey(KEY_INPUT_RETURN)==1 || 
								  checkKey(KEY_INPUT_SPACE)==1  ||
								  checkKey(KEY_INPUT_J)==1)) {
				se_flag[1]=1;//効果音をオン
				start_mode=1;//画面の切り替え
				start_select_mode=i;//スタート画面の切り替え
				if(i==0) display_mode=1;
			}
		}
	}
	return 0;
}

//操作方法を説明
void how_play() {
	play_explanation epl[7]={
		{100, 40, "↑キー・fキー : 上に移動"},
		{100, 100, "↓キー・aキー : 下に移動"},
		{100, 160, "→キー・dキー : 右に移動"},
		{100, 220, "←キー・sキー : 左に移動"},
		{100, 280, "Enterキー・Spaceキー・jキー : 決定、ショット"},
		{100, 340, "kキー・bキー : キャンセル、戻る"},
		{100, 400, "lキー・vキー : レーザー"},
	};

	//説明を描画
	for(int i=0; i<7; i++) DrawFormatString(epl[i].x, epl[i].y, GetColor(255,255,255), epl[i].sentence);

	//キャンセルボタンが押されたら、元のスタート画面に戻る
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//効果音をオン
		start_mode=0;
	}
}

//自機の種類を説明
/*
void mc_knd() {
	mc_explanation epl[3]={
		{200, 60, 300, 60, 300, 80, "バランスタイプ", "平均的な戦闘機"},
		{200, 220, 300, 220, 300, 240, "アタックタイプ", "攻撃が高く、防御が低い"},
		{200, 380, 300, 380, 300, 400, "ディフェンスタイプ", "防御が高く、攻撃が低い"},
	};
	//バランスタイプの説明
	DrawFormatString(epl[0].nx, epl[0].ny, GetColor(255,255,255), epl[0].name);
	DrawGraph(epl[0].ix, epl[0].iy, blc.img[0], TRUE);
	DrawFormatString(epl[0].sx, epl[0].sy, GetColor(255,255,255), epl[0].sentence);
	//アタックタイプの説明
	DrawFormatString(epl[1].nx, epl[1].ny, GetColor(255,255,255), epl[1].name);
	DrawGraph(epl[1].ix, epl[1].iy, atk.img[0], TRUE);
	DrawFormatString(epl[1].sx, epl[1].sy, GetColor(255,255,255), epl[1].sentence);
	//ディフェンスタイプの説明
	DrawFormatString(epl[2].nx, epl[2].ny, GetColor(255,255,255), epl[2].name);
	DrawGraph(epl[2].ix, epl[2].iy, dfc.img[0], TRUE);
	DrawFormatString(epl[2].sx, epl[2].sy, GetColor(255,255,255), epl[2].sentence);

	//キャンセルボタンが押されたら、元のスタート画面に戻る
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//効果音をオン
		start_mode=0;
	}
}
*/

void start_display() {
	if(start_mode==1) {
		if(start_select_mode==1) how_play();
		//else if(start_select_mode==2) mc_knd();
	} else {
		start();
	}
}