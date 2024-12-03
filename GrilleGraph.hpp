#include "Grille.hpp"

class GrilleGraph : public Grille
{
public:
    GrilleGraph();
    ~GrilleGraph();
    virtual void affichage(sf::RenderWindow &window) const override;
    virtual void affichage() const override;
    virtual void initializegrille(std::string chemin) override;
    virtual void run() override;
};


