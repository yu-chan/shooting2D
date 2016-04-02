#include "GV.h"

//��Փx�I�����
void rank_display() {
	static int num=0;
	rank_explanation exp[3]={
		{180, 60, "C�����N:��ԊȒP�ŃN���A���₷��"},
		{200, 220, "B�����N:��������Ȃ�"},
		{200, 380, "A�����N:��ԓ���Ȃ�"},
	};
	char name[256]="��Փx�I��";
	int nx=50, ny=25;

	if(checkKey(KEY_INPUT_UP)==1 || checkKey(KEY_INPUT_F)==1) {//up�L�[�܂���f�L�[��������Ă����
			num=(num+2)%3;
			se_flag[0]=1;//���ʉ����I��
		} else if(checkKey(KEY_INPUT_DOWN)==1 ||checkKey(KEY_INPUT_A)==1) {//down�L�[�܂���a�L�[��������Ă����
			num=(num+1)%3;
			se_flag[0]=1;//���ʉ����I��
	}

	for(int i=0; i<3; i++) {
			if(i==num) exp[i].x=180;
			else       exp[i].x=200;
	}

	//��Փx�`��
	for(int i=0; i<3; i++) {
			DrawFormatString(exp[i].x, exp[i].y, GetColor(255,255,255), exp[i].name);
			//Enter�܂��̓X�y�[�X�L�[�������ꂽ��A��ʂ�؂�ւ���
			if(exp[i].x==180 && (checkKey(KEY_INPUT_RETURN)==1 || 
								  checkKey(KEY_INPUT_SPACE)==1  ||
								  checkKey(KEY_INPUT_J)==1)) {
				se_flag[1]=1;//���ʉ����I��
				rank=i;//�����N�ԍ����i�[
				display_mode=3;//���̉�ʂɈڂ�
			}
	}

	//�L�����Z���{�^����������Ă�����
	if(checkKey(KEY_INPUT_K)==1 || checkKey(KEY_INPUT_B)==1) {
		se_flag[2]=1;//���ʉ����I��
		start_mode=0;
		display_mode=1;//�O�̉�ʂɖ߂�
		num=0;//�ŏ��̑I�����ɂ���
	}
}