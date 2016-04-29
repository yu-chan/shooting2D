#include "GV.h"

//�摜�Ɖ��y��ǂݍ���
void load() {
	//�퓬�@�o�����X�^�C�v
	blc.img[0]=LoadGraph("�摜/���@/normal1.png");
	blc.img[1]=LoadGraph("�摜/���@/normal2.png");

	//�X�^�[�g��ʂ̔w�i�摜��ǂݍ���
	start_back=LoadGraph("�摜/�w�i/start_back.png");

	//�w�i�摜��ǂݍ���
	img_back[0]=LoadGraph("�摜/�w�i/stage0.png");
	img_back[1]=LoadGraph("�摜/�w�i/stage1.png");
	img_back[2]=LoadGraph("�摜/�w�i/stage2.png");
	img_back[3]=LoadGraph("�摜/�w�i/stage3.png");

	//�G�摜��ǂݍ���
	es0_img[0]=LoadGraph("�摜/�G/senkan00.png");
	es0_img[1]=LoadGraph("�摜/�G/senkan01.png");
	GetGraphSize(es0_img[0], &eny_xs[0], &eny_ys[0]);//�摜�̃T�C�Y�𓾂�
	es1_img[0]=LoadGraph("�摜/�G/senkan10.png");
	es1_img[1]=LoadGraph("�摜/�G/senkan11.png");
	GetGraphSize(es1_img[0], &eny_xs[1], &eny_ys[1]);
	es2_img[0]=LoadGraph("�摜/�G/senkan20.png");
	es2_img[1]=LoadGraph("�摜/�G/senkan21.png");
	GetGraphSize(es2_img[0], &eny_xs[2], &eny_ys[2]);
	es3_img[0]=LoadGraph("�摜/�G/senkan30.png");
	es3_img[1]=LoadGraph("�摜/�G/senkan31.png");
	GetGraphSize(es3_img[0], &eny_xs[3], &eny_ys[3]);
	LoadDivGraph("�摜/�G/dim_enemy0.png", 4, 1, 4, 64, 64, ed0_img);
	LoadDivGraph("�摜/�G/dim_enemy1.png", 4, 1, 4, 64, 64, ed1_img);
	LoadDivGraph("�摜/�G/dim_enemy2.png", 4, 1, 4, 64, 64, ed2_img);

	//�G�̃V���b�g��ǂݍ���
	LoadDivGraph("�摜/�e/enemy_shot.png", 4, 4, 1, 5, 7, eny_shot_img);

	//�����摜��ǂݍ���
	LoadDivGraph("�摜/�G�t�F�N�g/explosion.png", 16, 4, 4, 56, 56, eps_img);
	LoadDivGraph("�摜/�G�t�F�N�g/bom_explosion.png", 16, 4, 4, 225, 225, b_eps_img);

	//�r�[���̃`���[�W�G�t�F�N�g�摜��ǂݍ���
	img_charge=LoadGraph("�摜/�G�t�F�N�g/charge.png");

	//�r�[���̉摜��ǂݍ���
	img_beam=LoadGraph("�摜/�e/boss_beam0.png");

	//�T�E���h��ǂݍ���
	se[0]=LoadSoundMem("���y/SE/cursol0.wav");
	se[1]=LoadSoundMem("���y/SE/decision0.wav");
	se[2]=LoadSoundMem("���y/SE/cancel0.wav");
	se[3]=LoadSoundMem("���y/SE/mc_shot0.wav");
	se[4]=LoadSoundMem("���y/SE/mc_bom0.wav");
	se[5]=LoadSoundMem("���y/SE/mc_laser0.wav");
	se[6]=LoadSoundMem("���y/SE/s_recover.wav");
	se[7]=LoadSoundMem("���y/SE/g_recover.wav");
	se[8]=LoadSoundMem("���y/SE/full_recover.wav");
	se[9]=LoadSoundMem("���y/SE/explosion0.wav");
	se[10]=LoadSoundMem("���y/SE/item_get.wav");
	se[11]=LoadSoundMem("���y/SE/enemy_shot.wav");
	se[12]=LoadSoundMem("���y/SE/eny_shot_hit.wav");

	//���@�V���b�g�̉摜��ǂݍ���
	LoadDivGraph("�摜/�e/mc_shot.png", 3, 3, 1, 5, 7, mS);

	//���@�{���̉摜��ǂݍ���
	//LoadDivGraph("�摜/�e/mc_bom.png", 3, 3, 1, 14, 18, mB);

	//���@���[�U�[�̉摜��ǂݍ���
	LoadDivGraph("�摜/�e/mc_laser.png", 3, 3, 1, 5, 120, mL);

	//�{�X�̉摜��ǂݍ���
	boss_img[0]=LoadGraph("�摜/�{�X/boss0.png");

	//�Q�[���I�[�o�[�̉摜��ǂݍ���
	game_over_back=LoadGraph("�摜/�Q�[���I�[�o�[/GameOver_back.png");
	gameover=LoadGraph("�摜/�Q�[���I�[�o�[/GameOver.png");

	//�Q�[���N���A�[�̉摜��ǂݍ���
	gameclear=LoadGraph("�摜/�Q�[���N���A�[/GameClear.png");
}

void load_story_e0() {
	int n=0, num=0, fp;
	char fn_e0[32]={"�G���/�X�e�[�W0/story_e0.csv"};
	int input[64];
	char inputc[64];

	//�t�@�C���ǂݍ���
	if(stage==0)
		fp=FileRead_open(fn_e0);
	if(fp==NULL) return;

	//�t�@�C���̍ŏ��̂Q�s��ǂݔ�΂�
	for(int i=0; i<2; i++) while(FileRead_getc(fp)!='\n');

	while(1) {
		for(int i=0; i<64; i++) {
			inputc[i]=input[i]=FileRead_getc(fp);//�P�����擾����
			if(inputc[i]=='/') {//�X���b�V���������
				while(FileRead_getc(fp)!='\n');//���s�܂Ń��[�v
				i=-1;//�J�E���^���ŏ��ɖ߂�
				continue;
			}
			if(input[i]==',' || input[i]=='\n') {//�J���}�����s�Ȃ�
				inputc[i]='\0';//�����܂ł𕶎���Ƃ��ēǂݍ���
				break;
			}
			if(input[i]==EOF) return;//�t�@�C���̏I���Ȃ�I��
		}
		//���ꂼ��̃f�[�^���i�[
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
	FileRead_close(fp);//�t�@�C�������
}

//�G�̍s���p�^�[����ǂݍ���
void load_story() {
	load_story_e0();
}

//�{�X����ǂݍ���
void load_boss() {
	int n=stage, num=0, fp;
	char fn_boss0[32]={"�{�X���/�X�e�[�W0/boss0.csv"};
	int input[64];
	char inputc[64];

	//�t�@�C���ǂݍ���
	if(stage==0)
		fp=FileRead_open(fn_boss0);
	if(fp==NULL) return;

	//�t�@�C���̍ŏ��̂Q�s��ǂݔ�΂�
	for(int i=0; i<2; i++) while(FileRead_getc(fp)!='\n');

	while(1) {
		for(int i=0; i<64; i++) {
			inputc[i]=input[i]=FileRead_getc(fp);//�P�����擾����
			if(inputc[i]=='/') {//�X���b�V���������
				while(FileRead_getc(fp)!='\n');//���s�܂Ń��[�v
				i=-1;//�J�E���^���ŏ��ɖ߂�
				continue;
			}
			if(input[i]==',' || input[i]=='\n') {//�J���}�����s�Ȃ�
				inputc[i]='\0';//�����܂ł𕶎���Ƃ��ēǂݍ���
				break;
			}
			if(input[i]==EOF) return;//�t�@�C���̏I���Ȃ�I��
		}
		//���ꂼ��̃f�[�^���i�[
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
	FileRead_close(fp);//�t�@�C�������
}