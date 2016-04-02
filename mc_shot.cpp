#include "GV.h"

//���@�̍U���p�^�[���̊֐��錾
extern void mc_atk0(); extern void mc_atk1(); extern void mc_atk2();

//���@�̍U���p�^�[���̔z��錾
void (*mc_atk_pattern[MC_ATK_PATTERN_MAX])()={
	mc_atk0, mc_atk1, mc_atk2,
};

//�V���b�g�̃t���O���m�F����
int is_shot_flag() {
	for(int i=0; i<MC_SHOT_MAX; i++)
		if(ms[i].flag==0) return i;
	return -1;
}

//�V���b�g�̃L�[��������Ă���Ȃ�V���b�g����o�^����
void mc_shot_regist() {
	
	//int f;
	if((checkKey(KEY_INPUT_RETURN)>0 && checkKey(KEY_INPUT_RETURN)<=10)||
	   (checkKey(KEY_INPUT_SPACE)>0 && checkKey(KEY_INPUT_SPACE)<=10)||
	   (checkKey(KEY_INPUT_J)>0 && checkKey(KEY_INPUT_J)<=10)) {
		   mc_atk_pattern[shot_mode]();
		   /*
		   if(mc_num==0)      blc.shot_cnt++;
		   else if(mc_num==1) atk.shot_cnt++;
		   else               dfc.shot_cnt++;
		 
			

		   if((f=is_shot_flag())!=-1 && 
			   (blc.shot_cnt%3==0 || atk.shot_cnt%3==0 || dfc.shot_cnt%3==0)) {
			   ms[f].flag=1;
			   ms[f].cnt=0;
			   ms[f].power=5;
			   ms[f].spd=10;
			   if(mc_num==0)      { ms[f].x=blc.x; ms[f].y=blc.y-20; }
			   else if(mc_num==1) { ms[f].x=atk.x; ms[f].y=atk.y-20; }
			   else               { ms[f].x=dfc.x; ms[f].y=dfc.y-20; }
			   se_flag[3]=1;
		   }*/
	}
	
	//N�L�[��C�L�[�������΃V���b�g���ς��
	if(checkKey(KEY_INPUT_N)==1)
		shot_mode=(shot_mode+1)%MC_ATK_PATTERN_MAX;
	else if(checkKey(KEY_INPUT_C)==1)
	    shot_mode=(shot_mode+MC_ATK_PATTERN_MAX-1)%MC_ATK_PATTERN_MAX;
}

//�q�b�g�������ǂ����𒲂ׂ�
int is_enemy_hit_s(int i, int j) {
	int r=eny[j].xSize/2;
	float x=ms[i].x-eny[j].x;
	float y=ms[i].y-eny[j].y;
	if(x * x + y * y <r * r) {//�摜���Ȃ�
			return 1;
	}
	return 0;
}

//�{�X�Ƀq�b�g�������ǂ����𒲂ׂ�
int is_boss_hit_s(int i, int j) {
	int h;
	int r;
	float x, y, bx, by;
	switch(j) {
		case 0:
			bx=boss[j].x;
			by=boss[j].y;
			if(ms[i].x>bx-13 && ms[i].x<bx+13 &&
				ms[i].y>by-57 && ms[i].y<by+76) {
					h=1;
			} else {
				h=0;
			}
			break;
		case 1:
			bx=boss[j].x;
			by=boss[j].y-15;
			x=ms[i].x-bx;
			y=ms[i].y-by;
			r=8;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		case 2:
			bx=boss[j].x;
			by=boss[j].y;
			x=ms[i].x-bx;
			y=ms[i].y-by;
			r=65;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		case 3:
			bx=boss[j].x;
			by=boss[j].y-10;
			x=ms[i].x-bx;
			y=ms[i].y-by;
			r=15;
			if(x * x + y * y < r * r)
				h=1;
			else
				h=0;
			break;
		default:
			h=0;
			break;
	}
	return h;
}

//�����G�t�F�N�g����o�^
void explosion_regist_s(float x, float y) {
	if(eps_count==EPS_MAX) eps_count=0;
	eps[eps_count].flag=1;
	eps[eps_count].x=x;
	eps[eps_count].y=y;
	se_flag[9]=1;
	eps_count++;
	if(eps_count==EPS_MAX) eps_count=0;
}

//�A�C�e���m�F
int is_item_s(int j) {
	for(int i=0; i<ITEM_KND; i++) {
		if(eny[j].item_knd[i]==1) {
			eny[j].item_flag[i]=1;
			return i;
		}
	}
	return -1;
}

//�A�C�e����o�^
void item_regist_s(int j, int knd) {
	item[item_count].flag=1;
	item[item_count].knd=knd;
	item[item_count].x=eny[j].x;
	item[item_count].y=eny[j].y;
	item[item_count].xSize=30;
	item[item_count].ySize=30;
	item[item_count].sp=2;
	item_count++;
}

//�G�̐�������
int eny_death_judge_s(int j) {
	int knd;
	//�G��HP��0�ȉ��ɂȂ�����A�G������
	if(eny[j].hp<=0) {
		eny[j].flag=0;
		score[rank][stage]+=5;
		//�������Ƃ��A�C�e���������Ă��邩���ׂ�
		//�����Ă���Γo�^
		if((knd=is_item_s(j))!=-1) {
			item_regist_s(j, knd);
		}
		return 1;
	}
	return 0;
}

//�{�X�̐�������
int boss_death_judge_s(int j) {
	if(boss[j].hp<=0) {
		boss[j].flag=0;
		return 1;
	}
	return 0;
}

//�V���b�g�̈ړ��v�Z
void mc_shot_calc() {
	for(int i=0; i<MC_SHOT_MAX; i++) {
		if(ms[i].flag==1) {
			ms[i].x-=ms[i].vx;
			ms[i].y-=ms[i].vy;
			ms[i].cnt++;
			//�V���b�g��ł�����̓����蔻��
			//�G�̓����蔻��
			for(int j=0; j<ENEMY_MAX; j++) {
				//�������������
				if(eny[j].flag==1 && is_enemy_hit_s(i, j)==1) {
					ms[i].flag=0;
					eny[j].hp-=ms[i].power;
					if(eny_death_judge_s(j)==1)//�G�����񂾂��ǂ������肷��
						explosion_regist_s(ms[i].x, ms[i].y);//�����G�t�F�N�g���Ăяo��
				}
			}
			//�{�X�̓����蔻��
			if(boss[stage].flag==1 && is_boss_hit_s(i, stage)) {
				ms[i].flag=0;
				boss[stage].hp-=ms[i].power;
				if(boss_death_judge_s(stage)==1) {
					explosion_regist_s(ms[i].x, ms[i].y);
					clear_regist();
				}
			}

			if(ms[i].x<-20 || ms[i].x>WND_WID+20 ||
				ms[i].y<-20 || ms[i].y>WND_HET+20) {
				ms[i].flag=0;//�V���b�g����ʊO�Ȃ����
				ms[i].cnt=0;
			}
		}
	}
}

//���@�V���b�g�̊֐����Ăяo��
void mc_shot() {
	mc_shot_regist();
	mc_shot_calc();
}