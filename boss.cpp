#include "GV.h"

//�{�X�̍s���p�^�[���̊֐��錾
extern void boss_pattern0(int); extern void boss_pattern1(int); extern void boss_pattern2(int);
extern void boss_pattern3(int); extern void boss_pattern4(int); extern void boss_pattern5(int);
extern void boss_pattern6(int); extern void boss_pattern7(int); extern void boss_pattern8(int);
extern void boss_pattern9(int); extern void boss_pattern10(int); extern void boss_pattern11(int);

//�{�X�̍s���p�^�[���̔z��錾
void (*boss_act_pattern[BOSS_PATTERN_MAX])(int)={
	boss_pattern0, boss_pattern1, boss_pattern2,
	boss_pattern3, boss_pattern4, boss_pattern5,
	boss_pattern6, boss_pattern7, boss_pattern8,
	boss_pattern9, boss_pattern10, boss_pattern11,
};
//void regist_phy2(int t);
//�{�X�̏o�����Ԃ�������A�t���O�𗧂Ă�
void boss_flag() {
	if(boss_load[stage].cnt==stage_count) boss_load[stage].flag=1;
}
void regist_phy(float pos_x, float pos_y, int t);
//�{�X����o�^
void boss_regist() {
	if(boss_load[stage].cnt==stage_count) {
		boss[stage].flag=1;
		boss[stage].cnt=0;
		boss[stage].x=boss_load[stage].x;
		boss[stage].y=boss_load[stage].y;
		boss[stage].sp=boss_load[stage].sp;
		boss[stage].wait=boss_load[stage].wait;
		boss[stage].hp=boss_load[stage].hp;
		boss[stage].hp_max=boss[stage].hp;
		boss[stage].power=boss_load[stage].power;
		for(int i=0; i<BOSS_PATTERN_MAX; i++) {
			boss[stage].mv_ptn[i] =boss_load[stage].mv_ptn[i];
			boss[stage].mv_cnt[i] =boss_load[stage].mv_cnt[i];
			boss[stage].mv_cnt2[i]=0;
		}
		for(int i=0; i<BOSS_ATK_PATTERN_MAX; i++)
			boss[stage].atk_ptn[i]=boss_load[stage].atk_ptn[i];
		boss[stage].ang=PI/2;
		boss[stage].vx=0;
		boss[stage].vy=0;
		//�{�X���ォ��~��Ă���or��ʒu����o��
		boss[stage].mv_state=-1;
		regist_phy(X_BOSS, Y_BOSS, 120);
		//regist_phy2(25);
	}
}

//�e�����Z�b�g
void boss_shot_regist(int i) {
	memset(&boss_shot[i], 0, sizeof(boss_shot_info));
	boss_shot[i].flag=1;
	boss_shot[i].cnt=0;
}

//�r�[�����Z�b�g
void boss_beam_regist(int i) {
	memset(&charge, 0, sizeof(beam_charge_info)*CHARGE_MAX);
	memset(&boss_beam[i], 0, sizeof(boss_shot_info));
	boss_beam[i].flag=1;
	boss_beam[i].cnt=0;
}

//�{�X�̏o��
void boss_appear() {
}

//�����I�v�Z�������邽�߂ɁAphy�\���̂ɏ���o�^����֐�
//pos_x:�w��x���W, pos_y:�w��y���W, t:�w����W�܂łɂ�����w�莞��
void regist_phy(float pos_x, float pos_y, int t) {
	float ymax_x, ymax_y;
	if(t==0) t=1;
	boss[stage].phy.flag=1;//�����I�v�Z�̃I��
	boss[stage].phy.cnt=0;//�J�E���g������
	boss[stage].phy.set_t=t;//�ړ��ɂ����鎞�Ԃ��Z�b�g
	ymax_x=boss[stage].x-pos_x;//�ړ���������������
	boss[stage].phy.v0x=2*ymax_x/t;//���������̏����x
	boss[stage].phy.ax =2*ymax_x/(t*t);//���������̉����x
	boss[stage].phy.prex=boss[stage].x;//����x���W
	ymax_y=boss[stage].y-pos_y;//�ړ���������������
	boss[stage].phy.v0y=2*ymax_y/t;//���������̏����x
	boss[stage].phy.ay =2*ymax_y/(t*t);//���������̉����x
	boss[stage].phy.prey=boss[stage].y;//����y���W
}

void regist_phy2(int t) {
	float ymax_x, ymax_y;
	if(t==0) t=1;
	boss[stage].phy.flag=1;//�����I�v�Z�̃I��
	boss[stage].phy.cnt=0;//�J�E���g������
	boss[stage].phy.set_t=t;//�ړ��ɂ����鎞�Ԃ��Z�b�g
	ymax_x=boss[stage].x-X_BOSS;//�ړ���������������
	boss[stage].phy.v0x=2*ymax_x/t;//���������̏����x
	boss[stage].phy.ax =2*ymax_x/(t*t);//���������̉����x
	boss[stage].phy.prex=boss[stage].x;//����x���W
	ymax_y=boss[stage].y-Y_BOSS;//�ړ���������������
	boss[stage].phy.v0y=2*ymax_y/t;//���������̏����x
	boss[stage].phy.ay =2*ymax_y/(t*t);//���������̉����x
	boss[stage].phy.prey=boss[stage].y;//����y���W
}

//�����I�ړ��v�Z
void calc_phy() {
	double t=boss[stage].phy.cnt;
	//���݂���ׂ�x���W�v�Z
	boss[stage].x=boss[stage].phy.prex-(float)((boss[stage].phy.v0x*t)-0.5*boss[stage].phy.ax*t*t);
	//���݂���ׂ�y���W�v�Z
	boss[stage].y=boss[stage].phy.prey-(float)((boss[stage].phy.v0y*t)-0.5*boss[stage].phy.ay*t*t);
	boss[stage].phy.cnt++;
	if(boss[stage].phy.cnt>=boss[stage].phy.set_t) {//�ړ��ɂ����鎞�ԕ��ɂȂ�����I�t
		if(boss[stage].mv_state==-1) {
			boss[stage].mv_state=0;
			boss_shot_regist(stage);
			boss_beam_regist(stage);
		}
		boss[stage].phy.flag=0;
	}
}

//�{�X�̍s������
void boss_move() {
	if(boss[stage].flag==1) { //�t���O���I���ɂȂ��Ă���ԁA�o������

		if(boss[stage].mv_state!=-1) { //�{�X�̏o����̍s��
			boss_act_pattern[boss[stage].mv_ptn[boss[stage].mv_state]](stage);
			boss[stage].x+=boss[stage].vx;
			boss[stage].y+=boss[stage].vy;
			boss[stage].cnt++;
			boss[stage].mv_cnt2[boss[stage].mv_state]++;

			//boss[stage].mv_state�Ԗڂ̍s�����I�������A���̍s���ֈڂ�
			if(boss[stage].mv_cnt2[boss[stage].mv_state]==boss[stage].mv_cnt[boss[stage].mv_state]) {
				int mv_ptn;
				int atk_ptn;
				boss[stage].mv_cnt2[boss[stage].mv_state]=0;//�J�E���g��0�ɖ߂�
				boss[stage].mv_state++;//���̍s���Ɉڂ�
				mv_ptn=boss[stage].mv_ptn[boss[stage].mv_state];

				//�s���p�^�[�����ŏ��ɖ߂�(�s�����z������)
				if(mv_ptn==-1 || boss[stage].mv_state==BOSS_PATTERN_MAX) {
					boss[stage].mv_state=0;
				}

				atk_ptn=boss[stage].atk_ptn[boss[stage].mv_state];
				if(atk_ptn==2 || atk_ptn==7) {		 //�U���p�^�[�����r�[���Ȃ�
					boss_beam_regist(stage);		 //�r�[����o�^
				} else if(atk_ptn!=2 && atk_ptn!=7){ //����ȊO�Ȃ�
					boss_shot_regist(stage);		 //�V���b�g��o�^
				}

				//�{�X��HP��0�ȉ��ɂȂ��������
				if(boss[stage].hp<=0) boss[stage].flag=0;
			}
		}

		//�����v�Z
		if(boss[stage].phy.flag==1) calc_phy();
	}
}

//�{�X�̃��C������
void boss_main() {
	boss_flag();
	boss_regist();
	boss_move();
	//if(boss[stage].cnt==0 && boss[stage].mv_state==-1) regist_phy(X_BOSS, Y_BOSS, 25);
	//if(boss[stage].cnt==0) regist_phy2(25);
	//if(boss[stage].phy.flag==1) calc_phy();
}