#pragma once

#include "../Grilles/Grille.hpp"

class Affichage {
public:
    virtual void affichage(Grille g, int iterations) = 0;
    virtual void affichage(Grille g, sf::RenderWindow &window) = 0;
    virtual ~Affichage() {}
};