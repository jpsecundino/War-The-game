#include<stdio.h>
#include<stdlib.h>
#include<string>

struct Territory{
	int id_territory;
	int soldiers_count;
	int id_owner;

};

struct Objective{
	int id_objective;
	string obj_descript;
};
 
enum GeomFig{
	Circunf,
	Square,
	Triang,
};

struct Player{
	int id;
	string player_name;
	obj objective;
	vector<int> cards;
};

