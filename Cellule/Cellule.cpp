#include "Cellule.hpp"

Cellule::Cellule() : vivant(0) {}

Cellule::Cellule(int viv) : vivant(viv) {}

Cellule::~Cellule() {}

int Cellule::estVivant() const { return vivant; } // Retourne la valeur de la Cellule (0 : Morte,1 : Vivante,2 : Obstacle mort,3 : Obstacle vivant)

void Cellule::setVie(int viv) { vivant = viv; } // Mets à jour l'état de vivant

void Cellule::updateCellule(int voisinVivant){
    // Vérifie si la Cellule est morte et qu'elle a 3 voisins
    if (estVivant() == 0 && voisinVivant == 3){
        vivant = 1; // La Cellule devient vivante
    }
    // Vérifie si la cellule est vivante et qu'elle a moins de 2 voisins ou plus de 3
    else if (estVivant() == 1 && (voisinVivant < 2 || voisinVivant > 3)){ 
        vivant = 0; // La Cellule meurt
    }
    // Dans un autre cas la valeur de la Cellule ne change pas
}