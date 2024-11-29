#include "Grille.hpp"

Grille::Grille(int taille, int longueur, int haut) 
    : cellSize(taille), grilleLongueur(longueur), grilleHauteur(haut), grille(grilleHauteur, std::vector<Cellule>(grilleLongueur, 0)) {}


Grille::~Grille() {}

int Grille::getTaille() { return cellSize; }

int Grille::getLongueur() { return grilleLongueur; }

int Grille::getHauteur() { return grilleHauteur; }

void Grille::majGrille(sf::RenderWindow &window) {  
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < grilleLongueur; x++) {
        for (int y = 0; y < grilleHauteur; y++) {
            if (grille[x][y].getVie() == true) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

void Grille::calculGrille() {
    int compteur = 0;
    std::vector<std::vector<Cellule>> tgrille(grilleHauteur, std::vector<Cellule>(grilleLongueur, 0));
    tgrille = grille;
    for (int x = 0; x < grilleLongueur; ++x) {
        for (int y = 0; y < grilleHauteur; ++y) {
            compteur = 0;
            if (tgrille[x][y].getVie() == false){
                if (tgrille[x-1 % grilleLongueur][y-1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % grilleLongueur][y].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % grilleLongueur][y+1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x][y-1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x][y+1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x+1 % grilleLongueur][y-1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x+1 % grilleLongueur][y].getVie() == true){
                    compteur++;
                } if (tgrille[x+1 % grilleLongueur][y+1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (compteur == 3) {
                    grille[x][y].setVie(true);
                } else {
                    grille[x][y].setVie(false);
                }
            }
            
            else if (tgrille[x][y].getVie() == true){
                if (tgrille[x-1 % grilleLongueur][y-1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % grilleLongueur][y].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % grilleLongueur][y+1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x][y-1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (tgrille[x][y+1 % grilleHauteur].getVie() == true){
                    compteur++;
                }  if (tgrille[x+1 % grilleLongueur][y-1 % grilleHauteur].getVie() == true){
                    compteur++;
                }  if (tgrille[x+1 % grilleLongueur][y].getVie() == true){
                    compteur++;
                }  if (tgrille[x+1 % grilleLongueur][y+1 % grilleHauteur].getVie() == true){
                    compteur++;
                } if (compteur == 2 || compteur == 3) {
                    grille[x][y].setVie(true);
                } else {
                    grille[x][y].setVie(false);
                }
            }
        }
    }
}

void Grille::initializegrille() {
    int temp;
    std::ifstream monFlux("data.txt");
    for (int x = 0; x < getLongueur(); ++x) {
        for (int y = 0; y < getHauteur(); ++y) {
            monFlux >> temp;
            if (temp==0){
                grille[x][y] = Cellule(false);
            } else if (temp==1) {
                grille[x][y] = Cellule(true);
            }
        }
    }
}

void Grille::imprimerConsole() const {
    for (int y = 0; y < grilleHauteur; ++y) {
        for (int x = 0; x < grilleLongueur; ++x) {
            std::cout << (grille[x][y].getVie() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}