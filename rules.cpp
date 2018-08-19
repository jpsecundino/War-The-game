#include "rules.h"
#include "war.h"

#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <ctime>

/*
TODO :
place_troops(Territory* territ, Player* player) {}

*/

struct Territory{
    int territory_id;
    int territory_soldiers_count;
    int territory_owner_id;

};

Dice roll_dice(int num_attack, int num_defense) {
    
    Dice dices;
    int r;
    
    for (int i = 0; i < num_defense; i++) {
        r = (rand()%6)+1;
        dices.defense_dices[i] = r;
    }
    std::sort(dices.defense_dices,dices.defense_dices+num_defense+1);
    
    for (int i = 0; i < num_attack; i++) {
        r = (rand()%6)+1;
        dices.attack_dices[i] = r;
    }
    std::sort(dices.attack_dices,dices.attack_dices+num_attack+1);
    
    return dices;
}

//return 1 if the attack wins and the defense has no soldiers
int attack(Territory* attack, Territory* defense,int soldiers_att,int soldiers_def) {
    
    if ((*attack).territory_soldiers_count < soldiers_att)
        printf("You don't have that number of soldiers to attack");

    if ((*defense).territory_soldiers_count < soldiers_def)
        printf("You don't have that number of soldiers to defend");

    //maximum of 3 dices
    if (soldiers_att > 4)
        soldiers_att = 3;
    if (soldiers_def > 4)
        soldiers_def = 3;

    Dice battle;

    //1 attack, 0 defense
    int wins[3];

    battle = roll_dice(soldiers_att, soldiers_def);

    //compare the greater dices of the users first
    for (int i = soldiers_def-1; i >=0 ; i--) {
        //attack wins
        if (battle.attack_dices[i] > battle.defense_dices[i]) {
            wins[soldiers_def - i] = 1;
            if ((*defense).territory_soldiers_count != 0) {
                (*defense).territory_soldiers_count--;
            }
        }
        //defense wins
        else {
            wins[soldiers_def - i] = 0;
            (*attack).territory_soldiers_count--;
        }
    }

    if ((*defense).territory_soldiers_count == 0)
        return 1;
    else
        return 0;
        
}

int draw_card(int valid[], int terr_per_p) {
    int r = rand() % players.size();
    if (valid[r] == terr_per_p)
        draw_card(valid,terr_per_p);
    valid[r]++;
    return r;
}

void distribute_territories(Game* game) {
    int valid[players.size()];
    terr_per_p = provinces.size() / players.size();
    for (int i = 0; i < provinces.size(); i++) {
        provinces[i] = draw_card(valid,terr_per_p);
    }
}


int main() {
    Dice test;
    srand(time(NULL));
    test = roll_dice(2, 3);
    
    return 0;
}
