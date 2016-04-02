#include "GV.h"

//�����G�t�F�N�g
void explosion_calc() {
	for(int i=0; i<EPS_MAX; i++) {
		if(eps[i].flag==1) eps[i].cnt++;
		if(eps[i].cnt%2==0) eps[i].index=eps[i].cnt%17;
		if(eps[i].index==16) eps[i].flag=0;
	}
}

//�{����ł����Ƃ��̔����G�t�F�N�g
void b_explosion_calc() {
	for(int i=0; i<EPS_MAX; i++) {
		if(b_eps[i].flag==1) b_eps[i].cnt++;
		if(b_eps[i].cnt%2==0) b_eps[i].index=b_eps[i].cnt%17;
		if(b_eps[i].index==16) b_eps[i].flag=0;
	}
}

//�`���[�W�G�t�F�N�g�̃����_����x���W��Ԃ�
int rang_x_place() {
	return GetRand(40)-20;
}

//�`���[�W�G�t�F�N�g�̃����_����y���W��Ԃ�
int rang_y_place() {
	return GetRand(20);
}

//�`���[�W�G�t�F�N�g�ƃ{�X�Ƃ̊p�x��Ԃ�
double chargeatan2(float x, float y) {
	double ang;
	ang=atan2(boss_shot_y_place(stage)-y, boss_shot_x_place(stage)-x);
	return ang;
}

//�`���[�W�������������ǂ������m�F����
int is_charge_end() {
	for(int i=0; i<CHARGE_MAX; i++) {
		if(charge[i].end_flag==0) return -1;
	}
	//�S�Ă�end_flag��1�Ȃ�`���[�W���������Ă���
	return 1;
}

//�`���[�W�G�t�F�N�g�̃t���O���m�F����
int is_charge_flag() {
	for(int i=0; i<CHARGE_MAX; i++) {
		if(charge[i].flag==0 && charge[i].end_flag==0) return i;
	}
	return -1;
}

//�r�[���`���[�W�G�t�F�N�g��o�^����
void beam_charge_regist(int i) {
	charge[i].flag=1;
	charge[i].x=boss_shot_x_place(stage)+(float)rang_x_place();
	charge[i].y=boss_shot_y_place(stage)+(float)rang_y_place();
	charge[i].ang=chargeatan2(charge[i].x, charge[i].y);
	charge[i].sp=2.5;
	charge[i].vx=charge[i].sp*cos((float)charge[i].ang);
	charge[i].vy=charge[i].sp*sin((float)charge[i].ang);
}

//�r�[���`���[�W
void beam_charge() {
	for(int i=0; i<CHARGE_MAX; i++) {
		//1�̃G�t�F�N�g�̃t���O���I���Ȃ�A�`���[�W���Ă���
		if(charge[i].end_flag==0) {
			if(charge[i].flag==1) {
				charge[i].x=boss_shot_x_place(stage)+boss[stage].vx+charge[i].vx;
				charge[i].y+=charge[i].vy;
				
				if(charge[i].y<=boss_shot_y_place(stage)) { //�{�X�̔��ˌ��Ƀ`���[�W������
					charge[i].flag=0;                       //�t���O���I�t�ɂ��A
					charge[i].end_flag=1;                   //�I���t���O���I���ɂ���
				}
			}
		}
	}
}

//�G�t�F�N�g���C��
void effect() {
	explosion_calc();
	b_explosion_calc();
	beam_charge();
}