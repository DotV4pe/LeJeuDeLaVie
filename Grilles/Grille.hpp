#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
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
    std::vector<std::vector<Cellule>> getGrille();
    void update(int x,int y, int compt);
    void setGrille(std::vector<std::vector<Cellule>> g);
    void initializegrille(Fichier *f);
};

#endif