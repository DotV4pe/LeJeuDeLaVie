// SauvegardeTxt.hpp

#pragma once

#include <fstream>
#include "Sauvegarde.hpp"

class SauvegardeFichierTxt : public Sauvegarde{
public:
    SauvegardeFichierTxt(){}
    void sauvegarder(const Grille g, const std::string& nomFichier) override;
};