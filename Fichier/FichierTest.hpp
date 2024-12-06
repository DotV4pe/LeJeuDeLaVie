#include "Fichier.hpp"

#include <fstream>

class FichierTest : public Fichier {
public:
    FichierTest() : Fichier() {}
    virtual void getChemin(int mode) override;
};