#include "Menu.hpp"

Menu::Menu() {}

Menu::~Menu() {}

void Menu::affichage(Grille g, int iterations) {}

void Menu::affichage(Grille g, sf::RenderWindow &window) {}

void Menu::affichageMenu(){
    std::cout << "Choisissez le mode :\n";
    std::cout << "1. Terminal\n";
    std::cout << "2. Graphique\n";
    std::cout << "0. Quitter\n";
    std::cout << "Votre choix : ";
    std::cin >> mode;
}

void Menu::lancer() {
    JeuDeLaVie jeu;
    Grille g;
    Fichier *f = new FichierTxt;
    if (mode==0) { exit(0); }
    affichageMenu();
    f->getChemin(mode);
    g.initializegrille(f);
    jeu.run(g,f,mode);
}