#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "../Cellule/Cellule.hpp"
#include "../Fichier/FichierTxt.hpp"

class Grille
{
private:
    int cellSize;
    int nbColonne;
    int nbLigne;
protected:
    std::vector<std::vector<Cellule>> grille;
public:
    Grille();
    ~Grille();
    int getTaille() const ;
    int get_nbColonne() const ;
    int get_nbLigne() const ;
    int getValeur(int x, int y) const;
    void setGrille(std::vector<std::vector<Cellule>> g);
    void setTaille(int t);
    void set_nbColonne(int nbC);
    void set_nbLigne(int nbL);
    void calculGrilleTorique();
    void calculGrilleNonTorique();
    void initializegrille(Fichier *f);
};

#endif