#include "Grille.hpp"

Grille::Grille(int taille, int longueur, int haut) 
    : cellSize(taille), grilleLongueur(longueur), grilleHauteur(haut), grille(grilleHauteur, std::vector<int>(grilleLongueur, 0))
{
}


Grille::~Grille() {}

int Grille::getTaille() { return cellSize; }

int Grille::getLongueur() { return grilleLongueur; }

int Grille::getHauteur() { return grilleHauteur; }

void Grille::renderGrille(sf::RenderWindow &window) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < grilleLongueur; ++x) {
        for (y = 0; y < grilleHauteur; ++y) {
            if (grille[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

void Grille::calculGrille() {
    srand(time(0));
    for (int x = 0; x < grilleLongueur; ++x) {
        for (int y = 0; y < grilleHauteur; ++y) {
            if (grille[x][y] == 0){
                grille[x][y] = rand() % 5;
            } else {
                grille[x][y] = 0;
            }
        }
    }
}

void Grille::initializegrille() {
    srand(time(0));
    for (int x = 0; x < getLongueur(); ++x) {
        for (int y = 0; y < getHauteur(); ++y) {
            grille[x][y] = rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
}