#pragma once

#include "Menu.hpp"

class Console : public Menu
{
public:
    Console();
    ~Console();
    void affichage(Grille g, int iterations);
};