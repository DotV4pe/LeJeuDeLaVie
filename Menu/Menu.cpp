#include "Menu.hpp"

Menu::Menu() {}

Menu::~Menu() {}

void Menu::affichageMenu(){
    std::cout << "\nVeuillez choisir le mode de visualisation :\n";
    std::cout << "1. Terminal\n";
    std::cout << "2. Graphique\n";
    std::cout << "0. Quitter\n";
    std::cout << "Votre choix : ";
    std::cin >> mode;
    std::cout << std::endl;
}

void Menu::lancer() {
    JeuDeLaVie jeu;
    Grille g;
    Fichier *f = new FichierTxt;
    affichageMenu();
    if (mode==0) { exit(0); }
    else if (mode != 1 && mode != 2) {
        std::cout << "Mode incorrect ! Mode terminal choisi par défaut." << std::endl;
        mode = 1;
    }
    f->getChemin(mode);
    g.initializegrille(f);
    jeu.run(g,f,mode);
}