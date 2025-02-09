#ifndef AC_MY_ROOM_H
#define AC_MY_ROOM_H

#include "types.h"
#include "m_actor.h"
#include "ac_furniture.h"
#include "m_room_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct my_room_actor_s MY_ROOM_ACTOR;

typedef struct my_room_clock_info_s {
  int tick0; /* set on frame 15 */
  int tick1; /* set on frame 45 */
  int tick_stop; /* set on frame 0 */
  int frame; /* 0-119 */
} aMR_clock_info_c;

typedef int (*aMR_JUDGE_BREED_NEW_FTR_PROC)(GAME_PLAY* play, u16 ftr_no, int* ut_x, int* ut_z, u16* rotation, int* square_offset, int* layer);
typedef mActor_name_t (*aMR_SEARCH_PICKUP_FURNITURE_PROC)(GAME_PLAY* play);
typedef void (*aMR_FURNITURE2ITEMBAG_PROC)(GAME_PLAY* play);
typedef int (*aMR_JUDGE_PLAYER_ACTION_PROC)(xyz_t* wpos0, xyz_t* wpos1, int ftr_actor_idx);
typedef void (*aMR_PLAYER_MOVE_FURNITURE_PROC)(int ftr_actor_idx, xyz_t* wpos);
typedef int (*aMR_FTR_ID_2_WPOS_PROC)(xyz_t* wpos, int ftr_id);
typedef int (*aMR_UNIT_NUM_2_FTR_ITEMNO_FTRID_PROC)(mActor_name_t* ftr_item_no, int* ftr_id, int ut_x, int ut_z, s16 layer);
typedef void (*aMR_FTR_ID_2_EXTINGUISH_FURNITURE_PROC)(int ftr_id);
typedef void (*aMR_REDMA_FTR_BANK_PROC)();
typedef int (*aMR_RESERVE_FURNITURE_PROC)(GAME_PLAY* play, u16 ftr_no, int judge_res, int ut_x, int ut_z, u16 rotation, int square_offset, int layer);
typedef int (*aMR_COUNT_FRIEND_FURNITURE_PROC)(FTR_ACTOR* ftr_actor, u8 switch_on);
typedef int (*aMR_JUDGE_PLACE_2ND_LAYER_PROC)(int ut_x, int ut_z);
typedef void (*aMR_OPEN_CLOSE_COMMON_MOVE_PROC)(FTR_ACTOR* ftr_actor, ACTOR* actor, GAME* game, f32 start_frame, f32 end_frame);

typedef struct my_room_clip_s {
  MY_ROOM_ACTOR* my_room_actor_p;
  aMR_JUDGE_BREED_NEW_FTR_PROC judge_breed_new_ftr_proc;
  aMR_SEARCH_PICKUP_FURNITURE_PROC search_pickup_ftr_proc;
  aMR_FURNITURE2ITEMBAG_PROC ftr2itemBag_proc;
  aMR_JUDGE_PLAYER_ACTION_PROC judge_player_action_proc;
  aMR_PLAYER_MOVE_FURNITURE_PROC player_move_ftr_proc;
  aMR_FTR_ID_2_WPOS_PROC ftrId2wpos_proc;
  aMR_UNIT_NUM_2_FTR_ITEMNO_FTRID_PROC unitNum2ftrItemNoftrId_proc;
  aMR_FTR_ID_2_EXTINGUISH_FURNITURE_PROC ftrId2extinguishFtr_proc;
  aMR_REDMA_FTR_BANK_PROC redma_ftr_bank_proc;
  aMR_RESERVE_FURNITURE_PROC reserve_ftr_proc;
  aMR_COUNT_FRIEND_FURNITURE_PROC count_friend_ftr_proc;
  aMR_JUDGE_PLACE_2ND_LAYER_PROC judge_place_2nd_layer_proc;
  aMR_OPEN_CLOSE_COMMON_MOVE_PROC open_close_common_move_proc;
  /* TODO: function definitions */
  void* get_bed_action_proc;
  void* mini_disk_common_move_proc;
  void* famicom_emum_common_move_proc;
  void* set_leaf_proc;
  void* ftr2leaf_proc;
  void* leaf_start_pos_proc;
  void* pickup_ftr_layer_proc;
  void* leaf_pickuped_proc;
  void* ftrNo2bankAddress_proc;
  void* call_sit_down_ongen_pos_se_proc;
  aMR_clock_info_c* clock_info_p; /* used for playing the clock tick? sfx */
  void* sound_melody_proc;
  void* check_danna_kill_proc;
} aMR_Clip_c;

/* TODO: my room actor */

extern ACTOR_PROFILE My_Room_Profile;

extern int aMR_CorrespondFurniture(mActor_name_t ftr0, mActor_name_t ftr1);
extern int aMR_GetFurnitureUnit(mActor_name_t ftr);
extern mActor_name_t aMR_FurnitureFg_to_FurnitureFgWithDirect(mActor_name_t ftr, int direct);

#ifdef __cplusplus
}
#endif

#endif

