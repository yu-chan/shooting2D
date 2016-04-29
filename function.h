//start.cpp
//スタート画面
GLOBAL void start_display();
GLOBAL void how_play();

//load.cpp
//データのロード
GLOBAL void load();
GLOBAL void load_story();
GLOBAL void load_boss();

//ini.cpp
//データの初期化
GLOBAL void ini();

//keyboard.cpp
GLOBAL int getKey();
GLOBAL int checkKey(unsigned char Handle);

//music.cpp
GLOBAL void sound_ini();
GLOBAL void sound_play();
GLOBAL void delete_bgm();
GLOBAL void bgm_main();

//graph.cpp
GLOBAL void graph_start_back();
GLOBAL void graph_select_stage();
GLOBAL void graph_play();

//blance_type.cpp
GLOBAL void blc_calc();
GLOBAL void blc_move();

//mc_shot.cpp
GLOBAL int is_shot_flag();
GLOBAL void mc_shot();

//mc_laser.cpp
GLOBAL void mc_laser();

//enemy.cpp
GLOBAL void enemy_main();

//eny_shot.cpp
GLOBAL double shotatan2(int i);
GLOBAL int is_eny_shot_flag(int i);
GLOBAL void enemy_shot();

//effect.cpp
GLOBAL void effect();
GLOBAL int is_charge_flag();
GLOBAL void beam_charge_regist(int i);
GLOBAL int is_charge_end();

//eny_act_pattern.cpp
GLOBAL double rang(double ang);

//boss.cpp
GLOBAL void boss_main();
GLOBAL void regist_phy(float pos_x, float pos_y, int t);
GLOBAL void calc_phy();

//boss_shot.cpp
GLOBAL void boss_danmaku_main();
GLOBAL double bossatan2(float x, float y);
GLOBAL int is_boss_shot_flag(int i);
GLOBAL int is_boss_beam_flag(int i);

//boss_atk_pattern.cpp
GLOBAL float boss_shot_x_place(int i);
GLOBAL float boss_shot_y_place(int i);

//clear_or_over.cpp
GLOBAL void c_o_main();
GLOBAL void clear_regist();
GLOBAL void over_regist();
