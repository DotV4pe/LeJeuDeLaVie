#include "GrilleTerm.hpp"

GrilleTerm::GrilleTerm() {}

GrilleTerm::~GrilleTerm() {}

void GrilleTerm::affichage() const {
    std::string txt;
    std::cout << "Grille : " << std::endl;
    for (int x = 0; x < get_nbLigne(); ++x) {
        for (int y = 0; y < get_nbColonne(); ++y) {
            if (grille[x][y].estVivant() == 0) {
                txt = "0 ";
            } else if (grille[x][y].estVivant() == 1) {
                txt = "1 ";
            } else if (grille[x][y].estVivant() == 2) {
                txt = "2 ";
            }
        }
        std::cout << std::endl;
    }
}

void GrilleTerm::affichage(sf::RenderWindow &window) const {}

void GrilleTerm::initializegrille(std::string chemin) {
    iterations = 0;

    int temp, hauteur, longueur, taille = 20;
    std::cout << "Nombre de cycles du jeu de la vie : ";
    std::cin >> iterations;
    // ouverture du fichier initial
    std::ifstream monFlux(chemin);
    if (!monFlux) {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        exit(0);
    }
    monFlux >> hauteur >> longueur;
    set_nbColonne(longueur);
    set_nbLigne(hauteur);
    setTaille(taille);

    std::vector<std::vector<Cellule>> gr(get_nbColonne(), std::vector<Cellule>(get_nbLigne(), Cellule(0)));
    setGrille(gr);
    
    for (int y = 0; y < get_nbLigne(); ++y) {
        for (int x = 0; x < get_nbColonne(); ++x) {
            if (!(monFlux >> temp)) {
                std::cout << "Erreur: Lecture échouée à la position (" << x << ", " << y << ")." << std::endl;
                return;
            }
            // Initialiser la cellule en fonction de la valeur lue
            grille[x][y] = Cellule(temp);
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

void GrilleTerm::imprimerFichier(const std::string& nom_fichier) const{
    std::ofstream file(nom_fichier);
    if (!file){
        std::cout << "Erreur - Impossible d'ouvrir le fichier en écriture : " + nom_fichier << std::endl;
    }

    file << get_nbLigne() << " " << get_nbColonne() << std::endl;
    std::string message;
    for (int y = 0; y < get_nbLigne(); ++y) {
        for (int x = 0; x < get_nbColonne(); ++x) {
            if (grille[x][y].estVivant() == 0) {
                message = "0 ";
            } else if (grille[x][y].estVivant() == 1) {
                message = "1 ";
            } else if (grille[x][y].estVivant() == 2) {
                message = "2 ";
            }
            file << message;
        }
        file << std::endl;
    }
}