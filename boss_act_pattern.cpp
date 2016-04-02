#include "GV.h"

//行動パターン0
//左右に動く
void boss_pattern0(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	
	/*所定位置についたら
	if(t==0)            regist_phy(540, Y_BOSS, 60);
	//左に動く
	if(t==25 || t==125) regist_phy(100, Y_BOSS, 120);
	//右に動く
	if(t==75)           regist_phy(540, Y_BOSS, 120);
	//ボスの定位置に戻る
	if(t==175)          regist_phy(X_BOSS, Y_BOSS, 60);
	*/
	
	if(t==0) boss[i].vx=boss[i].sp;
	if(boss[i].x>=540) boss[i].vx=-boss[i].sp;
	if(boss[i].x<=100) boss[i].vx=boss[i].sp;
	
}

//行動パターン1
//待機
void boss_pattern1(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t==0) {
		regist_phy(X_BOSS, Y_BOSS, 100);
		boss[i].vx=0;
		boss[i].vy=0;
	}
}

//行動パターン2
//定位置に戻る
void boss_pattern2(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t==200) regist_phy(X_BOSS, Y_BOSS, 180);
}

//行動パターン3
//消える
void boss_pattern3(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t>=0 && t<=100) boss[i].brt-=3;
}

//行動パターン4
//現れる
void boss_pattern4(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t>=0 && t<=100) boss[i].brt+=3;
}

//行動パターン5
//中央に移動
void boss_pattern5(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	if(t==0) regist_phy(320, 240, 60);
}

//行動パターン6
//雑魚敵を6体生成
void boss_pattern6(int i) {
	int t=boss[i].mv_cnt2[boss[i].mv_state];
	int between=boss[i].mv_cnt[boss[i].mv_state]/6;
	if(t%between==0) {
	}
}

//行動パターン7
//
void boss_pattern7(int i) {
}

//行動パターン8
//
void boss_pattern8(int i) {
}

//行動パターン9
//
void boss_pattern9(int i) {
}

//行動パターン10
//
void boss_pattern10(int i) {
}

//行動パターン11
//
void boss_pattern11(int i) {
}