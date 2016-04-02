#define _CRT_SECURE_NO_WARNINGS

#include "GV.h"


//効果音の初期化
void sound_ini() {
	memset(se_flag, 0, sizeof(int)*SE_MAX);
}

//効果音を発生
void sound_play() {
	for(int i=0; i<SE_MAX; i++) {
		if(se_flag[i]==1) {
			PlaySoundMem(se[i], DX_PLAYTYPE_BACK);
		}
	}
}

//bgmのロード
void load_bgm(int flag) {
	char str[64];
	sprintf(str, "音楽/BGM/stage%d_%d.mp3", stage, flag);
	area[stage].bgm.handle=LoadSoundMem(str);
}

//bgmの削除
void delete_bgm() {
	DeleteSoundMem(area[stage].bgm.handle);
}

//bgmのメイン処理
void bgm_main() {
	if(area[stage].bgm.flag==0) {//最初に読み込む
		load_bgm(0);
		SetLoopPosSoundMem(area[stage].bgm.loop_pos[0], area[stage].bgm.handle);//ループ一セット
		area[stage].bgm.flag=1;
	}
	if(area[stage].bgm.flag==1) {//種類に応じて再生を始める
		switch(area[stage].bgm.knd[0]) {
			case 0://再生種類0なら
				if(stage_count==60) {//始まって60カウント後に再生
					PlaySoundMem(area[stage].bgm.handle, DX_PLAYTYPE_LOOP);
					area[stage].bgm.flag=2;
				}
				break;
			default:
				break;
		}
	}
	if(area[stage].bgm.flag==2) {//ボス出現時に読み込む
		if(stage_count==boss_load[stage].cnt) {//ボスが現れたら読み込む
			StopSoundMem(area[stage].bgm.handle);
			delete_bgm();
			load_bgm(1);
			SetLoopPosSoundMem(area[stage].bgm.loop_pos[1], area[stage].bgm.handle);//ループ一セット
			area[stage].bgm.flag=3;
		}
	}
	if(area[stage].bgm.flag==3) {
		switch(area[stage].bgm.knd[0]) {
			case 0://再生種類0なら
				if(stage_count==boss_load[stage].cnt) {//ボスが現れたら再生
					PlaySoundMem(area[stage].bgm.handle, DX_PLAYTYPE_LOOP);
					area[stage].bgm.flag=4;
				}
				break;
			default:
				break;
		}
	}
}