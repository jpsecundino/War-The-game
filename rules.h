#ifndef RULES_H
#define RULES_H

#include "war.h"

struct Dices{
    int attack_dices[3];
    int defense_dices[3];
};

//return the attack and defense dices in increasing order
Dices Roll_dices(int num_attack, int num_defense);

//return 1 if the attack wins and the defense has no soldiers
int attack(Territory* a,Territory* d,int soldier_at,int soldier_def);


int draw_card(int valid[], int terr_per_p);

void distribute_territories(Game* game);

#endif
