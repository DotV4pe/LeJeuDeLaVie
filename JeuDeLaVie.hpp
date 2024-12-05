#pragma once

#include "./Sauvegarde/SauvegardeTxt.hpp"
#include "./Fichier/FichierTxt.hpp"
#include "./Affichage/Console.hpp"
#include "./Affichage/Graphique.hpp"
#include "./Grilles/GrilleMaj.hpp"

class JeuDeLaVie
{
public:
    JeuDeLaVie();
    ~JeuDeLaVie();
    virtual void run(Grille g, Fichier *f, int mode);
};