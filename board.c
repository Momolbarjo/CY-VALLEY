#include "header.h"

void ClearScreen() { printf("\033[H\033[J"); }

void open_website_part(int i) {
    size_t len = snprintf(NULL, 0, FORMAT_STRING, i) + 1;
    char *cmd = malloc(len*sizeof(char));
    snprintf(cmd, len, FORMAT_STRING, i);
    system(cmd);
    free(cmd);
}

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

void randomizer(int plateau[SIZE][SIZE],Position_Elements a) {
 
  int nb_herbs, nb_houses,nb_rocks,nb_woods;
  srand(time(NULL));
  nb_herbs = (SIZE - 4) * (SIZE - 4) /4; // Calculer le nombre de cases d'herbe à générer
  for (int i = 0; i < nb_herbs; i++) {
    a.grass.pos_x = rand() % (SIZE - 4) + 2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    a.grass.pos_y = rand() % (SIZE - 4) + 2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[a.grass.pos_x][a.grass.pos_y] ='@'; // Remplacer par le code Unicode de l'emoji de plante
  }
 
  nb_rocks = 15;
  for (int i = 0; i < nb_rocks; i++) {
    a.rock.pos_x= rand() % (SIZE - 4) +2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    a.rock.pos_y= rand() % (SIZE - 4) + 2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[a.rock.pos_x][a.rock.pos_y] = 'R'; // Remplacer par le code Unicode de l'emoji de maison
  }
   nb_houses = 20;
  for (int i = 0; i < nb_houses; i++) {
    a.house.pos_x = rand() % (SIZE - 4) + 2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    a.house.pos_y= rand() % (SIZE - 4) + 2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[a.house.pos_x][a.house.pos_y] = 'H'; // Remplacer par le code Unicode de l'emoji de maison
  }

   nb_woods =20;
  for (int i = 0; i <nb_woods; i++) {
    a.wood.pos_x = rand() % (SIZE - 4) + 2; // Générer une coordonnée x aléatoire entre 2 et SIZE-3
    a.wood.pos_y = rand() % (SIZE - 4) + 2; // Générer une coordonnée y aléatoire entre 2 et SIZE-3
    plateau[a.wood.pos_x][a.wood.pos_y] = 'W'; // Remplacer par le code Unicode de l'emoji de maison
  }

  a.sword.pos_x = rand() % (SIZE - 4) + 2;
  a.sword.pos_y = rand() % (SIZE - 4) + 2;
  plateau[a.sword.pos_x][a.sword.pos_y] = '*';

  a.shield.pos_x=rand() % (SIZE - 4) + 2;
  a.shield.pos_y=rand() % (SIZE - 4) + 2;
  plateau[a.shield.pos_x][a.shield.pos_y] = '#';

  a.npc1.pos_x=rand() % (SIZE - 4) + 2;
  a.npc1.pos_y=rand() % (SIZE - 4) + 2;
  plateau[a.npc1.pos_x][a.npc1.pos_y] = '=';
  
  a.npc2.pos_x=rand() % (SIZE - 4) + 2;
  a.npc2.pos_y=rand() % (SIZE - 4) + 2;
  plateau[a.npc2.pos_x][a.npc2.pos_y] = '^';

  a.random_item.pos_x=rand() % (SIZE - 4) + 2;
  a.random_item.pos_y=rand() % (SIZE - 4) + 2;
  plateau[a.random_item.pos_x][a.random_item.pos_y] = '~';

  for(int i=0;i<10;i++){  
  a.ennemy.pos_x=rand() % (SIZE - 4) + 2;
  a.ennemy.pos_y= rand() % (SIZE - 4) + 2;
  
  plateau[a.ennemy.pos_x][a.ennemy.pos_y] = '!';
  }
  if (plateau[a.ennemy.pos_x - 1][a.ennemy.pos_y] == 'H') { // Vérifier si la case précédente contient un emoji de maison
    plateau[a.ennemy.pos_x - 1][a.ennemy.pos_y] = '.';
  }
}
