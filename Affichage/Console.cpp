#include "Console.hpp"

Console::Console() {}

Console::~Console() {}

void Console::imprimerFichier(const std::string& nom_fichier, Grille *g) const{
    std::ofstream file(nom_fichier);
    if (!file){
        std::cout << "Erreur - Impossible d'ouvrir le fichier en écriture : " + nom_fichier << std::endl;
    }

    file << g->get_nbLigne() << " " << g->get_nbColonne() << std::endl;
    std::string message;
    for (int y = 0; y < g->get_nbLigne(); ++y) {
        for (int x = 0; x < g->get_nbColonne(); ++x) {
            if (g->getValeur(x,y) == 0) {
                message = "0 ";
            } else if (g->getValeur(x,y) == 1) {
                message = "1 ";
            } else if (g->getValeur(x,y) == 2) {
                message = "2 ";
            }
            file << message;
        }
        file << std::endl;
    }
}

void Console::run(Grille *g) {
    std::string cheminDossier = "./Cycles/";
    for (const auto& fichier : std::filesystem::directory_iterator(cheminDossier)) { // Parcours tout les éléments
        if (std::filesystem::is_regular_file(fichier.path())) { // .path() : Récupère le chemin complet || is_regular_file() : Vérifie si cet élément est un fichier.
            std::filesystem::remove(fichier.path()); // Supprime le fichier
        }
    }

    int iterations;
    std::cout << "Nombre de cycles du jeu de la vie : ";
    std::cin >> iterations;
    for (int cycle = 0; cycle < iterations; ++cycle) {
        // Fichier de sortie pour chaque cycle
        std::string nom_sortie = "Cycles/cycle_" + std::to_string(cycle) + ".txt";
        imprimerFichier(nom_sortie, g);
        affichage(g);
        g->calculGrille();
    }
}