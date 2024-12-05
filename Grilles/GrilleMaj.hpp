#pragma once

#include "Grille.hpp"

class GrilleMaj
{
public:
    GrilleMaj();
    ~GrilleMaj();
    void calculGrilleTorique(Grille &g);
    void calculGrilleNonTorique(Grille &g);
};