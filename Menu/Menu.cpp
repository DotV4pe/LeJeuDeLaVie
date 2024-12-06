#include "Menu.hpp"
using namespace std;

Menu::Menu() {}

Menu::~Menu() {}

void Menu::affichageMenu(){
    cout << "Veuillez choisir le mode de visualisation :" << endl;
    cout << "1. Terminal"<< endl;
    cout << "2. Graphique"<< endl;
    cout << "0. Quitter"<< endl;
    cout << "Votre choix : ";
    cin >> mode;
    cout << endl;
}

void Menu::lancer() {
    JeuDeLaVie jeu;
    Grille g;
    Fichier *f = new FichierTxt;
    affichageMenu();
    if (mode==0) { exit(0); }
    else if (mode != 1 && mode != 2) {
        cout << "Mode incorrect ! Mode terminal choisi par défaut." << endl;
        mode = 1;
    }
    f->getChemin(mode);
    g.initializegrille(f);
    jeu.run(g,f,mode);
}