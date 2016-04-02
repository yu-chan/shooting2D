#define _CRT_SECURE_NO_WARNINGS

#include "GV.h"


//���ʉ��̏�����
void sound_ini() {
	memset(se_flag, 0, sizeof(int)*SE_MAX);
}

//���ʉ��𔭐�
void sound_play() {
	for(int i=0; i<SE_MAX; i++) {
		if(se_flag[i]==1) {
			PlaySoundMem(se[i], DX_PLAYTYPE_BACK);
		}
	}
}

//bgm�̃��[�h
void load_bgm(int flag) {
	char str[64];
	sprintf(str, "���y/BGM/stage%d_%d.mp3", stage, flag);
	area[stage].bgm.handle=LoadSoundMem(str);
}

//bgm�̍폜
void delete_bgm() {
	DeleteSoundMem(area[stage].bgm.handle);
}

//bgm�̃��C������
void bgm_main() {
	if(area[stage].bgm.flag==0) {//�ŏ��ɓǂݍ���
		load_bgm(0);
		SetLoopPosSoundMem(area[stage].bgm.loop_pos[0], area[stage].bgm.handle);//���[�v��Z�b�g
		area[stage].bgm.flag=1;
	}
	if(area[stage].bgm.flag==1) {//��ނɉ����čĐ����n�߂�
		switch(area[stage].bgm.knd[0]) {
			case 0://�Đ����0�Ȃ�
				if(stage_count==60) {//�n�܂���60�J�E���g��ɍĐ�
					PlaySoundMem(area[stage].bgm.handle, DX_PLAYTYPE_LOOP);
					area[stage].bgm.flag=2;
				}
				break;
			default:
				break;
		}
	}
	if(area[stage].bgm.flag==2) {//�{�X�o�����ɓǂݍ���
		if(stage_count==boss_load[stage].cnt) {//�{�X�����ꂽ��ǂݍ���
			StopSoundMem(area[stage].bgm.handle);
			delete_bgm();
			load_bgm(1);
			SetLoopPosSoundMem(area[stage].bgm.loop_pos[1], area[stage].bgm.handle);//���[�v��Z�b�g
			area[stage].bgm.flag=3;
		}
	}
	if(area[stage].bgm.flag==3) {
		switch(area[stage].bgm.knd[0]) {
			case 0://�Đ����0�Ȃ�
				if(stage_count==boss_load[stage].cnt) {//�{�X�����ꂽ��Đ�
					PlaySoundMem(area[stage].bgm.handle, DX_PLAYTYPE_LOOP);
					area[stage].bgm.flag=4;
				}
				break;
			default:
				break;
		}
	}
}