#include "Grille.hpp"

Grille::Grille(int taille, int longueur, int haut) 
    : cellSize(taille), grilleLongueur(longueur), grilleHauteur(haut), grille(grilleHauteur, std::vector<int>(grilleLongueur, 0)) {}


Grille::~Grille() {}

int Grille::getTaille() { return cellSize; }

int Grille::getLongueur() { return grilleLongueur; }

int Grille::getHauteur() { return grilleHauteur; }

void Grille::majGrille(sf::RenderWindow &window) {  
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < grilleLongueur; x++) {
        for (int y = 0; y < grilleHauteur; y++) {
            if (grille[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

void Grille::calculGrille() {
    int compteur = 0;
    std::vector<std::vector<int>> tgrille(grilleHauteur, std::vector<int>(grilleLongueur, 0));
    tgrille = grille;
    for (int x = 0; x < grilleLongueur; ++x) {
        for (int y = 0; y < grilleHauteur; ++y) {
            if (tgrille[x][y] == 0){
                if (tgrille[x-1][y-1] == 1){
                    compteur++;
                } if (tgrille[x-1][y] == 1){
                    compteur++;
                } if (tgrille[x-1][y+1] == 1){
                    compteur++;
                } if (tgrille[x][y-1] == 1){
                    compteur++;
                } if (tgrille[x][y+1] == 1){
                    compteur++;
                }  if (tgrille[x+1][y-1] == 1){
                    compteur++;
                }  if (tgrille[x][y] == 1){
                    compteur++;
                }  if (tgrille[x][y+1] == 1){
                    compteur++;
                } if (compteur == 3) {
                    grille[x][y] = 1;
                } else {
                    grille[x][y] = 0;
                }
            } 
            
            else if (tgrille[x][y] == 1){
                if (tgrille[x-1][y-1] == 1){
                    compteur++;
                } if (tgrille[x-1][y] == 1){
                    compteur++;
                } if (tgrille[x-1][y+1] == 1){
                    compteur++;
                } if (tgrille[x][y-1] == 1){
                    compteur++;
                } if (tgrille[x][y+1] == 1){
                    compteur++;
                }  if (tgrille[x+1][y-1] == 1){
                    compteur++;
                }  if (tgrille[x][y] == 1){
                    compteur++;
                }  if (tgrille[x][y+1] == 1){
                    compteur++;
                } if (compteur == 2 || compteur == 3) {
                    grille[x][y] = 1;
                } else {
                    grille[x][y] = 0;
                }
            } compteur = 0;
        }
    }
}

void Grille::initializegrille() {
    std::ifstream monFlux("data.txt");
    for (int x = 0; x < getLongueur(); ++x) {
        for (int y = 0; y < getHauteur(); ++y) {
            monFlux >> grille[x][y];
        }
    }
}