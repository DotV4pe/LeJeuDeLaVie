#include "JeuDeLaVie.hpp"

JeuDeLaVie::JeuDeLaVie() {}

JeuDeLaVie::~JeuDeLaVie() {}

void JeuDeLaVie::run(Grille g, Fichier *f, int mode) {
    if (mode == 1) {
        Console cons;
        Sauvegarde *s = new SauvegardeFichierTxt();
        std::string cheminDossier = f->getDossierSortie(); // Utiliser le chemin du dossier de sortie
        std::cout << f->getDossierSortie() << std::endl;
        if (!std::filesystem::is_empty(cheminDossier)) {
            std::cout << "Done" << std::endl;
            for (const auto& fichier : std::filesystem::directory_iterator(cheminDossier)) { // Parcours tout les éléments
                if (std::filesystem::is_regular_file(fichier.path())) { // .path() : Récupère le chemin complet || is_regular_file() : Vérifie si cet élément est un fichier.
                    std::filesystem::remove(fichier.path()); // Supprime le fichier
                    std::cout << "Fichier supprimé" << std::endl;
                } 
            }
        }

        int iterations;
        std::cout << "Nombre de cycles du jeu de la vie : ";
        std::cin >> iterations;
        for (int cycle = 0; cycle < iterations; cycle++) {
            // Fichier de sortie pour chaque cycle
            std::string nom_sortie = cheminDossier + "/cycle_" + std::to_string(cycle+1) + ".txt";
            s->sauvegarder(g, nom_sortie);
            cons.affichage(g, cycle);
            g.calculGrille();
        }
    }
    else if (mode == 2) {
        int temps;
        std::cout << "Entrez le temps de génération de chaque cycle (en ms) : ";
        std::cin >> temps;
        Graphique graph;
        sf::RenderWindow window(sf::VideoMode(g.get_nbColonne() * g.getTaille(), g.get_nbLigne() * g.getTaille()), "Le Jeu de la Vie");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            graph.affichage(g, window);
            g.calculGrille();
                
            sf::sleep(sf::milliseconds(temps));
        }
    } else {
        std::cout << "Aucun mode demandé" << std::endl;
    }
}