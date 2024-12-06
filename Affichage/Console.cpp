#include "Console.hpp"
using namespace std;

Console::Console() {}

Console::~Console() {}

void Console::affichage(Grille g, int iterations) {
    // Affichage du numéro de la grille 
    cout << "Grille n°" << (iterations+1) << " : " << endl;
    // Parcours de la grille
    for (int x = 0; x < g.get_nbLigne(); ++x) {
        for (int y = 0; y < g.get_nbColonne(); ++y) {
            cout << to_string(g.getValeur(y,x)) + " "; // Affichage de la valeur de la Cellule
        }
        cout << endl;
    }
    cout << endl;
}