#include "GV.h"

//���[�U�[�̃t���O���m�F����
int is_laser_flag() {
	for(int i=0; i<MC_LASER_MAX; i++)
		if(ml[i].flag==0) return i;
	return -1;
}

//���[�U�[�̃L�[��������Ă���Ȃ�V���b�g����o�^����
void mc_laser_regist() {
	int f;
	if(checkKey(KEY_INPUT_L)==1 || checkKey(KEY_INPUT_V)==1) {
		   if((f=is_laser_flag())!=-1) {
			   ml[f].flag=1;
			   ml[f].cnt=0;
			   ml[f].spd=15;
			   ml[f].power=10;
			   if(mc_num==0)      { ml[f].x=blc.x; ml[f].y=blc.y-20; }
			   //else if(mc_num==1) { ml[f].x=atk.x; ml[f].y=atk.y-20; }
			   //else               { ml[f].x=dfc.x; ml[f].y=dfc.y-20; }
			   se_flag[5]=1;
		   }
	}
}

//�q�b�g�������ǂ����𒲂ׂ�
int is_enemy_hit_l(int i, int j) {
	/*
	if(ml[i].x<eny[j].x+eny[j].xSize && ml[i].x+5>eny[j].x && 
		ml[i].y<eny[j].y+eny[j].ySize && ml[i].y+120>eny[j].y) {//�摜���Ȃ�
			ml[i].y=eny[j].y+eny[j].ySize;
			return 1;
	}
	return 0;
	*/
	if(ml[i].x>eny[j].x-eny[j].xSize/2 && ml[i].x<eny[j].x+eny[j].xSize/2 &&
		ml[i].y-60<eny[j].y+eny[j].ySize/2 && ml[i].y+60>eny[j].y-eny[j].ySize/2) {
			return 1;
	}
	return 0;
}

//�{�X�Ƀq�b�g�������ǂ����𒲂ׂ�
int is_boss_hit_l(int i, int j) {
	int h;
	int r;
	float bx, by;
	switch(j) {
		case 0:
			bx=boss[j].x;
			by=boss[j].y;
			if(ml[i].x>bx-13 && ml[i].x<bx+13 &&
				ml[i].y+60>by-57 && ml[i].y-60<by+76) {
					h=1;
			} else {
				h=0;
			}
			break;
		case 1:
			bx=boss[j].x;
			by=boss[j].y-15;
			r=8;
			if(ml[i].x>bx-13 && ml[i].x<bx+13 &&
				ml[i].y+60>by-r && ml[i].y-60<by+r) {
					h=1;
			} else {
				h=0;
			}
			break;
		case 2:
			bx=boss[j].x;
			by=boss[j].y;
			r=65;
			if(ml[i].x>bx-13 && ml[i].x<bx+13 &&
				ml[i].y+60>by-r && ml[i].y-60<by+r) {
					h=1;
			} else {
				h=0;
			}
			break;
		case 3:
			bx=boss[j].x;
			by=boss[j].y-10;
			r=15;
			if(ml[i].x>bx-13 && ml[i].x<bx+13 &&
				ml[i].y+60>by-r && ml[i].y-60<by+r) {
					h=1;
			} else {
				h=0;
			}
			break;
		default:
			h=0;
			break;
	}
	return h;
}

//�����G�t�F�N�g����o�^
void explosion_regist_l(float x, float y) {
	if(eps_count==EPS_MAX) eps_count=0;
	eps[eps_count].flag=1;
	eps[eps_count].x=x;
	eps[eps_count].y=y;
	se_flag[9]=1;
	eps_count++;
	if(eps_count==EPS_MAX) eps_count=0;
}

//�A�C�e���m�F
//int is_item_l(int j) {
//	for(int i=0; i<ITEM_KND; i++) {
//		if(eny[j].item_knd[i]==1) {
//			eny[j].item_flag[i]=1;
//			return i;
//		}
//	}
//	return 0;
//}

//�A�C�e����o�^
/*
void item_regist_l(int j, int knd) {
	item[item_count].flag=1;
	item[item_count].knd=knd;
	item[item_count].x=eny[j].x;
	item[item_count].y=eny[j].y;
	item[item_count].xSize=30;
	item[item_count].ySize=30;
	item[item_count].sp=2;
	item_count++;
}*/

//�G�̐�������
int eny_death_judge_l(int j) {
	//int knd;
	//�G��HP��0�ȉ��ɂȂ�����A�G������
	if(eny[j].hp<=0) {
		eny[j].flag=0;
		//score[rank][stage]+=5;
		//�������Ƃ��A�C�e���������Ă��邩���ׂ�
		//�����Ă���Γo�^
		/*if((knd=is_item_l(j))!=-1) {
			item_regist_l(j, knd);
		}*/
		return 1;
	}
	return 0;
}

//�{�X�̐�������
int boss_death_judge_l(int j) {
	if(boss[j].hp<=0) {
		boss[j].flag=0;
		return 1;
	}
	return 0;
}

//���[�U�[�̈ړ��v�Z
void mc_laser_calc() {
	for(int i=0; i<MC_LASER_MAX; i++) {
		if(ml[i].flag==1) {
			ml[i].y-=ml[i].spd;
			ml[i].cnt++;
			//�{����ł�����̓����蔻��
			//�G�̓����蔻��
			for(int j=0; j<ENEMY_MAX; j++) {
				//�������������
				if(eny[j].flag==1 && is_enemy_hit_l(i, j)==1) {
					ml[i].flag=0;
					eny[j].hp-=ml[i].power;
					if(eny_death_judge_l(j)==1)//�G�����񂾂��ǂ������肷��
						explosion_regist_l(ml[i].x, ml[i].y);//�����G�t�F�N�g���Ăяo��
				}
			}
			//�{�X�̓����蔻��
			if(boss[stage].flag==1 && is_boss_hit_l(i, stage)) {
				boss[stage].hp-=ml[i].power;
				if(boss_death_judge_l(stage)==1) {
					explosion_regist_l(ml[i].x, ml[i].y);
					clear_regist();
				}
			}
			if(ml[i].y+60<0) ml[i].flag=0;//���[�U�[����ʊO�Ȃ����
		}
	}
}

//���@���[�U�[�̊֐����Ăяo��
void mc_laser() {
	mc_laser_regist();
	mc_laser_calc();
}