#include "Grille.hpp"

class GrilleGraph : public Grille
{
public:
    GrilleGraph();
    ~GrilleGraph();
    virtual void initializegrille(std::string chemin) override;
};


