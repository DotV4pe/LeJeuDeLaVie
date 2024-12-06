#include "Fichier.hpp"

std::string Fichier::getNomFichier() { return nomFichier; }

void Fichier::setDossierSortie(std::string ds) { dossierSortie = ds; }

int Fichier::getTailleFichier() { return taille; }

std::string Fichier::getDossierSortie() { return dossierSortie; }

std::string Fichier::getcheminFichier() { return cheminFichier; }