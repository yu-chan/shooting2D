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

void start_display() {
	if(start_mode==1) {
		if(start_select_mode==1) how_play();
		//else if(start_select_mode==2) mc_knd();
	} else {
		start();
	}
}