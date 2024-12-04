#pragma once

#include <iostream>
#include <filesystem>
#include "./Grilles/Grille.hpp"

class JeuDeLaVie
{
public:
    JeuDeLaVie();
    ~JeuDeLaVie();
    virtual void affichage(Grille *g);
    virtual void affichage(Grille *g, sf::RenderWindow &window);
    virtual void run(Grille *g) = 0;
};