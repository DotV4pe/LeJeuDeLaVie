#pragma once

#include <iostream>

class Cellule
{
private:
    bool vivant;
public:
    Cellule(bool viv);
    ~Cellule();
    bool getVie() const;
    void setVie(bool viv);
};