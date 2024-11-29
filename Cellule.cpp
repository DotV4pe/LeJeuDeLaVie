#include "Cellule.hpp"

Cellule::Cellule(bool viv) : vivant(viv) {}

Cellule::~Cellule() {}

bool Cellule::getVie() const { return vivant; }

void Cellule::setVie(bool viv) { vivant = viv; }