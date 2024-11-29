#ifndef GRILLE_H
#define GRILLE_H

class Grille
{
private:
    const int cellSize;
    const int grilleLongueur;
    const int grilleHauteur;
public:
    Grille(int taille, int longueur, int haut);
    virtual ~Grille();
};

#endif