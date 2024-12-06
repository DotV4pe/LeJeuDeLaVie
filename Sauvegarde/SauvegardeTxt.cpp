// SauvegardeTxt.cpp 

#include "SauvegardeTxt.hpp"
using namespace std;

// Méthode permettant de sauvegarder la grille en mode Terminal
void SauvegardeFichierTxt::sauvegarder(const Grille g, const string& nom_fichier){
    ofstream file(nom_fichier); // Créé objet ofstream pour ouvrir le fichier en mode ecriture
    if (!file){
        cout << "Erreur - Impossible d'ouvrir le fichier en écriture : " + nom_fichier << endl;
    }
    // Ecrire les dimensions de la grille (nombre de lignes et de colonnes) dans le fichier
    file << g.get_nbLigne() << " " << g.get_nbColonne() << endl;
    string message; // Stocker la valeur à écrire

    // Parcourir chaque cellule de la grille
    for (int y = 0; y < g.get_nbLigne(); ++y) {
        for (int x = 0; x < g.get_nbColonne(); ++x) {
            // Déterminer la valeur de la cellule et la stocker dans "message"
            if (g.getValeur(x,y) == 0) {
                message = "0 ";
            } else if (g.getValeur(x,y) == 1) {
                message = "1 ";
            } else if (g.getValeur(x,y) == 2) {
                message = "2 ";
            } else if (g.getValeur(x,y) == 3) {
                message = "3 ";
            } else if (g.getValeur(x,y) == 4) {
                message = "4 ";
            }
            // Écrire valeur dans fichier
            file << message;
        }
        file << endl;
    }
    file.close();
}
