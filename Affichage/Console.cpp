#include "Console.hpp"

Console::Console() {}

Console::~Console() {}

void Console::affichage(Grille g, int iterations) {
    std::string txt;
    std::cout << "Grille n°" << (iterations+1) << " : " << std::endl;
    for (int x = 0; x < g.get_nbLigne(); ++x) {
        for (int y = 0; y < g.get_nbColonne(); ++y) {
            if (g.getValeur(y,x) == 0) {
                txt = "0 ";
            } else if (g.getValeur(y,x) == 1) {
                txt = "1 ";
            } else if (g.getValeur(y,x) == 2) {
                txt = "2 ";
            } std::cout << txt;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}