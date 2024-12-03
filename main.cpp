#include "GrilleTerm.hpp"
#include "GrilleGraph.hpp"
#include <iostream>

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