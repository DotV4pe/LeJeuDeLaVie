#include "GrilleTerm.hpp"
#include "GrilleGraph.hpp"
#include <iostream>

using namespace std;

int affichageMenu(){
    int m; // voir si ce n'est pas mieux de faire une classe avec enum ?
    cout << "Choisissez le mode :\n";
    cout << "1. Terminal\n";
    cout << "2. Graphique\n";
    cout << "Votre choix : ";
    cin >> m;
    return m;
}

int main() {
    int mode = affichageMenu();

    Grille *g;

    if (mode==1){
        g = new GrilleTerm();
    } else if (mode==2)
    {
        g = new GrilleGraph();
    } else {
        cout << "Choix invalide. Mode par défaut : Terminal\n";
        mode = 1;
        g = new GrilleTerm();
    }
    

    int hauteur, longueur;
    monFlux >> hauteur >> longueur;
    int taille = 20;
    
    
    monFlux.close();

    if (mode == 2) {
        g = new GrilleGraph(taille,hauteur,longueur);
        g->initializegrille(chemin);
        sf::RenderWindow window(sf::VideoMode(g->get_nbColonne() * g->getTaille(), g->get_nbLigne() * g->getTaille()), "Le Jeu de la Vie");
        
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        
            g->affichage(window);
            g->calculGrille();
            
            sf::sleep(sf::milliseconds(500));
        }
    } 
    else {
        g = new GrilleTerm(taille,hauteur,longueur);
        g->initializegrille(chemin);
        // Mode Terminal
        for (int cycle = 0; cycle < iterations; ++cycle) {
            // Fichier de sortie pour chaque cycle
            string nom_sortie = "Cycles/cycle_" + to_string(cycle) + ".txt";
            g->imprimerFichier(nom_sortie);

            g->affichage();
            g->calculGrille();
        }
    }

    return 0;
}