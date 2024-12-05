#pragma once

#include <iostream>
#include <filesystem>
#include "../Grilles/Grille.hpp"
#include "../JeuDeLaVie.hpp"

class Menu
{
private:
    int mode;
public:
    Menu();
    ~Menu();
    virtual void affichage(Grille g, int iterations);
    virtual void affichage(Grille g, sf::RenderWindow &window);
    void affichageMenu();
    int getMode();
    void lancer();
};