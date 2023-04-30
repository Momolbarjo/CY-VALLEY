#include "header.h"

void ClearScreen() { printf("\033[H\033[J"); }

void initialise_board(int board[SIZE][SIZE]) {
  int x, y;
  // Initialiser le plateau avec des 'U' pour représenter la zone jouable
  for (x = 0; x < SIZE; x++) {
    for (y = 0; y < SIZE; y++) {
      board[x][y] = '.';
    }
  }
  // Initialiser les bords avec des 'X'
  for (y = 0; y < SIZE; y++) {
    board[0][y] = 'X';
    board[1][y] = 'X';
    board[SIZE - 2][y] = 'X';
    board[SIZE - 1][y] = 'X';
  }
  for (x = 0; x < SIZE; x++) {
    board[x][0] = 'X';
    board[x][1] = 'X';
    board[x][SIZE - 2] = 'X';
    board[x][SIZE - 1] = 'X';
  }
}

void randomizer(int plateau[SIZE][SIZE]) {
 
  int nb_herbs, nb_houses, sword_x, sword_y, ennemy_x, ennemy_y, shield_x,
      shield_y;
  int random_x, random_y, npc1_x, npc1_y, npc2_x, npc2_y,nb_rocks,nb_woods,rock_x,rock_y,wood_x,wood_y;

  srand(time(NULL));
  nb_herbs = (SIZE - 4) * (SIZE - 4) /
             4; // Calculer le nombre de cases d'herbe à générer
  for (int i = 0; i < nb_herbs; i++) {
    int herbs_x = rand() % (SIZE - 4) +
            2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    int herbs_y = rand() % (SIZE - 4) +
            2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[herbs_x][herbs_y] ='@'; // Remplacer par le code Unicode de l'emoji de plante
  }
 
  nb_rocks = 15;
  for (int i = 0; i < nb_rocks; i++) {
    int rocks_x = rand() % (SIZE - 4) +
            2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    int rocks_y = rand() % (SIZE - 4) +
            2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[rocks_x][rocks_y] = 'R'; // Remplacer par le code Unicode de l'emoji de maison
  }
   nb_houses = 20;
  for (int i = 0; i < nb_houses; i++) {
    int houses_x = rand() % (SIZE - 4) +
            2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    int houses_y = rand() % (SIZE - 4) +
            2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[houses_x][houses_y] = 'H'; // Remplacer par le code Unicode de l'emoji de maison
  }

   nb_woods =20;
  for (int i = 0; i <nb_woods; i++) {
    int woods_x = rand() % (SIZE - 4) +
            2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    int woods_y = rand() % (SIZE - 4) +
            2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[woods_x][woods_y] = 'W'; // Remplacer par le code Unicode de l'emoji de maison
  }

  sword_x = rand() % (SIZE - 4) + 2;
  sword_y = rand() % (SIZE - 4) + 2;
  plateau[sword_x][sword_y] = '*';

  shield_x=rand() % (SIZE - 4) + 2;
  shield_y=rand() % (SIZE - 4) + 2;
  plateau[shield_x][shield_y] = '#';

  npc1_x=rand() % (SIZE - 4) + 2;
  npc1_y=rand() % (SIZE - 4) + 2;
  plateau[npc1_x][npc1_y] = '=';
  
  npc2_x=rand() % (SIZE - 4) + 2;
  npc2_y=rand() % (SIZE - 4) + 2;
  plateau[npc2_x][npc2_y] = '^';

  random_x=rand() % (SIZE - 4) + 2;
  random_y=rand() % (SIZE - 4) + 2;
  plateau[random_x][random_y] = '~';

  for(int i=0;i<10;i++){  
  ennemy_x =rand() % (SIZE - 4) + 2;
  ennemy_y = rand() % (SIZE - 4) + 2;
  
  plateau[ennemy_x][ennemy_y] = '!';
  }
  if (plateau[ennemy_x - 1][ennemy_y] == 'H') { // Vérifier si la case précédente contient un emoji de maison
    plateau[ennemy_x - 1][ennemy_y] = '.';
  }
}
