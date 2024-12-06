// SauvegardeTxt.hpp

#pragma once

#include "Sauvegarde.hpp"

class SauvegardeFichierTxt : public Sauvegarde{
public:
    SauvegardeFichierTxt(){}
    void sauvegarder(const Grille g, const std::string& nomFichier) override; // Réutilise la méthode virtuelle de la classe mère en fonction du besoin (ici pour le fichier txt)
};