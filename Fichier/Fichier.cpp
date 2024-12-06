#include "Fichier.hpp"
using namespace std;

string Fichier::getNomFichier() { return nomFichier; } // Renvoie le nom du fichier (Ex : data)

void Fichier::setDossierSortie(string ds) { dossierSortie = ds; } // Permet de mettre à jour le nom du dossier de sortie

int Fichier::getTailleFichier() { return taille; } // Renvoie la taille des pixels attribuer en fonction du fichier (Ex : 20)

string Fichier::getDossierSortie() { return dossierSortie; } // Renvoie le nom du dossier de sortie (Ex : ./data_out/)

string Fichier::getcheminFichier() { return cheminFichier; } // Renvoie le nom du chemin du fichier de la grille (Ex : ./Matrices/data.txt)