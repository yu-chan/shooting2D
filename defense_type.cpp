#include "GV.h"

//�f�B�t�F���X�^�C�v�̌v�Z
void dfc_calc() {
	dfc.cnt++;
	if(dfc.cnt%5==0) dfc.index=dfc.cnt%2;
}

//�ړ�����
void dfc_move() {
	float naname=1;
	int ud_flag=0, rl_flag=0;
	//x,y���W�̃X�s�[�h{��,��,�E,��}
	float sp_x[4]={0, 0, 4.0, -4.0}, sp_y[4]={-4.0, 4.0, 0, 0};
	unsigned char allow_key[4]={KEY_INPUT_UP,
								KEY_INPUT_DOWN,
								KEY_INPUT_RIGHT,
								KEY_INPUT_LEFT};
	unsigned char char_key[4]={KEY_INPUT_F,
							   KEY_INPUT_A,
							   KEY_INPUT_D,
							   KEY_INPUT_S};

	for(int i=0; i<2; i++)//�㉺�L�[�܂���f�Ea���[��������Ă���Ȃ�A�t���O�𗧂Ă�
		if(checkKey(allow_key[i])>0 || checkKey(char_key[i])>0) ud_flag=1;

	for(int i=2; i<4; i++)//���E�L�[�܂���d�Es�L�[��������Ă���Ȃ�A�t���O�𗧂Ă�
		if(checkKey(allow_key[i])>0 || checkKey(char_key[i])>0) rl_flag=1;

	//�΂߂̓��͂�����Έړ��X�s�[�h�����[�g�Q�Ŋ���
	if(ud_flag==1 && rl_flag==1) naname=(float)sqrt(2.0);
	
	//���͂̉ۂňړ�����
	for(int i=0; i<4; i++) {
		//i�����L�[�����͂���Ă���Ȃ�
		if(checkKey(allow_key[i])>0 || checkKey(char_key[i])>0) {
			dfc.x+=sp_x[i]/naname; dfc.y+=sp_y[i]/naname;
			//���@����ʊO�ɔz�u����Ȃ��悤�ɂ���
			if(dfc.y<HET_MIN) dfc.y=HET_MIN;
			if(dfc.y>HET_MAX) dfc.y=HET_MAX;
			if(dfc.x<WID_MIN) dfc.x=WID_MIN;
			if(dfc.x>WID_MAX) dfc.x=WID_MAX;
		}
	}
}