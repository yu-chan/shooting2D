#include "GV.h"

//�s���p�^�[��0
//���E�ɓ���
void boss_pattern0(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	
	/*����ʒu�ɂ�����
	if(t==0)            regist_phy(540, Y_BOSS, 60);
	//���ɓ���
	if(t==25 || t==125) regist_phy(100, Y_BOSS, 120);
	//�E�ɓ���
	if(t==75)           regist_phy(540, Y_BOSS, 120);
	//�{�X�̒�ʒu�ɖ߂�
	if(t==175)          regist_phy(X_BOSS, Y_BOSS, 60);
	*/
	
	if(t==0) boss[i].vx=boss[i].sp;
	if(boss[i].x>=540) boss[i].vx=-boss[i].sp;
	if(boss[i].x<=100) boss[i].vx=boss[i].sp;
	
}

//�s���p�^�[��1
//�ҋ@
void boss_pattern1(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t==0) {
		regist_phy(X_BOSS, Y_BOSS, 100);
		boss[i].vx=0;
		boss[i].vy=0;
	}
}

//�s���p�^�[��2
//��ʒu�ɖ߂�
void boss_pattern2(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t==200) regist_phy(X_BOSS, Y_BOSS, 180);
}

//�s���p�^�[��3
//������
void boss_pattern3(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t>=0 && t<=100) boss[i].brt-=3;
}

//�s���p�^�[��4
//�����
void boss_pattern4(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t>=0 && t<=100) boss[i].brt+=3;
}

//�s���p�^�[��5
//�����Ɉړ�
void boss_pattern5(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t==0) regist_phy(320, 240, 60);
}

//�s���p�^�[��6
//�G���G��6�̐���
void boss_pattern6(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	int between=boss[i].mv_cnt[boss[i].mv_state]/6;
	if(t%between==0) {
	}
}

//�s���p�^�[��7
//
void boss_pattern7(int i) {
}

//�s���p�^�[��8
//
void boss_pattern8(int i) {
}

//�s���p�^�[��9
//
void boss_pattern9(int i) {
}

//�s���p�^�[��10
//
void boss_pattern10(int i) {
}

//�s���p�^�[��11
//
void boss_pattern11(int i) {
}