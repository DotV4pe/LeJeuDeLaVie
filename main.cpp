#include "Grille.hpp"
#include <iostream>
#include <limits>

int main() {
    int mode; // voir si ce n'est pas mieux de faire une classe avec enum ?
    std::cout << "Choisissez le mode :\n";
    std::cout << "1. Terminal\n";
    std::cout << "2. Graphique\n";
    std::cout << "Votre choix : ";
    std::cin >> mode;

    if (mode != 1 && mode != 2) {
        std::cout << "Choix invalide. Mode par défaut : Terminal\n";
        mode = 1;
    }

    std::string chemin;
    std::cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    std::cin >> chemin;

    int iterations = 0;
    if (mode == 1){
        std::cout << "Nombre de cycles du jeu de la vie : ";
        std::cin >> iterations;
    }

    // ouverture du fichier initial
    std::ifstream monFlux(chemin);
    if (!monFlux) {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        return 1;
    }

    int hauteur, longueur;
    monFlux >> hauteur >> longueur;
    int taille = 20;
    Grille g(taille, longueur, hauteur);
    
    monFlux.close();
    g.initializegrille(chemin);

    if (mode == 2) {
        sf::RenderWindow window(sf::VideoMode(g.get_nbColonne() * g.getTaille(), g.get_nbLigne() * g.getTaille()), "Le Jeu de la Vie");
        
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
           
            g.majGrille(window);
            g.calculGrille();
            
            sf::sleep(sf::milliseconds(500));
        }
    } 
    else{
        // Mode Terminal
        for (int cycle = 0; cycle < iterations; ++cycle) {
            // Fichier de sortie pour chaque cycle
            std::string nom_sortie = "Cycles/cycle_" + std::to_string(cycle) + ".txt";
            g.imprimerFichier(nom_sortie);

            g.imprimerConsole();
            g.calculGrille();
        }
    }

    return 0;
}