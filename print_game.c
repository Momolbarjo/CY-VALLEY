#include "header.h"

void Introduction(Player* knight){

  knight->itemsPlayer.herbs=0 ;
  knight->score=0;
  knight->health = 100;
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


void print_Overlay(Player *a) {
  
  printf("              \u2694  %s  \u2694",a->name);


  int Health_MAX = 100;
  const int Long = 20; // Longueur totale de la barre de vie
  int longHealth =
      (a->health * Long) / Health_MAX; // Longueur de la barre de vie en
                                       // fonction des points de vie actuels
  printf(
      "\n                                                            Health : [");
  for (int i = 0; i < Long; i++) {
    if (i < longHealth) {
      printf(ANSI_COLOR_RED
             "|" ANSI_COLOR_RESET); // Caractère représentant la vie
    } else {
      printf(" "); // Caractère représentant l'espace vide
    }
  }
  printf("]\n");

  printf("                                                            Score:%d\n",a->score);
  printf("                                                            Inventory:\n");
  printf("                                                            \U0001F33F x %d\n",a->itemsPlayer.herbs);
  printf("                                                            %s\n",a->itemsPlayer.item1);
  printf("                                                            %s\n",a->itemsPlayer.item2);
  printf("                                                            %s\n",a->itemsPlayer.item3);

  
  if(a->health==0){
    
    printf(" _____          __  __ ______    ______      ________ _____   \n");
    printf("/ ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\  \n");
    printf("| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | \n");
    printf("| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /  \n");
    printf("| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\  \n");
    printf(" \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ \n");
    
    sleep(2);
    exit(0)
      
    }
}

void area_print(int tab[SIZE][SIZE], Player *player){

     int window_x = player->posPlayer.pos_x -
                 18; // Coordonnée x du coin supérieur gauche de la fenêtre
  int window_y = player->posPlayer.pos_y -
                 18; // Coordonnée y du coin supérieur gauche de la fenêtre

  
    // Afficher la fenêtre
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
        printf( "\U0001F64B"); // Ajout d'un espace après l'emoji
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
      } else {
        printf("%c ", tab[x][y]);
      }
    }else {
          printf("  "); // Afficher un espace pour les coordonnées en dehors de
                        // la map
        }
      }
      printf("\n");
    }
}
