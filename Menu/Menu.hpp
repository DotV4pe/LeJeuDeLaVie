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
    void affichageMenu();
    void lancer();
};