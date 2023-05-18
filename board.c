#include "header.h"

//ClearScreen will clear the console and put the cursor at the beginnig of the screen  using ansi escape code/
void ClearScreen() { printf("\033[H\033[J"); }

void open_website_part(int i) {
    size_t len = snprintf(NULL, 0, FORMAT_STRING, i) + 1;
    char *cmd = malloc(len*sizeof(char));
    snprintf(cmd, len, FORMAT_STRING, i);
    system(cmd);
    free(cmd);
}

//initialise_board will randomly place the items on the map
void initialise_board(int board[SIZE][SIZE]) {
  int x, y;
  // Initialize the board with '.' to represent the playable area.
  for (x = 0; x < SIZE; x++) {
    for (y = 0; y < SIZE; y++) {
      board[x][y] = '.';
    }
  }
  // Initialize the borders with 'X'.
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
 
  int nb_herbs, nb_houses,nb_teleports, sword_x, sword_y, ennemy_x, ennemy_y, shield_x,
      shield_y;
  int random_x, random_y, npc1_x, npc1_y, npc2_x,npc2_questpos_x,npc2_questpos_y ,npc2_y,nb_rocks,nb_woods;

  srand(time(NULL));//generating more unpredictable and varied random numbers.
  nb_herbs = (SIZE - 4) * (SIZE - 4) /4; // Calculate the number of grass tiles to generate
  for (int i = 0; i < nb_herbs; i++) {
    int herbs_x = rand() % (SIZE - 4) +2; // Generate a random x-coordinate between 2 and SIZE-3.
    int herbs_y = rand() % (SIZE - 4) +2; // Generate a random x-coordinate between 2 and SIZE-3.
    plateau[herbs_x][herbs_y] ='@'; //character for the herbs that will be displayed using Unicode emojis
  }
  nb_rocks = 15;
  for (int i = 0; i < nb_rocks; i++) {
    int rocks_x = rand() % (SIZE - 4) +2;
    int rocks_y = rand() % (SIZE - 4) +2;
    plateau[rocks_x][rocks_y] = 'R'; 
  }
   nb_houses = 20;
  for (int i = 0; i < nb_houses; i++) {
    int houses_x = rand() % (SIZE - 4) +2;
    int houses_y = rand() % (SIZE - 4) +2;
    plateau[houses_x][houses_y] = 'H';
  }
   nb_woods=20;
  for (int i = 0; i <nb_woods; i++) {
    int woods_x = rand() % (SIZE - 4) +2;
    int woods_y = rand() % (SIZE - 4) + 2;
    plateau[woods_x][woods_y] = 'W';
  }

  nb_teleports=12;

for (int i = 0; i <nb_teleports; i++) {
    int teleports_x = rand() % (SIZE - 4) +2;
    int teleports_y = rand() % (SIZE - 4) + 2;
    plateau[teleports_x][teleports_y] = 'T';
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
  ennemy_x = rand() % (SIZE - 4) + 2;
  ennemy_y = rand() % (SIZE - 4) + 2;
  plateau[ennemy_x][ennemy_y] = '!';
  }
}
