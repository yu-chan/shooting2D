#include "GV.h"

unsigned int Key[256];

//�L�[�̓��͏�Ԃ��擾
int getKey() {
	char buf[256];//�S�ẴL�[�̓��͏�Ԃ��i�[���邽�߂̃o�b�t�@
	GetHitKeyStateAll(buf);
	for(int i=0; i<256; i++) {
		if(buf[i]==1) Key[i]++;
		else          Key[i]=0;
	}
	return 0;
}

//�L�[��������Ă��邩�`�F�b�N����
int checkKey(unsigned char Handle) {
	return Key[Handle];
}