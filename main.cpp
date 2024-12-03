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

    g->initializegrille();
    g->run();
    return 0;
}