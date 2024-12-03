#include "Grille.hpp"

class GrilleGraph : public Grille
{
private:
    /* data */
public:
    GrilleGraph(int taille, int hauteur, int largeur);
    ~GrilleGraph();
    virtual void affichage(sf::RenderWindow &window) const override;
    virtual void affichage() const override;
    virtual void initializegrille() override;
};


