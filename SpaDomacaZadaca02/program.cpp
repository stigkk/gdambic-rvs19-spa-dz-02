#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

const int velicina = 75;

void ispis(bool vl[velicina + 1][velicina + 1]) {
    for (int a = 1; a < velicina; a++) {
        for (int b = 1; b < velicina; b++) {
            if (vl[a][b] == true) {
                cout << " * ";
            }
            else {
                cout << "-";
            }
            if (b == velicina - 1) {
                //cout << std::endl;
            }
        }
    }
}

void kopja(bool vl[velicina + 1][velicina + 1], bool vl2[velicina + 1][velicina + 1]) {
    for (int a = 0; a < velicina; a++) {
        for (int b = 0; b < velicina; b++) { vl2[a][b] = vl[a][b]; }
    }
}
void stvaranje(bool vl[velicina + 1][velicina + 1]) {
    bool vl2[velicina + 1][velicina + 1] = {};
    kopja(vl, vl2);
    for (int a = 1; a < velicina; a++) {
        for (int b = 1; b < velicina; b++) {
            int ziv = 0;
            for (int c = -1; c < 2; c++) {
                for (int d = -1; d < 2; d++) {
                    if (!(c == 0 && d == 0)) {
                        if (vl2[a + c][b + d]) { ++ziv; }
                    }
                }
            }
            if (ziv < 2) { vl[a][b] = false; }
            else if (ziv == 3) { vl[a][b] = true; }
            else if (ziv > 3) { vl[a][b] = false; }
        }
    }
}



int main() {
	game_of_life the_game;
     
    bool vl[velicina + 1][velicina + 1] = {};
    vl[velicina / 2][velicina / 2] = true;
    vl[velicina / 2 - 1][velicina / 2] = true;
    vl[velicina / 2][velicina / 2 + 1] = true;
    vl[velicina / 2][velicina / 2 - 1] = true;
    vl[velicina / 2 + 1][velicina / 2 + 1] = true;
    
	bool dalje;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

        ispis(vl);
        stvaranje(vl);

		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);

	return 0;
}