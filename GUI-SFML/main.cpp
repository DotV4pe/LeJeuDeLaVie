#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Grille.cpp"

using namespace std;

vector<vector<int>> grille(grilleLongueur, vector<int>(grilleHauteur));

void initializegrille(Grille gr) {
    srand(time(0));
    for (int x = 0; x < gr.getLongueur(); ++x) {
        for (int y = 0; y < gr.getHauteur; ++y) {
            grille[x][y] = rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
}

void rendergrille(sf::RenderWindow &window) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < grilleLongueur; ++x) {
        for (y = 0; y < grilleHauteur; ++y) {
            if (grille[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

void calculgrille() {
    srand(time(0));
    for (int x = 0; x < grilleLongueur; ++x) {
        for (int y = 0; y < grilleHauteur; ++y) {
            if (grille[x][y] == 0){
                grille[x][y] = rand() % 5;
            } else {
                grille[x][y] = 0;
            }
        }
    }
}

int main() {
    Grille g(10,50,50);

    sf::RenderWindow window(sf::VideoMode(g.getLongueur() * g.getTaille(), g.getHauteur() * g.getTaille()), "Le Jeu de la Vie");
    
    initializegrille();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        rendergrille(window);
        calculgrille();
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
