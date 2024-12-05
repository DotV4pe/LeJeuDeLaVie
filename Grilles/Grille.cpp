#include "Grille.hpp"

Grille::Grille() {}

Grille::~Grille() {}

int Grille::getTaille() const { return cellSize; }

int Grille::get_nbColonne() const { return nbColonne; }

int Grille::get_nbLigne() const { return nbLigne; }

int Grille::getValeur(int x, int y) const { return grille[x][y].estVivant(); }

std::vector<std::vector<Cellule>> Grille::getGrille() { return grille; }

void Grille::update(int x,int y, int compt) { grille[x][y].update(compt); }

void Grille::setGrille(std::vector<std::vector<Cellule>> g) { grille = g; }

void Grille::setTaille(int t) { cellSize = t; }

void Grille::set_nbColonne(int nbC) { nbColonne = nbC; }

void Grille::set_nbLigne(int nbL) { nbLigne = nbL; }

void Grille::initializegrille(Fichier *f) {
    int temp;

    std::ifstream monFlux(f->getcheminFichier());
    if (!monFlux) {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
        exit(0);
    } else {
        std::cout << "Fichier " << f->getNomFichier() << ".txt ouvert avec succès !" << std::endl;
    }

    std::cout << std::endl;

    monFlux >> nbLigne >> nbColonne;
    cellSize = f->getTaille();

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