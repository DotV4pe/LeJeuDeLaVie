#include "JeuDeLaVie.hpp"

JeuDeLaVie::JeuDeLaVie() {}

JeuDeLaVie::~JeuDeLaVie() {}

void JeuDeLaVie::run(Grille g, Fichier *f, int mode) {
    int temps, iterations, torique;
    std::cout << "Voulez-vous une grille torique : " << std::endl;
    std::cout << "0. Oui" << std::endl;
    std::cout << "1. Non" << std::endl;
    std::cout << "Votre choix : ";
    std::cin >> torique;
    if (torique == 0){
        std::cout << "Grille torique initialisée \n" << std::endl;
    } else {
        std::cout << "Grille non torique initialisée \n" << std::endl;
    }
    if (mode == 1) {
        Console cons;
        Sauvegarde *s = new SauvegardeFichierTxt();
        std::string cheminDossier = f->getDossierSortie(); // Utiliser le chemin du dossier de sortie

        std::cout << "Nombre de cycles du jeu de la vie : ";
        std::cin >> iterations;
        for (int cycle = 0; cycle < iterations; cycle++) {
            // Fichier de sortie pour chaque cycle
            std::string nom_sortie = cheminDossier + "/cycle_" + std::to_string(cycle+1) + ".txt";
            s->sauvegarder(g, nom_sortie);
            cons.affichage(g, cycle);
            if (torique == 0){
                g.calculGrilleTorique();
            } else {
                g.calculGrilleNonTorique();
            }
        }
    }
    else if (mode == 2) {
        std::cout << "Entrez le temps de génération de chaque cycle (en ms) : ";
        std::cin >> temps;
        std::cout << "Temps initialisé à " << temps << "ms\n" << std::endl;
        Graphique graph;
        sf::RenderWindow window(sf::VideoMode(g.get_nbColonne() * g.getTaille(), g.get_nbLigne() * g.getTaille()), "Le Jeu de la Vie");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            graph.affichage(g, window);
            if (torique == 0){
                g.calculGrilleTorique();
            } else {
                g.calculGrilleNonTorique();
            }
                
            sf::sleep(sf::milliseconds(temps));
        }
    }
}