#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "../Cellule/Cellule.hpp"

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
    virtual ~Grille();
    virtual int getTaille() const ;
    virtual int get_nbColonne() const ;
    virtual int get_nbLigne() const ;
    virtual int getValeur(int x, int y) const;
    virtual void setGrille(std::vector<std::vector<Cellule>> g);
    virtual void setTaille(int t);
    virtual void set_nbColonne(int nbC);
    virtual void set_nbLigne(int nbL);
    virtual std::vector<std::vector<Cellule>> calculGrille();
    virtual void initializegrille(std::string chemin) = 0;
};

#endif