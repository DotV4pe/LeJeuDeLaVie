//Sauvegarde.hpp 

#pragma once

#include <vector>
#include <fstream>
#include "../Cellule/Cellule.hpp"
#include "../Grilles/Grille.hpp"

// Rôle d'interface (classe abstraite) qui permet l'extensibilité plus tard avec un nouveau format de fichier
class Sauvegarde {
public:
    virtual void sauvegarder(const Grille g, const std::string& nomFichier) = 0; // Méthode virtuelle pure qui sera redéfinie pour tous les types de sauvegardes (ici on ne l'applique que pour le texte)
    virtual ~Sauvegarde() {};
};