#include "GV.h"

//�{�X�̍U���p�^�[���̊֐��錾
extern void boss_atk0(int); extern void boss_atk1(int); extern void boss_atk2(int);
extern void boss_atk3(int); extern void boss_atk4(int); extern void boss_atk5(int);
extern void boss_atk6(int); extern void boss_atk7(int);

//�{�X�̍U���p�^�[���̔z��錾
void (*boss_atk_pattern[BOSS_ATK_PATTERN_MAX])(int)={
	boss_atk0, boss_atk1, boss_atk2,
	boss_atk3, boss_atk4, boss_atk5,
	boss_atk6, boss_atk7,
};

//�{�X�Ǝ��@�Ƃ̊p�x��Ԃ�
double bossatan2(float x, float y) {
	double ang;

	if(mc_num==0)
		ang=atan2(blc.y-y, blc.x-x);
	/*else if(mc_num==1)
		ang=atan2(atk.y-y, atk.x-x);
	else
		ang=atan2(dfc.y-y, dfc.x-x);*/

	return ang;
}

//�V���b�g�̃t���O���m�F����
int is_boss_shot_flag(int i) {
	for(int j=0; j<BOSS_SHOT_MAX; j++)
		if(boss_shot[i].bullet[j].flag==0) return j;
	return -1;
}

//�r�[���̃t���O���m�F����
int is_boss_beam_flag(int i) {
	for(int j=0; j<BOSS_BEAM_MAX; j++)
		if(boss_beam[i].bullet[j].flag==0) return j;
	return -1;
}

//�q�b�g�������ǂ������ׂ�
int is_mc_hit2(int j) {
	float r=10.0f;
	float x, y;
	if(mc_num==0) {
		x=boss_shot[stage].bullet[j].x-blc.x;
		y=boss_shot[stage].bullet[j].y-blc.y;
		if(x * x + y * y < r * r)
			return 1;
	} /*else if(mc_num==1) {
		x=boss_shot[stage].bullet[j].x-atk.x;
		y=boss_shot[stage].bullet[j].y-atk.y;
		if(x * x + y * y < r * r)
			return 1;
	} else {
		x=boss_shot[stage].bullet[j].x-dfc.x;
		y=boss_shot[stage].bullet[j].y-dfc.y;
		if(x * x + y * y < r * r)
			return 1;
	}*/
	return 0;
}

//�r�[�����q�b�g�������ǂ������ׂ�
int is_mc_hit3(int j) {
	float r=20.0f;
	float x, y;
	if(mc_num==0) {
		x=boss_beam[stage].bullet[j].x-blc.x;
		y=boss_beam[stage].bullet[j].y-blc.y;
		if(x * x + y * y < r * r)
			return 1;
	} /*else if(mc_num==1) {
		x=boss_beam[stage].bullet[j].x-atk.x;
		y=boss_beam[stage].bullet[j].y-atk.y;
		if(x * x + y * y < r * r)
			return 1;
	} else {
		x=boss_beam[stage].bullet[j].x-dfc.x;
		y=boss_beam[stage].bullet[j].y-dfc.y;
		if(x * x + y * y < r * r)
			return 1;
	}*/
	return 0;
}

//�e�̈ړ��v�Z
void boss_shot_calc(int i) {
	//�{�X���|����Ă�����A�V���b�g��o�^���Ȃ��t���O�ɂ���
	if(boss[i].flag!=1) boss_shot[i].flag=2;

	for(int j=0; j<BOSS_SHOT_MAX; j++) {
		//�e�̃t���O���I���Ȃ�A�e�����v�Z����
		if(boss_shot[i].bullet[j].flag>0) {
			boss_shot[i].bullet[j].x+=boss_shot[i].bullet[j].vx;
			boss_shot[i].bullet[j].y+=boss_shot[i].bullet[j].vy;
			boss_shot[i].bullet[j].cnt++;
			//��ʊO�Ȃ����
			if(boss_shot[i].bullet[j].x<-20 || boss_shot[i].bullet[j].x>WND_WID+20 ||
				boss_shot[i].bullet[j].y<-20 || boss_shot[i].bullet[j].y>WND_HET+20)
				boss_shot[i].bullet[j].flag=0;//�t���O���I�t�ɂ���
			//���@�ɓ������������
			if(is_mc_hit2(j)==1) {
				se_flag[12]=1;
				boss_shot[i].bullet[j].flag=0;
				if(mc_num==0)      blc.hp-=boss[i].power;
				//else if(mc_num==1) atk.hp-=boss[i].power;
				//else               dfc.hp-=boss[i].power;
				if(blc.hp<=0) {
					over_regist();
					display_mode++;
				}
			}
		}
	}
}

//�r�[���̈ړ��v�Z
void boss_beam_calc(int i) {
	//�{�X���|����Ă�����A�V���b�g��o�^���Ȃ��t���O�ɂ���
	if(boss[i].flag!=1) boss_beam[i].flag=2;

	for(int j=0; j<BOSS_SHOT_MAX; j++) {
		//�e�̃t���O���I���Ȃ�A�e�����v�Z����
		if(boss_beam[i].bullet[j].flag>0) {
			boss_beam[i].bullet[j].x=boss[stage].x;
			boss_beam[i].bullet[j].y+=boss_beam[i].bullet[j].vy;
			boss_beam[i].bullet[j].cnt++;
			//��ʊO�Ȃ����
			if(boss_beam[i].bullet[j].x<-20 || boss_beam[i].bullet[j].x>WND_WID+20 ||
				boss_beam[i].bullet[j].y<-20 || boss_beam[i].bullet[j].y>WND_HET+20) {
				boss_beam[i].bullet[j].flag=0;//�t���O���I�t�ɂ���
				boss_beam[i].bullet[j].cnt=0;
			}
			//���@�ɓ������������
			if(is_mc_hit3(j)==1) {
				se_flag[12]=1;
				//boss_beam[i].bullet[j].flag=0;
				if(mc_num==0)      blc.hp-=boss[i].power;
				//else if(mc_num==1) atk.hp-=boss[i].power;
				//else               dfc.hp-=boss[i].power;
			}
		}
	}
}

//�e���̏���
void boss_danmaku_calc() {
	//�V���b�g�̏���
	if(boss_shot[stage].flag!=0) {
		int atk_ptn=boss[stage].atk_ptn[boss[stage].mv_state];
		if(atk_ptn!=-1 || boss[stage].mv_state!=-1)
			boss_atk_pattern[boss[stage].atk_ptn[boss[stage].mv_state]](stage);
		//boss_atk_pattern[0](stage);
		boss_shot_calc(stage);
		boss_shot[stage].cnt++;
	}

	//�r�[���̏���
	if(boss_beam[stage].flag!=0) {
		boss_atk_pattern[boss[stage].atk_ptn[boss[stage].mv_state]](stage);
		boss_beam_calc(stage);
		boss_beam[stage].cnt++;
	}
}

//�{�X�V���b�g�̊֐����Ăяo��
void boss_danmaku_main() {
	if(boss[stage].mv_state!=-1)
		boss_danmaku_calc();
}