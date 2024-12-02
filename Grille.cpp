#include "Grille.hpp"

Grille::Grille(int taille, int longueur, int haut) 
    : cellSize(taille), grilleLongueur(longueur), grilleHauteur(haut), grille(grilleLongueur, std::vector<Cellule>(grilleHauteur, 0)) {}


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
    std::vector<std::vector<Cellule>> tgrille;
    tgrille = grille;

    for (int x = 0; x < grilleLongueur; x++) {
        for (int y = 0; y < grilleHauteur; y++) {
            int compteur = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    
                    int nx = (x + dx + grilleLongueur) % grilleLongueur;
                    int ny = (y + dy + grilleHauteur) % grilleHauteur;

                    if (tgrille[nx][ny].getVie() == true) {
                        compteur++;
                    }
                }
            }

            if (tgrille[x][y].getVie() == true) {
                grille[x][y].setVie(compteur == 2 || compteur == 3);
            } else {
                grille[x][y].setVie(compteur == 3);
            }
        }
    }
}


void Grille::initializegrille(std::string chemin) {
    std::ifstream monFlux(chemin);
    for (int x = 0; x < getLongueur(); x++) {
        for (int y = 0; y < getHauteur(); y++) {
            int temp;
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
    std::cout << "Grille : " << std::endl;
    for (int y = 0; y < grilleHauteur; ++y) {
        for (int x = 0; x < grilleLongueur; ++x) {
            std::cout << (grille[x][y].getVie() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}