#include "Graphique.hpp"

Graphique::Graphique() {}

Graphique::~Graphique() {}

void Graphique::run(Grille *g) {
    sf::RenderWindow window(sf::VideoMode(g->get_nbColonne() * g->getTaille(), g->get_nbLigne() * g->getTaille()), "Le Jeu de la Vie");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        affichage(g, window);
        g->calculGrille();
            
        sf::sleep(sf::milliseconds(10));
    }
}