#ifndef _ANIMATIONPLAYER_H
#define _ANIMATIONPLAYER_H

#include "utils/list.h"
#include "video/texture.h"
#include "audio/sound_state.h"

typedef struct aniplayer_sprite_t {
    int x,y;
    texture *tex;
    int blendmode;
} aniplayer_sprite;

typedef struct aniplayer_slide_op_t {
    int x_per_tick;
    int y_per_tick;
    int enabled;
} aniplayer_slide_op;

typedef struct animationplayer_t {
    unsigned int id;
    unsigned int finished;
    unsigned int ticks;
    
    animation *ani;
    sound_state *snd;
    sd_stringparser *parser;
    
    aniplayer_slide_op slide_op;
    
    int x,y;
    aniplayer_sprite *obj;
    void *userdata;
    
    void (*del_player)(void *userdata, int id);
    void (*add_player)(void *userdata, int id, int mx, int my);
} animationplayer;

int animationplayer_create(animationplayer *player, unsigned int id, animation *animation);
void animationplayer_free(animationplayer *player);
void animationplayer_run(animationplayer *player);
void animationplayer_render(animationplayer *player);
void animationplayer_reset(animationplayer *player);

#endif // _ANIMATIONPLAYER_H
