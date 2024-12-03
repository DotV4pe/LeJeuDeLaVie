#include "Grille.hpp"

class GrilleTerm : public Grille
{
private:
    int iterations;
public:
    GrilleTerm();
    ~GrilleTerm();
    virtual void affichage() const override;
    virtual void affichage(sf::RenderWindow &window) const override;
    virtual void initializegrille(std::string chemin) override;
    virtual void run() override;
    void imprimerFichier(const std::string& nom_fichier) const;
};

