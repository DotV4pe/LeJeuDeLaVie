#include "Fichier.hpp"

std::string Fichier::getNomFichier() { return nomFichier; }

void Fichier::setDossierSortie(std::string ds) { dossierSortie = ds; }

int Fichier::getTaille() { return taille; }

std::string Fichier::getDossierSortie() { std::cout << dossierSortie << std::endl; return dossierSortie; }

std::string Fichier::getcheminFichier() { return cheminFichier; }