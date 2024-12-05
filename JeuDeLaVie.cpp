#include "JeuDeLaVie.hpp"

JeuDeLaVie::JeuDeLaVie() {}

JeuDeLaVie::~JeuDeLaVie() {}

void JeuDeLaVie::run(Grille grid, Fichier *f, int mode) {
    int temps, iterations;
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
            s->sauvegarder(grid, nom_sortie);
            cons.affichage(grid, cycle);
            updateGrille(grid);
        }
    }
    else if (mode == 2) {
        std::cout << "Entrez le temps de génération de chaque cycle (en ms) : ";
        std::cin >> temps;
        std::cout << "Temps initialisé à " << temps << "ms\n" << std::endl;
        Graphique graph;
        std::cout << grid.get_nbColonne() << ", " << grid.get_nbLigne() << std::endl;
        sf::RenderWindow window(sf::VideoMode(grid.get_nbColonne() * grid.getTaille(), grid.get_nbLigne() * grid.getTaille()), "Le Jeu de la Vie");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            graph.affichage(grid, window);
            updateGrille(grid);
                
            sf::sleep(sf::milliseconds(temps));
        }
    }
}

void JeuDeLaVie::updateGrille(Grille &grid) {
    if (torique == 0) {
        std::vector<std::vector<Cellule>> tgrille = grid.getGrille();
        for (int x = 0; x < grid.get_nbColonne(); ++x) {
            for (int y = 0; y < grid.get_nbLigne(); ++y) {
                int compteur = 0;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        
                        int nx = (x + dx + grid.get_nbColonne()) % grid.get_nbColonne();
                        int ny = (y + dy + grid.get_nbLigne()) % grid.get_nbLigne();

                        if ((tgrille[nx][ny].estVivant() % 2) == 1) {
                            compteur++;
                        }
                    }
                }
                grid.update(x,y,compteur);
            }
        }
    } else if (torique == 1) {
        std::vector<std::vector<Cellule>> tgrille = grid.getGrille();

        for (int x = 0; x < grid.get_nbColonne(); ++x) {
            for (int y = 0; y < grid.get_nbLigne(); ++y) {
                int compteur = 0;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (dx != 0 || dy != 0) {
                            if (nx < grid.get_nbColonne()) {
                                if (nx > 0) {
                                    if (ny < grid.get_nbLigne()) {
                                        if (ny > 0) {
                                            if ((tgrille[nx][ny].estVivant() % 2) == 1) {
                                                compteur++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                grid.update(x,y,compteur);
            }
        }
    }
}