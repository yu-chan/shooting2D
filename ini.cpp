#include "GV.h"


/*�v���C����Ƃ��ɁA
  �G�⎩�@�̏��Ȃ�
  ���܂��܂ȏ�������������
*/
void ini() {
	//�X�e�[�W�̃J�E���g
	stage_count=0;

	//���@(�o�����X)
	blc.x=320;
	blc.y=440;
	blc.cnt=0;
	blc.hp_max=100;
	blc.hp=blc.hp_max;
	blc.power=10;
	blc.num=2;
	blc.index=0;
	blc.shot_cnt=0;

	//���@(�A�^�b�N)
	/*atk.x=320;
	atk.y=440;
	atk.cnt=0;
	atk.index=0;
	atk.hp_max=100;
	atk.hp=atk.hp_max;
	atk.power=15;
	atk.num=2;
	atk.shot_cnt=0;*/

	//���@(�f�B�t�F���X)
	/*dfc.x=320;
	dfc.y=440;
	dfc.cnt=0;
	dfc.hp_max=100;
	dfc.hp=dfc.hp_max;
	dfc.power=5;
	dfc.num=2;
	dfc.index=0;
	dfc.shot_cnt=0;*/

	//���@�̃V���b�g���[�h
	shot_mode=0;

	//���@�̃V���b�g
	memset(ms, 0, sizeof(mc_shot_info)*MC_SHOT_MAX);

	//���@�̃{��
	//memset(mb, 0, sizeof(mc_bom_info)*MC_BOM_MAX);

	//���@�̃��[�U�[
	memset(ml, 0, sizeof(mc_laser_info)*MC_LASER_MAX);

	//�X�e�[�W�̃^�C�g��
	/*memset(st_ti, 0, sizeof(stage_title)*BACK_MAX);
	for(int i=0; i<BACK_MAX; i++) {
		stage_title_count[i]=200;
		st_ti[i].appear_cnt=stage_title_count[i];
	}*/

	//�G
	memset(eny_info, 0, sizeof(enemy)*ENEMY_MAX);
	memset(eny, 0, sizeof(enemy)*ENEMY_MAX);

	//�G�̃V���b�g
	memset(eny_shot, 0, sizeof(enemy_shot_info)*ENY_SHOT_MAX);

	//�����G�t�F�N�g
	memset(eps, 0, sizeof(explosion)*EPS_MAX);
	memset(b_eps, 0, sizeof(explosion)*EPS_MAX);
	eps_count=0;
	b_eps_count=0;

	//�A�C�e��
	/*memset(item, 0, sizeof(item_info)*ITEM_MAX);
	item_count=0;*/

	//�X�R�A
	/*for(int i=0; i<3; i++) {
		for(int j=0; j<5; j++) {
			score[i][j]=0;
		}
	}*/

	//�{�X
	memset(boss_load, 0, sizeof(boss_info)*BACK_MAX);
	memset(boss, 0, sizeof(boss_info)*BACK_MAX);

	//�{�X�V���b�g
	memset(boss_shot, 0, sizeof(boss_shot_info)*BACK_MAX);

	//�{�X�r�[��
	memset(boss_beam, 0, sizeof(boss_shot_info)*BACK_MAX);

	//bgm
	memset(&area, 0, sizeof(area_info)*BACK_MAX);
	//memset(&area, 0, sizeof(area_info));
	area[0].bgm.knd[0]=0;//�ʏ�bgm���ǂ������^�C�~���O�ōĐ����邩
	area[0].bgm.knd[1]=0;//�{�Xbgm���ǂ������^�C�~���O�ōĐ����邩
	area[0].bgm.loop_pos[0]=26672;//�ʏ�bgm�̃��[�v�ʒu
	area[0].bgm.loop_pos[1]=27010;//�{�Xbgm�̃��[�v�ʒu

	//�Q�[���I�[�o�[or�N���A�[
	memset(&g_over, 0, sizeof(game_clear_or_over));
	memset(&g_clear, 0, sizeof(game_clear_or_over));
}