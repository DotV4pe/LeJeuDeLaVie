#include "JeuDeLaVie.hpp"

JeuDeLaVie::JeuDeLaVie() {}

JeuDeLaVie::~JeuDeLaVie() {}

void JeuDeLaVie::affichage(Grille *g, sf::RenderWindow &window) {
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(g->getTaille(), g->getTaille()));
    for (int x = 0; x < g->get_nbColonne(); ++x) {
        for (int y = 0; y < g->get_nbLigne(); ++y) {
            cell.setPosition(x * g->getTaille(), y * g->getTaille());
            if (g->getValeur(x,y) == 1) {
                cell.setFillColor(sf::Color(166,77,121));
            }
            else if (g->getValeur(x,y) == 0) {
                cell.setFillColor(sf::Color(26,26,29)); 
            } else if (g->getValeur(x,y) == 2) {
                cell.setFillColor(sf::Color(106,30,85)); 
            }
            window.draw(cell);
        }
    }
    window.display();
}

void JeuDeLaVie::affichage(Grille *g) {
    std::string txt;
    std::cout << "Grille : " << std::endl;
    for (int x = 0; x < g->get_nbLigne(); ++x) {
        for (int y = 0; y < g->get_nbColonne(); ++y) {
            if (g->getValeur(y,x) == 0) {
                txt = "0 ";
            } else if (g->getValeur(y,x) == 1) {
                txt = "1 ";
            } else if (g->getValeur(y,x) == 2) {
                txt = "2 ";
            } std::cout << txt;
        }
        std::cout << std::endl;
    }
}