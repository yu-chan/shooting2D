#include "GV.h"

//“G‚Ìs“®ƒpƒ^[ƒ“‚ÌŠÖ”éŒ¾
extern void enemy_pattern0(int); extern void enemy_pattern1(int); extern void enemy_pattern2(int);
extern void enemy_pattern3(int); extern void enemy_pattern4(int); extern void enemy_pattern5(int);
extern void enemy_pattern6(int); extern void enemy_pattern7(int); extern void enemy_pattern8(int);
extern void enemy_pattern9(int); extern void enemy_pattern10(int); extern void enemy_pattern11(int);
extern void enemy_pattern12(int); extern void enemy_pattern13(int); extern void enemy_pattern14(int);
extern void enemy_pattern15(int); extern void enemy_pattern16(int); extern void enemy_pattern17(int);
extern void enemy_pattern18(int); extern void enemy_pattern19(int); extern void enemy_pattern20(int);
extern void enemy_pattern21(int); extern void enemy_pattern22(int); extern void enemy_pattern23(int);
extern void enemy_pattern24(int); extern void enemy_pattern25(int); extern void enemy_pattern26(int);
extern void enemy_pattern27(int); extern void enemy_pattern28(int); extern void enemy_pattern29(int);
extern void enemy_pattern30(int); extern void enemy_pattern31(int); extern void enemy_pattern32(int);
extern void enemy_pattern33(int); extern void enemy_pattern34(int); extern void enemy_pattern35(int);
extern void enemy_pattern36(int); extern void enemy_pattern37(int); extern void enemy_pattern38(int);
extern void enemy_pattern39(int); extern void enemy_pattern40(int); extern void enemy_pattern41(int);
extern void enemy_pattern42(int); extern void enemy_pattern43(int); extern void enemy_pattern44(int);
extern void enemy_pattern45(int); extern void enemy_pattern46(int); extern void enemy_pattern47(int);
extern void enemy_pattern48(int); extern void enemy_pattern49(int); extern void enemy_pattern50(int);
extern void enemy_pattern51(int); extern void enemy_pattern52(int); extern void enemy_pattern53(int);
extern void enemy_pattern54(int); extern void enemy_pattern55(int); extern void enemy_pattern56(int);
extern void enemy_pattern57(int); extern void enemy_pattern58(int); extern void enemy_pattern59(int);
extern void enemy_pattern60(int); extern void enemy_pattern61(int); extern void enemy_pattern62(int);
extern void enemy_pattern63(int); extern void enemy_pattern64(int); extern void enemy_pattern65(int);
extern void enemy_pattern66(int); extern void enemy_pattern67(int); extern void enemy_pattern68(int);
extern void enemy_pattern69(int); extern void enemy_pattern70(int); extern void enemy_pattern71(int);
extern void enemy_pattern72(int); extern void enemy_pattern73(int); extern void enemy_pattern74(int);
extern void enemy_pattern75(int); extern void enemy_pattern76(int); extern void enemy_pattern77(int);
extern void enemy_pattern78(int); extern void enemy_pattern79(int); extern void enemy_pattern80(int);
extern void enemy_pattern81(int); extern void enemy_pattern82(int); extern void enemy_pattern83(int);
extern void enemy_pattern84(int); extern void enemy_pattern85(int); extern void enemy_pattern86(int);
extern void enemy_pattern87(int); extern void enemy_pattern88(int); extern void enemy_pattern89(int);
extern void enemy_pattern90(int); extern void enemy_pattern91(int); extern void enemy_pattern92(int);
extern void enemy_pattern93(int); extern void enemy_pattern94(int); extern void enemy_pattern95(int);
extern void enemy_pattern96(int); extern void enemy_pattern97(int); extern void enemy_pattern98(int);
extern void enemy_pattern99(int); extern void enemy_pattern100(int); extern void enemy_pattern101(int);
extern void enemy_pattern102(int); extern void enemy_pattern103(int); extern void enemy_pattern104(int);
extern void enemy_pattern105(int); extern void enemy_pattern106(int); extern void enemy_pattern107(int);
extern void enemy_pattern108(int); extern void enemy_pattern109(int); extern void enemy_pattern110(int);
extern void enemy_pattern111(int); extern void enemy_pattern112(int); extern void enemy_pattern113(int);
extern void enemy_pattern114(int); extern void enemy_pattern115(int); extern void enemy_pattern116(int);
extern void enemy_pattern117(int); extern void enemy_pattern118(int); extern void enemy_pattern119(int);
extern void enemy_pattern120(int);

//“G‚Ìs“®ƒpƒ^[ƒ“‚Ì”z—ñéŒ¾
void (*eny_act_pattern[ENY_PATTERN_MAX])(int)={
	enemy_pattern0, enemy_pattern1, enemy_pattern2,
	enemy_pattern3, enemy_pattern4, enemy_pattern5,
	enemy_pattern6, enemy_pattern7, enemy_pattern8,
	enemy_pattern9, enemy_pattern10, enemy_pattern11,
	enemy_pattern12, enemy_pattern13, enemy_pattern14,
	enemy_pattern15, enemy_pattern16, enemy_pattern17,
	enemy_pattern18, enemy_pattern19, enemy_pattern20,
	enemy_pattern21, enemy_pattern22, enemy_pattern23,
	enemy_pattern24, enemy_pattern25, enemy_pattern26,
	enemy_pattern27, enemy_pattern28, enemy_pattern29,
	enemy_pattern30, enemy_pattern31, enemy_pattern32,
	enemy_pattern33, enemy_pattern34, enemy_pattern35,
	enemy_pattern36, enemy_pattern37, enemy_pattern38,
	enemy_pattern39, enemy_pattern40, enemy_pattern41,
	enemy_pattern42, enemy_pattern43, enemy_pattern44,
	enemy_pattern45, enemy_pattern46, enemy_pattern47, 
	enemy_pattern48, enemy_pattern49, enemy_pattern50,
	enemy_pattern51, enemy_pattern52, enemy_pattern53,
	enemy_pattern54, enemy_pattern55, enemy_pattern56,
	enemy_pattern57, enemy_pattern58, enemy_pattern59,
	enemy_pattern60, enemy_pattern61, enemy_pattern62,
	enemy_pattern63, enemy_pattern64, enemy_pattern65,
	enemy_pattern66, enemy_pattern67, enemy_pattern68,
	enemy_pattern69, enemy_pattern70, enemy_pattern71,
	enemy_pattern72, enemy_pattern73, enemy_pattern74,
	enemy_pattern75, enemy_pattern76, enemy_pattern77,
	enemy_pattern78, enemy_pattern79, enemy_pattern80,
	enemy_pattern81, enemy_pattern82, enemy_pattern83,
	enemy_pattern84, enemy_pattern85, enemy_pattern86,
	enemy_pattern87, enemy_pattern88, enemy_pattern89,
	enemy_pattern90, enemy_pattern91, enemy_pattern92,
	enemy_pattern93, enemy_pattern94, enemy_pattern95,
	enemy_pattern96, enemy_pattern97, enemy_pattern98,
	enemy_pattern99, enemy_pattern100, enemy_pattern101,
	enemy_pattern102, enemy_pattern103, enemy_pattern104,
	enemy_pattern105, enemy_pattern106, enemy_pattern107,
	enemy_pattern108, enemy_pattern109, enemy_pattern110,
	enemy_pattern111, enemy_pattern112, enemy_pattern113,
	enemy_pattern114, enemy_pattern115, enemy_pattern116,
	enemy_pattern117, enemy_pattern118, enemy_pattern119,
	enemy_pattern120,
};

//“G‚ÌoŒ»ŠÔ‚ª‚«‚½‚çAƒtƒ‰ƒO‚ğ—§‚Ä‚é
void enemy_flag() {
	for(int i=0; i<ENEMY_MAX; i++) {
		if(eny_info[i].cnt==stage_count) eny_info[i].flag=1;
	}
}

//“Gî•ñ‚ğ“o˜^
void enemy_regist() {
	for(int i=0; i<ENEMY_MAX; i++) {
		if(eny_info[i].cnt==stage_count) {
			eny[i].flag=1;
			eny[i].cnt   =0;
			eny[i].mv_ptn=eny_info[i].mv_ptn;
			eny[i].knd   =eny_info[i].knd;
			eny[i].x     =eny_info[i].x;
			eny[i].y     =eny_info[i].y;
			eny[i].sp    =eny_info[i].sp;
			eny[i].bltime=eny_info[i].bltime;
			eny[i].wait  =eny_info[i].wait;
			eny[i].hp    =eny_info[i].hp;
			eny[i].hp_max=eny[i].hp;
			eny[i].power =eny_info[i].power;
			for(int j=0; j<ITEM_KND; j++)
				eny[i].item_knd[j]=eny_info[i].item_knd[j];
			eny[i].bul_knd=eny_info[i].bul_knd;
			eny[i].bul_ptn=eny_info[i].bul_ptn;
			if(eny[i].knd==0) { eny[i].xSize=eny_xs[0]; eny[i].ySize=eny_ys[0]; }
			else if(eny[i].knd==1) { eny[i].xSize=eny_xs[1]; eny[i].ySize=eny_ys[1]; }
			else if(eny[i].knd==2) { eny[i].xSize=eny_xs[2]; eny[i].ySize=eny_ys[2]; }
			else if(eny[i].knd==3) { eny[i].xSize=eny_xs[3]; eny[i].ySize=eny_ys[3]; }
			else if(eny[i].knd==4) { eny[i].xSize=64;        eny[i].ySize=64;        }
			else if(eny[i].knd==5) { eny[i].xSize=64;        eny[i].ySize=64;        }
			else if(eny[i].knd==6) { eny[i].xSize=64;        eny[i].ySize=64;        }
			eny[i].vx    =0;
			eny[i].vy    =0;
			eny[i].ang   =0;
			eny[i].naname=0;
		}
	}
}

//’e–‹î•ñ‚ğ“o˜^
void enemy_shot_regist(int i) {
	for(int j=0; j<ENEMY_MAX; j++) {
		//–¢g—p‚Ì’e–‹ƒf[ƒ^‚ª‚ ‚ê‚Î“o˜^
		if(eny_shot[j].flag==0) {
			memset(&eny_shot[j], 0, sizeof(enemy_shot_info));//‰Šú‰»‚µ‚Ä“o˜^
			eny_shot[j].flag=1;//ƒtƒ‰ƒO‚ğ—§‚Ä‚é
			eny_shot[j].knd=eny[i].bul_ptn;//’e–‹í—Ş
			eny_shot[j].power=eny[i].power;//ƒpƒ[
			eny_shot[j].num=i;//“G‚Ì”Ô†“o˜^
			eny_shot[j].cnt=0;
			return;
		}
	}
	/*
	eny_shot[i].flag=1;
	eny_shot[i].x=eny[i].x;
	eny_shot[i].y=eny[i].y+(float)eny[i].ySize;
	eny_shot[i].spd=10;
	se_flag[11]=1;
	*/
}

//“G‚Ìs“®§Œä
void enemy_move() {
	for(int i=0; i<ENEMY_MAX; i++) {
		if(eny[i].flag==1) {//ƒtƒ‰ƒO‚ªƒIƒ“‚É‚È‚Á‚Ä‚¢‚éŠÔoŒ»‚·‚é
			eny_act_pattern[eny[i].mv_ptn](i);
			eny[i].x+=eny[i].vx;
			eny[i].y+=eny[i].vy;
			eny[i].cnt++;
			//ƒAƒjƒ[ƒVƒ‡ƒ“
			if(eny[i].cnt%5==0) {
				if(eny[i].knd>=0 && eny[i].knd<=4)
					eny[i].index=eny[i].cnt%2;
				else
					eny[i].index=eny[i].cnt%4;
			}
			//‰æ–ÊŠO‚È‚çÁ‚·
			if(eny[i].x<-200 || eny[i].x>WND_WID+200 || eny[i].y<-200 || eny[i].y>WND_HET+200)
				eny[i].flag=eny_info[i].flag=0;
			//”­ËŠÔ‚ª—ˆ‚½‚çƒVƒ‡ƒbƒg‚Ìƒtƒ‰ƒO‚ğ—§‚Ä‚é
			if(eny[i].bltime==eny[i].cnt && eny[i].bul_ptn!=-1 && eny[i].bul_knd!=-1) enemy_shot_regist(i);
		}
	}
}

//“G‚Ìˆ—
void enemy_main() {
	enemy_flag();
	enemy_regist();
	enemy_move();
}