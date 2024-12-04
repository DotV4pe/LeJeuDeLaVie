#pragma once

#include "../JeuDeLaVie.hpp"

class Console : public JeuDeLaVie
{
public:
    Console();
    ~Console();
    virtual void run(Grille *g) override;
    void imprimerFichier(const std::string& nom_fichier, Grille *g) const;
};

