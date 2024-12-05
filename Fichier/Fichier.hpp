#pragma once

#include <iostream>
#include <filesystem>

class Fichier
{
protected:
    std::string nomFichier;
    int taille;
    std::string dossierSortie;
    std::string cheminFichier;
public:
    Fichier() {}
    ~Fichier() {}
    virtual void getChemin(int mode) = 0;
    virtual void setDossierSortie(std::string ds);
    virtual std::string getNomFichier();
    virtual int getTaille();
    virtual std::string getDossierSortie();
    virtual std::string getcheminFichier();
};