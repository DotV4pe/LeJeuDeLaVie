#include "GrilleGraph.hpp"

GrilleGraph::GrilleGraph() {}

GrilleGraph::~GrilleGraph() {}

void GrilleGraph::affichage(sf::RenderWindow &window) const {
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(getTaille() - 1.0f, getTaille() - 1.0f));
    for (int x = 0; x < get_nbColonne(); x++) {
        for (int y = 0; y < get_nbLigne(); y++) {
            if (grille[x][y].estVivant() == true) {
                cell.setPosition(x * getTaille(), y * getTaille());
                if (grille[x][y].estVivant()) {
                    cell.setFillColor(sf::Color(255, 192, 203));
                } else if (!grille[x][y].estVivant()) {
                    cell.setFillColor(sf::Color(200,200,200)); 
                }
                window.draw(cell);
            }
        }
    }
    window.display();
}

void GrilleGraph::affichage() const {}

void GrilleGraph::initializegrille(std::string chemin) {
    
    int temp, hauteur, longueur, taille = 20;
    
    // ouverture du fichier initial
    
    std::ifstream monFlux(chemin);
    if (!monFlux) {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        return;
    } else {
        std::cout << "Ouverture Done" ;
    }

    monFlux >> hauteur >> longueur;
    set_nbColonne(hauteur);
    set_nbLigne(longueur);
    setTaille(taille);

    for (int y = 0; y < get_nbLigne(); ++y) {
        for (int x = 0; x < get_nbColonne(); ++x) {
            if (!(monFlux >> temp)) {
                std::cout << "Erreur: Lecture échouée à la position (" << x << ", " << y << ")." << std::endl;
                return;
            }
            // Initialiser la cellule en fonction de la valeur lue
            grille[x][y] = Cellule(temp == 1);
        }
    }
    monFlux.close();
}

void GrilleGraph::run() {
    sf::RenderWindow window(sf::VideoMode(get_nbColonne() * getTaille(), get_nbLigne() * getTaille()), "Le Jeu de la Vie");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        affichage(window);
        calculGrille();
            
        sf::sleep(sf::milliseconds(500));
    }
}