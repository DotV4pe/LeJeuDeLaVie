#include "Grille.hpp"

Grille::Grille(int taille, int largeur, int hauteur) 
    : cellSize(taille), nbColonne(largeur), nbLigne(hauteur), grille(nbColonne, std::vector<Cellule>(nbLigne, 0)) {}


Grille::~Grille() {}

int Grille::getTaille() { return cellSize; }

int Grille::get_nbColonne() { return nbColonne; }

int Grille::get_nbLigne() { return nbLigne; }

void Grille::majGrille(sf::RenderWindow &window) {  
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (int x = 0; x < nbColonne; x++) {
        for (int y = 0; y < nbLigne; y++) {
            if (grille[x][y].estVivant() == true) {
                cell.setPosition(x * cellSize, y * cellSize);
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

void Grille::calculGrille() {
    std::vector<std::vector<Cellule>> tgrille;
    tgrille = grille;

    for (int x = 0; x < nbColonne; x++) {
        for (int y = 0; y < nbLigne; y++) {
            int compteur = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    
                    int nx = (x + dx + nbColonne) % nbColonne;
                    int ny = (y + dy + nbLigne) % nbLigne;

                    if (tgrille[nx][ny].estVivant() == true) {
                        compteur++;
                    }
                }
            }
            grille[x][y].update(compteur);
        }
    }
}

void Grille::initializegrille(std::string chemin) {
    std::ifstream monFlux(chemin);
    int temp;
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

void Grille::imprimerConsole() const {
    std::cout << "Grille : " << std::endl;
    for (int x = 0; x < nbLigne; ++x) {
        for (int y = 0; y < nbColonne; ++y) {
            std::cout << (grille[y][x].estVivant() ? "1 " : "0 ");
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
                file << (grille[x][y].estVivant() ? "1 " : "0 ");
            }
        file << std::endl;
    }
}