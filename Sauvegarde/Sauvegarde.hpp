//Sauvegarde.hpp 

#pragma once

#include <vector>
#include <fstream>
#include "../Cellule/Cellule.hpp"
#include "../Grilles/Grille.hpp"

class Sauvegarde {
public:
    virtual void sauvegarder(const Grille g, const std::string& nomFichier) = 0;
    virtual ~Sauvegarde() {};
};