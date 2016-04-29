//�퓬�@�o�����X�^�C�v
typedef struct {
	float x, y, ang;//x���W, y���W, �p�x
	int hp, hp_max;//x���W, y���W, �p�x, ���x, hp, �ő�hp
	int flag, power, num, mutekicnt;//�t���O, �p���[,�c�@��,���G��Ԃ̃J�E���g
	int shot_mode, shot_cnt, brake;//�V���b�g���[�h,�V���b�g�J�E���g,�u���[�L
	int cnt, index;//�摜�p�̃J�E���g�A�z��̓Y����
	int img[2];//�摜
}blc_mc;

//�퓬�@�A�^�b�N�^�C�v
/*
typedef struct {
	float x, y, ang;//x���W, y���W, �p�x
	int hp, hp_max;//x���W, y���W, �p�x, ���x, hp, �ő�hp
	int flag, power, num, mutekicnt;//�t���O, �p���[,�c�@��,���G��Ԃ̃J�E���g
	int shot_mode, shot_cnt, brake;//�V���b�g���[�h,�V���b�g�J�E���g,�u���[�L
	int cnt, index;//�摜�p�̃J�E���g�A�z��̓Y����
	int img[2];//�摜
}atk_mc;

//�퓬�@�f�B�t�F���X�^�C�v
typedef struct {
	float x, y, ang;//x���W, y���W, �p�x
	int hp, hp_max;//x���W, y���W, �p�x, ���x, hp, �ő�hp
	int flag, power, num, mutekicnt;//�t���O, �p���[,�c�@��,���G��Ԃ̃J�E���g
	int shot_mode, shot_cnt, brake;//�V���b�g���[�h,�V���b�g�J�E���g,�u���[�L
	int cnt, index;//�摜�p�̃J�E���g�A�z��̓Y����
	int img[2];//�摜
}dfc_mc;   */

//���@�V���b�g�̍\����
typedef struct {
	int flag,power,cnt,knd;//�t���O�A�p���[�A�J�E���^�A���
	double ang, naname;
	float x,y,spd,vx,vy;//���W�A�p�x�A�X�s�[�h�Ax���x�Ay���x
}mc_shot_info;

//���@�{���̍\����
/*typedef struct {
	int flag,power,cnt,knd;//�t���O�A�p���[�A�J�E���^�A���
	float x,y,angle,spd;//���W�A�p�x�A�X�s�[�h
}mc_bom_info;*/

//���@���[�U�[�̍\����
typedef struct {
	int flag,power,cnt,knd;//�t���O�A�p���[�A�J�E���^�A���
	float x,y,angle,spd;//���W�A�p�x�A�X�s�[�h
}mc_laser_info;

//�X�^�[�g��ʂ̃��j���[
typedef struct {
	int x, y;
	char name[256];
}sMenu;

//�v���C���ɒ��f�����Ƃ��̉�ʂ̃��j���[
/*typedef struct {
	float x, y;
	char name[256];
}pMenu;	*/

//���@����
/*typedef struct {
	int ix, iy, nx, ny, sx, sy;//�摜�E���O�E���͂̈ʒu
	char name[128];
	char sentence[256];
}mc_explanation;   */

//�������
typedef struct {
	int x, y;
	char sentence[256];
}play_explanation;

//��Փx�\����
//typedef struct {
//	int x, y;
//	char name[256];
//}rank_explanation;

//�G
typedef struct {
	int cnt, mv_ptn,knd;//�J�E���^,�ړ��p�^�[��,�G�̎��,�ҋ@����
	float x, y, sp;//�����W,�����W,�X�s�[�h
	int bltime, wait, hp, power;//���ˎ���,HP,�ő�HP,�p���[
	int item_knd[ITEM_KND];//�����Ă���A�C�e���̎��
	int bul_knd, bul_ptn;//�e�̎��,�e�����
	int item_flag[ITEM_KND];//�A�C�e���̃t���O
	int xSize, ySize, index;//�摜�p�̃T�C�Y�A�Y����(�A�j���[�V����)
	int flag, hp_max;
	double ang, naname;//�p�x
	float vx, vy;//�����x�A�����x
}enemy;

//�e�Ɋւ���\����
typedef struct {
	int flag, power, cnt, knd;//�t���O�A�p���[�A�J�E���^�A�e�̎��
	double ang, naname;//�p�x�A�摜�̊p�x
	float x, y, sp, vx, vy;//x���W�Ay���W�A�X�s�[�h�Ax���x�Ay���x
} bullet_info;

//�G�V���b�g�̍\����
typedef struct {
	int flag,power,cnt,knd, num;//�t���O�A�p���[�A�J�E���^�A�e����ށA�G�̔ԍ�
	float x, y, spd, vx, vy;//���W�A�X�s�[�h�Ax���x�Ay���x
	double ang, naname;
	bullet_info bullet[ENY_SHOT_MAX];
}enemy_shot_info;

//�����I�v�Z�Ɏg���\����
typedef struct {
	int flag, cnt, set_t;
	float ax, v0x, ay, v0y, vx, vy, prex, prey;
}physics;

//�{�X
typedef struct {
	int cnt;
	float x, y, sp, vx, vy;
	int wait, hp, power;
	int mv_ptn[BOSS_PATTERN_MAX];//�s���p�^�[��
	int mv_cnt[BOSS_PATTERN_MAX];//���̍s���Ɉڂ�܂ł̃J�E���g
	int mv_cnt2[BOSS_PATTERN_MAX];//x�Ԗڂ̍s���p�^�[���̃J�E���^
	int atk_ptn[BOSS_PATTERN_MAX];//�U���p�^�[��
	int bltime,bul_knd, hp_max, state;
	int mv_state, atk_state;//�{�X�̍s���E�U���p�^�[���̑J�ڔԍ�
	int flag;
	int brt;//�P�x
	double ang;
	physics phy;
}boss_info;

//�{�X�V���b�g�̍\����
typedef struct {
	int flag,power,cnt,knd;//�t���O�A�p���[�A�J�E���^�A�e�����
	float x, y, sp, vx, vy;//���W�A�X�s�[�h�Ax���x�Ay���x
	double ang, base_ang[2], naname;
	bullet_info bullet[BOSS_SHOT_MAX];
}boss_shot_info;

//�r�[���`���[�W(�G�t�F�N�g)
typedef struct {
	float x, y, vx, vy, sp;
	int flag, end_flag;//�t���O�A�`���[�W���I���������ǂ����̃t���O
	double ang;
}beam_charge_info;

//�L�[�{�[�h�Ɋւ���\����
typedef struct{
	int key[KEY_MAX];
}keyboard;

//�L�[�R���t�B�O�Ɋւ���\����
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}config;

//�����Ɋւ���\����
typedef struct {
	float x,y;
	int cnt, index, flag;
}explosion;

//�X�e�[�W�^�C�g���Ɋւ���\����
//typedef struct {
//	//�t���O�A�摜�n���h���A�J�E���^�A�P�x�A�o���J�E���g
//    int flag,img,cnt,brt,appear_cnt;
//}stage_title;

//�A�C�e���Ɋւ���\����
//typedef struct {
//	int flag, cnt, knd, state;
//	float x, y, xSize, ySize, sp;
//}item_info;

//bgm�Ɋւ���\����
typedef struct {
	//bgm�̍Đ��t���O�A�Đ��n���h���A���Ȃ炷���Đ���ޔԍ�������A���[�v�ʒu
	int flag, handle, knd[2], loop_pos[2];
}bgm_info;

//���̃G���A�������Ă�����
typedef struct {
	bgm_info bgm;
}area_info;

//�Q�[���N���Aor�Q�[���I�[�o�[�Ɋւ���\����
typedef struct {
	int flag, brr;
	float x, y, vy;
}game_clear_or_over;
