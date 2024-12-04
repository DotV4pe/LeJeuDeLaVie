// SauvegardeTxt.hpp

#pragma once

#include <fstream>
#include <stdexcept>
#include "Sauvegarde.hpp"

class SauvegardeFichierTxt : public Sauvegarde{
public:
    SauvegardeFichierTxt(){}
    void sauvegarder(const Grille* g, const std::string& nomFichier) override;
};

