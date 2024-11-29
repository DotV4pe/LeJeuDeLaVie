#include <ctime>
#include <cstdlib>

#include "Grille.hpp"

using namespace std;

int main() {
    Grille g(10,50,50);

    sf::RenderWindow window(sf::VideoMode(g.getLongueur() * g.getTaille(), g.getHauteur() * g.getTaille()), "Le Jeu de la Vie");
    
    g.initializegrille();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        g.renderGrille(window);
        g.calculGrille();
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
