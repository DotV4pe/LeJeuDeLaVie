#include "Cellule.hpp"

Cellule::Cellule() : vivant(0) {}

Cellule::Cellule(int viv) : vivant(viv) {}

Cellule::~Cellule() {}

int Cellule::estVivant() const { return vivant; }

void Cellule::setVie(int viv) { vivant = viv; }

void Cellule::updateCellule(int voisinVivant){
    if (estVivant() == 0 && voisinVivant == 3){
        vivant = 1;
    }
    else if (estVivant() == 1 && (voisinVivant < 2 || voisinVivant > 3)){
        vivant = 0;
    }
}