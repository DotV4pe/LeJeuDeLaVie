#pragma once

#include <iostream>

class Cellule
{
private:
    bool vivant;
public:
    Cellule(bool viv);
    ~Cellule();
    bool estVivant() const;
    void setVie(bool viv);
    void update(int voisinVivant);
};