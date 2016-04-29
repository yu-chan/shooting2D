#include "GV.h"

//�X�^�[�g��ʂ̃��j���[
int start() {
	if(start_mode==0) {
		static int num=0;
		sMenu sm[SM_MAX]={
			{80,100,"Play"},
			{100,150,"������@"},
			{100,200,"exit"},
		};
		if(checkKey(KEY_INPUT_UP)==1 || checkKey(KEY_INPUT_F)==1) {//up�L�[�܂���f�L�[��������Ă����
			num=(num+SM_MAX-1)%SM_MAX;
			se_flag[0]=1;//���ʉ����I��
		} else if(checkKey(KEY_INPUT_DOWN)==1 ||checkKey(KEY_INPUT_A)==1) {//down�L�[�܂���a�L�[��������Ă����
			num=(num+1)%SM_MAX;
			se_flag[0]=1;//���ʉ����I��
		}

		for(int i=0; i<SM_MAX; i++) {
			if(i==num) sm[i].x=80;
			else       sm[i].x=100;
		}

		//���j���[�`��
		for(int i=0; i<SM_MAX; i++) {
			DrawFormatString(sm[i].x, sm[i].y, GetColor(255,255,255), sm[i].name);
			//Enter�܂��̓X�y�[�X�L�[�������ꂽ��A��ʂ�؂�ւ���
			if(sm[i].x==80 && (checkKey(KEY_INPUT_RETURN)==1 || 
								  checkKey(KEY_INPUT_SPACE)==1  ||
								  checkKey(KEY_INPUT_J)==1)) {
				se_flag[1]=1;//���ʉ����I��
				start_mode=1;//��ʂ̐؂�ւ�
				start_select_mode=i;//�X�^�[�g��ʂ̐؂�ւ�
				if(i==0) display_mode=1;
			}
		}
	}
	return 0;
}

//������@�����
void how_play() {
	play_explanation epl[7]={
		{100, 40, "���L�[�Ef�L�[ : ��Ɉړ�"},
		{100, 100, "���L�[�Ea�L�[ : ���Ɉړ�"},
		{100, 160, "���L�[�Ed�L�[ : �E�Ɉړ�"},
		{100, 220, "���L�[�Es�L�[ : ���Ɉړ�"},
		{100, 280, "Enter�L�[�ESpace�L�[�Ej�L�[ : ����A�V���b�g"},
		{100, 340, "k�L�[�Eb�L�[ : �L�����Z���A�߂�"},
		{100, 400, "l�L�[�Ev�L�[ : ���[�U�["},
	};

	//������`��
	for(int i=0; i<7; i++) DrawFormatString(epl[i].x, epl[i].y, GetColor(255,255,255), epl[i].sentence);

	//�L�����Z���{�^���������ꂽ��A���̃X�^�[�g��ʂɖ߂�
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//���ʉ����I��
		start_mode=0;
	}
}

//���@�̎�ނ����
/*
void mc_knd() {
	mc_explanation epl[3]={
		{200, 60, 300, 60, 300, 80, "�o�����X�^�C�v", "���ϓI�Ȑ퓬�@"},
		{200, 220, 300, 220, 300, 240, "�A�^�b�N�^�C�v", "�U���������A�h�䂪�Ⴂ"},
		{200, 380, 300, 380, 300, 400, "�f�B�t�F���X�^�C�v", "�h�䂪�����A�U�����Ⴂ"},
	};
	//�o�����X�^�C�v�̐���
	DrawFormatString(epl[0].nx, epl[0].ny, GetColor(255,255,255), epl[0].name);
	DrawGraph(epl[0].ix, epl[0].iy, blc.img[0], TRUE);
	DrawFormatString(epl[0].sx, epl[0].sy, GetColor(255,255,255), epl[0].sentence);
	//�A�^�b�N�^�C�v�̐���
	DrawFormatString(epl[1].nx, epl[1].ny, GetColor(255,255,255), epl[1].name);
	DrawGraph(epl[1].ix, epl[1].iy, atk.img[0], TRUE);
	DrawFormatString(epl[1].sx, epl[1].sy, GetColor(255,255,255), epl[1].sentence);
	//�f�B�t�F���X�^�C�v�̐���
	DrawFormatString(epl[2].nx, epl[2].ny, GetColor(255,255,255), epl[2].name);
	DrawGraph(epl[2].ix, epl[2].iy, dfc.img[0], TRUE);
	DrawFormatString(epl[2].sx, epl[2].sy, GetColor(255,255,255), epl[2].sentence);

	//�L�����Z���{�^���������ꂽ��A���̃X�^�[�g��ʂɖ߂�
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//���ʉ����I��
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