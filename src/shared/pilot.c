#include <stdio.h>
#include "pilot.h"

static const char *har_list[] = {
    "Jaguar",
    "Shadow",
    "Thorn",
    "Pyros",
    "Electra",
    "Katana",
    "Shredder",
    "Flail",
    "Gargoyle",
    "Chronos",
    "Nova"
};

static const char *difficulty_names[] = {
    "Aluminum",
    "Iron",
    "Steel",
    "Heavy Metal",
};

void print_bytes(char *buf, int len, int line, int padding) {
    for(int k = 0; k < padding; k++) {
        printf(" ");
    }
    for(int i = 1; i <= len; i++) {
        printf("%02x ", (uint8_t)buf[i-1]);
        if(i % line == 0) {
            if(len != i) {
                printf("\n");
            }
            for(int k = 0; k < padding; k++) {
                printf(" ");
            }
        }
    }
}

void print_pilot_player_info(sd_pilot *pilot) {
    if(pilot) {
        printf("  - Name:            %s\n", pilot->name);
        printf("  - Wins:            %d\n", pilot->wins);
        printf("  - Losses:          %d\n", pilot->losses);
        printf("  - Rank:            %d\n", pilot->rank);
        if(pilot->har_id == 255)
            printf("  - Har:             Random\n");
        else
            printf("  - Har:             %s\n", har_list[pilot->har_id]);
        printf("  - Arm Power:       %d\n", pilot->arm_power);
        printf("  - Leg Power:       %d\n", pilot->leg_power);
        printf("  - Arm Speed:       %d\n", pilot->arm_speed);
        printf("  - Leg Speed:       %d\n", pilot->leg_speed);
        printf("  - Armor:           %d\n", pilot->armor);
        printf("  - Stun Res.:       %d\n", pilot->stun_resistance);
        printf("  - Power:           %d\n", pilot->power);
        printf("  - Agility:         %d\n", pilot->agility);
        printf("  - Endurance:       %d\n", pilot->endurance);
        printf("  - Unknown:         %d\n", pilot->unknown_stat);
        printf("  - Offense:         %d\n", pilot->offense);
        printf("  - Defense:         %d\n", pilot->defense);
        printf("  - Money:           %d\n", pilot->money);
        printf("  - Color:           %d,%d,%d\n",
            pilot->color_1,
            pilot->color_2,
            pilot->color_3);
    }
}

void print_pilot_info(sd_pilot *pilot) {
    if(pilot != NULL) {
        printf("### Pilot header for %s:\n", pilot->name);

        print_pilot_player_info(pilot);

        printf("  - TRN Name:        %s\n", pilot->trn_name);
        printf("  - TRN Desc:        %s\n", pilot->trn_desc);
        printf("  - TRN Image:       %s\n", pilot->trn_image);
        printf("  - Difficulty:      %s\n", difficulty_names[pilot->difficulty]);

        printf("  - unk_block_a:\n");
        print_bytes(pilot->unk_block_a, sizeof(pilot->unk_block_a), 16, 5);
        printf("\n");
        printf("  - Pilot ID:        %d\n", pilot->pilot_id);
        printf("  - Unknown K:       %d\n", pilot->unknown_k);
        printf("  - Force arena:     %d\n", pilot->force_arena);
        printf("  - unk_block_b: ");
        print_bytes(pilot->unk_block_b, sizeof(pilot->unk_block_b), 16, 0);
        printf("\n");
        printf("  - Movement:        %d\n", pilot->movement);
        printf("  - unk_block_c: ");
        print_bytes(pilot->unk_block_c, sizeof(pilot->unk_block_c), 16, 0);
        printf("\n");
        printf("  - Enhancements:\n");
        for(int i = 0; i < 11; i++) {
            printf("     * %-10s: %x\n", har_list[i], pilot->enhancements[i]);
        }

        printf("  - Secret:          %d\n", pilot->secret);
        printf("  - Only fight once: %d\n", pilot->only_fight_once);
        printf("  - Requirements:\n");
        printf("    * Rank:          %d\n", pilot->req_rank);
        printf("    * Max rank:      %d\n", pilot->req_max_rank);
        printf("    * Fighter:       %d\n", pilot->req_fighter);
        printf("    * Difficulty:    %d\n", pilot->req_difficulty);
        printf("    * Enemy:         %d\n", pilot->req_enemy);
        printf("    * Vitality:      %d\n", pilot->req_vitality);
        printf("    * Accuracy:      %d\n", pilot->req_accuracy);
        printf("    * Avg Damage:    %d\n", pilot->req_avg_dmg);
        printf("    * Scrap:         %d\n", pilot->req_scrap);
        printf("    * Destruction    %d\n", pilot->req_destroy);

        printf("  - Attitude:\n");
        printf("    * Normal:        %d\n", pilot->att_normal);
        printf("    * Hyper:         %d\n", pilot->att_hyper);
        printf("    * Jump:          %d\n", pilot->att_jump);
        printf("    * Def:           %d\n", pilot->att_def);
        printf("    * Sniper:        %d\n", pilot->att_sniper);

        printf("  - unk_block_d: ");
        print_bytes(pilot->unk_block_d, sizeof(pilot->unk_block_d), 16, 0);
        printf("\n");

        printf("  - AP Throw:        %d\n", pilot->ap_throw);
        printf("  - AP Special:      %d\n", pilot->ap_special);
        printf("  - AP Jump:         %d\n", pilot->ap_jump);
        printf("  - AP High:         %d\n", pilot->ap_high);
        printf("  - AP Low:          %d\n", pilot->ap_low);
        printf("  - AP Middle:       %d\n", pilot->ap_middle);

        printf("  - Pref jump:       %d\n", pilot->pref_jump);
        printf("  - Pref fwd:        %d\n", pilot->pref_fwd);
        printf("  - Pref back:       %d\n", pilot->pref_back);

        printf("  - Unknown E:       %d\n", pilot->unknown_e);
        printf("  - Learning:        %f\n", pilot->learning);
        printf("  - Forget:          %f\n", pilot->forget);

        printf("  - unk_block_f: ");
        print_bytes(pilot->unk_block_f, sizeof(pilot->unk_block_f), 26, 0);
        printf("\n");

        printf("  - Enemies (inc unranked): %d\n", pilot->enemies_inc_unranked);
        printf("  - Enemies (exl unranked): %d\n", pilot->enemies_ex_unranked);

        printf("  - unk_block_g: ");
        print_bytes(pilot->unk_block_g, sizeof(pilot->unk_block_g), 26, 0);
        printf("\n");

        printf("  - Winnings:        %d\n", pilot->winnings);
        printf("  - Total value:     %d\n", pilot->total_value);

        printf("  - unk_block_h:\n");
        print_bytes(pilot->unk_block_h, sizeof(pilot->unk_block_h), 16, 4);
        printf("\n");

        printf("  - Photo ID         %d\n", pilot->photo_id);
    }
}