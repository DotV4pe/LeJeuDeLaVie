#include "Test.hpp"

Test::Test() {}

Test::~Test() {}

void Test::test() {
    int fail = 0;

    std::cout << std::endl;
    std::cout << "Cellule - Règles de vie et de mort, [Cellule]" << std::endl;
    std::cout << std::endl;

    std::cout << "Initialisation" << std::endl;
    Cellule cell;
    if (cell.estVivant() == 0) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }

    std::cout << "Reproduction" << std::endl;
    cell.updateCellule(3);
    if (cell.estVivant() == 1) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }

    cell.setVie(1);
    std::cout << "Mort par isolement" << std::endl;
    cell.updateCellule(1);
    if (cell.estVivant() == 0) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }

    cell.setVie(1);
    std::cout << "Mort par surpeuplement" << std::endl;
    cell.updateCellule(4);
    if (cell.estVivant() == 0) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }

    std::cout << std::endl;
    std::cout << "Grille - Initialisation et manipulation, [Grille]" << std::endl;
    std::cout << std::endl;
    Grille grille;
    Fichier *fichier = new FichierTest;

    fichier->getChemin(1);

    std::cout << "Initialisation" << std::endl;
    grille.initializegrille(fichier);

    std::cout << "Test nombre colonne" << std::endl;
    if (grille.get_nbColonne() == 5) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }

    std::cout << "Test nombre ligne" << std::endl;
    if (grille.get_nbLigne() == 5) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }
    
    std::cout << "Test taille grille" << std::endl;
    if (grille.getTaille() == 25) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }

    std::cout << "Mise à jour des valeurs" << std::endl;
    grille.update(1, 1, 3);
    if (grille.getValeur(1, 1) == 1) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }

    std::cout << std::endl;
    std::cout << "JeuDeLaVie - Mise à jour de la grille, [JeuDeLaVie]" << std::endl;
    std::cout << std::endl;
    JeuDeLaVie jeu;
    
    std::cout << "Mise à jour grille torique" << std::endl;
    grille.initializegrille(fichier);
        
    // Sauvegarde de l'état initial
    std::vector<std::vector<Cellule>> grilleAvant = grille.getGrille();
        
    // Mettre à jour la grille
    jeu.updateGrille(grille);
        
    // Vérifier que la grille a changé
    std::vector<std::vector<Cellule>> grilleApres = grille.getGrille();
        
    bool changed = false;
    for (size_t x = 0; x < grilleAvant.size(); ++x) {
        for (size_t y = 0; y < grilleAvant[x].size(); ++y) {
            if (grilleAvant[x][y].estVivant() != grilleApres[x][y].estVivant()) {
                changed = true;
                break;
            }
        }
        if (changed) break;
    }
    if (changed == true) { std::cout << "TEST PASSED ✅" << std::endl; }
    else { std::cout << "TEST FAILED ❌" << std::endl; fail++; }
    std::cout << std::endl;

    std::cout << "Nombre de test échoué : " << fail << " test(s)." << std::endl;
}