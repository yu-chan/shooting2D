#include "GV.h"

//�U���p�^�[��0
//�܂������ł�
//�V���b�g�L�[���������ςȂ��ŁA10���o��
void mc_atk0() {
	int s;
	if((s=is_shot_flag())!=-1) {
		ms[s].flag=1;
		ms[s].cnt=0;
		ms[s].spd=10;
		ms[s].naname=0;
		ms[s].vx=0;
		ms[s].vy=ms[s].spd;
		if(mc_num==0)      { ms[s].x=blc.x; ms[s].y=blc.y-20; ms[s].power=blc.power; }
		else if(mc_num==1) { ms[s].x=atk.x; ms[s].y=atk.y-20; ms[s].power=atk.power; }
		else               { ms[s].x=dfc.x; ms[s].y=dfc.y-20; ms[s].power=dfc.power; }
		se_flag[3]=1;
	}
}

//�U���p�^�[��1
//���E��10���ł�
//�V���b�g�L�[���������ςȂ��ŁA10���o��
void mc_atk1() {
	int s;
	for(int j=0; j<2; j++) {
		if((s=is_shot_flag())!=-1) {
			ms[s].flag=1;
			ms[s].cnt=0;
			ms[s].spd=10;
			if(mc_num==0) { 
				ms[s].x=blc.x; ms[s].y=blc.y; ms[s].power=blc.power/2; 
			} else if(mc_num==1) { 
				ms[s].x=atk.x; ms[s].y=atk.y; ms[s].power=atk.power/2; 
			} else { 
				ms[s].x=dfc.x; ms[s].y=dfc.y; ms[s].power=dfc.power/2; 
			}
			if(j%2==0) {
				ms[s].naname=-PI/2;
				ms[s].vx=ms[s].spd;
				ms[s].vy=0;
			} else {
				ms[s].naname=PI/2;
				ms[s].vx=-ms[s].spd;
				ms[s].vy=0;
				se_flag[3]=1;
			}
		}
	}
}

//�U���p�^�[��2
//�~�`�ɍU��
//�V���b�g�L�[���������ςȂ��ł��A1������1�������o�Ȃ�
void mc_atk2() {
	int s;
	if(checkKey(KEY_INPUT_RETURN)==1 || 
		checkKey(KEY_INPUT_SPACE)==1 ||
		checkKey(KEY_INPUT_J)==1) {
		for(int j=0; j<50; j++) {
			if((s=is_shot_flag())!=-1) {
				ms[s].flag=1;
				ms[s].cnt=0;
				ms[s].ang=2*PI/50*j;
				ms[s].naname=ms[s].ang-PI/2;
				ms[s].spd=10;
				ms[s].vx=ms[s].spd*cos((float)ms[s].ang);
				ms[s].vy=ms[s].spd*sin((float)ms[s].ang);
				if(mc_num==0) { 
					ms[s].x=blc.x; ms[s].y=blc.y; ms[s].power=5; 
				} else if(mc_num==1) { 
					ms[s].x=atk.x; ms[s].y=atk.y; ms[s].power=5; 
				} else { 
					ms[s].x=dfc.x; ms[s].y=dfc.y; ms[s].power=5; 
				}
				se_flag[3]=1;
			}
		}
	}
}