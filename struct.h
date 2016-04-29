//戦闘機バランスタイプ
typedef struct {
	float x, y, ang;//x座標, y座標, 角度
	int hp, hp_max;//x座標, y座標, 角度, 速度, hp, 最大hp
	int flag, power, num, mutekicnt;//フラグ, パワー,残機数,無敵状態のカウント
	int shot_mode, shot_cnt, brake;//ショットモード,ショットカウント,ブレーキ
	int cnt, index;//画像用のカウント、配列の添え字
	int img[2];//画像
}blc_mc;

//戦闘機アタックタイプ
/*
typedef struct {
	float x, y, ang;//x座標, y座標, 角度
	int hp, hp_max;//x座標, y座標, 角度, 速度, hp, 最大hp
	int flag, power, num, mutekicnt;//フラグ, パワー,残機数,無敵状態のカウント
	int shot_mode, shot_cnt, brake;//ショットモード,ショットカウント,ブレーキ
	int cnt, index;//画像用のカウント、配列の添え字
	int img[2];//画像
}atk_mc;

//戦闘機ディフェンスタイプ
typedef struct {
	float x, y, ang;//x座標, y座標, 角度
	int hp, hp_max;//x座標, y座標, 角度, 速度, hp, 最大hp
	int flag, power, num, mutekicnt;//フラグ, パワー,残機数,無敵状態のカウント
	int shot_mode, shot_cnt, brake;//ショットモード,ショットカウント,ブレーキ
	int cnt, index;//画像用のカウント、配列の添え字
	int img[2];//画像
}dfc_mc;   */

//自機ショットの構造体
typedef struct {
	int flag,power,cnt,knd;//フラグ、パワー、カウンタ、種類
	double ang, naname;
	float x,y,spd,vx,vy;//座標、角度、スピード、x速度、y速度
}mc_shot_info;

//自機ボムの構造体
/*typedef struct {
	int flag,power,cnt,knd;//フラグ、パワー、カウンタ、種類
	float x,y,angle,spd;//座標、角度、スピード
}mc_bom_info;*/

//自機レーザーの構造体
typedef struct {
	int flag,power,cnt,knd;//フラグ、パワー、カウンタ、種類
	float x,y,angle,spd;//座標、角度、スピード
}mc_laser_info;

//スタート画面のメニュー
typedef struct {
	int x, y;
	char name[256];
}sMenu;

//プレイ中に中断したときの画面のメニュー
/*typedef struct {
	float x, y;
	char name[256];
}pMenu;	*/

//自機説明
/*typedef struct {
	int ix, iy, nx, ny, sx, sy;//画像・名前・文章の位置
	char name[128];
	char sentence[256];
}mc_explanation;   */

//操作説明
typedef struct {
	int x, y;
	char sentence[256];
}play_explanation;

//難易度構造体
//typedef struct {
//	int x, y;
//	char name[256];
//}rank_explanation;

//敵
typedef struct {
	int cnt, mv_ptn,knd;//カウンタ,移動パターン,敵の種類,待機時間
	float x, y, sp;//ｘ座標,ｙ座標,スピード
	int bltime, wait, hp, power;//発射時間,HP,最大HP,パワー
	int item_knd[ITEM_KND];//持っているアイテムの種類
	int bul_knd, bul_ptn;//弾の種類,弾幕種類
	int item_flag[ITEM_KND];//アイテムのフラグ
	int xSize, ySize, index;//画像用のサイズ、添え字(アニメーション)
	int flag, hp_max;
	double ang, naname;//角度
	float vx, vy;//ｘ速度、ｙ速度
}enemy;

//弾に関する構造体
typedef struct {
	int flag, power, cnt, knd;//フラグ、パワー、カウンタ、弾の種類
	double ang, naname;//角度、画像の角度
	float x, y, sp, vx, vy;//x座標、y座標、スピード、x速度、y速度
} bullet_info;

//敵ショットの構造体
typedef struct {
	int flag,power,cnt,knd, num;//フラグ、パワー、カウンタ、弾幕種類、敵の番号
	float x, y, spd, vx, vy;//座標、スピード、x速度、y速度
	double ang, naname;
	bullet_info bullet[ENY_SHOT_MAX];
}enemy_shot_info;

//物理的計算に使う構造体
typedef struct {
	int flag, cnt, set_t;
	float ax, v0x, ay, v0y, vx, vy, prex, prey;
}physics;

//ボス
typedef struct {
	int cnt;
	float x, y, sp, vx, vy;
	int wait, hp, power;
	int mv_ptn[BOSS_PATTERN_MAX];//行動パターン
	int mv_cnt[BOSS_PATTERN_MAX];//次の行動に移るまでのカウント
	int mv_cnt2[BOSS_PATTERN_MAX];//x番目の行動パターンのカウンタ
	int atk_ptn[BOSS_PATTERN_MAX];//攻撃パターン
	int bltime,bul_knd, hp_max, state;
	int mv_state, atk_state;//ボスの行動・攻撃パターンの遷移番号
	int flag;
	int brt;//輝度
	double ang;
	physics phy;
}boss_info;

//ボスショットの構造体
typedef struct {
	int flag,power,cnt,knd;//フラグ、パワー、カウンタ、弾幕種類
	float x, y, sp, vx, vy;//座標、スピード、x速度、y速度
	double ang, base_ang[2], naname;
	bullet_info bullet[BOSS_SHOT_MAX];
}boss_shot_info;

//ビームチャージ(エフェクト)
typedef struct {
	float x, y, vx, vy, sp;
	int flag, end_flag;//フラグ、チャージが終了したかどうかのフラグ
	double ang;
}beam_charge_info;

//キーボードに関する構造体
typedef struct{
	int key[KEY_MAX];
}keyboard;

//キーコンフィグに関する構造体
typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}config;

//爆発に関する構造体
typedef struct {
	float x,y;
	int cnt, index, flag;
}explosion;

//ステージタイトルに関する構造体
//typedef struct {
//	//フラグ、画像ハンドル、カウンタ、輝度、出現カウント
//    int flag,img,cnt,brt,appear_cnt;
//}stage_title;

//アイテムに関する構造体
//typedef struct {
//	int flag, cnt, knd, state;
//	float x, y, xSize, ySize, sp;
//}item_info;

//bgmに関する構造体
typedef struct {
	//bgmの再生フラグ、再生ハンドル、いつならすか再生種類番号を入れる、ループ位置
	int flag, handle, knd[2], loop_pos[2];
}bgm_info;

//そのエリアが持っている情報
typedef struct {
	bgm_info bgm;
}area_info;

//ゲームクリアorゲームオーバーに関する構造体
typedef struct {
	int flag, brr;
	float x, y, vy;
}game_clear_or_over;
