#include "Grille.hpp"

class GrilleTerm : public Grille
{
private:
    int iterations;
public:
    GrilleTerm();
    ~GrilleTerm();
    virtual void initializegrille(std::string chemin) override;
    void imprimerFichier(const std::string& nom_fichier) const;
};