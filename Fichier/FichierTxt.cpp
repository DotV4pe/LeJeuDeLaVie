#include "FichierTxt.hpp"
using namespace std;

FichierTxt::FichierTxt() : Fichier() {}

FichierTxt::~FichierTxt() {}

void FichierTxt::getChemin(int mode) {
    // Demande utilisateur le chemin du fichier (Ex : data)
    cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    cin >> nomFichier;

    // Attribution d'une taille en fonction du fichier donner
    if (nomFichier == "data") {
        taille = 190;
    } else if (nomFichier == "test") {
        taille = 25;
    } else if (nomFichier == "a") {
        taille = 20;
    } else if (nomFichier == "b") {
        taille = 7;
    } else {
        cout << "Entrez la taille des pixels que vous souhaitez : ";
        cin >> taille; // Si le fichier n'est pas fourni de base (data,test,a,b)
    }
    cheminFichier = "./Matrices/" + nomFichier + ".txt"; // Initialisation du chemin du fichier

    if (mode == 1) {
        // Créer le dossier de sortie
        setDossierSortie("./" + nomFichier + "_out/");
        if (filesystem::exists(dossierSortie)) {
            for (const auto& fichier : filesystem::directory_iterator(dossierSortie)) { // Parcours tout les éléments
                if (filesystem::is_regular_file(fichier.path())) { // .path() : Récupère le chemin complet || is_regular_file() : Vérifie si cet élément est un fichier.
                    filesystem::remove(fichier.path()); // Supprime le fichier
                    cout << "Fichier supprimé" << endl;
                } 
            }
            // Suppression du dossier de sortie s'il existait
            filesystem::remove(dossierSortie);
            cout << "Le dossier a correctement été supprimé" << endl;
        }
        // Création du dossier de sortie
        filesystem::create_directory(dossierSortie);
        if (filesystem::exists(dossierSortie)) {
            cout << "Le dossier a correctement été créé" << endl;
        }
    }
}