#pragma once

#include <iostream>

class Cellule
{
private:
    int vivant;
public:
    Cellule();
    Cellule(int viv);
    ~Cellule();
    int estVivant() const;
    void setVie(int viv);
    void update(int voisinVivant);
};