#include "Menu.hpp"
using namespace std;

// Constructeur
Menu::Menu() {}

// Destructeur
Menu::~Menu() {}

void Menu::affichageMenu(){
    // Affichage du menu de choix 
    cout << "Veuillez choisir le mode de visualisation :" << endl;
    cout << "1. Terminal"<< endl;
    cout << "2. Graphique"<< endl;
    cout << "0. Quitter"<< endl;
    cout << "Votre choix : ";
    // Enregistre le mode choisi par l'utilisateur
    cin >> mode;
    cout << endl;
}

void Menu::lancer() {
    JeuDeLaVie jeu;
    Grille g;
    Fichier *f = new FichierTxt;
    // Appel de la fonction affichageMenu()
    affichageMenu();
    // Vérification du mode choisi
    if (mode==0) { exit(0); }
    else if (mode != 1 && mode != 2) {
        cout << "Mode incorrect ! Mode terminal choisi par défaut." << endl;
        mode = 1;
    }
    // Appel de la fonction getChemin() pour obtenir le chemin du fichier de la grille
    f->getChemin(mode);
    // Appel de la fonction initializegrille() pour obtenir la grille que l'on trouve dans le fichier
    g.initializegrille(f);
    // Appel de la fonction run() pour lancer le jeu à l'aide des informations obtenu auparavant (grille, fichier, mode)
    jeu.run(g,f,mode);
}