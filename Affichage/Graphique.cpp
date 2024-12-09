#include "Graphique.hpp"

Graphique::Graphique() {}

Graphique::~Graphique() {}

void Graphique::affichage(Grille g, sf::RenderWindow &window) {
    window.clear(); 
    sf::RectangleShape cell(sf::Vector2f(g.getTaille(), g.getTaille())); // Création de rectangle (pixel) de taille x taille
    // Boucle pour parcourir la grille
    for (int x = 0; x < g.get_nbColonne(); ++x) { 
        for (int y = 0; y < g.get_nbLigne(); ++y) {
            cell.setPosition(x * g.getTaille(), y * g.getTaille()); // Position du rectangle en fonction de x et y
            if (g.getValeur(x,y) == 1) { // Changement de la couleur en fonction du type de Cellule que l'on a (Vivante)
                cell.setFillColor(sf::Color(238,238,238)); 
            }
            else if (g.getValeur(x,y) == 0) { // Changement de la couleur en fonction du type de Cellule que l'on a (Morte)
                cell.setFillColor(sf::Color(34,40,49)); 
            } else if (g.getValeur(x,y) == 2) { // Changement de la couleur en fonction du type de Cellule que l'on a (Obstacle Mort)
                cell.setFillColor(sf::Color(57,62,70)); 
            } else if (g.getValeur(x,y) == 3) { // Changement de la couleur en fonction du type de Cellule que l'on a (Obstacle Vivant)
                cell.setFillColor(sf::Color(0,173,181)); 
            }
            window.draw(cell); // Dessine le pixel dans la fenêtre
        }
    }
    window.display(); // Affichage de la fenêtre sur SFML
}