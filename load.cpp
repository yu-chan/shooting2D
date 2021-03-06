#include "GV.h"

//画像と音楽を読み込む
void load() {
	//戦闘機バランスタイプ
	blc.img[0]=LoadGraph("画像/自機/normal1.png");
	blc.img[1]=LoadGraph("画像/自機/normal2.png");

	//スタート画面の背景画像を読み込む
	start_back=LoadGraph("画像/背景/start_back.png");

	//背景画像を読み込む
	img_back[0]=LoadGraph("画像/背景/stage0.png");

	//敵画像を読み込む
	es0_img[0]=LoadGraph("画像/敵/senkan00.png");
	es0_img[1]=LoadGraph("画像/敵/senkan01.png");
	GetGraphSize(es0_img[0], &eny_xs[0], &eny_ys[0]);//画像のサイズを得る
	es1_img[0]=LoadGraph("画像/敵/senkan10.png");
	es1_img[1]=LoadGraph("画像/敵/senkan11.png");
	GetGraphSize(es1_img[0], &eny_xs[1], &eny_ys[1]);
	es2_img[0]=LoadGraph("画像/敵/senkan20.png");
	es2_img[1]=LoadGraph("画像/敵/senkan21.png");
	GetGraphSize(es2_img[0], &eny_xs[2], &eny_ys[2]);
	es3_img[0]=LoadGraph("画像/敵/senkan30.png");
	es3_img[1]=LoadGraph("画像/敵/senkan31.png");
	GetGraphSize(es3_img[0], &eny_xs[3], &eny_ys[3]);

	//敵のショットを読み込む
	LoadDivGraph("画像/弾/enemy_shot.png", 4, 4, 1, 5, 7, eny_shot_img);

	//爆発画像を読み込む
	LoadDivGraph("画像/エフェクト/explosion.png", 16, 4, 4, 56, 56, eps_img);

	//ビームのチャージエフェクト画像を読み込む
	img_charge=LoadGraph("画像/エフェクト/charge.png");

	//ビームの画像を読み込む
	img_beam=LoadGraph("画像/弾/boss_beam0.png");

	//サウンドを読み込む
	se[0]=LoadSoundMem("音楽/SE/cursol0.wav");
	se[1]=LoadSoundMem("音楽/SE/decision0.wav");
	se[2]=LoadSoundMem("音楽/SE/cancel0.wav");
	se[3]=LoadSoundMem("音楽/SE/mc_shot0.wav");
	se[4]=LoadSoundMem("音楽/SE/mc_bom0.wav");
	se[5]=LoadSoundMem("音楽/SE/mc_laser0.wav");
	se[6]=LoadSoundMem("音楽/SE/s_recover.wav");
	se[7]=LoadSoundMem("音楽/SE/g_recover.wav");
	se[8]=LoadSoundMem("音楽/SE/full_recover.wav");
	se[9]=LoadSoundMem("音楽/SE/explosion0.wav");
	se[10]=LoadSoundMem("音楽/SE/item_get.wav");
	se[11]=LoadSoundMem("音楽/SE/enemy_shot.wav");
	se[12]=LoadSoundMem("音楽/SE/eny_shot_hit.wav");

	//自機ショットの画像を読み込む
	LoadDivGraph("画像/弾/mc_shot.png", 3, 3, 1, 5, 7, mS);

	//自機ボムの画像を読み込む
	//LoadDivGraph("画像/弾/mc_bom.png", 3, 3, 1, 14, 18, mB);

	//自機レーザーの画像を読み込む
	LoadDivGraph("画像/弾/mc_laser.png", 3, 3, 1, 5, 120, mL);

	//ボスの画像を読み込む
	boss_img[0]=LoadGraph("画像/ボス/boss0.png");

	//ゲームオーバーの画像を読み込む
	game_over_back=LoadGraph("画像/ゲームオーバー/GameOver_back.png");
	gameover=LoadGraph("画像/ゲームオーバー/GameOver.png");

	//ゲームクリアーの画像を読み込む
	gameclear=LoadGraph("画像/ゲームクリアー/GameClear.png");
}

void load_story_e0() {
	int n=0, num=0, fp;
	char fn_e0[32]={"敵情報/ステージ0/story_e0.csv"};
	int input[64];
	char inputc[64];

	//ファイル読み込み
	if(stage==0)
		fp=FileRead_open(fn_e0);
	if(fp==NULL) return;

	//ファイルの最初の２行を読み飛ばす
	for(int i=0; i<2; i++) while(FileRead_getc(fp)!='\n');

	while(1) {
		for(int i=0; i<64; i++) {
			inputc[i]=input[i]=FileRead_getc(fp);//１文字取得する
			if(inputc[i]=='/') {//スラッシュがあれば
				while(FileRead_getc(fp)!='\n');//改行までループ
				i=-1;//カウンタを最初に戻す
				continue;
			}
			if(input[i]==',' || input[i]=='\n') {//カンマか改行なら
				inputc[i]='\0';//そこまでを文字列として読み込む
				break;
			}
			if(input[i]==EOF) return;//ファイルの終わりなら終了
		}
		//それぞれのデータを格納
		switch(num) {
			case 0:  eny_info[n].cnt        =atoi(inputc);        break;
			case 1:  eny_info[n].mv_ptn     =atoi(inputc);        break;
			case 2:  eny_info[n].knd        =atoi(inputc);        break;
			case 3:  eny_info[n].x          =(float)atof(inputc); break;
			case 4:  eny_info[n].y          =(float)atof(inputc); break;
			case 5:  eny_info[n].sp         =(float)atof(inputc); break;
			case 6:  eny_info[n].bltime     =atoi(inputc);        break;
			case 7:  eny_info[n].wait       =atoi(inputc);        break;
			case 8:  eny_info[n].hp         =atoi(inputc);        break;
			case 9:  eny_info[n].power      =atoi(inputc);        break;
			case 10: eny_info[n].item_knd[0]=atoi(inputc);        break;
			case 11: eny_info[n].item_knd[1]=atoi(inputc);        break;
			case 12: eny_info[n].item_knd[2]=atoi(inputc);        break;
			case 13: eny_info[n].item_knd[3]=atoi(inputc);        break;
			case 14: eny_info[n].item_knd[4]=atoi(inputc);        break;
			case 15: eny_info[n].item_knd[5]=atoi(inputc);        break;
			case 16: eny_info[n].item_knd[6]=atoi(inputc);        break;
			case 17: eny_info[n].bul_knd    =atoi(inputc);        break;
			case 18: eny_info[n].bul_ptn    =atoi(inputc);        break;
			default:                                              break;
		}
		num++;
		if(num==19) { num=0; n++; }
	}
	FileRead_close(fp);//ファイルを閉じる
}

//敵の行動パターンを読み込む
void load_story() {
	load_story_e0();
}

//ボス情報を読み込む
void load_boss() {
	int n=stage, num=0, fp;
	char fn_boss0[32]={"ボス情報/ステージ0/boss0.csv"};
	int input[64];
	char inputc[64];

	//ファイル読み込み
	if(stage==0)
		fp=FileRead_open(fn_boss0);
	if(fp==NULL) return;

	//ファイルの最初の２行を読み飛ばす
	for(int i=0; i<2; i++) while(FileRead_getc(fp)!='\n');

	while(1) {
		for(int i=0; i<64; i++) {
			inputc[i]=input[i]=FileRead_getc(fp);//１文字取得する
			if(inputc[i]=='/') {//スラッシュがあれば
				while(FileRead_getc(fp)!='\n');//改行までループ
				i=-1;//カウンタを最初に戻す
				continue;
			}
			if(input[i]==',' || input[i]=='\n') {//カンマか改行なら
				inputc[i]='\0';//そこまでを文字列として読み込む
				break;
			}
			if(input[i]==EOF) return;//ファイルの終わりなら終了
		}
		//それぞれのデータを格納
		switch(num) {
			case 0:  boss_load[n].cnt       =       atoi(inputc); break;
			case 1:  boss_load[n].x         =(float)atof(inputc); break;
			case 2:  boss_load[n].y         =(float)atof(inputc); break;
			case 3:  boss_load[n].sp        =(float)atof(inputc); break;
			case 4:  boss_load[n].wait      =       atoi(inputc); break;
			case 5:  boss_load[n].hp        =		atoi(inputc); break;
			case 6:  boss_load[n].power     =		atoi(inputc); break;
			case 7:  boss_load[n].mv_ptn[0] =		atoi(inputc); break;
			case 8:  boss_load[n].mv_ptn[1] =		atoi(inputc); break;
			case 9:  boss_load[n].mv_ptn[2] =		atoi(inputc); break;
			case 10: boss_load[n].mv_ptn[3] =		atoi(inputc); break;
			case 11: boss_load[n].mv_ptn[4] =		atoi(inputc); break;
			case 12: boss_load[n].mv_ptn[5] =		atoi(inputc); break;
			case 13: boss_load[n].mv_ptn[6] =		atoi(inputc); break;
			case 14: boss_load[n].mv_ptn[7] =		atoi(inputc); break;
			case 15: boss_load[n].mv_ptn[8] =		atoi(inputc); break;
			case 16: boss_load[n].mv_ptn[9] =		atoi(inputc); break;
			case 17: boss_load[n].mv_ptn[10]=		atoi(inputc); break;
			case 18: boss_load[n].mv_ptn[11]=		atoi(inputc); break;
			case 19: boss_load[n].mv_cnt[0] =		atoi(inputc); break;
			case 20: boss_load[n].mv_cnt[1] =		atoi(inputc); break;
			case 21: boss_load[n].mv_cnt[2] =		atoi(inputc); break;
			case 22: boss_load[n].mv_cnt[3] =		atoi(inputc); break;
			case 23: boss_load[n].mv_cnt[4] =		atoi(inputc); break;
			case 24: boss_load[n].mv_cnt[5] =		atoi(inputc); break;
			case 25: boss_load[n].mv_cnt[6] =		atoi(inputc); break;
			case 26: boss_load[n].mv_cnt[7] =		atoi(inputc); break;
			case 27: boss_load[n].mv_cnt[8] =		atoi(inputc); break;
			case 28: boss_load[n].mv_cnt[9] =		atoi(inputc); break;
			case 29: boss_load[n].mv_cnt[10]=		atoi(inputc); break;
			case 30: boss_load[n].mv_cnt[11]=		atoi(inputc); break;
			case 31: boss_load[n].atk_ptn[0]=		atoi(inputc); break;
			case 32: boss_load[n].atk_ptn[1]=		atoi(inputc); break;
			case 33: boss_load[n].atk_ptn[2]=		atoi(inputc); break;
			case 34: boss_load[n].atk_ptn[3]=		atoi(inputc); break;
			case 35: boss_load[n].atk_ptn[4]=		atoi(inputc); break;
			case 36: boss_load[n].atk_ptn[5]=		atoi(inputc); break;
			case 37: boss_load[n].atk_ptn[6]=		atoi(inputc); break;
			case 38: boss_load[n].atk_ptn[7]=		atoi(inputc); break;
			case 39: boss_load[n].atk_ptn[8]=		atoi(inputc); break;
			case 40: boss_load[n].atk_ptn[9]=		atoi(inputc); break;
			case 41: boss_load[n].atk_ptn[10]=		atoi(inputc); break;
			case 42: boss_load[n].atk_ptn[11]=		atoi(inputc); break;
			default:                                              break;
		}
		num++;
	}
	FileRead_close(fp);//ファイルを閉じる
}