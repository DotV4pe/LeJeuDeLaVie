#include "Grille.hpp"

Grille::Grille(int taille, int longueur, int haut) : cellSize(taille), grilleLongueur(longueur), grilleHauteur(haut) {
    vector<vector<int>> grille(grilleLongueur, vector<int>(grilleHauteur));
}

Grille::~Grille() {}

int Grille::getTaille() { return cellSize; }

int Grille::getLongueur() { return grilleLongueur; }

int Grille::getHauteur() { return grilleHauteur; }