#include "GrilleTerm.hpp"
#include "GrilleGraph.hpp"
#include <filesystem>

using namespace std;

int affichageMenu(){
    int m; // voir si ce n'est pas mieux de faire une classe avec enum ?
    cout << "Choisissez le mode :\n";
    cout << "1. Terminal\n";
    cout << "2. Graphique\n";
    cout << "Votre choix : ";
    cin >> m;
    return m;
}

int main() {
    string cheminDossier = "./Cycles/";
    for (const auto& fichier : filesystem::directory_iterator(cheminDossier)) { // Parcours tout les éléments
        if (filesystem::is_regular_file(fichier.path())) { // .path() : Récupère le chemin complet || is_regular_file() : Vérifie si cet élément est un fichier.
            filesystem::remove(fichier.path()); // Supprime le fichier
            cout << "Fichier supprimé : " << fichier.path() << endl;
        }
    }
    cout << "Tous les fichiers du dossier ont été supprimés." << endl;
    
    int mode = affichageMenu();

    Grille *g;

    string chemin;
    cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    cin >> chemin;

    if (mode==1){
        g = new GrilleTerm();
    } else if (mode==2)
    {
        g = new GrilleGraph();
    } else {
        cout << "Choix invalide. Mode par défaut : Terminal\n";
        mode = 1;
        g = new GrilleTerm();
    }

    g->initializegrille(chemin);
    g->run();
    return 0;
}