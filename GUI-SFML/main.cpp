#include <ctime>
#include <cstdlib>
#include <fstream>
#include <filesystem>

#include "Grille.hpp"

using namespace std;

int main() {
    ifstream monFlux("data.txt");  //Ouverture d'un fichier en lecture

    if(monFlux)
    {
        cout << "Tout est prêt pour la lecture." << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

    int hauteur,longueur, taille;
    monFlux >> longueur;
    monFlux >> hauteur;
    taille = 75;

    Grille g(taille,longueur,hauteur);

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
