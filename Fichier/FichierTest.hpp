#include "Fichier.hpp"

#include <fstream>

class FichierTest : public Fichier {
public:
    FichierTest() : Fichier() {}
    virtual void getChemin(int mode) override {
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
        
        nomFichier = "test";
        taille = 25;
    }
};