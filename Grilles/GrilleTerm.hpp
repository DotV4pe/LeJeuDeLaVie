#include "Grille.hpp"

class GrilleTerm : public Grille
{
private:
    int iterations;
public:
    GrilleTerm();
    ~GrilleTerm();
    virtual void initializegrille(Fichier *f) override;
};