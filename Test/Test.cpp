#include "Test.hpp"
using namespace std;

Test::Test() {}

Test::~Test() {}

void Test::test() {
    int fail = 0;

    cout << endl;
    cout << "Cellule - Règles de vie et de mort, [Cellule]" << endl;
    cout << endl;

    cout << "Initialisation" << endl;
    Cellule cell;
    if (cell.estVivant() == 0) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }

    cout << "Reproduction" << endl;
    cell.updateCellule(3);
    if (cell.estVivant() == 1) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }

    cell.setVie(1);
    cout << "Mort par isolement" << endl;
    cell.updateCellule(1);
    if (cell.estVivant() == 0) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }

    cell.setVie(1);
    cout << "Mort par surpeuplement" << endl;
    cell.updateCellule(4);
    if (cell.estVivant() == 0) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }

    cout << endl;
    cout << "Grille - Initialisation et manipulation, [Grille]" << endl;
    cout << endl;
    Grille grille;
    Fichier *fichier = new FichierTest;

    fichier->getChemin(1);

    cout << "Initialisation" << endl;
    grille.initializegrille(fichier);

    cout << "Test nombre colonne" << endl;
    if (grille.get_nbColonne() > 0) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }

    cout << "Test nombre ligne" << endl;
    if (grille.get_nbLigne() > 0) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }
    
    cout << "Test taille grille" << endl;
    if (grille.getTaille() > 0) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }

    cout << "Mise à jour des valeurs" << endl;
    grille.update(1, 1, 3);
    if (grille.getValeur(1, 1) == 1) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }

    cout << endl;
    cout << "JeuDeLaVie - Mise à jour de la grille, [JeuDeLaVie]" << endl;
    cout << endl;
    JeuDeLaVie jeu;
    
    cout << "Mise à jour grille torique" << endl;
    grille.initializegrille(fichier);
        
    // Sauvegarde de l'état initial
    vector<vector<Cellule>> grilleAvant = grille.getGrille();
        
    // Mettre à jour la grille
    jeu.updateGrille(grille);
        
    // Vérifier que la grille a changé
    vector<vector<Cellule>> grilleApres = grille.getGrille();
        
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
    if (changed == true) { cout << "\033[1;32mTEST PASSED ✅\033[0m" << endl; }
    else { cout << "\033[1;31mTEST FAILED ❌\033[0m" << endl; fail++; }
    cout << endl;

    cout << "Nombre de test échoué : " << fail << " test(s)." << endl;
}