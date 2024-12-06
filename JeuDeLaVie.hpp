#pragma once

#include "./Sauvegarde/SauvegardeTxt.hpp"
#include "./Fichier/FichierTxt.hpp"
#include "./Affichage/Console.hpp"
#include "./Affichage/Graphique.hpp"

class JeuDeLaVie
{
private:
    std::vector<std::vector<Cellule>> tgrille;
    int torique;
public:
    JeuDeLaVie();
    virtual ~JeuDeLaVie();
    void run(Grille &grid, Fichier *f, int mode);
    void updateGrille(Grille &grid);
};