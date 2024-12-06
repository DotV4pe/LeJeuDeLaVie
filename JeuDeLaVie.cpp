#include "JeuDeLaVie.hpp"
using namespace std;

JeuDeLaVie::JeuDeLaVie() : torique(0) // Initialisation de torique à 0 par défaut
{   
}

JeuDeLaVie::~JeuDeLaVie() {}

void JeuDeLaVie::run(Grille& grid, Fichier *f, int mode) {
    int temps, iterations, cycle = 0;
    bool continuer = true;
    // Choix d'une grille torique ou non
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

    // Création d'une grille pour enregistrer son état précédent
    Grille grillePrecedente; 
    vector<vector<Cellule>> donneeGriPre = grid.getGrille(); 
    grillePrecedente.setGrille(donneeGriPre); 
 
    if (mode == 1) { 
        // Création d'un objet cons pour l'affichage
        Console cons; 
        Sauvegarde *s = new SauvegardeFichierTxt(); // Création d'un objet SauvegardeFichierTxt
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
                if (gridChanged) break; // Sortie de la boucle for si l'état d'une des cellules à changer.
            } 
             
            // Vérification si la grille n'a pas changé.
            if (!gridChanged) { 
                cout << "Grille stabilisée après " << cycle + 1 << " cycles." << endl; 
                continuer = false; // Changement de l'état de la variable continuer
            } 
            
            grillePrecedente = grid; // Enregistrement de l'état de la grille précédente
            cycle++; // Incrémentation du nombre de cycles réalisé
        }
        // Vérification si le nombre d'itérations a été atteint
        if (cycle == iterations) {
            cout << "Nombre maximum de cycles atteint." << endl; // Message de sortie
        }
        
        delete s; // Suppression du pointeur de l'objet sauvegarde
    }
    else if (mode == 2) {
        // Demande et stock le temps en ms de la vitesse d'actualisation de la fenêtre
        cout << "Entrez le temps de génération de chaque cycle (en ms) : ";
        cin >> temps;
        cout << "Temps initialisé à " << temps << "ms\n" << endl;
        // Création d'un objet graph pour l'affichage
        Graphique graph;
        // cout << grid.get_nbColonne() << ", " << grid.get_nbLigne() << endl; // Débuggage
        sf::RenderWindow window(sf::VideoMode(grid.get_nbColonne() * grid.getTaille(), grid.get_nbLigne() * grid.getTaille()), "Le Jeu de la Vie");
        // La boucle tourne tant que la fenêtre est ouverte
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
             
            // Affichage de la grille dans notre fenêtre
            graph.affichage(grid, window); 
            // Update de la grille pour l'afficher
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
            
            // Enregistrement de la grille dans la grillePrecedente
            grillePrecedente = grid;

            // Temps d'attente entre chaque éxécution de la boucle
            sf::sleep(sf::milliseconds(temps));
        } 
    }
}
 
void JeuDeLaVie::updateGrille(Grille &grid) {
    vector<vector<Cellule>> tgrille = grid.getGrille(); // Création d'une grille temporaire
    for (int x = 0; x < grid.get_nbColonne(); ++x) {
        for (int y = 0; y < grid.get_nbLigne(); ++y) { 
            int compteur = 0; // Déclaration du compteur

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) { 
                    if (torique == 0) { // Update de la grille si la grille est torique
                        if (dx == 0 && dy == 0) continue; 
                        
                        // Prends en compte le cas où nous sommes sur des bords de la grille
                        int nx = (x + dx + grid.get_nbColonne()) % grid.get_nbColonne(); 
                        int ny = (y + dy + grid.get_nbLigne()) % grid.get_nbLigne(); 

                        if ((tgrille[nx][ny].estVivant() % 2) == 1) { // Vérifie si la Cellule est vivante
                                compteur++; // Si la cellule est vivante, on incrémente le compteur de voisin
                        }
                    } else if (torique == 1) { // Update de la grille si la grille est non torique
                        int nx = x + dx;
                        int ny = y + dy;
                        if (dx != 0 || dy != 0) { // Vérifie si ce n'est pas la cellule pour laquelle on calcule ces voisins
                            if (nx < grid.get_nbColonne()) { // Vérifie si nx n'est pas supérieur aux nombres de colonnes
                                if (nx > 0) { // Vérifie si nx n'est pas inférieur à 0
                                    if (ny < grid.get_nbLigne()) { // Vérifie si ny n'est pas supérieur aux nombres de lignes
                                        if (ny > 0) { // Vérifie si ny n'est pas inférieur à 0
                                            if ((tgrille[nx][ny].estVivant() % 2) == 1) { // Vérifie si la Cellule est vivante
                                                compteur++; // Si la cellule est vivante, on incrémente le compteur de voisin
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } 
            grid.update(x,y,compteur); // Mise à jour de la cellule en fonction de son nombre de voisin
        } 
    }
}