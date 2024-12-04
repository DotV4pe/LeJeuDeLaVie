#include "GrilleGraph.hpp"

GrilleGraph::GrilleGraph() {}

GrilleGraph::~GrilleGraph() {}

void GrilleGraph::affichage(sf::RenderWindow &window) const {
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(getTaille() - 1.0f, getTaille() - 1.0f));
    for (int x = 0; x < get_nbColonne(); ++x) {
        for (int y = 0; y < get_nbLigne(); ++y) {
            cell.setPosition(x * getTaille(), y * getTaille());
            if (grille[x][y].estVivant() == 1) {
                cell.setFillColor(sf::Color(255, 192, 203));
            }
            else if (grille[x][y].estVivant() == 0) {
                cell.setFillColor(sf::Color(0,0,0)); 
            } else if (grille[x][y].estVivant() == 2) {
                cell.setFillColor(sf::Color(255,0,0)); 
            }
            window.draw(cell);
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
        exit(0);
    }

    monFlux >> hauteur >> longueur;
    set_nbColonne(longueur);
    set_nbLigne(hauteur);
    setTaille(taille);

    std::vector<std::vector<Cellule>> gr(get_nbColonne(), std::vector<Cellule>(get_nbLigne(), Cellule(0)));
    setGrille(gr);

    for (int y = 0; y < get_nbLigne(); ++y) {
        for (int x = 0; x < get_nbColonne(); ++x) {
            if (!(monFlux >> temp)) {
                std::cout << "Erreur: Lecture échouée à la position (" << x << ", " << y << ")." << std::endl;
                return;
            }
            // Initialiser la cellule en fonction de la valeur lue
            grille[x][y] = Cellule(temp);
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