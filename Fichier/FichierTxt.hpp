#pragma once

#include "Fichier.hpp"

class FichierTxt : public Fichier
{
public:
    FichierTxt();
    ~FichierTxt();
    virtual void getChemin(int mode);
};