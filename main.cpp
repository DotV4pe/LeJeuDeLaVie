#include "./Test/Test.hpp"
#include "./Menu/Menu.hpp"

using namespace std;

int main() {
    int choix = 2;
    while(choix != 1 && choix != 0) {
        cout << endl;
        cout << "Voulez vous faire les tests unitaires ? " << endl;
        cout << "0. Oui" << endl;
        cout << "1. Non" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        if (choix == 0){
            // Création d'un objet test
            Test t;
            t.test();
        }
        cout << endl;
        if (choix != 1 && choix != 0) {
            cout << "Choix non valable" << endl;
        }   
    }
    
    // Création d'un objet menu pour lancer le jeu
    Menu m;
    m.lancer();
    return 0;
}