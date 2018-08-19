#ifndef RULES_H
#define RULES_H

#include "war.h"

struct Dice{
    int attack_dices[3];
    int defense_dices[3];
};

/** Returns the attack and defense dice in increasing order */
Dice roll_dices(int num_attack, int num_defense);

/** Return 1 if the attack wins and the defense has no soldiers */
int attack(Province* attack, Province* defense, int n_soldiers_attack, int n_soldier_defense);

// TODO docs
int draw_card(int valid[], int terr_per_p);

// TODO docs
void distribute_territories(Game* game);

#endif
