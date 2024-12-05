#include "Menu.hpp"

Menu::Menu() { affichageMenu(); }

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

int Menu::getMode() { return mode; }

void Menu::lancer() {
    JeuDeLaVie jeu;
    Grille g;
    Fichier *f = new FichierTxt;
    affichageMenu();
    f->getChemin();
    g.initializegrille(f);
    jeu.run(g,f,mode);
}