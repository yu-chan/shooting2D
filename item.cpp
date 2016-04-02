#include "GV.h"

//アイテムが自機にヒットしたどうか
int is_hit(int i) {
	if(mc_num==0) {
		if(item[i].x<blc.x+60 && item[i].x+item[i].xSize>blc.x &&
			item[i].y<blc.y+60 && item[i].y+item[i].ySize>blc.y+10)
			return 1;
	} else if(mc_num==1) {
		if(item[i].x<atk.x+60 && item[i].x+item[i].xSize>atk.x &&
			item[i].y<atk.y+60 && item[i].y+item[i].ySize>atk.y+10)
			return 1;
	} else {
		if(item[i].x<dfc.x+60 && item[i].x+item[i].xSize>dfc.x &&
			item[i].y<dfc.y+60 && item[i].y+item[i].ySize>dfc.y+10)
			return 1;
	}
	return 0;
}

//アイテムの計算
void item_calc() {
	for(int i=0; i<ITEM_MAX; i++) {
		if(item[i].flag==1) {
			item[i].y+=item[i].sp;
			item[i].cnt++;
			//自機にヒットしたなら消える
			if(is_hit(i)==1) {
				item[i].flag=0;
				for(int j=0; j<ITEM_KND; j++) {
					if(item[j].knd==1) {
						se_flag[6]=1;
					} else if(item[j].knd==2) {
						se_flag[7]=1;
					} else if(item[j].knd==3) {
						se_flag[8]=1;
					} else {
						se_flag[10]=1;
					}
				}
			}
		}
	}
}