#include "GV.h"

//�U���p�^�[��0
//�ォ�牺�ɂ܂������ɑł�
void enemy_atk0(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//�e�����n�܂�
		//�G���|����ĂȂ��A�e�������Ƃ��ł���Ȃ�A�e��o�^����
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//�e�̎��
			eny_shot[i].bullet[s].naname=0;//�摜�̊p�x
			eny_shot[i].bullet[s].flag=1;//�t���O���I���ɂ���
			eny_shot[i].bullet[s].x=eny[n].x;//�e�̂����W
			eny_shot[i].bullet[s].y=eny[n].y;//�e�̂����W
			eny_shot[i].bullet[s].cnt=0;//�J�E���^
			eny_shot[i].bullet[s].sp=10;//�X�s�[�h
			eny_shot[i].bullet[s].vx=0;//�����x
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp;//�����x
			se_flag[11]=1;//���ˉ��̃t���O���I���ɂ���
		}
	}
	/*
	eny_shot[i].vy=eny_shot[i].spd;
	eny_shot[i].naname=0;
	*/
}

//�U���p�^�[��1
//�������ɂ܂������ɑł�
void enemy_atk1(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//�e�����n�܂�
		//�G���|����ĂȂ��A�e�������Ƃ��ł���Ȃ�A�e��o�^����
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//�e�̎��
			eny_shot[i].bullet[s].naname=PI;//�摜�̊p�x
			eny_shot[i].bullet[s].flag=1;//�t���O���I���ɂ���
			eny_shot[i].bullet[s].x=eny[n].x;//�e�̂����W
			eny_shot[i].bullet[s].y=eny[n].y;//�e�̂����W
			eny_shot[i].bullet[s].cnt=0;//�J�E���^
			eny_shot[i].bullet[s].sp=10;//�X�s�[�h
			eny_shot[i].bullet[s].vx=0;//�����x
			eny_shot[i].bullet[s].vy=-eny_shot[i].bullet[s].sp;//�����x
			se_flag[11]=1;//���ˉ��̃t���O���I���ɂ���
		}
	}
	/*
	eny_shot[i].vy=-eny_shot[i].spd;
	eny_shot[i].naname=PI;
	*/
}

//�U���p�^�[��2
//�E���獶�ɂ܂������ɑł�
void enemy_atk2(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//�e�����n�܂�
		//�G���|����ĂȂ��A�e�������Ƃ��ł���Ȃ�A�e��o�^����
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//�e�̎��
			eny_shot[i].bullet[s].naname=PI/2;//�摜�̊p�x
			eny_shot[i].bullet[s].flag=1;//�t���O���I���ɂ���
			eny_shot[i].bullet[s].x=eny[n].x;//�e�̂����W
			eny_shot[i].bullet[s].y=eny[n].y;//�e�̂����W
			eny_shot[i].bullet[s].cnt=0;//�J�E���^
			eny_shot[i].bullet[s].sp=10;//�X�s�[�h
			eny_shot[i].bullet[s].vx=-eny_shot[i].bullet[s].sp;//�����x
			eny_shot[i].bullet[s].vy=0;//�����x
			se_flag[11]=1;//���ˉ��̃t���O���I���ɂ���
		}
	}
	/*
	eny_shot[i].vx=-eny_shot[i].spd;
	eny_shot[i].naname=PI/2;
	*/
}

//�U���p�^�[��3
//������E�ɂ܂������ɑł�
void enemy_atk3(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//�e�����n�܂�
		//�G���|����ĂȂ��A�e�������Ƃ��ł���Ȃ�A�e��o�^����
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//�e�̎��
			eny_shot[i].bullet[s].naname=-PI/2;//�摜�̊p�x
			eny_shot[i].bullet[s].flag=1;//�t���O���I���ɂ���
			eny_shot[i].bullet[s].x=eny[n].x;//�e�̂����W
			eny_shot[i].bullet[s].y=eny[n].y;//�e�̂����W
			eny_shot[i].bullet[s].cnt=0;//�J�E���^
			eny_shot[i].bullet[s].sp=10;//�X�s�[�h
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp;//�����x
			eny_shot[i].bullet[s].vy=0;//�����x
			se_flag[11]=1;//���ˉ��̃t���O���I���ɂ���
		}
	}
	/*
	eny_shot[i].vx=eny_shot[i].spd;
	eny_shot[i].naname=-PI/2;
	*/
}

//�U���p�^�[��4
//���@�Ɍ������đł�
void enemy_atk4(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//�e�����n�܂�
		//�G���|����ĂȂ��A�e�������Ƃ��ł���Ȃ�A�e��o�^����
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].ang=shotatan2(i);
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//�e�̎��
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;//�摜�̊p�x
			eny_shot[i].bullet[s].flag=1;//�t���O���I���ɂ���
			eny_shot[i].bullet[s].x=eny[n].x;//�e�̂����W
			eny_shot[i].bullet[s].y=eny[n].y;//�e�̂����W
			eny_shot[i].bullet[s].cnt=0;//�J�E���^
			eny_shot[i].bullet[s].sp=10;//�X�s�[�h
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);//�����x
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);//�����x
			se_flag[11]=1;//���ˉ��̃t���O���I���ɂ���
		}
	}
	/*
	int t=eny_shot[i].cnt;
	if(t==0) {
		if(mc_num==0)
			eny_shot[i].ang=atan2f(eny_shot[i].y-blc.y, eny_shot[i].x-blc.x);
		else if(mc_num==1)
			eny_shot[i].ang=atan2f(eny_shot[i].y-atk.y, eny_shot[i].x-atk.x);
		else
			eny_shot[i].ang=atan2f(eny_shot[i].y-dfc.y, eny_shot[i].x-dfc.x);
		eny_shot[i].naname=eny_shot[i].ang-PI/2;
		eny_shot[i].vx=eny_shot[i].spd*cos((float)eny_shot[i].ang);
		eny_shot[i].vy=eny_shot[i].spd*sin((float)eny_shot[i].ang);
	}
	*/
}

//�U���p�^�[��5
//100�J�E���g����10���A���@�Ɍ������Ē�������(�p�x�L��)
void enemy_atk5(int i) {
	int n=eny_shot[i].num;
	int t=eny_shot[i].cnt;
	int s;
	if(t>=0 && t<100 && t%10==0) {
		if(t==0) {//�p�x���L������
			eny_shot[i].ang=shotatan2(i);
		}
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}

	}
}

//�U���p�^�[��6
//�قȂ�p�x���瓯���ɑ����e���T���ł�
void enemy_atk6(int i) {
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(eny_shot[i].cnt==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=10;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//�U���p�^�[��7
//�قȂ�p�x���瓯���ɒx���e���T���ł�
void enemy_atk7(int i) {
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(eny_shot[i].cnt==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//�U���p�^�[��8
//100�J�E���g��10���A���@�Ɍ������ăX�s�[�h�ω����đł�
void enemy_atk8(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<100 && t%10==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].ang=shotatan2(i);
			/*
			if(mc_num==0)
				eny_shot[i].ang=atan2f(blc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													blc.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
			else if(mc_num==1)
				eny_shot[i].ang=atan2f(atk.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													atk.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
			else
				eny_shot[i].ang=atan2f(dfc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													dfc.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
													*/
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].ang-PI/2;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}
	}
}

//�U���p�^�[��9
//0.5�b���~�`����
void enemy_atk9(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%20==0) {
		double ang=shotatan2(i);
		for(int j=0; j<20; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=ang+2*PI/20*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//�U���p�^�[��10
//�΂�T���V���b�g
void enemy_atk10(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double ang=shotatan2(i);

	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=ang+rang(PI/4);
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=(float)(3+rang(1.5));
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//�U���p�^�[��11
//�΂�T���V���b�g(����)
void enemy_atk11(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double ang=shotatan2(i);

	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=ang+rang(PI/4);
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=(float)(4+rang(2.0));
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
	for(int j=0; j<ENY_SHOT_MAX; j++) {
		if(eny_shot[i].bullet[j].sp>1.5) {//���x��1.5���傫�����̂�����Ό���
			eny_shot[i].bullet[j].sp-=0.04f;
			eny_shot[i].bullet[j].vx=eny_shot[i].bullet[j].sp*cos((float)eny_shot[i].bullet[j].ang);
			eny_shot[i].bullet[j].vy=eny_shot[i].bullet[j].sp*sin((float)eny_shot[i].bullet[j].ang);
		}
	}
}

//�U���p�^�[��12
//�΂߂���܂������ł�
void enemy_atk12(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny[n].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=10;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//�U���p�^�[��13
//0.5�b���قȂ�p�x���瓯���ɑ����e���T���ł�
void enemy_atk13(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(t>=0 && t<100 && t%10==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=10;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//�U���p�^�[��14
//0.5�b���قȂ�p�x���瓯���ɒx���e���T���ł�
void enemy_atk14(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(t>=0 && t<100 && t%10==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//�U���p�^�[��15
//�ォ�牺�ւ܂������A���őł�
void enemy_atk15(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=PI;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=0;
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp;
			se_flag[11]=1;
		}
	}
}

//�U���p�^�[��16
//�������ւ܂������A���őł�
void enemy_atk16(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=0;
			eny_shot[i].bullet[s].vy=-eny_shot[i].bullet[s].sp;
			se_flag[11]=1;
		}
	}
}

//�U���p�^�[��17
//�E���獶�ւ܂������A���őł�
void enemy_atk17(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=-eny_shot[i].bullet[s].sp;
			eny_shot[i].bullet[s].vy=0;
			se_flag[11]=1;
		}
	}
}

//�U���p�^�[��18
//������E�ւ܂������A���őł�
void enemy_atk18(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp;
			eny_shot[i].bullet[s].vy=0;
			se_flag[11]=1;
		}
	}
}

//�U���p�^�[��19
//�s���p�^�[��113�`120�ɑΉ������U��
void enemy_atk19(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0 || t==20 || t==40) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].ang=shotatan2(i);
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].ang-PI/2;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}
	}
}