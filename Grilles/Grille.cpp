#include "Grille.hpp"

Grille::Grille() {}

Grille::~Grille() {}

int Grille::getTaille() const { return cellSize; }

int Grille::get_nbColonne() const { return nbColonne; }

int Grille::get_nbLigne() const { return nbLigne; }

int Grille::getValeur(int x, int y) const { return grille[x][y].estVivant(); }

void Grille::setGrille(std::vector<std::vector<Cellule>> g) { grille = g; }

void Grille::setTaille(int t) { cellSize = t; }

void Grille::set_nbColonne(int nbC) { nbColonne = nbC; }

void Grille::set_nbLigne(int nbL) { nbLigne = nbL; }

void Grille::calculGrilleTorique() {
    std::vector<std::vector<Cellule>> tgrille = grille;

    for (int x = 0; x < nbColonne; ++x) {
        for (int y = 0; y < nbLigne; ++y) {
            int compteur = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    
                    int nx = (x + dx + nbColonne) % nbColonne;
                    int ny = (y + dy + nbLigne) % nbLigne;

                    if ((tgrille[nx][ny].estVivant() % 2) == 1) {
                        compteur++;
                    }
                }
            }
            grille[x][y].update(compteur);
        }
    }
}

void Grille::calculGrilleNonTorique() {
    std::vector<std::vector<Cellule>> tgrille = grille;

    for (int x = 0; x < nbColonne; ++x) {
        for (int y = 0; y < nbLigne; ++y) {
            int compteur = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (dx != 0 || dy != 0) {
                        if (nx < nbColonne) {
                            if (nx > 0) {
                                if (ny < nbLigne) {
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
            grille[x][y].update(compteur);
        }
    }
}

void Grille::initializegrille(Fichier *f) {
    int temp;

    std::ifstream monFlux(f->getcheminFichier());
    if (!monFlux) {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        exit(0);
    } else {
        std::cout << "Fichier " << f->getNomFichier() << ".txt ouvert avec succès !" << std::endl;
    }

    std::cout << std::endl;

    monFlux >> nbLigne >> nbColonne;
    cellSize = f->getTaille();

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