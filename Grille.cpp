#include "Grille.hpp"

Grille::Grille() {}

Grille::~Grille() {}

int Grille::getTaille() const { return cellSize; }

int Grille::get_nbColonne() const { return nbColonne; }

int Grille::get_nbLigne() const { return nbLigne; }

void Grille::setGrille(std::vector<std::vector<Cellule>> g) { grille = g; }

void Grille::setTaille(int t) { cellSize = t; }

void Grille::set_nbColonne(int nbC) { nbColonne = nbC; }

void Grille::set_nbLigne(int nbL) { nbLigne = nbL; }

void Grille::calculGrille() {
    std::vector<std::vector<Cellule>> tgrille = grille;

    for (int x = 0; x < nbColonne; ++x) {
        for (int y = 0; y < nbLigne; ++y) {
            int compteur = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    
                    int nx = (x + dx + nbColonne) % nbColonne;
                    int ny = (y + dy + nbLigne) % nbLigne;

                    if (tgrille[nx][ny].estVivant() == true) {
                        compteur++;
                    }
                }
            }
            grille[x][y].update(compteur);
        }
    }
}