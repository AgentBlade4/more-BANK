#include "ac_t_bag2.h"

#include "m_name_table.h"
#include "sys_matrix.h"
#include "m_lib.h"
#include "m_rcp.h"


static void aTBG2_actor_ct(ACTOR* actor, GAME*);
static void aTBG2_actor_move(ACTOR* actor, GAME*);
static void aTBG2_actor_draw(ACTOR* actor, GAME*);
static void aTBG2_setupAction(ACTOR*, int);

ACTOR_PROFILE T_Bag2_Profile = {
    mAc_PROFILE_T_BAG2,
    ACTOR_PART_BG,
    ACTOR_STATE_NO_DRAW_WHILE_CULLED | ACTOR_STATE_NO_MOVE_WHILE_CULLED,
    EMPTY_NO,
    ACTOR_OBJ_BANK_TOOLS,
    sizeof(BAG2_ACTOR),
    &aTBG2_actor_ct,
    NONE_ACTOR_PROC,
    &aTBG2_actor_move,
    &aTBG2_actor_draw,
    NULL
};

extern Gfx crw_bag2_body_model[];

static void aTBG2_actor_ct(ACTOR* actor, GAME*){

    aTBG2_setupAction(actor,4);
}

static void aTBG2_destruct(ACTOR* actor){

    Actor_delete(actor);
}


static void aTBG2_setupAction(ACTOR*actor, int action){
    BAG2_ACTOR* bag = (BAG2_ACTOR*)actor;
    static BAG2_PROC process[] = {
        (BAG2_PROC)none_proc1,(BAG2_PROC)none_proc1,(BAG2_PROC)none_proc1,aTBG2_destruct,(BAG2_PROC)none_proc1,NULL
    };

    bag->proc = process[action];
    bag->current_id = action;
    bag->tools_class.process_id = action;

}

static void aTBG2_actor_move(ACTOR* actor, GAME*){
    BAG2_ACTOR* bag = (BAG2_ACTOR*)actor;

    if(bag->tools_class.process_id != bag->current_id){
        aTBG2_setupAction(actor, bag->tools_class.process_id);
    }

    bag->proc(actor);
}

static void aTBG2_actor_draw(ACTOR* actor, GAME* game){
    BAG2_ACTOR* bag = (BAG2_ACTOR*)actor;

    GRAPH* graph;
    Gfx* gfxp;

    if(bag->tools_class.enable == 1){
        graph = game->graph;
        
        OPEN_DISP(graph);
        
        Matrix_put(&bag->tools_class.matrix_work);
        Matrix_Position_Zero(&bag->tools_class.actor_class.world.position);
        
        bag->tools_class.enable = 0;
    
        _texture_z_light_fog_prim_npc(graph); 

        gfxp = NOW_POLY_OPA_DISP;
        gSPMatrix(gfxp++, _Matrix_to_Mtx_new(graph),G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfxp++, crw_bag2_body_model);
        SET_POLY_OPA_DISP(gfxp);
        
        CLOSE_DISP(graph);
    }

        
}