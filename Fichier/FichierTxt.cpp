#include "FichierTxt.hpp"

FichierTxt::FichierTxt() : Fichier() {}

FichierTxt::~FichierTxt() {}

void FichierTxt::getChemin() {
    std::cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    std::cin >> nomFichier;
    if (nomFichier == "data") {
        taille = 190;
    } else if (nomFichier == "test") {
        taille = 25;
    } else if (nomFichier == "a") {
        taille = 20;
    } else if (nomFichier == "b") {
        taille = 10;
    }
    cheminFichier = "./Matrices/" + nomFichier + ".txt";

    // Créer le dossier de sortie
    setDossierSortie("./" + nomFichier + "_out/");
    if (std::filesystem::exists(dossierSortie)) {
        for (const auto& fichier : std::filesystem::directory_iterator(dossierSortie)) { // Parcours tout les éléments
            if (std::filesystem::is_regular_file(fichier.path())) { // .path() : Récupère le chemin complet || is_regular_file() : Vérifie si cet élément est un fichier.
                std::filesystem::remove(fichier.path()); // Supprime le fichier
                std::cout << "Fichier supprimé" << std::endl;
            } 
        }
        std::filesystem::remove(dossierSortie);
        std::cout << "Le dossier a correctement était supprimé" << std::endl;
    }
    std::filesystem::create_directory(dossierSortie);
    if (std::filesystem::exists(dossierSortie)) {
        std::cout << "Le dossier a correctement était créé" << std::endl;
    }
}