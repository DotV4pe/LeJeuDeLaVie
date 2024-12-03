#include "GrilleTerm.hpp"

GrilleTerm::GrilleTerm() : Grille() {}

GrilleTerm::~GrilleTerm() {}

void GrilleTerm::affichage() const {
    std::cout << "Grille : " << std::endl;
    for (int x = 0; x < get_nbLigne(); ++x) {
        for (int y = 0; y < get_nbColonne(); ++y) {
            std::cout << (grille[y][x].estVivant() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}

void GrilleTerm::affichage(sf::RenderWindow &window) const {}

void GrilleTerm::initializegrille() {
    std::string chemin;
    std::cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    std::cin >> chemin;

    int temp, hauteur, longueur, taille = 20;
    std::cout << "Nombre de cycles du jeu de la vie : ";
    std::cin >> iterations;

    // ouverture du fichier initial
    std::ifstream monFlux(chemin);
    if (!monFlux) {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        return;
    }

    monFlux >> hauteur >> longueur;
    set_nbColonne(hauteur);
    set_nbLigne(longueur);
    setTaille(taille);

    for (int y = 0; y < get_nbLigne(); ++y) {
        for (int x = 0; x < get_nbColonne(); ++x) {
            if (!(monFlux >> temp)) {
                std::cout << "Erreur: Lecture échouée à la position (" << x << ", " << y << ")." << std::endl;
                return;
            }
            // Initialiser la cellule en fonction de la valeur lue
            grille[x][y] = Cellule(temp == 1);
        }
    }
    monFlux.close();
}

void GrilleTerm::run() {
    for (int cycle = 0; cycle < iterations; ++cycle) {
        // Fichier de sortie pour chaque cycle
        std::string nom_sortie = "Cycles/cycle_" + std::to_string(cycle) + ".txt";
        imprimerFichier(nom_sortie);
        affichage();
        calculGrille();
    }
}
