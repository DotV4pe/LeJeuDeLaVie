#include "Grille.hpp"
using namespace std;

Grille::Grille() {}

Grille::~Grille() {}

int Grille::getTaille() const { return cellSize; } // Retourne la taille des pixels

int Grille::get_nbColonne() const { return nbColonne; } // Retourne le nombre de colonne

int Grille::get_nbLigne() const { return nbLigne; } // Retourne le nombre de ligne

int Grille::getValeur(int x, int y) const { return grille[x][y].estVivant(); } // Retourne la valeur de la Cellule à la position (x, y)

vector<vector<Cellule>> Grille::getGrille() { return grille; } // Renvoie la grille

void Grille::update(int x,int y, int compt) { grille[x][y].updateCellule(compt); } // Mets à jour la Cellule à la position (x, y)

void Grille::setGrille(vector<vector<Cellule>> g) { grille = g; } // Mets à jour la grille

void Grille::initializegrille(Fichier *f) {
    int temp;
    // Ouverture du fichier en mode lecture
    ifstream monFlux(f->getcheminFichier());
    if (!monFlux) {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        exit(0);
    } else {
        cout << "Fichier " << f->getNomFichier() << ".txt ouvert avec succès !" << endl;
    }
     
    
    monFlux >> nbLigne >> nbColonne;
    cellSize = f->getTailleFichier();

    vector<vector<Cellule>> gr(get_nbColonne(), vector<Cellule>(get_nbLigne(), Cellule()));
    setGrille(gr);

    for (int y = 0; y < get_nbLigne(); ++y) {
        for (int x = 0; x < get_nbColonne(); ++x) {
            if (!(monFlux >> temp)) {
                cout << "Erreur: Lecture échouée à la position (" << x << ", " << y << ")." << endl;
                return;
            }
            // Initialiser la cellule en fonction de la valeur lue
            grille[x][y] = Cellule(temp);
        }
    }
    monFlux.close();
}