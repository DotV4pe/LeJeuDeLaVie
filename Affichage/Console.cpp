#include "Console.hpp"
using namespace std;

Console::Console() {}

Console::~Console() {}

void Console::affichage(Grille g, int iterations) {
    string txt;
    cout << "Grille n°" << (iterations+1) << " : " << endl;
    for (int x = 0; x < g.get_nbLigne(); ++x) {
        for (int y = 0; y < g.get_nbColonne(); ++y) {
            if (g.getValeur(y,x) == 0) {
                txt = "0 ";
            } else if (g.getValeur(y,x) == 1) {
                txt = "1 ";
            } else if (g.getValeur(y,x) == 2) {
                txt = "2 ";
            } else if (g.getValeur(y,x) == 3) {
                txt = "3 ";
            } cout << txt;
        }
        cout << endl;
    }
    cout << endl;
}