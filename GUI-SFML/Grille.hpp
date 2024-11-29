#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Grille
{
private:
    const int cellSize;
    const int grilleLongueur;
    const int grilleHauteur;
    std::vector<std::vector<int>> grille;
public:
    Grille(int taille, int longueur, int haut);
    virtual ~Grille();
    int getTaille();
    int getLongueur();
    int getHauteur();
    void renderGrille(sf::RenderWindow &window);
    void calculGrille();
    void initializegrille();
};

#endif