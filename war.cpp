#include<stdio.h>
#include<stdlib.h>
#include<string>

struct Territorio{
	int id_territorio;
	int qtd_de_soldados;
	int id_dono;

};

struct Objetivo{
	int id_objetivo;
	string descricao_objetivo;
};

struct Jogador{
	int id;
	string nome;
	obj objetivo;
	vector<int> cartas;
};

