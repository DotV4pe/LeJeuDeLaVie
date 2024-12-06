#include "./Test/Test.hpp"
#include "./Menu/Menu.hpp"

int main() {
    // Création d'un objet test
    Test t;
    t.test();
    
    // Création d'un objet menu pour lancer le jeu
    Menu m;
    m.lancer();
    return 0;
}