#include "GV.h"

//���@�I�����
void mc_select() {
	static int num=0;
	char name[256]="���@�̎�ނ�I��";
	int nx=50, ny=25;
	mc_explanation epl[3]={
		{180, 60, 300, 60, 300, 80, "�o�����X�^�C�v", "���ϓI�Ȑ퓬�@"},
		{200, 220, 300, 220, 300, 240, "�A�^�b�N�^�C�v", "�U���������A�h�䂪�Ⴂ"},
		{200, 380, 300, 380, 300, 400, "�f�B�t�F���X�^�C�v", "�h�䂪�����A�U�����Ⴂ"},
	};

	if(checkKey(KEY_INPUT_UP)==1 || checkKey(KEY_INPUT_F)==1) {//up�L�[�܂���f�L�[��������Ă����
		num=(num+2)%3;
		se_flag[0]=1;//���ʉ����I��
	} else if(checkKey(KEY_INPUT_DOWN)==1 ||checkKey(KEY_INPUT_A)==1) {//down�L�[�܂���a�L�[��������Ă����
		num=(num+1)%3;
		se_flag[0]=1;//���ʉ����I��
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
		//Enter�܂��̓X�y�[�X�L�[�������ꂽ��A��ʂ�؂�ւ���
		if(epl[i].ix==180 && (checkKey(KEY_INPUT_RETURN)==1 || 
						     checkKey(KEY_INPUT_SPACE)==1  ||
							 checkKey(KEY_INPUT_J)==1)) {
				se_flag[1]=1;//���ʉ����I��
				mc_num=i;//�����N�ԍ����i�[
				display_mode=4;//���̉�ʂɈڂ�
		}
	}

	//�L�����Z���{�^����������Ă�����
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//���ʉ����I��
		start_mode=0;
		display_mode=2;//�O�̉�ʂɖ߂�
		num=0;//�ŏ��̑I�����ɂ���
	}
}