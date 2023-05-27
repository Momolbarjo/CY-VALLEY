#include "header.h"

void timer(Player *knight) {
    if (knight->npcs.timer_start == true) {
        int minutes = knight->quest_seconds / 60;
        int seconds = knight->quest_seconds % 60;

        printf("Time left: %d:%02d\n", minutes, seconds);

        knight->quest_seconds--;

        if (knight->quest_seconds < 0) {
            printf("The time is over, bye bye...");
            sleep(1);
            game_over();
        }
    }
}


void display_end_screen() {
    ClearScreen();
    printf("             \\                  /\n");
    printf("    _________))                ((__________\n");
    printf("   /.-------./\\\\    \\    /    //\\.--------.\\\n");
    printf("  //#######//##\\\\   ))  ((   //##\\\\########\\\\\n");
    printf(" //#######//###((  ((    ))  ))###\\\\########\\\\\n");
    printf("((#######((#####\\\\  \\\\  //  //#####))########))\n");
    printf(" \\##' `###\\\\######\\\\  \\)(/  //######/####' `##/\n");
    printf("  )'    ``#)'  `##\\`->oo<-'/##'  `(#''     `(\n");
    printf("          (       ``\\`..'/''       )\n");
    printf("                     \"\\\"(\n");
    printf("                      `- )\n");
    printf("                      / /\n");
    printf("                     ( /\\\n");
    printf("                     /\\| \\\n");
    printf("                    (  \\\n");
    printf("                        )\n");
    printf("                       /\n");
    printf("                      (\n");
    printf("                      `\n");
    
    printf("\n    Thank you for playing our game!\n");
    exit(0);
}

//game_over screen will be called when the player lose like when  he has 0 health point or he missed an quest//
void game_over(){
  
    ClearScreen();
    printf("\x1b[31m");
    printf("  ██████╗ █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗     ██╗\n");
    printf("██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗    ██║\n");
    printf("██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝    ██║\n");
    printf("██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗    ╚═╝\n");
    printf("╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║    ██╗\n");
    printf(" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝    ╚═╝\n");
    printf("\x1b[0m");
    deleteSaveFiles("game.bin", "map.bin");
    exit(0);
}

//Introduction initialize all the importante  variable that are going to be possibly changed, it will also get the name of the player and check if it is too long//
void Introduction(Player* knight){

    knight->itemsPlayer.herbs=0 ;
    knight->itemsPlayer.woods=0;
    knight->score=0;
    knight->health =101;
    knight->dimensions=0;
    knight->quest_seconds=250;
    knight->npcs.npc1_step1=false;
    knight->npcs.npc2_step1=false;
    knight->npcs.npc1_step2=false;
    knight->npcs.npc2_step2=false;
    knight->npcs.timer_start=false;
    strcpy(knight->itemsPlayer.item1, ".");
    strcpy(knight->itemsPlayer.item2, ".");
    strcpy(knight->itemsPlayer.item3, ".");

    knight->posPlayer.pos_x = SIZE / 2;
    knight->posPlayer.pos_y = SIZE / 2;

    printf("Welcome brave knight...We need you to save our kingdom...But, what's your name ?\n");
    scanf("%s", knight->name);
    clear_buffer();
    while(strlen(knight->name)>12 || strlen(knight->name)<1){
        printf("Please enter a correct name\n");
        scanf("%s", knight->name);
	clear_buffer();
      }
      printf("%s, save us...please\n", knight->name);
      sleep(3);


}

//print_Overlay display all the important informations of the player like his health points, score, pieces of wood...//
void print_Overlay(Player *knight) {
  
  int Health_MAX = 100;
  if(knight->health>100){
    knight->health=100;
}
  const int Long = 20; // total length of the health bar
  int longHealth=0; // Length of the health bar based on current health points

  printf("\n                                                            Health : [");
  longHealth = (knight->health * Long) / Health_MAX; // Updating the length of the health bar
  for (int i = 0; i < Long; i++) {
    if (i < longHealth) {
      printf(ANSI_COLOR_RED "|" ANSI_COLOR_RESET); // health symbol
  } else {
      printf(" "); // empty space
  }
}
  printf("]\n");
//display of the overlay//

  printf("                                                            Score:%d\n",knight->score);


  printf("                                                            Inventory:\n\n");
  printf("                                                           \U0001F33F x %d\n",knight->itemsPlayer.herbs);
  printf("                                                           \U0001FAB5  x %d\n",knight->itemsPlayer.woods);
  printf("              \u2694  %s  \u2694\n",knight->name);
  printf("                                                           %s\n",knight->itemsPlayer.item1);
  printf("                                                           %s\n",knight->itemsPlayer.item2);
  printf("                                                           %s\n",knight->itemsPlayer.item3);
 
    
  
  if(knight->score >= 5000){
   	knight->score =5000;
	printf("\nYou reached the maximum score, well played !!");	   
}

}

//area_print display for a few second an 35*35 area of the map//
void area_print(int map[SIZE][SIZE], Player *player){

    int window_x = player->posPlayer.pos_x -18; // x-coordinate of the top-left corner of the window
    int window_y = player->posPlayer.pos_y -18; // y-coordinate of the top-left corner of the window
  
    // display the window
    ClearScreen();
    printf("\n");
    for (int x = window_x; x < window_x + 35; x++) {
      for (int y = window_y; y < window_y + 35; y++) {
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
          if (x == player->posPlayer.pos_x && y == player->posPlayer.pos_y) {
            printf("\U0001F977");
          } else if (map[x][y] == '*') {
        printf("\u2694 ");
      } else if (map[x][y] == '@') {
        printf("\U0001F33F");
      } else if (map[x][y] == '=') {
        printf( "\U0001F64B"); 
      } else if (map[x][y] == '^') {
        printf("\U0001F9D9");
      } else if (map[x][y] == '#') {
        printf("\U0001F6E1 ");
      } else if (map[x][y] == '~') {
        printf("\U0001F381");
      } else if (map[x][y] == 'W') {
        printf("\U0001FAB5 ");
      } else if (map[x][y] == 'R') {
        printf("\U0001FAA8 ");
      } else if (map[x][y] == '!') {
        printf("\U0001F9DF ");
      } else if (map[x][y] == 'H') {
        printf("\U0001F3E1");
      } else if (map[x][y] == 'X') {
        printf("\U0001F30A");
      } else if (map[x][y] == 'T') {
        printf("\U0001F300");
      } else if (map[x][y] == 'B') {
        printf("\U0001F3DA");
      } else {
        printf("%c ", map[x][y]);
      }
    }else {
          printf("  "); 
        }
      }
      printf("\n");
    }
}
