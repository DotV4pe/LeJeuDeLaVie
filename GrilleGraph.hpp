#include "Grille.hpp"

class GrilleGraph : public Grille
{
private:
    /* data */
public:
    GrilleGraph();
    ~GrilleGraph();
    virtual void affichage(sf::RenderWindow &window) const override;
    virtual void affichage() const override;
    virtual void initializegrille() override;
    virtual void run() override;
};


