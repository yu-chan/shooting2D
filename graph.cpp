#include "GV.h"

//�X�^�[�g��ʂ̔w�i�摜��`��
void graph_start_back() {
	int i,j;
	int sizeX,sizeY;//�摜�̃T�C�Y
	GetGraphSize(start_back, &sizeX, &sizeY);//�摜�̃T�C�Y���擾
	if(display_mode>=0 && display_mode<=1) {
		for(i=0; i<WND_WID; i+=sizeX) {
			for(j=0; j<WND_HET; j+=sizeY) {
				DrawGraph(i, j, start_back, FALSE);
			}
		}
	}
}

//�X�e�[�W�I��p�摜��`��
void graph_select_stage() {
	static int num=0;
	int sx[BACK_MAX]={32, 192, 352, 512};
	int sy[BACK_MAX]={292, 312, 312, 312};
	char name[256]="�X�e�[�W�I��";
	int nx=50, ny=25;
	int bx=192, by=50;

	if(checkKey(KEY_INPUT_LEFT)==1 || checkKey(KEY_INPUT_S)==1) {//left�L�[�܂���s�L�[��������Ă����
		num=(num+BACK_MAX-1)%BACK_MAX;
		se_flag[0]=1;//���ʉ����I��
	} else if(checkKey(KEY_INPUT_RIGHT)==1 ||checkKey(KEY_INPUT_D)==1) {//right�L�[�܂���d�L�[��������Ă����
		num=(num+1)%BACK_MAX;
		se_flag[0]=1;//���ʉ����I��
	}

	for(int i=0; i<BACK_MAX; i++) {
		if(i==num) sy[i]=292;
		else       sy[i]=312;
	}

	DrawFormatString(nx, ny, GetColor(255,255,255), name);
	for(int i=0; i<BACK_MAX; i++) {
		if(i==num) DrawGraph(bx, by, b_back_select[i], FALSE);
		DrawGraph(sx[i], sy[i], s_back_select[i], FALSE);
		if(sy[i]==292 && (checkKey(KEY_INPUT_RETURN)==1 || 
								  checkKey(KEY_INPUT_SPACE)==1  ||
								  checkKey(KEY_INPUT_J)==1)) {
			se_flag[1]=1;//���ʉ����I��
			stage=i;//�X�e�[�W�ԍ����i�[
			display_mode=2;//���̉�ʂֈڂ�
		}
	}

	//�L�����Z���{�^����������Ă�����
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//���ʉ����I��
		start_mode=0;
		display_mode=0;//�O�̉�ʂɈڂ�
		num=0;//�ŏ��̑I�����ɂ���
	}
}

//���@�̕`��
void graph_mc() {
	if(mc_num==0)      DrawRotaGraphF(blc.x, blc.y, 1.0, 0.0, blc.img[blc.index], TRUE, FALSE);
	else if(mc_num==1) DrawRotaGraphF(atk.x, atk.y, 1.0, 0.0, atk.img[atk.index], TRUE, FALSE);
	else               DrawRotaGraphF(dfc.x, dfc.y, 1.0, 0.0, dfc.img[dfc.index], TRUE, FALSE);
}

//�v���C���̔w�i�`��
void graph_play_back() {
	DrawGraph(0, 0, img_back[stage], FALSE);
}

//���@�V���b�g�̕`��
void graph_mc_shot() {
	for(int i=0; i<MC_SHOT_MAX; i++)
		if(ms[i].flag>0) DrawRotaGraphF(ms[i].x, ms[i].y, 1.0, ms[i].naname, mS[0], TRUE, FALSE);
}

//���@�{���̕`��
void graph_mc_bom() {
	for(int i=0; i<MC_BOM_MAX; i++)
		if(mb[i].flag>0) DrawRotaGraphF(mb[i].x, mb[i].y, 1.0, 0.0, mB[0], TRUE, FALSE);
}

//���@���[�U�[�̕`��
void graph_mc_laser() {
	for(int i=0; i<MC_LASER_MAX; i++)
		if(ml[i].flag>0) DrawRotaGraphF(ml[i].x, ml[i].y, 1.0, 0.0, mL[0], TRUE, FALSE);
}

//�X�e�[�W�^�C�g���̕`��
void graph_stage_title() {
	if(st_ti[stage].flag>0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, st_ti[stage].brt);
		DrawGraph(30, 50, st_ti[stage].img, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

//�G�̕`��
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

//�G�V���b�g�̕`��
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

//�����̕`��
void graph_explosion() {
	for(int i=0; i<EPS_MAX; i++) {
		if(eps[i].flag==1)   
			DrawRotaGraphF(eps[i].x, eps[i].y, 1.0, 0.0, eps_img[eps[i].index], TRUE, FALSE);
		if(b_eps[i].flag==1) 
			DrawRotaGraphF(b_eps[i].x, b_eps[i].y, 1.0, 0.0, b_eps_img[b_eps[i].index], TRUE, FALSE);
	}
}

//�A�C�e���̕`��
void graph_item() {
	for(int i=0; i<ITEM_MAX; i++)
		if(item[i].flag==1)
			DrawRotaGraphF(item[i].x, item[i].y, 1.0, 0.0, item_img[item[i].knd], TRUE, FALSE);
}

//�X�R�A�̕\��
void graph_score() {
	DrawGraph(0, 461, score_img[score[rank][stage]/100], TRUE);
	DrawGraph(20, 461, score_img[(score[rank][stage]%100)/10],TRUE);
	DrawGraph(40, 461, score_img[score[rank][stage]%10], TRUE);
}

//�{�X�̕`��
void graph_boss() {
	if(boss[stage].flag==1)
		DrawRotaGraphF(boss[stage].x, boss[stage].y, 1.0, 0.0, boss_img[stage], TRUE, FALSE);
}

//�{�X�̖��O�`��
void graph_boss_name() {
}

//�{�X�V���b�g�̕`��
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

//�r�[���`���[�W�̕`��
void graph_beam_charge() {
	for(int i=0; i<CHARGE_MAX; i++) {
		if(charge[i].flag==1) {
			DrawRotaGraphF(charge[i].x, charge[i].y, 1.0, 0.0, img_charge, TRUE, FALSE);
		}
	}
}

//�{�X�r�[���̕`��
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

//�Q�[���N���A�[�̕\��
void graph_clear() {
	if(g_clear.flag==1)
		DrawRotaGraphF(g_clear.x, g_clear.y, 1.0, 0.0, gameclear, TRUE, FALSE);
}

//�Q�[���I�[�o�[�̕\��
void graph_over() {
	if(g_over.flag==1) {
		//DrawRotaGraphF(WND_WID/2, WND_HET/2, 1.0, 0.0, game_over_back, TRUE, FALSE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, g_over.brr);
		DrawRotaGraphF(g_over.x, g_over.y, 1.0, 0.0, gameover, TRUE, FALSE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawFormatString(75, 230, GetColor(255, 255, 255), "�X�y�[�X�L�[�܂���enter�L�[�������΁A������x�v���C�ł��܂�");
		DrawFormatString(75, 250, GetColor(255, 255, 255), "Esc�L�[�������΁A�Q�[���I���ł�");
	}
}

//�v���C���̑S�Ẳ摜�̕`��
void graph_play() {
	if(display_mode==1) {
	graph_play_back();
	//graph_item();
	graph_mc_shot();
	graph_mc_bom();
	graph_mc_laser();
	graph_mc();
	graph_stage_title();
	graph_eny_shot();
	graph_enemy();
	graph_explosion();
	//graph_score();
	graph_boss();
	//graph_boss_name();
	graph_boss_shot();
	graph_beam_charge();
	graph_boss_beam();
	graph_clear();
	} else if(display_mode==2) {
	graph_over();
	}
}