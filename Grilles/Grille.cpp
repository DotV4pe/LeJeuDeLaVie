#include "Grille.hpp"
using namespace std;

Grille::Grille() {}

Grille::~Grille() {}

int Grille::getTaille() const { return cellSize; }

int Grille::get_nbColonne() const { return nbColonne; }

int Grille::get_nbLigne() const { return nbLigne; }

int Grille::getValeur(int x, int y) const { return grille[x][y].estVivant(); }

vector<vector<Cellule>> Grille::getGrille() { return grille; }

void Grille::update(int x,int y, int compt) { grille[x][y].updateCellule(compt); }

void Grille::setGrille(vector<vector<Cellule>> g) { grille = g; }

void Grille::initializegrille(Fichier *f) {
    int temp;
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