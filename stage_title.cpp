#include "GV.h"

//�X�e�[�W�^�C�g���̕\�����Ԃ��v�Z����
void calc_stage_title() {
	if(st_ti[stage].appear_cnt==stage_count) {
		st_ti[stage].flag=1;
	}
	if(st_ti[stage].flag==0) return;

	if(st_ti[stage].cnt<60) st_ti[stage].brt+=2;//���񂾂񖾂邭�Ȃ�
	if(st_ti[stage].cnt>210) st_ti[stage].brt-=2;//���񂾂�Â��Ȃ�
	if(st_ti[stage].cnt>360) {
		st_ti[stage].cnt=0;
		st_ti[stage].brt=0;
		st_ti[stage].flag=0;
		return;
	}
	st_ti[stage].cnt++;
}