#include "./Grilles/GrilleTerm.hpp"
#include "./Grilles/GrilleGraph.hpp"
#include <filesystem>

using namespace std;

int affichageMenu(){
    int m; // voir si ce n'est pas mieux de faire une classe avec enum ?
    cout << "Choisissez le mode :\n";
    cout << "1. Terminal\n";
    cout << "2. Graphique\n";
    cout << "0. Quitter\n";
    cout << "Votre choix : ";
    cin >> m;
    return m;
}

int main() {
    string cheminDossier = "./Cycles/", chemin;
    for (const auto& fichier : filesystem::directory_iterator(cheminDossier)) { // Parcours tout les éléments
        if (filesystem::is_regular_file(fichier.path())) { // .path() : Récupère le chemin complet || is_regular_file() : Vérifie si cet élément est un fichier.
            filesystem::remove(fichier.path()); // Supprime le fichier
        }
    }
    cout << "Tous les fichiers du dossier ont été supprimés." << endl;
    
    int mode = affichageMenu();

    Grille *g;

    if (mode==1){
        g = new GrilleTerm();
    } else if (mode==2)
    {
        g = new GrilleGraph();
    } else if (mode == 0) {
        exit(0);
    } else {
        cout << "Choix invalide. Mode par défaut : Terminal" << endl;
        g = new GrilleTerm();
    }

    cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    cin >> chemin;

    g->initializegrille(chemin);
    g->run();
    return 0;
}