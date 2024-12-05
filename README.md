# 🌱 Jeu de la vie - Projet POO

Le programme est une implémentation en C++ de l'automate cellulaire "Jeu de la vie" de Conway, développé dans le cadre d'un projet de Programmation Orientée Objet (POO). Il permet de simuler l'évolution de cellules sur une grille selon des règles simples mais captivantes.

---

## 🎮 Documentation Utilisateur

### 📋 Présentation du Jeu de la vie

Le **Jeu de la vie**, créé par John Conway en 1970, est un automate cellulaire où des cellules vivantes ou mortes évoluent sur une grille en fonction de leurs voisines. Ce modèle simule des phénomènes émergents, illustrant comment des règles simples engendrent des comportements complexes.

---

### 📐 Règles du Jeu

1. **Naissance** : Une cellule morte avec exactement **3 voisines vivantes** devient vivante.
2. **Surpopulation** : Une cellule vivante avec plus de **3 voisines vivantes** meurt.
3. **Sous-population** : Une cellule vivante avec moins de **2 voisines vivantes** meurt.
4. **Survie** : Une cellule vivante avec **2 ou 3 voisines vivantes** reste vivante.

---

### 🚀 Modes de lancement

Le programme propose deux modes principaux :

- **Mode Terminal** : Affichage textuel pour une utilisation rapide.
- **Mode Graphique** : Visualisation dynamique avec l'interface **SFML** pour un rendu immersif.

---

### 🔧 Instructions d'utilisation

#### Pré-requis
Assurez-vous d'avoir les dépendances nécessaires :
- **Compilateur C++ (gcc/g++)**
- **SFML** (pour le mode graphique)

#### 📁 Organisation des fichiers

Votre programme utilise des fichiers pour initialiser l'état des cellules. Vous devrez fournir un fichier texte contenant une grille de cellules (vivantes (`1`) ou mortes(`0`)). La première ligne permettra de spécifier la taille de la grille (hauteur & largeur) comme suit :
```
5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```
Ici, `1` représente une cellule vivante, et `0` une cellule morte.

---

### 📦 Utilisation du Makefile

Le **Makefile** simplifie la compilation et l'exécution du programme. Voici les commandes disponibles : 

- **Compilation** : 
  ```
  make
  ```
  Cette commande génère un exécutable nommé `main`.

- **Nettoyage des fichiers compilés** :
  ```
  make clean
  ```
  Supprime les fichiers objets et l'exécutable pour une recompilation propre.

- **Exécution** :
  ```
  ./main
  ```
  Lance le programme interactif.

---

### 🎮 Étapes pour Lancer le programme

#### 1. Choix du Mode
Au lancement, choisissez le mode de visualisation :
- **1** : Mode Terminal
- **2** : Mode Graphique
- **0** : Quitter

#### 2. Sélection du fichier d'entrée
Indiquez le fichier d'état initial des cellules sans son extension. Exemple : 
```
Veuillez renseigner votre fichier : data
```

#### 3. Configuration de la grille
Définissez si la grille doit être **torique** :
```
Voulez-vous une grille torique :
0. Oui
1. Non
```

---

### 🖥️ Mode Terminal

1. **Définissez le nombre de cycles** :
   ```
   Nombre de cycles du jeu de la vie : 5
   ```

2. **Visualisation** :
   Les cycles sont affichés dans le terminal, et les fichiers texte correspondants sont enregistrés dans un dossier de sortie.

---

### 🖼️ Mode Graphique

1. **Configurez la vitesse** :
   Définissez le délai (en millisecondes) entre chaque cycle d'affichage :
   ```
   Entrez le temps de génération de chaque cycle (en ms) : 1000
   ```

2. **Visualisation graphique** :
   Regardez l'évolution des cellules en temps réel grâce à l'interface graphique.

---

### ✨ Fonctionnalités générales

- **Gestion automatique des dossiers** : Le programme crée et nettoie automatiquement les dossiers/fichiers nécessaires. En utilisant le mode terminal, vous pourrez retrouver vos fichiers dans un dossier nommé de la forme suivante : `<nom_du_fichier_dentree>_out`
- **Fichiers générés** : Chaque cycle est enregistré dans un fichier texte nommé de la forme `cycle_<n°_révision>.txt`, ce qui permet d'analyser ou de rejouer les simulations.
- **Extensions des obstacles** : Le programme intègre une extension où vous pouvez choisir un obstacle (statique) qui peut agir comme une cellule vivante (`2`) ou comme une cellule morte (`3`).

---

### 🛠️ Extensions, conseils & astuces

- **Fichiers d'entrée** : Vérifiez que vos fichiers contiennent uniquement des `0`, `1`, `2` ou `3`.
- **Performance** : Le mode graphique peut être gourmand en ressources pour des grilles de grande taille. Préférez le mode terminal pour des simulations rapides.


---

## 👥 Contributeurs

- ***DotVape / lb_sioul* : Louis**
- ***Lilixnp* : Lilian**


---