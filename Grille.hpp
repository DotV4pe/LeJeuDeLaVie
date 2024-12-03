#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "Cellule.hpp"

class Grille
{
private:
    const int cellSize;
    const int nbColonne;
    const int nbLigne;
protected:
    std::vector<std::vector<Cellule>> grille;
public:
    Grille();
    virtual ~Grille();
    virtual int getTaille() const ;
    virtual int get_nbColonne() const ;
    virtual int get_nbLigne() const ;
    virtual void calculGrille();
    virtual void initializegrille() = 0;
    virtual void affichage() const = 0;
    virtual void affichage(sf::RenderWindow &window) const = 0;
    virtual void imprimerFichier(const std::string &nom_fichier) const;
};

#endif