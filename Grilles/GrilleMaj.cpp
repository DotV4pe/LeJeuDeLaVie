#include "GrilleMaj.hpp"

GrilleMaj::GrilleMaj() {}

GrilleMaj::~GrilleMaj() {}

void GrilleMaj::calculGrilleTorique(Grille &g) {
    std::vector<std::vector<Cellule>> tgrille = g.getGrille();


    for (int x = 0; x < g.get_nbColonne(); ++x) {
        for (int y = 0; y < g.get_nbLigne(); ++y) {
            int compteur = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    
                    int nx = (x + dx + g.get_nbColonne()) % g.get_nbColonne();
                    int ny = (y + dy + g.get_nbLigne()) % g.get_nbLigne();

                    if ((tgrille[nx][ny].estVivant() % 2) == 1) {
                        compteur++;
                    }
                }
            }
            g.update(x,y,compteur);
        }
    }
}

void GrilleMaj::calculGrilleNonTorique(Grille &g) {std::vector<std::vector<Cellule>> tgrille = g.getGrille();

    for (int x = 0; x < g.get_nbColonne(); ++x) {
        for (int y = 0; y < g.get_nbLigne(); ++y) {
            int compteur = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (dx != 0 || dy != 0) {
                        if (nx < g.get_nbColonne()) {
                            if (nx > 0) {
                                if (ny < g.get_nbLigne()) {
                                    if (ny > 0) {
                                        if ((tgrille[nx][ny].estVivant() % 2) == 1) {
                                            compteur++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            g.update(x,y,compteur);
        }
    }
    
}