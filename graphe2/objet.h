#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <iostream>
#include "myconio.h"

using namespace std;

class materiel {
public:
	int nbarme = 4;
	string listearme[3] = { "gun","fusil","AK47" };
	int lisnbchargeur[3] = { 2,3,4 };
	int listmun[3] = { 5,10,20 };
	int compte(int* choix) {
		if (listmun[*choix] > 0) {
			if (*choix < 2) {
				listmun[*choix]--;
			}
			else {
				listmun[*choix] -= 5;
			}
		}
		else {
			if (lisnbchargeur[*choix] > 0) {
				lisnbchargeur[*choix]--;
				switch (*choix)
				{
				case 0: listmun[*choix] = 5;
					break;
				case 1:listmun[*choix] = 10;
					break;
				case 2:listmun[*choix] = 20;
				}
			}
		}
		if (listmun[*choix] == 0 && lisnbchargeur[*choix] == 0) {
			return 0;
		}
		else {

			return 1;
		}
	}

};

//class pour les cible est leur generation
class cible {
public:
	char symb = 43;
	int position[5] = { 5, 10, 30 , 50 , 90 };
	void ini() {
		for (int i = 0; i < 5; i++) {
			gotoxy(position[i], 10);
			cout << symb;
		}
		gotoxy(0, 10);
	}
};

class score2 {
public:
	string tab[100] = {};
	int nbscore=0;
	void initab() {
		ifstream monFlux("test.txt");
		string ligne;
		int res=0;
		while (getline(monFlux, ligne)) {
			tab[res] = ligne;
			res++;
			nbscore++;
		}
		monFlux.clear();
	}
	void fscore(int re,bool t2) {
		cout << re << endl;
		if (t2 == 0) {
			tab[nbscore]=to_string(re);
			string const nomFichier("test.txt");
			ofstream monFlux(nomFichier.c_str());
			if (monFlux)
			{
				for (int i = 0; i <= nbscore; i++) {
					monFlux << tab[i] << endl;
				}
			}
			
		}
	}
};