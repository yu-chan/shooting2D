#include "GV.h"

//�A�^�b�N�^�C�v�̌v�Z
//void atk_calc() {
//	atk.cnt++;
//	if(atk.cnt%5==0) atk.index=atk.cnt%2;
//}

//�ړ�����
	/*
void atk_move() {
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
			atk.x+=sp_x[i]/naname; atk.y+=sp_y[i]/naname;
			//���@����ʊO�ɔz�u����Ȃ��悤�ɂ���
			if(atk.y<HET_MIN) atk.y=HET_MIN;
			if(atk.y>HET_MAX) atk.y=HET_MAX;
			if(atk.x<WID_MIN) atk.x=WID_MIN;
			if(atk.x>WID_MAX) atk.x=WID_MAX;
		}
	}
}*/