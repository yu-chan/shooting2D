#include "GV.h"

//UŒ‚ƒpƒ^[ƒ“0
//ã‚©‚ç‰º‚É‚Ü‚Á‚·‚®‚É‘Å‚Â
void enemy_atk0(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//’e–‹‚ªŽn‚Ü‚é
		//“G‚ª“|‚³‚ê‚Ä‚È‚­A’e‚ðŒ‚‚Â‚±‚Æ‚ª‚Å‚«‚é‚È‚çA’e‚ð“o˜^‚·‚é
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//’e‚ÌŽí—Þ
			eny_shot[i].bullet[s].naname=0;//‰æ‘œ‚ÌŠp“x
			eny_shot[i].bullet[s].flag=1;//ƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
			eny_shot[i].bullet[s].x=eny[n].x;//’e‚Ì‚˜À•W
			eny_shot[i].bullet[s].y=eny[n].y;//’e‚Ì‚™À•W
			eny_shot[i].bullet[s].cnt=0;//ƒJƒEƒ“ƒ^
			eny_shot[i].bullet[s].sp=10;//ƒXƒs[ƒh
			eny_shot[i].bullet[s].vx=0;//‚˜‘¬“x
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp;//‚™‘¬“x
			se_flag[11]=1;//”­ŽË‰¹‚Ìƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
		}
	}
	/*
	eny_shot[i].vy=eny_shot[i].spd;
	eny_shot[i].naname=0;
	*/
}

//UŒ‚ƒpƒ^[ƒ“1
//‰º‚©‚çã‚É‚Ü‚Á‚·‚®‚É‘Å‚Â
void enemy_atk1(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//’e–‹‚ªŽn‚Ü‚é
		//“G‚ª“|‚³‚ê‚Ä‚È‚­A’e‚ðŒ‚‚Â‚±‚Æ‚ª‚Å‚«‚é‚È‚çA’e‚ð“o˜^‚·‚é
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//’e‚ÌŽí—Þ
			eny_shot[i].bullet[s].naname=PI;//‰æ‘œ‚ÌŠp“x
			eny_shot[i].bullet[s].flag=1;//ƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
			eny_shot[i].bullet[s].x=eny[n].x;//’e‚Ì‚˜À•W
			eny_shot[i].bullet[s].y=eny[n].y;//’e‚Ì‚™À•W
			eny_shot[i].bullet[s].cnt=0;//ƒJƒEƒ“ƒ^
			eny_shot[i].bullet[s].sp=10;//ƒXƒs[ƒh
			eny_shot[i].bullet[s].vx=0;//‚˜‘¬“x
			eny_shot[i].bullet[s].vy=-eny_shot[i].bullet[s].sp;//‚™‘¬“x
			se_flag[11]=1;//”­ŽË‰¹‚Ìƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
		}
	}
	/*
	eny_shot[i].vy=-eny_shot[i].spd;
	eny_shot[i].naname=PI;
	*/
}

//UŒ‚ƒpƒ^[ƒ“2
//‰E‚©‚ç¶‚É‚Ü‚Á‚·‚®‚É‘Å‚Â
void enemy_atk2(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//’e–‹‚ªŽn‚Ü‚é
		//“G‚ª“|‚³‚ê‚Ä‚È‚­A’e‚ðŒ‚‚Â‚±‚Æ‚ª‚Å‚«‚é‚È‚çA’e‚ð“o˜^‚·‚é
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//’e‚ÌŽí—Þ
			eny_shot[i].bullet[s].naname=PI/2;//‰æ‘œ‚ÌŠp“x
			eny_shot[i].bullet[s].flag=1;//ƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
			eny_shot[i].bullet[s].x=eny[n].x;//’e‚Ì‚˜À•W
			eny_shot[i].bullet[s].y=eny[n].y;//’e‚Ì‚™À•W
			eny_shot[i].bullet[s].cnt=0;//ƒJƒEƒ“ƒ^
			eny_shot[i].bullet[s].sp=10;//ƒXƒs[ƒh
			eny_shot[i].bullet[s].vx=-eny_shot[i].bullet[s].sp;//‚˜‘¬“x
			eny_shot[i].bullet[s].vy=0;//‚™‘¬“x
			se_flag[11]=1;//”­ŽË‰¹‚Ìƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
		}
	}
	/*
	eny_shot[i].vx=-eny_shot[i].spd;
	eny_shot[i].naname=PI/2;
	*/
}

//UŒ‚ƒpƒ^[ƒ“3
//¶‚©‚ç‰E‚É‚Ü‚Á‚·‚®‚É‘Å‚Â
void enemy_atk3(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//’e–‹‚ªŽn‚Ü‚é
		//“G‚ª“|‚³‚ê‚Ä‚È‚­A’e‚ðŒ‚‚Â‚±‚Æ‚ª‚Å‚«‚é‚È‚çA’e‚ð“o˜^‚·‚é
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//’e‚ÌŽí—Þ
			eny_shot[i].bullet[s].naname=-PI/2;//‰æ‘œ‚ÌŠp“x
			eny_shot[i].bullet[s].flag=1;//ƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
			eny_shot[i].bullet[s].x=eny[n].x;//’e‚Ì‚˜À•W
			eny_shot[i].bullet[s].y=eny[n].y;//’e‚Ì‚™À•W
			eny_shot[i].bullet[s].cnt=0;//ƒJƒEƒ“ƒ^
			eny_shot[i].bullet[s].sp=10;//ƒXƒs[ƒh
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp;//‚˜‘¬“x
			eny_shot[i].bullet[s].vy=0;//‚™‘¬“x
			se_flag[11]=1;//”­ŽË‰¹‚Ìƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
		}
	}
	/*
	eny_shot[i].vx=eny_shot[i].spd;
	eny_shot[i].naname=-PI/2;
	*/
}

//UŒ‚ƒpƒ^[ƒ“4
//Ž©‹@‚ÉŒü‚©‚Á‚Ä‘Å‚Â
void enemy_atk4(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {//’e–‹‚ªŽn‚Ü‚é
		//“G‚ª“|‚³‚ê‚Ä‚È‚­A’e‚ðŒ‚‚Â‚±‚Æ‚ª‚Å‚«‚é‚È‚çA’e‚ð“o˜^‚·‚é
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].ang=shotatan2(i);
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;//’e‚ÌŽí—Þ
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;//‰æ‘œ‚ÌŠp“x
			eny_shot[i].bullet[s].flag=1;//ƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
			eny_shot[i].bullet[s].x=eny[n].x;//’e‚Ì‚˜À•W
			eny_shot[i].bullet[s].y=eny[n].y;//’e‚Ì‚™À•W
			eny_shot[i].bullet[s].cnt=0;//ƒJƒEƒ“ƒ^
			eny_shot[i].bullet[s].sp=10;//ƒXƒs[ƒh
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);//‚˜‘¬“x
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);//‚™‘¬“x
			se_flag[11]=1;//”­ŽË‰¹‚Ìƒtƒ‰ƒO‚ðƒIƒ“‚É‚·‚é
		}
	}
	/*
	int t=eny_shot[i].cnt;
	if(t==0) {
		if(mc_num==0)
			eny_shot[i].ang=atan2f(eny_shot[i].y-blc.y, eny_shot[i].x-blc.x);
		else if(mc_num==1)
			eny_shot[i].ang=atan2f(eny_shot[i].y-atk.y, eny_shot[i].x-atk.x);
		else
			eny_shot[i].ang=atan2f(eny_shot[i].y-dfc.y, eny_shot[i].x-dfc.x);
		eny_shot[i].naname=eny_shot[i].ang-PI/2;
		eny_shot[i].vx=eny_shot[i].spd*cos((float)eny_shot[i].ang);
		eny_shot[i].vy=eny_shot[i].spd*sin((float)eny_shot[i].ang);
	}
	*/
}

//UŒ‚ƒpƒ^[ƒ“5
//100ƒJƒEƒ“ƒg’†‚É10”­AŽ©‹@‚ÉŒü‚©‚Á‚Ä’¼ü”­ŽË(Šp“x‹L‰¯)
void enemy_atk5(int i) {
	int n=eny_shot[i].num;
	int t=eny_shot[i].cnt;
	int s;
	if(t>=0 && t<100 && t%10==0) {
		if(t==0) {//Šp“x‚ð‹L‰¯‚·‚é
			eny_shot[i].ang=shotatan2(i);
		}
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}

	}
}

//UŒ‚ƒpƒ^[ƒ“6
//ˆÙ‚È‚éŠp“x‚©‚ç“¯Žž‚É‘¬‚¢’e‚ð‚T”­‘Å‚Â
void enemy_atk6(int i) {
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(eny_shot[i].cnt==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=10;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“7
//ˆÙ‚È‚éŠp“x‚©‚ç“¯Žž‚É’x‚¢’e‚ð‚T”­‘Å‚Â
void enemy_atk7(int i) {
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(eny_shot[i].cnt==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“8
//100ƒJƒEƒ“ƒg’†10”­AŽ©‹@‚ÉŒü‚©‚Á‚ÄƒXƒs[ƒh•Ï‰»‚µ‚Ä‘Å‚Â
void enemy_atk8(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<100 && t%10==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].ang=shotatan2(i);
			/*
			if(mc_num==0)
				eny_shot[i].ang=atan2f(blc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													blc.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
			else if(mc_num==1)
				eny_shot[i].ang=atan2f(atk.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													atk.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
			else
				eny_shot[i].ang=atan2f(dfc.y-eny[n].y+eny[n].ySize/2*sin((float)eny[n].ang), 
													dfc.x-eny[n].x+eny[n].ySize/2*cos((float)eny[n].ang));
													*/
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].ang-PI/2;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“9
//0.5•b‚¸‚Â‰~Œ`”­ŽË
void enemy_atk9(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%20==0) {
		double ang=shotatan2(i);
		for(int j=0; j<20; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=ang+2*PI/20*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//UŒ‚ƒpƒ^[ƒ“10
//‚Î‚çŽT‚«ƒVƒ‡ƒbƒg
void enemy_atk10(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double ang=shotatan2(i);

	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=ang+rang(PI/4);
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=(float)(3+rang(1.5));
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“11
//‚Î‚çŽT‚«ƒVƒ‡ƒbƒg(Œ¸‘¬)
void enemy_atk11(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double ang=shotatan2(i);

	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=ang+rang(PI/4);
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=(float)(4+rang(2.0));
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
	for(int j=0; j<ENY_SHOT_MAX; j++) {
		if(eny_shot[i].bullet[j].sp>1.5) {//‘¬“x‚ª1.5‚æ‚è‘å‚«‚¢‚à‚Ì‚ª‚ ‚ê‚ÎŒ¸‘¬
			eny_shot[i].bullet[j].sp-=0.04f;
			eny_shot[i].bullet[j].vx=eny_shot[i].bullet[j].sp*cos((float)eny_shot[i].bullet[j].ang);
			eny_shot[i].bullet[j].vy=eny_shot[i].bullet[j].sp*sin((float)eny_shot[i].bullet[j].ang);
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“12
//ŽÎ‚ß‚©‚ç‚Ü‚Á‚·‚®‘Å‚Â
void enemy_atk12(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny[n].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=10;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
			se_flag[11]=1;
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“13
//0.5•b‚¸‚ÂˆÙ‚È‚éŠp“x‚©‚ç“¯Žž‚É‘¬‚¢’e‚ð‚T”­‘Å‚Â
void enemy_atk13(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(t>=0 && t<100 && t%10==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=10;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//UŒ‚ƒpƒ^[ƒ“14
//0.5•b‚¸‚ÂˆÙ‚È‚éŠp“x‚©‚ç“¯Žž‚É’x‚¢’e‚ð‚T”­‘Å‚Â
void enemy_atk14(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	double r=PI/5;
	if(t>=0 && t<100 && t%10==0) {
		for(int j=0; j<5; j++) {
			if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
				eny_shot[i].bullet[s].knd=eny[n].bul_knd;
				eny_shot[i].bullet[s].ang=eny[n].ang-r+PI/10*j;
				eny_shot[i].bullet[s].naname=eny_shot[i].bullet[s].ang-PI/2;
				eny_shot[i].bullet[s].cnt=0;
				eny_shot[i].bullet[s].flag=1;
				eny_shot[i].bullet[s].x=eny[n].x;
				eny_shot[i].bullet[s].y=eny[n].y;
				eny_shot[i].bullet[s].sp=4;
				eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].bullet[s].ang);
				eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].bullet[s].ang);
				se_flag[11]=1;
			}
		}	
	}
}

//UŒ‚ƒpƒ^[ƒ“15
//ã‚©‚ç‰º‚Ö‚Ü‚Á‚·‚®˜A‘±‚Å‘Å‚Â
void enemy_atk15(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=PI;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=0;
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp;
			se_flag[11]=1;
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“16
//‰º‚©‚çã‚Ö‚Ü‚Á‚·‚®˜A‘±‚Å‘Å‚Â
void enemy_atk16(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=0;
			eny_shot[i].bullet[s].vy=-eny_shot[i].bullet[s].sp;
			se_flag[11]=1;
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“17
//‰E‚©‚ç¶‚Ö‚Ü‚Á‚·‚®˜A‘±‚Å‘Å‚Â
void enemy_atk17(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=-eny_shot[i].bullet[s].sp;
			eny_shot[i].bullet[s].vy=0;
			se_flag[11]=1;
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“18
//¶‚©‚ç‰E‚Ö‚Ü‚Á‚·‚®˜A‘±‚Å‘Å‚Â
void enemy_atk18(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t>=0 && t<120 && t%2==0) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].naname=-PI/2;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp;
			eny_shot[i].bullet[s].vy=0;
			se_flag[11]=1;
		}
	}
}

//UŒ‚ƒpƒ^[ƒ“19
//s“®ƒpƒ^[ƒ“113`120‚É‘Î‰ž‚µ‚½UŒ‚
void enemy_atk19(int i) {
	int t=eny_shot[i].cnt;
	int n=eny_shot[i].num;
	int s;
	if(t==0 || t==20 || t==40) {
		if(eny_shot[i].flag!=2 && (s=is_eny_shot_flag(i))!=-1) {
			eny_shot[i].ang=shotatan2(i);
			eny_shot[i].bullet[s].knd=eny[n].bul_knd;
			eny_shot[i].bullet[s].ang=eny_shot[i].ang;
			eny_shot[i].bullet[s].naname=eny_shot[i].ang-PI/2;
			eny_shot[i].bullet[s].cnt=0;
			eny_shot[i].bullet[s].flag=1;
			eny_shot[i].bullet[s].x=eny[n].x;
			eny_shot[i].bullet[s].y=eny[n].y;
			eny_shot[i].bullet[s].sp=3;
			eny_shot[i].bullet[s].vx=eny_shot[i].bullet[s].sp*cos((float)eny_shot[i].ang);
			eny_shot[i].bullet[s].vy=eny_shot[i].bullet[s].sp*sin((float)eny_shot[i].ang);
			se_flag[11]=1;
		}
	}
}