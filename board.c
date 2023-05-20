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

void randomizer(int map[SIZE][SIZE]) {
 
  int  nb_herbs,sword_x, sword_y, ennemy_x, ennemy_y, shield_x,shield_y,rocks_x,rocks_y,houses_x,houses_y;
  int woods_x,woods_y,random_x, random_y,teleports_x,teleports_y,npc1_x, npc1_y, npc2_x,npc2_y;

  srand(time(NULL));//generating more unpredictable and varied random numbers.
  nb_herbs = (SIZE - 4) * (SIZE - 4) /4; // Calculate the number of grass tiles to generate
  for (int i = 0; i < nb_herbs; i++) {
      int herbs_x = rand() % (SIZE - 4) +2; // Generate a random x-coordinate between 2 and SIZE-3.
      int herbs_y = rand() % (SIZE - 4) +2; // Generate a random x-coordinate between 2 and SIZE-3.
      map[herbs_x][herbs_y] ='@'; //character for the herbs that will be displayed using Unicode emojis
  }

  for (int i = 0; i < 15; i++) {
    do{
          rocks_x = rand() % (SIZE - 6) +3;
          rocks_y = rand() % (SIZE - 6) +3;
    }while(map[rocks_x][rocks_y] != '.' && map[rocks_x][rocks_y] != '@' );
      map[rocks_x][rocks_y] = 'R'; 
  }
 
  for (int i = 0; i < 12; i++) {
    do{
          houses_x = rand() % (SIZE - 6) +3;
          houses_y = rand() % (SIZE - 6) +3;
    }while(map[houses_x][houses_y] != '.' && map[houses_x][houses_y] != '@' );
      map[houses_x][houses_y] = 'H';
  }

 for (int i = 0; i < 20; i++) {
    do{
          woods_x = rand() % (SIZE - 6) +3;
          woods_y = rand() % (SIZE - 6) +3;
    }while(map[woods_x][woods_y] != '.' && map[woods_x][woods_y] != '@' );
      map[woods_x][woods_y] = 'W';
  }

for (int i = 0; i < 12; i++) {
    do{
          teleports_x = rand() % (SIZE - 6) +3;
          teleports_y = rand() % (SIZE - 6) +3;
    }while(map[teleports_x][teleports_y] != '.' && map[teleports_x][teleports_y] != '@' );
      map[teleports_x][teleports_y] = 'T';
  }

 do {
        sword_x = rand() % (SIZE - 6) + 3;
        sword_y = rand() % (SIZE - 6) + 3;
  } while (map[sword_x][sword_y] != '.' && map[sword_x][sword_y] != '@' );
  map[sword_x][sword_y] = '*';

 do {
  shield_x=rand() % (SIZE - 6) + 3;
  shield_y=rand() % (SIZE - 6) + 3;
  } while (map[shield_x][shield_y] != '.' && map[shield_x][shield_y] != '@' );
  map[shield_x][shield_y] = '#';

 do {
        npc1_x=rand() % (SIZE - 20) + 10;
        npc1_y=rand() % (SIZE - 20) + 10;
  } while (map[npc1_x][npc1_y] != '.' && map[npc1_x][npc1_y] != '@' );
  map[npc1_x][npc1_y] = '=';
  
 do {
        npc2_x=rand() % (SIZE - 20) + 10;
        npc2_y=rand() % (SIZE - 20) + 10;
   } while (map[npc2_x][npc2_y] != '.' && map[npc2_x][npc2_y] != '@' );
  map[npc2_x][npc2_y] = '^';

 do {
        random_x = rand() % (SIZE - 6) + 3;
        random_y = rand() % (SIZE - 6) + 3;
    } while (map[random_x][random_y] != '.' && map[random_x][random_y] != '@' );
  map[random_x][random_y] = '~';
  
 for (int i = 0; i < 10; i++) {
    do {
        ennemy_x = rand() % (SIZE - 6) + 3;
        ennemy_y = rand() % (SIZE - 6) + 3;
    } while (map[ennemy_x][ennemy_y] != '.' && map[ennemy_x][ennemy_y] != '@' ); 

    map[ennemy_x][ennemy_y] = '!';
}
 
}

