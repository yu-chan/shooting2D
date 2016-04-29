#include "DxLib.h"
#include "define.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"


#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

#include "function.h"

//���@�̍\���̐錾
GLOBAL blc_mc blc;
//GLOBAL atk_mc atk;
//GLOBAL dfc_mc dfc;

//�v���C���ĂȂ��Ƃ��̔w�i�摜���i�[
GLOBAL int start_back;

//�v���C���̔w�i�摜(�X�e�[�W)���i�[
GLOBAL int img_back[BACK_MAX];

//�X�e�[�W�I��p�̉摜
//GLOBAL int s_back_select[BACK_MAX];//�������摜
//GLOBAL int b_back_select[BACK_MAX];//�傫���摜

//���ʉ�����荞��
GLOBAL int se[SE_MAX];
GLOBAL int se_flag[SE_MAX];//�T�E���h�t���O

//�X�^�[�g��ʂ̃��[�h
GLOBAL int start_mode;//0:�I�����Ă���Ƃ��@1:�I�����Ă��Ȃ��Ƃ�

//�X�^�[�g��ʂŃ��j���[��I�������Ƃ��̉�ʂ̃��[�h
/*0�`3��Enter���������Ƃ��̉��
  0:Play 1:������@ 2:���@�̎�� 3:exit
*/
GLOBAL int start_select_mode;

//��ʂ̃��[�h
/*
  0:�X�^�[�g���
  1:�X�e�[�W�I��
  2:��Փx�I��
  3:���@�I��
  4:�v���C��
  5:�Q�[���I�[�o�[
  6:�N���A�[
*/
GLOBAL int display_mode;

//�v���C���̉�ʂ̃��[�h
GLOBAL int play_mode;//0:�v���C�� 1:�v���C���f

//�v���C���f���̉�ʂ̃��[�h
//GLOBAL int play_stop;//0:continue 1:������@ 2:exit

//�X�e�[�W�ԍ����i�[
GLOBAL int stage;

//��Փx�ԍ����i�[
//GLOBAL int rank;

//���@�ԍ����i�[
GLOBAL int mc_num;

//���@�V���b�g
GLOBAL int mS[MC_SHOT_KIND];//�摜
GLOBAL mc_shot_info ms[MC_SHOT_MAX];//�V���b�g�̏��
GLOBAL int shot_mode;//���@�̃V���b�g���[�h

//���@�{��
//GLOBAL int mB[MC_BOM_KIND];//�摜
//GLOBAL mc_bom_info mb[MC_BOM_MAX];//�{���̏��

//���@���[�U�[
GLOBAL int mL[MC_LASER_KIND];//�摜
GLOBAL mc_laser_info ml[MC_LASER_MAX];//���[�U�[�̏��

//�G
GLOBAL int es0_img[2];//�摜��͂O
GLOBAL int es1_img[2];//�摜��͂P
GLOBAL int es2_img[2];//�摜��͂Q
GLOBAL int es3_img[2];//�摜��͂R
GLOBAL int ed0_img[4];//�摜�����X�^�[�O
GLOBAL int ed1_img[4];//�摜�����X�^�[�P
GLOBAL int ed2_img[4];//�摜�����X�^�[�Q
GLOBAL int eny_xs[7], eny_ys[7];//�摜�̃T�C�Y
GLOBAL enemy eny_info[ENEMY_MAX];//�t�@�C������ǂݍ��񂾃f�[�^�i�[����
GLOBAL enemy eny[ENEMY_MAX];//�ǂݍ��񂾂��̂��i�[

//�G�̍U��
GLOBAL int eny_shot_img[ENY_SHOT_KIND];//�V���b�g�̉摜
GLOBAL enemy_shot_info eny_shot[ENEMY_MAX];

//�X�e�[�W�^�C�g��
//GLOBAL stage_title st_ti[BACK_MAX];//�^�C�g���̏��
//GLOBAL int stage_title_count[BACK_MAX];//���J�E���g�ڂŃ^�C�g����\�������邩
GLOBAL int stage_count;

//�G�t�F�N�g���
//����
GLOBAL int eps_img[16];//�摜
GLOBAL int b_eps_img[16];//�{���ł����Ƃ��̉摜
//�V���b�g�܂��̓��[�U�[��ł����Ƃ��̏��
GLOBAL explosion eps[EPS_MAX];
GLOBAL int eps_count;
//�{����ł����Ƃ��̏��
GLOBAL explosion b_eps[EPS_MAX];
GLOBAL int b_eps_count;
//�r�[�����`���[�W�����
GLOBAL int img_charge;//�摜
GLOBAL beam_charge_info charge[CHARGE_MAX];//�G�t�F�N�g

//�A�C�e��
/*
  0:�{��
  1:�V���o�[�����O�i�񕜁j
  2:�S�[���h�����O�i�񕜁j
  3:���J�o�[�i�S�񕜁j
  4:�p���[�A�b�v�i�{���j
  5:�p���[�A�b�v�i���[�U�[�j
  6:�p���[�A�b�v�i�V���b�g�j
*/
//GLOBAL int item_img[ITEM_KND];//�摜
//GLOBAL item_info item[ITEM_MAX];//���
//GLOBAL int item_count;

//�X�R�A
//GLOBAL int score_img[10];//�摜
//GLOBAL int score[3][4];//�e�X�e�[�W�̃X�R�A

//�{�X
GLOBAL boss_info boss_load[BACK_MAX];//�ǂݍ��ݐ�p
GLOBAL boss_info boss[BACK_MAX];//�{�X�̏��
GLOBAL boss_shot_info boss_shot[BACK_MAX];//�{�X�̒e���
GLOBAL int img_beam;//�r�[���摜
GLOBAL boss_shot_info boss_beam[BACK_MAX];//�{�X�̃r�[�����
GLOBAL int boss_img[BACK_MAX];//�摜

//�Q�[���N���A�[or�I�[�o�[
GLOBAL int gameover;//�摜
GLOBAL int game_over_back;//�Q�[���I�[�o�[���̔w�i
GLOBAL int gameclear;//�摜
GLOBAL game_clear_or_over g_clear;//�Q�[���N���A
GLOBAL game_clear_or_over g_over;//�Q�[���I�[�o�[

//���̃G���A�������Ă���f�[�^
//GLOBAL area_info area;
GLOBAL area_info area[BACK_MAX];
