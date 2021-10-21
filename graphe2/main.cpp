#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "fonc.h"
#include "myconio.h"
#include "objet.h"

using namespace std;

int main() {
	char sym = 43;
	cible m2;
	materiel m;
	score2 m3;
	int res0;
	int* res = &res0;
	int nb = 5;
	int* nb0 = &nb;
	int nb10 = 10;
	int* nb010 = &nb10;
	int score = 0;
	int* pointeurscore = &score;
	bool t = true;
	bool* pointeurt = &t;
	change(m, res);
	m2.ini();
	m3.initab();
	while (t) {
		char e = _getch();
		switch (e)
		{
		case 13:tire(m, res, nb, m2, pointeurscore, pointeurt); m3.fscore(score,t); m2.ini();
			break;
		case 0x50: bas(nb010);
			break;
		case 0x48: haut(nb010);
			break;
		case 77: avancer(nb0);
			break;
		case 75: reculer(nb0);
			break;
		case 'a': change(m, res);
			break;
		}
		gotoxy(nb, nb10);

	}
} 