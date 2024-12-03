#include "Grille.hpp"

class GrilleTerm : public Grille
{
private:
    /* data */
public:
    GrilleTerm(int taille, int hauteur, int largeur);
    ~GrilleTerm();
    virtual void affichage() const override;
    virtual void affichage(sf::RenderWindow &window) const override;
    virtual void initializegrille() override;
};

