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
    const int nbColonne;
    const int nbLigne;
    std::vector<std::vector<Cellule>> grille;
public:
    Grille(int taille, int hauteur, int largeur);
    virtual ~Grille();
    int getTaille();
    int get_nbColonne();
    int get_nbLigne();
    void majGrille(sf::RenderWindow &window);
    void calculGrille();
    void initializegrille(std::string chemin);
    void imprimerConsole() const;
    void imprimerFichier(const std::string &nom_fichier) const;
};

#endif