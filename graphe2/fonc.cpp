#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "fonc.h"
#include <conio.h>
#include "myconio.h"
#include "objet.h"
#include <chrono>


using namespace std;

void avancer(int *nb2) {
	if (*nb2 < 100) { *nb2 = *nb2 + 5; }
}

void reculer(int *nb3) {
	if (*nb3 >= 0) {
		*nb3 = *nb3 - 5;
	}
}

void bas(int *nb0010) {
	if (*nb0010 < 100) { *nb0010 = *nb0010 + 5; }
}

void haut(int *nb2010) {
	if (*nb2010 > 5) { *nb2010 = *nb2010 - 5; }

}


void change(materiel& t, int *res) {
	gotoxy(0, 0);
	for (int i = 0; i < 3; i++) {
		cout << i << ":" << t.listearme[i] << " ";
	}
	cin >> *res;
	switch (*res)
	{
	case 0:cout << "vous avez choisi: " << t.listearme[0] << endl;
		break;
	case 1:cout << "vous avez choisi: " << t.listearme[1] << endl;
		break;
	case 2:cout << "vous avez choisi: " << t.listearme[2] << endl;
	}
}

void tire(materiel& tr, int *res, int nb, cible& tr2,int *pointeur,bool *pointeurt) {
	int random;
	srand(time(NULL));
	clrscr();
	gotoxy(0, 0);
	if (clock() < 10000) {
		if (tr.compte(res) <= 0) {
			cout << "plus de munition" << endl;
		}
		else {
			cout << "munition: " << tr.listmun[*res];
			cout << "chargeur: " << tr.lisnbchargeur[*res];
			cout << endl;
			for (int i = 0; i < 5; i++) {
				if (nb == tr2.position[i]) {
					*pointeur = *pointeur + 1;
					cout << "tire reussie" << endl;
					random = (rand() * 5) % 80;
					tr2.position[i] = random;
				}
			}
		}
	}
	else {
		clrscr();
		cout << "fin"<<endl;
		cout << "score=";
		*pointeurt = false;
	}

}

