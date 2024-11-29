#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "Cellule.hpp"

class Grille
{
private:
    const int cellSize;
    const int grilleLongueur;
    const int grilleHauteur;
    std::vector<std::vector<Cellule>> grille;
public:
    Grille(int taille, int longueur, int haut);
    virtual ~Grille();
    int getTaille();
    int getLongueur();
    int getHauteur();
    void majGrille(sf::RenderWindow &window);
    void calculGrille();
    void initializegrille();
    void imprimerConsole() const;
    void imprimerFichier(const std::string &nom_fichier) const;
};

#endif