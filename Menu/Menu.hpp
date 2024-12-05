#pragma once

#include "../Grilles/Grille.hpp"
#include "../JeuDeLaVie.hpp"

class Menu
{
private:
    int mode;
public:
    Menu();
    virtual ~Menu();
    virtual void affichage(Grille g, int iterations);
    virtual void affichage(Grille g, sf::RenderWindow &window);
    void affichageMenu();
    void lancer();
};