#pragma once

class Cellule
{
private:
    bool vivant;
public:
    Cellule(bool viv);
    ~Cellule();
    bool getVie();
    void setVie(bool viv);
};


