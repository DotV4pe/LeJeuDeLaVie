#include "FichierTest.hpp"

void FichierTest::getChemin(int mode) {
    // Création d'un fichier de test temporaire
    cheminFichier = "./Matrices/test_grid.txt"; 
    std::ofstream file(cheminFichier); // Ouverture en mode écriture du fichier ./Matrices/test_grid.txt
        
    // Écriture d'une grille de test simple
    file << "5 5\n";
    file << "0 0 0 0 0\n";
    file << "0 1 1 1 0\n";
    file << "0 0 0 0 0\n";
    file << "0 0 0 0 0\n";
    file << "0 0 0 0 0\n";
        
    file.close(); // Fermeture du fichier
        
    nomFichier = "test"; // Attribution du nom du fichier
    taille = 25; // Taille des pixels pour l'affichage
}