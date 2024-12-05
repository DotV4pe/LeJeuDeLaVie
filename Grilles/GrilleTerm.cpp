#include "GrilleTerm.hpp"

GrilleTerm::GrilleTerm() {}

GrilleTerm::~GrilleTerm() {}

void GrilleTerm::initializegrille(Fichier *f) {
    iterations = 0;

    int temp, hauteur, longueur;
    // ouverture du fichier initial
    std::ifstream monFlux(f->getcheminFichier());
    if (!monFlux) {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        exit(0);
    } else {
        std::cout << "Fichier ouvert avec succès !" << std::endl;
    }

    monFlux >> hauteur >> longueur;
    set_nbColonne(longueur);
    set_nbLigne(hauteur);
    setTaille(f->getTaille());

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