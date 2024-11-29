#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <iostream>

class Grille
{
private:
    const int cellSize;
    const int grilleLongueur;
    const int grilleHauteur;
    vector<vector<int>> grille;
public:
    Grille(int taille, int longueur, int haut);
    virtual ~Grille();
    int getTaille();
    int getLongueur();
    int getHauteur();
};

#endif