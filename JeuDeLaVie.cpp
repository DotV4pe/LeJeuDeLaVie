#include "JeuDeLaVie.hpp"
using namespace std;

JeuDeLaVie::JeuDeLaVie() : torique(0) {}

JeuDeLaVie::~JeuDeLaVie() {}

void JeuDeLaVie::run(Grille& grid, Fichier *f, int mode) {
    int temps, iterations, cycle = 0;
    bool continuer = true;

    cout << "Voulez-vous une grille torique : " << endl;
    cout << "0. Oui" << endl;
    cout << "1. Non" << endl;
    cout << "Votre choix : ";
    cin >> torique;
    if (torique == 0){
        cout << "Grille torique initialisée \n" << endl;
    } else {
        cout << "Grille non torique initialisée \n" << endl;
    }

    Grille grillePrecedente;
    vector<vector<Cellule>> donneeGriPre = grid.getGrille();
    grillePrecedente.setGrille(donneeGriPre);

    if (mode == 1) {
        Console cons;
        Sauvegarde *s = new SauvegardeFichierTxt();
        string cheminDossier = f->getDossierSortie(); // Utiliser le chemin du dossier de sortie

        cout << "Nombre de cycles du jeu de la vie : ";
        cin >> iterations;
        while (continuer && cycle < iterations) {
            // Fichier de sortie pour chaque cycle
            string nom_sortie = cheminDossier + "/cycle_" + to_string(cycle+1) + ".txt";
            s->sauvegarder(grid, nom_sortie);
            cons.affichage(grid, cycle);
            updateGrille(grid);
            bool gridChanged = false;
            for (int x = 0; x < grid.get_nbColonne(); ++x) {
                for (int y = 0; y < grid.get_nbLigne(); ++y) {
                    if (grid.getValeur(x,y) != grillePrecedente.getValeur(x,y)) {
                        gridChanged = true;
                        break;
                    }
                }
                if (gridChanged) break;
            }
            
            if (!gridChanged) {
                cout << "Grille stabilisée après " << cycle + 1 << " cycles." << endl;
                continuer = false;
            }
            
            grillePrecedente = grid;
            cycle++;
        }
        if (cycle == iterations) {
            cout << "Nombre maximum de cycles atteint." << endl;
        }
        
        delete s;
    }
    else if (mode == 2) {
        cout << "Entrez le temps de génération de chaque cycle (en ms) : ";
        cin >> temps;
        cout << "Temps initialisé à " << temps << "ms\n" << endl;
        Graphique graph;
        cout << grid.get_nbColonne() << ", " << grid.get_nbLigne() << endl;
        sf::RenderWindow window(sf::VideoMode(grid.get_nbColonne() * grid.getTaille(), grid.get_nbLigne() * grid.getTaille()), "Le Jeu de la Vie");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            graph.affichage(grid, window);
            updateGrille(grid);

            bool gridChanged = false;
            for (int x = 0; x < grid.get_nbColonne(); ++x) {
                for (int y = 0; y < grid.get_nbLigne(); ++y) {
                    if (grid.getValeur(x,y) != grillePrecedente.getValeur(x,y)) {
                        gridChanged = true;
                        break;
                    }
                }
                if (gridChanged) break;
            }
            
            if (!gridChanged) {
                cout << "Grille stabilisée." << endl;
                window.close();
            }
            
            grillePrecedente = grid;
                
            sf::sleep(sf::milliseconds(temps));
        }
    }
}

void JeuDeLaVie::updateGrille(Grille &grid) {
    if (torique == 0) {
        vector<vector<Cellule>> tgrille = grid.getGrille();
        for (int x = 0; x < grid.get_nbColonne(); ++x) {
            for (int y = 0; y < grid.get_nbLigne(); ++y) {
                int compteur = 0;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        
                        int nx = (x + dx + grid.get_nbColonne()) % grid.get_nbColonne();
                        int ny = (y + dy + grid.get_nbLigne()) % grid.get_nbLigne();

                        if ((tgrille[nx][ny].estVivant() % 2) == 1) {
                            compteur++;
                        }
                    }
                }
                grid.update(x,y,compteur);
            }
        }
    } else if (torique == 1) {
        vector<vector<Cellule>> tgrille = grid.getGrille();

        for (int x = 0; x < grid.get_nbColonne(); ++x) {
            for (int y = 0; y < grid.get_nbLigne(); ++y) {
                int compteur = 0;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (dx != 0 || dy != 0) {
                            if (nx < grid.get_nbColonne()) {
                                if (nx > 0) {
                                    if (ny < grid.get_nbLigne()) {
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
                grid.update(x,y,compteur);
            }
        }
    }
}