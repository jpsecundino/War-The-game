#include "rules.h"
#include "war.h"

#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <ctime>

/*
TODO :
place_trops(Territory* territ, Player* player) {}

*/

struct Territory{
	int territory_id;
	int territory_soldiers_count;
	int territory_owner_id;

};

Dices Roll_dices(int num_attack, int num_defense) {
	
	Dices dices;
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
int attack(Territory* a,Territory* d,int soldier_at,int soldier_def) {
	
		if ((*a).territory_soldiers_count < soldier_at) printf("You don't have that number of soldiers to attack");
		if ((*d).territory_soldiers_count < soldier_def) printf("You don't have that number of soldiers to defend");
		
		//maximum of 3 dices
		if (soldier_at > 4) soldier_at = 3;
		if (soldier_def > 4) soldier_def = 3; 
		
		
		Dices battle;
		
		//1 attack, 0 defense
		int wins[3]; 
		
		battle = Roll_dices(soldier_at,soldier_def);
		
		//compare the greater dices of the users first
		for (int i = soldier_def-1; i >=0 ; i--) {
				//attack wins
				if(battle.attack_dices[i] > battle.defense_dices[i]) {
					 wins[soldier_def - i] = 1;
					 if ((*d).territory_soldiers_count != 0)(*d).territory_soldiers_count--;
				 }
				//defense wins
				else {
					wins[soldier_def - i] = 0;
					(*a).territory_soldiers_count--;
				}
		}
		
		if((*d).territory_soldiers_count == 0) return 1;
		else return 0;
		
}

int draw_card(int valid[], int terr_per_p) {
		int r = rand()%players.size();
		if (valid[r] == terr_per_p) draw_card(valid,terr_per_p);
		valid[r]++;
		return r;
}

void distribute_territories(Game* game) {
		
		int valid[players.size()];
		terr_per_p = provinces.size()/players.size();
		for (int i = 0; i < provinces.size(); i++) {
						provinces[i] = draw_card(valid,terr_per_p);
				}
		}
}


int main() {
	Dices test;
	srand(time(NULL));
	test = Roll_dices(2,3);
	
	
	
	return 0;
}
