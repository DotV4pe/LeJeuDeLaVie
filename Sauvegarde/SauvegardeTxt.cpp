// SauvegardeTxt.cpp 

#include "SauvegardeTxt.hpp"
using namespace std;

void SauvegardeFichierTxt::sauvegarder(const Grille g, const string& nom_fichier){
    ofstream file(nom_fichier);
    if (!file){
        cout << "Erreur - Impossible d'ouvrir le fichier en écriture : " + nom_fichier << endl;
    }
    file << g.get_nbLigne() << " " << g.get_nbColonne() << endl;
    string message;
    for (int y = 0; y < g.get_nbLigne(); ++y) {
        for (int x = 0; x < g.get_nbColonne(); ++x) {
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
            file << message;
        }
        file << endl;
    }
    file.close();
}
