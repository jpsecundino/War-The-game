#include "war.h"

void new_round(Game & game);
void setup_game(Game & game);

int main() {

	// TODO register and listen to sockets
	// TODO accept clients
	// TODO setup and start game

	Game game;

	Player p1, p2;

	p1.name = "Prei Prei";
	p1.color = BLUE;

	p2.name = "Davida Cairuza";
	p2.color = GREEN;

	game.players.push_back(p1);
	game.players.push_back(p2);

	setup_game(game);

	// TODO loop rounds
	bool game_running = true;
	while (game_running) {
		// TODO anounce new round
		new_round(game);
		// TODO for each player (in sorted order)
		for (int i = 0; i < game.players.size(); i++) {
			Player & player = game.players[i];

			// TODO receive cards
			// TODO calc how many new soldiers
			// TODO receive player distribution of soldiers (and check objective)
			// TODO receive player attacks (and check objective)
			// TODO receive player movements (and objective)
			// TODO give card to player
		}
	}
	// TODO announce winner
	// TODO close sockets

	return 0;
}

void new_round(Game & game) {
	// TODO
}

void setup_game(Game & game) {
	// TODO
}

