#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
place_trops(Map* pmap, Player* player) {}

attack() {}

**/

struct Dices{
	int attack_dices[3];
	int defense_dices[3];
};

Dices Roll_dices(int num_attack, int num_defense) {
	
	Dices dices;
	int r;
	
	for (int i = 0; i < num_defense; i++) {
		r = (rand()%6)+1;
		dices.defense_dices[i] = r;
	}
	
	for (int i = 0; i < num_attack; i++) {
		r = (rand()%6)+1;
		dices.attack_dices[i] = r;
	}
	
	return dices;
}

int main() {
	Dices test;
	srand(time(NULL));
	test = Roll_dices(2,3);
	
	
	
	for (int i = 0; i < 2; i++) {
		printf("%d ",test.attack_dices[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		printf("%d ",test.defense_dices[i]);
	}
	
	printf("\n");
	
	return 0;
}
