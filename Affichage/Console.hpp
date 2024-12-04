#pragma once

#include "../JeuDeLaVie.hpp"

class Console : public JeuDeLaVie
{
public:
    Console();
    ~Console();
    virtual void run(Grille *g) override;
};