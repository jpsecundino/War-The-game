#include <string>
#include <vector>

using std::string;
using std::vector;

enum GeomFig{
	Circunf,
	Square,
	Triang
};

enum Color{
	white,
	black,
	red,
	blue,
	yellow,
	green
};

struct Territory{
	int territory_id;
	int territory_soldiers_count;
	int territory_owner_id;

};

struct Objective{
	int objective_id;
	string objective_descript;
};

struct Cards{
	int card_id;
	int card_territory_id;
	GeomFig card_figure; 

};

struct Player{
	int id;
	string player_name;
	Objective player_objective;
	vector<Cards> player_cards;
	Color player_color;
	string player_ip;
	int player_exchanges; 
};



