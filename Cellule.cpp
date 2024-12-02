#include "Cellule.hpp"

Cellule::Cellule(bool viv) : vivant(viv) {}

Cellule::~Cellule() {}

bool Cellule::estVivant() const { return vivant; }

void Cellule::setVie(bool viv) { vivant = viv; }

void Cellule::update(int voisinVivant){
    if (!estVivant && voisinVivant == 3){
        vivant = true;
    }
    else if (vivant && (voisinVivant < 2 || voisinVivant > 3)){
        vivant = false;
    }
}


