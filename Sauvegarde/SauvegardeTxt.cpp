// SauvegardeTxt.cpp 

#include "SauvegardeTxt.hpp"

void SauvegardeFichierTxt::sauvegarder(const Grille g, const std::string& nom_fichier){
    std::ofstream file(nom_fichier);
    if (!file){
        std::cout << "Erreur - Impossible d'ouvrir le fichier en écriture : " + nom_fichier << std::endl;
    }
    file << g.get_nbLigne() << " " << g.get_nbColonne() << std::endl;
    std::string message;
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
        file << std::endl;
    }
    file.close();
}
