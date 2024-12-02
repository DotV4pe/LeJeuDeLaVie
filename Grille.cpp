#include "Grille.hpp"

Grille::Grille(int taille, int longueur, int haut) 
    : cellSize(taille), nbColonne(longueur), nbLigne(haut), grille(nbLigne, std::vector<Cellule>(nbColonne, 0)) {}


Grille::~Grille() {}

int Grille::getTaille() { return cellSize; }

int Grille::get_nbColonne() { return nbColonne; }

int Grille::get_nbLigne() { return nbLigne; }

void Grille::majGrille(sf::RenderWindow &window) {  
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < nbColonne; x++) {
        for (int y = 0; y < nbLigne; y++) {
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
    std::vector<std::vector<Cellule>> tgrille(nbLigne, std::vector<Cellule>(nbColonne, 0));
    tgrille = grille;
    for (int x = 0; x < nbColonne; ++x) {
        for (int y = 0; y < nbLigne; ++y) {
            compteur = 0;
            if (tgrille[x][y].getVie() == false){
                if (tgrille[x-1 % nbColonne][y-1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % nbColonne][y].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % nbColonne][y+1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x][y-1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x][y+1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x+1 % nbColonne][y-1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x+1 % nbColonne][y].getVie() == true){
                    compteur++;
                } if (tgrille[x+1 % nbColonne][y+1 % nbLigne].getVie() == true){
                    compteur++;
                } if (compteur == 3) {
                    grille[x][y].setVie(true);
                } else {
                    grille[x][y].setVie(false);
                }
            }
            
            else if (tgrille[x][y].getVie() == true){
                if (tgrille[x-1 % nbColonne][y-1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % nbColonne][y].getVie() == true){
                    compteur++;
                } if (tgrille[x-1 % nbColonne][y+1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x][y-1 % nbLigne].getVie() == true){
                    compteur++;
                } if (tgrille[x][y+1 % nbLigne].getVie() == true){
                    compteur++;
                }  if (tgrille[x+1 % nbColonne][y-1 % nbLigne].getVie() == true){
                    compteur++;
                }  if (tgrille[x+1 % nbColonne][y].getVie() == true){
                    compteur++;
                }  if (tgrille[x+1 % nbColonne][y+1 % nbLigne].getVie() == true){
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
    for (int x = 0; x < get_nbColonne(); ++x) {
        for (int y = 0; y < get_nbLigne(); ++y) {
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
    for (int y = 0; y < nbLigne; ++y) {
        for (int x = 0; x < nbColonne; ++x) {
            std::cout << (grille[x][y].getVie() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}

void Grille::imprimerFichier(const std::string& nom_fichier) const{
    std::ofstream file(nom_fichier);
    if (!file){
        std::cout << "Erreur - Impossible d'ouvrir le fichier en écriture : " + nom_fichier << std::endl;
    }

    file << nbLigne << " " << nbColonne << std::endl;

        for (int y = 0; y < nbLigne; ++y) {
        for (int x = 0; x < nbColonne; ++x) {
            file << (grille[x][y].getVie() ? "1 " : "0 ");
        }
        file << std::endl;
    }
}