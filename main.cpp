#include <ctime>
#include <cstdlib>
#include <filesystem>

#include "Grille.hpp"

using namespace std;

int main() {
    string chemin;
    cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    cin >> chemin;
    cout << endl;
    ifstream monFlux(chemin);  //Ouverture d'un fichier en lecture

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
    taille = 25;

    Grille g(taille,longueur,hauteur);

    sf::RenderWindow window(sf::VideoMode(g.getLongueur() * g.getTaille(), g.getHauteur() * g.getTaille()), "Le Jeu de la Vie");
    monFlux.close();
    g.initializegrille();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        g.majGrille(window);
        g.calculGrille();
        // g.imprimerConsole();
        sf::sleep(sf::milliseconds(500));
    }

    return 0;
}
