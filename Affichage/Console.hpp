#pragma once

#include "../JeuDeLaVie.hpp"
#include "../Sauvegarde/SauvegardeTxt.hpp"
#include "../Fichier/FichierTxt.hpp"

class Console : public JeuDeLaVie
{
public:
    Console();
    ~Console();
    virtual void run(Grille *g, Fichier *f) override;
};