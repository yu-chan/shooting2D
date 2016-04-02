#include "GV.h"

//�����_���Ȋp�x��Ԃ�
double rang(double ang) {
	return (-ang+ang*2*GetRand(10000)/10000.0);
}

//�ړ��p�^�[��0
//�ォ��܂������s��
void enemy_pattern0(int i) {
	eny[i].vx=0;
	eny[i].vy=eny[i].sp;
	eny[i].ang=0;
	eny[i].naname=0;
}

//�ړ��p�^�[���P
//�E���ɍs��1
void enemy_pattern1(int i) {
	eny[i].naname=(-3)*PI/10;
	eny[i].ang=(float)(PI/5);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�ړ��p�^�[���Q
//�����ɍs��1
void enemy_pattern2(int i) {
	eny[i].naname=PI/3;
	eny[i].ang=(float)(5*PI/6);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�ړ��p�^�[���R
//�������Q��ς��ĉE����
void enemy_pattern3(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	} else if(t==30) {
		eny[i].naname=-PI/4;
		eny[i].ang=(float)(PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//�ړ��p�^�[���S
//�������Q��ς��č�����
void enemy_pattern4(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	} else if(t==30) {
		eny[i].naname=PI/4;
		eny[i].ang=(float)(3*PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//�ړ��p�^�[���T
//�E��֍s��1
void enemy_pattern5(int i) {
	eny[i].naname=5*PI/4;
	eny[i].ang=(float)(7*PI/4);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�ړ��p�^�[���U
//����֍s��1
void enemy_pattern6(int i) {
	eny[i].naname=3*PI/4;
	eny[i].ang=(float)(5*PI/4);
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�ړ��p�^�[��7
//���@�̐^�����痈��
void enemy_pattern7(int i) {
	float x=eny[i].x;
	eny[i].naname=PI;
	eny[i].ang=3*PI/2;
	eny[i].vy=-eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].x=blc.x+x;
		else if(mc_num==1) eny[i].x=atk.x+x;
		else               eny[i].x=dfc.x+x;
	}
}

//�ړ��p�^�[��8
//���@�̐^�ォ�痈��
void enemy_pattern8(int i) {
	float x=eny[i].x;
	eny[i].naname=0;
	eny[i].ang=PI/2;
	eny[i].vy=eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].x=blc.x+x;
		else if(mc_num==1) eny[i].x=atk.x+x;
		else               eny[i].x=dfc.x+x;
	}
}

//�ړ��p�^�[��9
//���@�̐^�E���痈��
void enemy_pattern9(int i) {
	float y=eny[i].y;
	eny[i].naname=PI/2;
	eny[i].ang=PI;
	eny[i].vx=-eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].y=blc.y+y;
		else if(mc_num==1) eny[i].y=atk.y+y;
		else               eny[i].y=dfc.y+y;
	}
}

//�ړ��p�^�[��10
//���@�̐^�����痈��
void enemy_pattern10(int i) {
	float y=eny[i].y;
	eny[i].naname=-PI/2;
	eny[i].ang=0;
	eny[i].vx=eny[i].sp;
	if(eny[i].cnt==0) {
		if(mc_num==0)      eny[i].y=blc.y+y;
		else if(mc_num==1) eny[i].y=atk.y+y;
		else               eny[i].y=dfc.y+y;
	}
}

//�ړ��p�^�[��11
//�ォ��܂������s���č��J�[�u
void enemy_pattern11(int i) {
	if(eny[i].cnt==0) eny[i].vy=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//�������ɉ���
		eny[i].vy-=eny[i].sp/100;//����
	}
}

//�ړ��p�^�[��12
//�ォ��܂������s���ĉE�J�[�u
void enemy_pattern12(int i) {
	if(eny[i].cnt==0) eny[i].vy=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//�E�����ɉ���
		eny[i].vy-=eny[i].sp/100;//����
	}
}

//�ړ��p�^�[��13
//������܂������s���č��J�[�u
void enemy_pattern13(int i) {
	if(eny[i].cnt==0) eny[i].vy=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//�������ɉ���
		eny[i].vy+=eny[i].sp/100;//����
	}
}

//�ړ��p�^�[��14
//������܂������s���ĉE�J�[�u
void enemy_pattern14(int i) {
	if(eny[i].cnt==0) eny[i].vy=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//�E�����ɉ���
		eny[i].vy+=eny[i].sp/100;//����
	}
}

//�ړ��p�^�[��15
//�������Q��ς��ĉE���
void enemy_pattern15(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	} else if(t==30) {
		eny[i].naname=5*PI/4;
		eny[i].ang=(float)(7*PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//�ړ��p�^�[��16
//�������Q��ς��č����
void enemy_pattern16(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	} else if(t==30) {
		eny[i].naname=3*PI/4;
		eny[i].ang=(float)(5*PI/4);
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t>100) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//�s���p�^�[��17
//���@�̏ォ��܂������s������A�E�Ɉړ�
void enemy_pattern17(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=0;
		eny[i].vy=eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//�s���p�^�[��18
//���@�̏ォ��܂������s������A���Ɉړ�
void enemy_pattern18(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=0;
		eny[i].vy=eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//�s���p�^�[��19
//���@�̉�����܂������s������A�E�Ɉړ�
void enemy_pattern19(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI;
		eny[i].vy=-eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//�s���p�^�[��20
//���@�̉�����܂������s������A���Ɉړ�
void enemy_pattern20(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI;
		eny[i].vy=-eny[i].sp;
		if(mc_num==0)      eny[i].x=blc.x;
		else if(mc_num==1) eny[i].x=atk.x;
		else               eny[i].x=dfc.x;
	}
	if(t==30) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//�s���p�^�[��21
//���@�̉E����܂������s������A��Ɉړ�
void enemy_pattern21(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=-PI;
	}
}

//�s���p�^�[��22
//���@�̍�����܂������s������A��Ɉړ�
void enemy_pattern22(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
}

//�s���p�^�[��23
//���@�̉E����܂������s������A���Ɉړ�
void enemy_pattern23(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//�s���p�^�[��24
//���@�̍�����܂������s������A���Ɉړ�
void enemy_pattern24(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		if(mc_num==0)      eny[i].y=blc.y;
		else if(mc_num==1) eny[i].y=atk.y;
		else               eny[i].y=dfc.y;
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//�s���p�^�[��25
//�~��āA��؂��āA�~���
void enemy_pattern25(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=0;
	if(t==0)    eny[i].vy=eny[i].sp;//�~���
	if(t==30)   eny[i].vy=0;//�Ƃ܂�
	if(t==30+w) eny[i].vy=eny[i].sp;//�~���
}

//�s���p�^�[��26
//����āA��؂��āA���
void enemy_pattern26(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=PI;
	if(t==0)    eny[i].vy=-eny[i].sp;//���
	if(t==30)   eny[i].vy=0;//�Ƃ܂�
	if(t==30+w) eny[i].vy=-eny[i].sp;//���
}

//�s���p�^�[��27
//���ォ�痈����A�܂�Ԃ��ĉE��ɍs��
void enemy_pattern27(int i) {
	int t=eny[i].cnt;
	if(t==0) {//���ォ��~���
		eny[i].naname=-PI/6;
		eny[i].ang=PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//�܂�Ԃ��āA�E��ɍs��
		eny[i].naname=-5*PI/6;
		eny[i].ang=-PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��28
//�E�ォ�痈����A�܂�Ԃ��č���ɍs��
void enemy_pattern28(int i) {
	int t=eny[i].cnt;
	if(t==0) {//�E�ォ��~���
		eny[i].naname=PI/6;
		eny[i].ang=2*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//�܂�Ԃ��āA����ɍs��
		eny[i].naname=5*PI/6;
		eny[i].ang=4*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��29
//�������痈����A�܂�Ԃ��ĉE���ɍs��
void enemy_pattern29(int i) {
	int t=eny[i].cnt;
	if(t==0) {//����������
		eny[i].naname=-5*PI/6;
		eny[i].ang=-PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//�܂�Ԃ��āA�E���ɍs��
		eny[i].naname=-PI/6;
		eny[i].ang=PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��30
//�E�����痈����A�܂�Ԃ��č����ɍs��
void enemy_pattern30(int i) {
	int t=eny[i].cnt;
	if(t==0) {//�E��������
		eny[i].naname=5*PI/6;
		eny[i].ang=4*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	} else if(t==30) {//�܂�Ԃ��āA�����ɍs��
		eny[i].naname=PI/6;
		eny[i].ang=2*PI/3;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��31
//������܂������s��
void enemy_pattern31(int i) {
	eny[i].vx=0;
	eny[i].vy=-eny[i].sp;
	eny[i].ang=0;
	eny[i].naname=PI;
}

//�s���p�^�[��32
//�E����܂������s��
void enemy_pattern32(int i) {
	eny[i].vx=-eny[i].sp;
	eny[i].vy=0;
	eny[i].ang=0;
	eny[i].naname=PI/2;
}

//�s���p�^�[��33
//������܂������s��
void enemy_pattern33(int i) {
	eny[i].vx=eny[i].sp;
	eny[i].vy=0;
	eny[i].ang=0;
	eny[i].naname=-PI/2;
}

//�s���p�^�[��34
//�E�ォ��~��āA�E���ŕ����]�����č��ɍs��
void enemy_pattern34(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(eny[i].y==WND_HET-35) {//�����]�����āA���ɍs��
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//�s���p�^�[��35
//�E�ォ�獶�ɍs���āA����ŕ����]�����ĉ��ɍ~���
void enemy_pattern35(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(eny[i].x==35) {//�����]�����āA���ɍs��
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//�s���p�^�[��36
//���ォ��~��āA�����ŕ����]�����ĉE�ɍs��
void enemy_pattern36(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(eny[i].y==WND_HET-35) {//�����]�����ĉE�ɍs��
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//�s���p�^�[��37
//���ォ��E�ɍs���āA�E��ŕ����]�����ĉ��ɍ~���
void enemy_pattern37(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(eny[i].x==WND_WID-35) {//�����]�����ĉ��ɍs��
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
}

//�s���p�^�[��38
//�����������āA����ŕ����]�����ĉE�ɍs��
void enemy_pattern38(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(eny[i].y==35) {//�����]�����ĉE�ɍs��
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
}

//�s���p�^�[��39
//��������E�ɍs���āA�E���ŕ����]�����ď�ɏ��
void enemy_pattern39(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(eny[i].x==WND_WID-35) {//�����]�����ď�ɍs��
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
}

//�s���p�^�[��40
//�E���������āA�E��ŕ����]�����č��ɍs��
void enemy_pattern40(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(eny[i].y==35) {//�����]�����č��ɍs��
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
}

//�s���p�^�[��41
//�E�����獶�ɍs���āA�����ŕ����]�����ď�ɏ��
void enemy_pattern41(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(eny[i].x==35) {//�����]�����ď�ɍs��
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
}

//�s���p�^�[��42
//�ォ��EU�^�[��
void enemy_pattern42(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].ang=PI/2;
		eny[i].naname=0;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx=eny[i].sp;
		eny[i].vy-=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy<=-eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=0;
			eny[i].vy=-eny[i].sp;
			eny[i].ang=3*PI/4;
			eny[i].naname=PI;
		}
	}
}

//�s���p�^�[��43
//�ォ�獶U�^�[��
void enemy_pattern43(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx=-eny[i].sp;
		eny[i].vy-=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy<=-eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=0;
			eny[i].vy=-eny[i].sp;
			eny[i].ang=-PI/2;
			eny[i].naname=-PI;
		}
	}
}

//�s���p�^�[��44
//������EU�^�[��
void enemy_pattern44(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=-PI;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx=eny[i].sp;
		eny[i].vy+=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy>=eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=0;
			eny[i].vy=eny[i].sp;
			eny[i].ang=PI/2;
			eny[i].naname=0;
		}
	}
}

//�s���p�^�[��45
//�����獶U�^�[��
void enemy_pattern45(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
		eny[i].naname=-PI;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx=-eny[i].sp;
		eny[i].vy+=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vy>=eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=0;
			eny[i].vy=eny[i].sp;
			eny[i].ang=PI/2;
			eny[i].naname=0;
		}
	}
}

//�s���p�^�[��46
//�E�����U�^�[��
void enemy_pattern46(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx+=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].vy=-eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx>=eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=0;
			eny[i].naname=-PI/2;
		}
	}
}

//�s���p�^�[��47
//�E���牺U�^�[��
void enemy_pattern47(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=PI/2;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx+=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].vy=eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx>=eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=0;
			eny[i].naname=-PI/2;
		}
	}
}

//�s���p�^�[��48
//�������U�^�[��
void enemy_pattern48(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx-=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].vy=eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx<=-eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=-eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=PI/2;
			eny[i].naname=PI/2;
		}
	}
}

//�s���p�^�[��49
//�����牺U�^�[��
void enemy_pattern49(int i) {
	int t=eny[i].cnt;
	const float g=0.2f;
	if(t==0) {
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
		eny[i].naname=-PI/2;
	}
	if(t>=50) {//�������n�߂�
		eny[i].vx-=g*eny[i].sp;//0�ɂȂ�΁AU�^�[������
		eny[i].vy=eny[i].sp;
		eny[i].ang=atan2f(eny[i].vy, eny[i].vx);
		eny[i].naname=eny[i].ang-PI/2;
		if(eny[i].vx<=-eny[i].sp) {//�܂������ɑ�������
			eny[i].vx=-eny[i].sp;
			eny[i].vy=0;
			eny[i].ang=PI/2;
			eny[i].naname=PI/2;
		}
	}
}

//�s���p�^�[��50
//�ォ��~��āA�E���񂵂č~���
void enemy_pattern50(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=eny[i].sp;
	if(t==0) { eny[i].naname=0; eny[i].ang=PI/2; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=0;
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
	}
}

//�s���p�^�[��51
//�ォ��~��āA�����񂵂č~���
void enemy_pattern51(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=eny[i].sp;
	if(t==0) { eny[i].naname=0; eny[i].ang=PI/2; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=0;
		eny[i].vx=0;
		eny[i].vy=eny[i].sp;
	}
}

//�s���p�^�[��52
//��������A�E���񂵂ď��
void enemy_pattern52(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=-eny[i].sp;
	if(t==0) { eny[i].naname=PI; eny[i].ang=3*PI/2; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=PI;
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
	}
}

//�s���p�^�[��53
//��������A�����񂵂ď��
void enemy_pattern53(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vy=-eny[i].sp;
	if(t==0) { eny[i].naname=PI; eny[i].ang=3*PI/2; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=PI;
		eny[i].vx=0;
		eny[i].vy=-eny[i].sp;
	}
}

//�s���p�^�[��54
//�E����s���āA����񂵂čs��
void enemy_pattern54(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=-eny[i].sp;
	if(t==0) { eny[i].naname=PI/2; eny[i].ang=PI; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//�s���p�^�[��55
//�E����s���āA�����񂵂čs��
void enemy_pattern55(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=-eny[i].sp;
	if(t==0) { eny[i].naname=PI/2; eny[i].ang=PI; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=PI/2;
		eny[i].vx=-eny[i].sp;
		eny[i].vy=0;
	}
}

//�s���p�^�[��56
//������s���āA����񂵂čs��
void enemy_pattern56(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=eny[i].sp;
	if(t==0) { eny[i].naname=-PI/2; eny[i].ang=0; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//�s���p�^�[��57
//������s���āA�����񂵂čs��
void enemy_pattern57(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	eny[i].vx=eny[i].sp;
	if(t==0) { eny[i].naname=-PI/2; eny[i].ang=0; }
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=-PI/2;
		eny[i].vx=eny[i].sp;
		eny[i].vy=0;
	}
}

//�s���p�^�[��58
//�E�ォ��΂߂ɍ~��āA����񂵂čs��
void enemy_pattern58(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=PI/4; eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=PI/4;
		eny[i].ang=11*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��59
//�E�ォ��΂߂ɍ~��āA�����񂵂čs��
void enemy_pattern59(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=PI/4; eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=PI/4;
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��60
//���ォ��΂߂ɍ~��āA����񂵂čs��
void enemy_pattern60(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-PI/4; eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=-PI/4;
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��61
//���ォ��΂߂ɍ~��āA�����񂵂čs��
void enemy_pattern61(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-PI/4; eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=-PI/4;
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��62
//�E������΂߂ɏ���āA����񂵂čs��
void enemy_pattern62(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=3*PI/4; eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=3*PI/4;
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��63
//�E������΂߂ɏ���āA�����񂵂čs��
void enemy_pattern63(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=3*PI/4; eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=3*PI/4;
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��64
//��������΂߂ɏ���āA����񂵂čs��
void enemy_pattern64(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-3*PI/4; eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname-=a;
		eny[i].ang-=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=-3*PI/4;
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��65
//��������΂߂ɏ���āA�����񂵂čs��
void enemy_pattern65(int i) {
	int t=eny[i].cnt;
	const double a=PI/20;
	if(t==0) {
		eny[i].naname=-3*PI/4; eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=30 && t<70) {//�����������͂��߂�
		eny[i].naname+=a;
		eny[i].ang+=a;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=70) {//�P��������܂������s��
		eny[i].naname=-3*PI/4;
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��66
//�ォ��M�U�M�U�ɍ~���(�E)
void enemy_pattern66(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI/r;
	else if(t==30)eny[i].ang=PI/r+PI/2;//�������Ɋp�x��ς���
	else if(t==60)eny[i].ang=PI/r;//�E�����Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��67
//�ォ��M�U�M�U�ɍ~���(��)
void enemy_pattern67(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI/r+PI/2;
	else if(t==30)eny[i].ang=PI/r;//�E�����Ɋp�x��ς���
	else if(t==60)eny[i].ang=PI/r+PI/2;//�������Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��68
//������M�U�M�U�ɍ~���(�E)
void enemy_pattern68(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=3*PI/2+PI/r;
	else if(t==30)eny[i].ang=3*PI/2-PI/r;//�������Ɋp�x��ς���
	else if(t==60)eny[i].ang=3*PI/2+PI/r;//�E�����Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��69
//������M�U�M�U�ɍ~���(��)
void enemy_pattern69(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=3*PI/2-PI/r;
	else if(t==30)eny[i].ang=3*PI/2+PI/r;//�E�����Ɋp�x��ς���
	else if(t==60)eny[i].ang=3*PI/2-PI/r;//�������Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��70
//�E����M�U�M�U�ɍ~���(��)
void enemy_pattern70(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI+PI/r;
	else if(t==30)eny[i].ang=PI-PI/r;//�������Ɋp�x��ς���
	else if(t==60)eny[i].ang=PI+PI/r;//������Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��71
//�E����M�U�M�U�ɍ~���(��)
void enemy_pattern71(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI-PI/r;
	else if(t==30)eny[i].ang=PI+PI/r;//������Ɋp�x��ς���
	else if(t==60)eny[i].ang=PI-PI/r;//�������Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��72
//������M�U�M�U�ɍ~���(��)
void enemy_pattern72(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=-PI/r;
	else if(t==30)eny[i].ang=PI/r;//�������Ɋp�x��ς���
	else if(t==60)eny[i].ang=-PI/r;//������Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��73
//������M�U�M�U�ɍ~���(��)
void enemy_pattern73(int i) {
	int t=eny[i].cnt;
	int r;
	srand((unsigned)time(NULL));
	r=rand()%8+3;
	if(t==0)      eny[i].ang=PI/r;
	else if(t==30)eny[i].ang=-PI/r;//������Ɋp�x��ς���
	else if(t==60)eny[i].ang=PI/r;//�������Ɋp�x��ς���
	eny[i].naname=eny[i].ang-PI/2;
	eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
	eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
}

//�s���p�^�[��74
//�E����܂������s���ď�J�[�u
void enemy_pattern74(int i) {
	if(eny[i].cnt==0) eny[i].vx=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//����
		eny[i].vy-=eny[i].sp/100;//������ɉ���
	}
}

//�s���p�^�[��75
//�E����܂������s���ĉ��J�[�u
void enemy_pattern75(int i) {
	if(eny[i].cnt==0) eny[i].vx=-eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx+=eny[i].sp/100;//����
		eny[i].vy+=eny[i].sp/100;//�������ɉ���
	}
}

//�s���p�^�[��76
//������܂������s���ď�J�[�u
void enemy_pattern76(int i) {
	if(eny[i].cnt==0) eny[i].vx=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//����
		eny[i].vy-=eny[i].sp/100;//������ɉ���
	}
}

//�s���p�^�[��77
//������܂������s���ĉ��J�[�u
void enemy_pattern77(int i) {
	if(eny[i].cnt==0) eny[i].vx=eny[i].sp;
	if(eny[i].cnt<100) {
		eny[i].vx-=eny[i].sp/100;//����
		eny[i].vy+=eny[i].sp/100;//�������ɉ���
	}
}

//�s���p�^�[��78
//�E���獶�ɍs���āA��؂��āA���ɍs��
void enemy_pattern78(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=PI/2;
	if(t==0)    eny[i].vx=-eny[i].sp;//���ɍs��
	if(t==30)   eny[i].vx=0;//�Ƃ܂�
	if(t==30+w) eny[i].vx=-eny[i].sp;//���ɍs��
}

//�s���p�^�[��79
//������E�ɍs���āA��؂��āA�E�ɍs��
void enemy_pattern79(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	eny[i].naname=-PI/2;
	if(t==0)    eny[i].vx=eny[i].sp;//�E�ɍs��
	if(t==30)   eny[i].vx=0;//�Ƃ܂�
	if(t==30+w) eny[i].vx=eny[i].sp;//�E�ɍs��
}

//�s���p�^�[��80
//�E���ɍs��2
void enemy_pattern80(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��81
//�����ɍs��2
void enemy_pattern81(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(5*PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��82
//�E��ɍs��2
void enemy_pattern82(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(-PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��83
//����ɍs��2
void enemy_pattern83(int i) {
	int t=eny[i].cnt;
	if(t==0) {
		eny[i].ang=(float)(7*PI/6);
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��84
//�������āA�Ƃ܂��āA�E���ɍs��
void enemy_pattern84(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��85
//�������āA�Ƃ܂��āA�����ɍs��
void enemy_pattern85(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=eny[i].sp;
		eny[i].naname=0;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=2*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��86
//�オ���āA�Ƃ܂��āA�E��ɍs��
void enemy_pattern86(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=-PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��87
//�オ���āA�Ƃ܂��āA����ɍs��
void enemy_pattern87(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].vy=-eny[i].sp;
		eny[i].naname=PI;
	}
	if(t==30) eny[i].vy=0;
	if(t==30+w) {
		eny[i].ang=4*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��88
//�E�ォ�獶���ɍs���āA�Ƃ܂��āA�����ɍs��
void enemy_pattern88(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=3*PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//�s���p�^�[��89
//���ォ��E���ɍs���āA�Ƃ܂��āA�E���ɍs��
void enemy_pattern89(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//�s���p�^�[��90
//�E�����獶��ɍs���āA�Ƃ܂��āA����ɍs��
void enemy_pattern90(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=5*PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//�s���p�^�[��91
//��������E��ɍs���āA�Ƃ܂��āA�E��ɍs��
void enemy_pattern91(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0 || t==30+w) {
		eny[i].ang=-PI/4;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0;
		eny[i].vy=0;
	}
}

//�s���p�^�[��92
//�E���ɍs���āA������]���āA�����ɍs��
void enemy_pattern92(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang+=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��93
//�����ɍs���āA������]���āA�E���ɍs��
void enemy_pattern93(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=2*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang-=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��94
//�E��ɍs���āA������]���āA����ɍs��
void enemy_pattern94(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=-PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang-=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��95
//����ɍs���āA������]���āA�E��ɍs��
void enemy_pattern95(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	const double a=PI/30;
	if(t==0) {
		eny[i].ang=-2*PI/3;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t>=20 && t<30) {
		eny[i].ang+=a;
		eny[i].naname=eny[i].ang-PI/2;
		eny[i].vx=0;
		eny[i].vy=0;
	}
	if(t==30+w) {
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

/*
  (*)�E�E�E��ʒ��ɓˑR�o������
*/

//�s���p�^�[��96
//�Ƃ܂��āA��ɍs��(*)
void enemy_pattern96(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vy=-eny[i].sp;
}

//�s���p�^�[��97
//�Ƃ܂��āA���ɍs��(*)
void enemy_pattern97(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vy=eny[i].sp;
}

//�s���p�^�[��98
//�Ƃ܂��āA�E�ɍs��(*)
void enemy_pattern98(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vx=eny[i].sp;
}

//�s���p�^�[��99
//�Ƃ܂��āA���ɍs��(*)
void enemy_pattern99(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) eny[i].vx=-eny[i].sp;
}

//�s���p�^�[��100
//�Ƃ܂��āA�E��ɍs��(*)
void enemy_pattern100(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��101
//�Ƃ܂��āA����ɍs��(*)
void enemy_pattern101(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��102
//�Ƃ܂��āA�E���ɍs��(*)
void enemy_pattern102(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��103
//�Ƃ܂��āA�����ɍs��(*)
void enemy_pattern103(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==w) {
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��104
//�~��āA�Ƃ܂��āA�オ��
void enemy_pattern104(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vy=eny[i].sp;
	if(t==30)   eny[i].vy=0;
	if(t==30+w)	eny[i].vy=-eny[i].sp;
}

//�s���p�^�[��105
//�オ���āA�Ƃ܂��āA������
void enemy_pattern105(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vy=-eny[i].sp;
	if(t==30)   eny[i].vy=0;
	if(t==30+w)	eny[i].vy=eny[i].sp;
}

//�s���p�^�[��106
//���ɍs���āA�Ƃ܂��āA�E�ɍs��
void enemy_pattern106(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vx=-eny[i].sp;
	if(t==30)   eny[i].vx=0;
	if(t==30+w)	eny[i].vx=eny[i].sp;
}

//�s���p�^�[��107
//�E�ɍs���āA�Ƃ܂��āA���ɍs��
void enemy_pattern107(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)    eny[i].vx=eny[i].sp;
	if(t==30)   eny[i].vx=0;
	if(t==30+w)	eny[i].vx=-eny[i].sp;
}

//�s���p�^�[��108
//�����ɍs���āA�Ƃ܂��āA�E��ɍs��
void enemy_pattern108(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��109
//�E���ɍs���āA�Ƃ܂��āA����ɍs��
void enemy_pattern109(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��110
//����ɍs���āA�Ƃ܂��āA�E���ɍs��
void enemy_pattern110(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=5*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��111
//�E��ɍs���āA�Ƃ܂��āA�����ɍs��
void enemy_pattern111(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) {
		eny[i].ang=-PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
	if(t==30) {
		eny[i].vx=0; eny[i].vy=0;
	}
	if(t==30+w)	{
		eny[i].ang=3*PI/4;
		eny[i].vx=eny[i].sp*cos((float)eny[i].ang);
		eny[i].vy=eny[i].sp*sin((float)eny[i].ang);
	}
}

//�s���p�^�[��112
//�Ƃ܂��āA������(*)
void enemy_pattern112(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==10+w) eny[i].flag=0;
}

//�s���p�^�[��113
//�������āA�Ƃ܂��āA�E�ɍs���āA�Ƃ܂��āA
//���ɍs���āA�Ƃ܂��āA�E�ɍs��
void enemy_pattern113(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=eny[i].sp;//������
	if(t==30)          eny[i].vy=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vx=eny[i].sp;//�E�ɍs��
	if(t==50 || t==70) eny[i].vx=0;//�Ƃ܂�
	if(t==60)          eny[i].vx=-eny[i].sp;//���ɍs��
}

//�s���p�^�[��114
//�������āA�Ƃ܂��āA���ɍs���āA�Ƃ܂��āA
//�E�ɍs���āA�Ƃ܂��āA���ɍs��
void enemy_pattern114(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=eny[i].sp;//������
	if(t==30)          eny[i].vy=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vx=-eny[i].sp;//���ɍs��
	if(t==50 || t==70) eny[i].vx=0;//�Ƃ܂�
	if(t==60)          eny[i].vx=eny[i].sp;//�E�ɍs��
}

//�s���p�^�[��115
//�オ���āA�Ƃ܂��āA�E�ɍs���āA�Ƃ܂��āA
//���ɍs���āA�Ƃ܂��āA�E�ɍs��
void enemy_pattern115(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=-eny[i].sp;//�オ��
	if(t==30)          eny[i].vy=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vx=eny[i].sp;//�E�ɍs��
	if(t==50 || t==70) eny[i].vx=0;//�Ƃ܂�
	if(t==60)          eny[i].vx=-eny[i].sp;//���ɍs��
}

//�s���p�^�[��116
//�オ���āA�Ƃ܂��āA���ɍs���āA�Ƃ܂��āA
//�E�ɍs���āA�Ƃ܂��āA���ɍs��
void enemy_pattern116(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vy=eny[i].sp;//�オ��
	if(t==30)          eny[i].vy=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vx=-eny[i].sp;//���ɍs��
	if(t==50 || t==70) eny[i].vx=0;//�Ƃ܂�
	if(t==60)          eny[i].vx=eny[i].sp;//�E�ɍs��
}

//�s���p�^�[��117
//���ɍs���āA�Ƃ܂��āA�オ���āA�Ƃ܂��āA
//�������āA�Ƃ܂��āA�オ��
void enemy_pattern117(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0)           eny[i].vx=-eny[i].sp;//���ɍs��
	if(t==30)          eny[i].vx=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vy=-eny[i].sp;//�オ��
	if(t==50 || t==70) eny[i].vy=0;//�Ƃ܂�
	if(t==60)          eny[i].vy=eny[i].sp;//������
}

//�s���p�^�[��118
//���ɍs���āA�Ƃ܂��āA�������āA�Ƃ܂��āA
//�オ���āA�Ƃ܂��āA������
void enemy_pattern118(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) eny[i].vx=-eny[i].sp;//���ɍs��
	if(t==30) eny[i].vx=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vy=eny[i].sp;//������
	if(t==50 || t==70) eny[i].vy=0;//�Ƃ܂�
	if(t==60) eny[i].vy=-eny[i].sp;//�オ��
}

//�s���p�^�[��119
//�E�ɍs���āA�Ƃ܂��āA�オ���āA�Ƃ܂��āA
//�������āA�Ƃ܂��āA�オ��
void enemy_pattern119(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) eny[i].vx=eny[i].sp;//�E�ɍs��
	if(t==30) eny[i].vx=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vy=-eny[i].sp;//�オ��
	if(t==50 || t==70) eny[i].vy=0;//�Ƃ܂�
	if(t==60) eny[i].vy=eny[i].sp;//������
}

//�s���p�^�[��120
//�E�ɍs���āA�Ƃ܂��āA�������āA�Ƃ܂��āA
//�オ���āA�Ƃ܂��āA������
void enemy_pattern120(int i) {
	int t=eny[i].cnt;
	int w=eny[i].wait;
	if(t==0) eny[i].vx=eny[i].sp;//�E�ɍs��
	if(t==30) eny[i].vx=0;//�Ƃ܂�
	if(t==40 || t==80) eny[i].vy=eny[i].sp;//������
	if(t==50 || t==70) eny[i].vy=0;//�Ƃ܂�
	if(t==60) eny[i].vy=-eny[i].sp;//�オ��
}