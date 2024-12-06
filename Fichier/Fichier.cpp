#include "Fichier.hpp"
using namespace std;

string Fichier::getNomFichier() { return nomFichier; }

void Fichier::setDossierSortie(string ds) { dossierSortie = ds; }

int Fichier::getTailleFichier() { return taille; }

string Fichier::getDossierSortie() { return dossierSortie; }

string Fichier::getcheminFichier() { return cheminFichier; }