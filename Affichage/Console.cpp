#include "Console.hpp"
#include "../Sauvegarde/SauvegardeTxt.hpp"

extern std::string cheminDossierSortie; // Déclaration de la variable globale

Console::Console() {}

Console::~Console() {}

void Console::run(Grille *g) {
    std::string cheminDossier = cheminDossierSortie; // Utiliser le chemin du dossier de sortie
    for (const auto& fichier : std::filesystem::directory_iterator(cheminDossier)) { // Parcours tout les éléments
        if (std::filesystem::is_regular_file(fichier.path())) { // .path() : Récupère le chemin complet || is_regular_file() : Vérifie si cet élément est un fichier.
            std::filesystem::remove(fichier.path()); // Supprime le fichier
        }
    }

    int iterations;
    Sauvegarde *s;
    s = new SauvegardeFichierTxt();
    std::cout << "Nombre de cycles du jeu de la vie : ";
    std::cin >> iterations;
    for (int cycle = 0; cycle < iterations; cycle++) {
        // Fichier de sortie pour chaque cycle
        std::string nom_sortie = cheminDossier + "/cycle_" + std::to_string(cycle+1) + ".txt";
        s->sauvegarder(g, nom_sortie);
        affichage(g, cycle);
        g->calculGrille();
    }
}
