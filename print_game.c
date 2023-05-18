#include "header.h"

//game_over screen will be called when the player lose like when  he has 0 health point or he missed an quest//
void game_over(){

    ClearScreen();
    printf("  _____          __  __ ______    ______      ________ _____   \n");
    printf(" / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\  \n");
    printf("| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | \n");
    printf("| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /  \n");
    printf("| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\  \n");
    printf(" \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ \n");
    exit(0);
}

//Introduction initialize all the importante  variable that are going to be possibly changed, it will also get the name of the player and check if it is too long//
void Introduction(Player* knight){

  knight->itemsPlayer.herbs=0 ;
  knight->itemsPlayer.woods=0;
  knight->score=0;
  knight->health = 100;
  knight->dimensions=0;
  knight->npcs.npc1=false;
  knight->npcs.npc2=false;
  strcpy(knight->itemsPlayer.item1, ".");
  strcpy(knight->itemsPlayer.item2, ".");
  strcpy(knight->itemsPlayer.item3, ".");
  knight->posPlayer.pos_x = SIZE / 2;
  knight->posPlayer.pos_y = SIZE / 2;

   printf("Welcome brave knight...We need you to save our kingdom...But, what's your name ?\n");
      scanf("%s", knight->name);
      while(strlen(knight->name)>12){
        printf("Please enter a correct name\n");
        scanf("%s", knight->name);
      }
      printf("%s, save us...please\n", knight->name);
      sleep(3);
}

//print_Overlay display all the important informations of the player like his health points, score, pieces of wood...//
void print_Overlay(Player *a) {
  
int Health_MAX = 100;
if(a->health>100){
  a->health=100;
}
const int Long = 20; // total length of the health bar
int longHealth=0; // Length of the health bar based on current health points

printf("\n                                                            Health : [");
longHealth = (a->health * Long) / Health_MAX; // Updating the length of the health bar
for (int i = 0; i < Long; i++) {
  if (i < longHealth) {
    printf(ANSI_COLOR_RED "|" ANSI_COLOR_RESET); // health symbol
  } else {
    printf(" "); // empty space
  }
}
printf("]\n");
//display of the overlay//

  printf("                                                            Score:%d\n",a->score);
  printf("                                                            Inventory:\n\n");
  printf("                                                           \U0001F33F x %d\n",a->itemsPlayer.herbs);
  printf("                                                           \U0001FAB5  x %d\n",a->itemsPlayer.woods);
  printf("                                                           %s\n",a->itemsPlayer.item1);
  printf("                                                           %s\n",a->itemsPlayer.item2);
  printf("              \u2694  %s  \u2694",a->name);
  printf("                                     %s\n",a->itemsPlayer.item3);

  if(a->health==0){   
    game_over();    
    }
}

//area_print display for a few second an 35*35 area of the map//
void area_print(int tab[SIZE][SIZE], Player *player){

  int window_x = player->posPlayer.pos_x -18; // x-coordinate of the top-left corner of the window
  int window_y = player->posPlayer.pos_y -18; // y-coordinate of the top-left corner of the window
  
    // display the window
    ClearScreen();
    printf("\n");
    for (int x = window_x; x < window_x + 35; x++) {
      for (int y = window_y; y < window_y + 35; y++) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
          if (x == player->posPlayer.pos_x && y == player->posPlayer.pos_y) {
            printf(ANSI_COLOR_YELLOW "P " ANSI_COLOR_RESET);
          } else if (tab[x][y] == '*') {
        printf("\u2694 ");
      } else if (tab[x][y] == '@') {
        printf("\U0001F33F");
      } else if (tab[x][y] == '=') {
        printf( "\U0001F64B"); 
      } else if (tab[x][y] == '^') {
        printf("\U0001F9D9");
      } else if (tab[x][y] == '#') {
        printf("\U0001F6E1 ");
      } else if (tab[x][y] == '~') {
        printf("\U0001F381");
      } else if (tab[x][y] == 'W') {
        printf("\U0001FAB5 ");
      } else if (tab[x][y] == 'R') {
        printf("\U0001FAA8 ");
      } else if (tab[x][y] == '!') {
        printf("\U0001F9DF ");
      } else if (tab[x][y] == 'H') {
        printf("\U0001F3E1");
      } else if (tab[x][y] == 'X') {
        printf("\U0001F30A");
      } else if (tab[x][y] == 'T') {
        printf("\U0001F300");
      } else {
        printf("%c ", tab[x][y]);
      }
    }else {
          printf("  "); 
        }
      }
      printf("\n");
    }
}
