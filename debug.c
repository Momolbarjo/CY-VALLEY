#include "header.h"

void print_board(int tab[SIZE][SIZE]) {
  fflush(stdout);
  ClearScreen();
  int x, y;

  for (x = 0; x < SIZE; x++) {
    for (y = 0; y < SIZE; y++) {
      if (tab[x][y] == '*') {
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
        printf("\U0001F9CC ");
      } else if (tab[x][y] == 'H') {
        printf("\U0001F3E1");
      } else if (tab[x][y] == 'X') {
        printf("\U0001F30A");
      } else {
        printf("%c ", tab[x][y]);
      }
    }
    printf("\n");
  }
}

void Secure_Boot(Player* knight,Inventory* invent_player,Position* pos,Quests* npcs){
    
    printf("Security checking...");

    if(invent_player == NULL){
    printf("Error while loading game due to invent_player struct pointer...");
}
     if(invent_player->item1 == NULL){
    printf("Error while loading game due to item1 pointer...");
    sleep(3);
    exit(0);
}
     if(invent_player->item2 == NULL){
    printf("Error while loading game due to item2 pointer...");
    sleep(3);
    exit(0);
}
     if(invent_player->item3 == NULL){
    printf("Error while loading game due to item3 pointer...");
    sleep(3);
    exit(0);
}
     if(invent_player->herbs == NULL){
    printf("Error while loading game due to herbs pointer...");
    sleep(3);
    
}
     if(knight == NULL){
    printf("Error while loading game due to knight struct pointer...");
    sleep(3);
    exit(0);
}
     if(knight->name == NULL){
    printf("Error while loading game due to name pointer...");
    sleep(3);
    exit(0);
}
     if(knight->score == NULL){
    printf("Error while loading game due to score pointer...");
    sleep(3);
    
}
    if(knight->health == NULL){
    printf("Error while loading game due to health pointer...");
    sleep(3);
    
}
    if(pos == NULL){
    printf("Error while loading game  due to pos pointer...");
    sleep(3);
    

}   if(pos->pos_x == NULL){
    printf("Error while loading game  due to pos_x pointer...");
    sleep(3);
    
}
    if(pos->pos_y == NULL){
    printf("Error while loading game due to pos_ypointer...");
    sleep(3);
    }
    if(npcs == NULL){
    printf("Error while loading game due to npc struct pointer...");
    sleep(3);
    
}
    if(npcs->npc1 == NULL){
    printf("Error while loading game due to npc1 pointer...");
    sleep(3);
    
}
    if(npcs->npc2 == NULL){
    printf("Error while loading game due to npc2 pointer...");
    sleep(3);
    
}
    sleep(2);
    exit(0);
    printf("Everything is good");
    sleep(2);
    

}
