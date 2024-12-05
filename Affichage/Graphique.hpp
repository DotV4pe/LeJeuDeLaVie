#pragma once

#include "Affichage.hpp"

class Graphique : public Affichage
{
public:
    Graphique();
    ~Graphique();
    virtual void affichage(Grille g, sf::RenderWindow &window);
    virtual void affichage(Grille g, int iterations) {}
};