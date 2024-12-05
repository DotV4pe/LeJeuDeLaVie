#include "Grille.hpp"

class GrilleGraph : public Grille
{
public:
    GrilleGraph();
    ~GrilleGraph();
    virtual void initializegrille(Fichier *f) override;
};