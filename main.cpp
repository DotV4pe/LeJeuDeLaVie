#include "./Grilles/GrilleTerm.hpp"
#include "./Grilles/GrilleGraph.hpp"
#include "./Affichage/Console.hpp"
#include "./Affichage/Graphique.hpp"

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

string getChemin(){
    string c;
    cout << "Entrez le chemin du fichier de l'état initial des cellules : ";
    cin >> c;
    return "./Matrices/" + c + ".txt";
}

int main() {
    string chemin;
    int mode = affichageMenu();

    Grille *g;
    JeuDeLaVie *jeu;

    if (mode==1){
        g = new GrilleTerm();
        jeu = new Console();
    } else if (mode==2)
    {
        g = new GrilleGraph();
        jeu = new Graphique();
    } else if (mode == 0) {
        exit(0);
    } else {
        cout << "Choix invalide. Mode par défaut : Terminal" << endl;
        g = new GrilleTerm();
        jeu = new Console();
    }

    chemin = getChemin();

    g->initializegrille(chemin);
    jeu->run(g);
    return 0;
}