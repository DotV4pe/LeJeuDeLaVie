#pragma once

#include "Affichage.hpp"

class Console : public Affichage
{
public:
    Console();
    ~Console();
    virtual void affichage(Grille g, int iterations);
    virtual void affichage(Grille g, sf::RenderWindow &window) {}
};