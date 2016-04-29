#include "GV.h"

//スタート画面の背景画像を描画
void graph_start_back() {
	int i,j;
	int sizeX,sizeY;//画像のサイズ
	GetGraphSize(start_back, &sizeX, &sizeY);//画像のサイズを取得
	if(display_mode>=0 && display_mode<=1) {
		for(i=0; i<WND_WID; i+=sizeX) {
			for(j=0; j<WND_HET; j+=sizeY) {
				DrawGraph(i, j, start_back, FALSE);
			}
		}
	}
}

//自機の描画
void graph_mc() {
	if(mc_num==0)      DrawRotaGraphF(blc.x, blc.y, 1.0, 0.0, blc.img[blc.index], TRUE, FALSE);
}

//プレイ中の背景描画
void graph_play_back() {
	DrawGraph(0, 0, img_back[stage], FALSE);
}

//自機ショットの描画
void graph_mc_shot() {
	for(int i=0; i<MC_SHOT_MAX; i++)
		if(ms[i].flag>0) DrawRotaGraphF(ms[i].x, ms[i].y, 1.0, ms[i].naname, mS[0], TRUE, FALSE);
}

//自機レーザーの描画
void graph_mc_laser() {
	for(int i=0; i<MC_LASER_MAX; i++)
		if(ml[i].flag>0) DrawRotaGraphF(ml[i].x, ml[i].y, 1.0, 0.0, mL[0], TRUE, FALSE);
}

//敵の描画
void graph_enemy() {
	for(int i=0; i<ENEMY_MAX; i++)
		if(eny[i].flag==1) {
			if(eny[i].knd==0)      
				DrawRotaGraphF(eny[i].x, eny[i].y, 1.0, eny[i].naname, es0_img[eny[i].index], TRUE, FALSE);
			else if(eny[i].knd==1) 
				DrawRotaGraphF(eny[i].x, eny[i].y, 1.0, eny[i].naname, es1_img[eny[i].index], TRUE, FALSE);
			else if(eny[i].knd==2) 
				DrawRotaGraphF(eny[i].x, eny[i].y, 1.0, eny[i].naname, es2_img[eny[i].index], TRUE, FALSE);
			else if(eny[i].knd==3) 
				DrawRotaGraphF(eny[i].x, eny[i].y, 1.0, eny[i].naname, es3_img[eny[i].index], TRUE, FALSE);
			else if(eny[i].knd==4) 
				DrawRotaGraphF(eny[i].x, eny[i].y, 1.0, eny[i].naname, ed0_img[eny[i].index], TRUE, FALSE);
			else if(eny[i].knd==5) 
				DrawRotaGraphF(eny[i].x, eny[i].y, 1.0, eny[i].naname, ed1_img[eny[i].index], TRUE, FALSE);
			else                   
				DrawRotaGraphF(eny[i].x, eny[i].y, 1.0, eny[i].naname, ed2_img[eny[i].index], TRUE, FALSE);
		}
}

//敵ショットの描画
void graph_eny_shot() {
	for(int i=0; i<ENEMY_MAX; i++) {
		if(eny_shot[i].flag>0) {
			for(int j=0; j<ENY_SHOT_MAX; j++) {
				if(eny_shot[i].bullet[j].flag!=0) {
					//if(eny[i].knd>=0 && eny[i].knd<=2) 
						DrawRotaGraphF(eny_shot[i].bullet[j].x, eny_shot[i].bullet[j].y, 1.0,
										eny_shot[i].bullet[j].naname, eny_shot_img[0], TRUE, FALSE);
				}
			}
		}
	}
}

//爆発の描画
void graph_explosion() {
	for(int i=0; i<EPS_MAX; i++) {
		if(eps[i].flag==1)   
			DrawRotaGraphF(eps[i].x, eps[i].y, 1.0, 0.0, eps_img[eps[i].index], TRUE, FALSE);
		if(b_eps[i].flag==1) 
			DrawRotaGraphF(b_eps[i].x, b_eps[i].y, 1.0, 0.0, b_eps_img[b_eps[i].index], TRUE, FALSE);
	}
}

//ボスの描画
void graph_boss() {
	if(boss[stage].flag==1)
		DrawRotaGraphF(boss[stage].x, boss[stage].y, 1.0, 0.0, boss_img[stage], TRUE, FALSE);
}

//ボスの名前描画
void graph_boss_name() {
}

//ボスショットの描画
void graph_boss_shot() {
	if(boss_shot[stage].flag>0) {
		for(int i=0; i<BOSS_SHOT_MAX; i++) {
			if(boss_shot[stage].bullet[i].flag!=0) {
				DrawRotaGraphF(boss_shot[stage].bullet[i].x, boss_shot[stage].bullet[i].y, 1.0,
					boss_shot[stage].bullet[i].naname, eny_shot_img[0], TRUE, FALSE); 
			}
		}
	}
}

//ビームチャージの描画
void graph_beam_charge() {
	for(int i=0; i<CHARGE_MAX; i++) {
		if(charge[i].flag==1) {
			DrawRotaGraphF(charge[i].x, charge[i].y, 1.0, 0.0, img_charge, TRUE, FALSE);
		}
	}
}

//ボスビームの描画
void graph_boss_beam() {
	if(boss_beam[stage].flag>0) {
		for(int i=0; i<BOSS_BEAM_MAX; i++) {
			if(boss_beam[stage].bullet[i].flag!=0) {
				SetDrawBlendMode(DX_BLENDMODE_ADD, 50);
				DrawRotaGraphF(boss_beam[stage].bullet[i].x, boss_beam[stage].bullet[i].y, 1.0,
					boss_beam[stage].bullet[i].naname, img_beam, TRUE, FALSE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
	}
}

//ゲームクリアーの表示
void graph_clear() {
	if(g_clear.flag==1)
		DrawRotaGraphF(g_clear.x, g_clear.y, 1.0, 0.0, gameclear, TRUE, FALSE);
}

//ゲームオーバーの表示
void graph_over() {
	if(g_over.flag==1) {
		//DrawRotaGraphF(WND_WID/2, WND_HET/2, 1.0, 0.0, game_over_back, TRUE, FALSE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, g_over.brr);
		DrawRotaGraphF(g_over.x, g_over.y, 1.0, 0.0, gameover, TRUE, FALSE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawFormatString(75, 230, GetColor(255, 255, 255), "スペースキーまたはenterキーを押せば、もう一度プレイできます");
		DrawFormatString(75, 250, GetColor(255, 255, 255), "Escキーを押せば、ゲーム終了です");
	}
}

//プレイ中の全ての画像の描画
void graph_play() {
	if(display_mode==1) {
	graph_play_back();
	graph_mc_shot();
	graph_mc_laser();
	graph_mc();
	graph_eny_shot();
	graph_enemy();
	graph_explosion();
	graph_boss();
	graph_boss_shot();
	graph_beam_charge();
	graph_boss_beam();
	graph_clear();
	} else if(display_mode==2) {
	graph_over();
	}
}