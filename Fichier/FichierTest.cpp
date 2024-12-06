#include "FichierTest.hpp"

void FichierTest::getChemin(int mode) {
    // Création d'un fichier de test temporaire
    cheminFichier = "./Matrices/test_grid.txt";
    std::ofstream file(cheminFichier);
        
    // Écriture d'une grille de test simple
    file << "5 5\n";
    file << "0 0 0 0 0\n";
    file << "0 1 1 1 0\n";
    file << "0 0 0 0 0\n";
    file << "0 0 0 0 0\n";
    file << "0 0 0 0 0\n";
        
    file.close();
        
    nomFichier = "test_grid";
    taille = 25;
}