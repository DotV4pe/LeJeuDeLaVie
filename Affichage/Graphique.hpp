#pragma once

#include "Menu.hpp"

class Graphique : public Menu
{
public:
    Graphique();
    ~Graphique();
    void affichage(Grille g, sf::RenderWindow &window);
};