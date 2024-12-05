#pragma once

#include "Menu.hpp"

class Graphique
{
public:
    Graphique();
    ~Graphique();
    void affichage(Grille g, sf::RenderWindow &window);
};