#pragma once

#include "../JeuDeLaVie.hpp"

class Graphique : public JeuDeLaVie
{
public:
    Graphique();
    ~Graphique();
    virtual void run(Grille *g) override;
};