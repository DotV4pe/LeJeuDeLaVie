#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int cellSize = 50;
const int grilleLongueur = 10;
const int grilleHauteur = 10;

vector<vector<int>> grille(grilleLongueur, vector<int>(grilleHauteur));

void initializegrille() {
    srand(time(0));
    for (int x = 0; x < grilleLongueur; ++x) {
        for (int y = 0; y < grilleHauteur; ++y) {
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
    sf::RenderWindow window(sf::VideoMode(grilleLongueur * cellSize, grilleHauteur * cellSize), "Le Jeu de la Vie");
    
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
