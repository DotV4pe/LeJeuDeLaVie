#include "Graphique.hpp"

Graphique::Graphique() {}

Graphique::~Graphique() {}

void Graphique::affichage(Grille g, sf::RenderWindow &window) {
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(g.getTaille(), g.getTaille()));
    for (int x = 0; x < g.get_nbColonne(); ++x) {
        for (int y = 0; y < g.get_nbLigne(); ++y) {
            cell.setPosition(x * g.getTaille(), y * g.getTaille());
            if (g.getValeur(x,y) == 1) {
                cell.setFillColor(sf::Color(166,77,121));
            }
            else if (g.getValeur(x,y) == 0) {
                cell.setFillColor(sf::Color(26,26,29)); 
            } else if (g.getValeur(x,y) == 2) {
                cell.setFillColor(sf::Color(106,30,85)); 
            } else if (g.getValeur(x,y) == 3) {
                cell.setFillColor(sf::Color(228,177,240)); 
            }
            window.draw(cell);
        }
    }
    window.display();
}