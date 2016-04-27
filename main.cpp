#define GLOBAL_INSTANCE
#include "malloc.h"
#include "GV.h"

int ProcessLoop(){
    if(ProcessMessage()!=0)return -1;//プロセス処理がエラーなら-1を返す
    if(ClearDrawScreen()!=0)return -1;//画面クリア処理がエラーなら-1を返す
	SetWindowSize(WND_WID,WND_HET);
	getKey();//キー入力処理を行う
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化
	ini();
	load();
	//load_story();
	start_mode=0;
	display_mode=0;
	while(ProcessLoop()==0 && start_select_mode!=2) {
		sound_ini();
		graph_start_back();
		switch(display_mode) {
			case 0:
				start_display();
				break;
			//case 1:
			//	graph_select_stage();
			//	break;
			//case 2:
			//	//load_boss();
			//	rank_display();
			//	break;
			//case 3:
			//	mc_select();
			//	break;
			case 1:
				if(stage_count==0) {
					load_story();
					load_boss();
				}
				calc_stage_title();
				graph_play();
				effect();
				item_calc();
				enemy_main();
				enemy_shot();
				//if(blc.hp<=0 || atk.hp<=0 || dfc.hp<=0) {
				boss_main();
				boss_danmaku_main();
				//}
				if(stage_count>10) {
					mc_shot();
					mc_bom();
					mc_laser();
				}
				blc_calc();
				blc_move();
				/*if(mc_num==0) {
					blc_calc();
					blc_move();
				} else if(mc_num==1) {
					atk_calc();
					atk_move();
				} else {
					dfc_calc();
					dfc_move();
				}*/
				bgm_main();
				c_o_main();
				stage_count++;
				break;
			case 2:
				graph_play();
				bgm_main();
				c_o_main();
				break;
			default:
				break;
		}
		sound_play();
		if(checkKey(KEY_INPUT_ESCAPE)==1) break;
		ScreenFlip();//裏画面反映
	}
	DxLib_End();
	return 0;
}