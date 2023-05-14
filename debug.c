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
        printf("\U0001F9DF ");
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

void Secure_Boot(Player* knight, Inventory* invent_player, Position* pos, Quests* npcs) {

    printf("Security checking...\n");

    // Vérification des pointeurs de l'inventaire
    if (!invent_player) {
        printf("Error while loading game due to invent_player struct pointer.\n");
        sleep(3);
        exit(0);
    }
    char* invent_ptr_names[] = {"item1", "item2", "item3", "herbs"};
    void* invent_ptrs[] = {invent_player->item1, invent_player->item2, invent_player->item3, &(invent_player->herbs)};
    int invent_ptr_count = sizeof(invent_ptrs) / sizeof(void*);
    for (int i = 0; i < invent_ptr_count; i++) {
        if (!invent_ptrs[i]) {
            printf("Error while loading game due to %s pointer.\n", invent_ptr_names[i]);
            sleep(3);
            exit(0);
        }
    }

    // Vérification des pointeurs du chevalier
    if (!knight) {
        printf("Error while loading game due to knight struct pointer.\n");
        sleep(3);
        exit(0);
    }
    char* knight_ptr_names[] = {"name", "score", "health"};
    void* knight_ptrs[] = {knight->name, &(knight->score), &(knight->health)};
    int knight_ptr_count = sizeof(knight_ptrs) / sizeof(void*);
    for (int i = 0; i < knight_ptr_count; i++) {
        if (!knight_ptrs[i]) {
            printf("Error while loading game due to %s pointer.\n", knight_ptr_names[i]);
            sleep(3);
            exit(0);
        }
    }

    // Vérification des pointeurs de la position
    if (!pos) {
        printf("Error while loading game due to pos pointer.\n");
        sleep(3);
        exit(0);
    }
    char* pos_ptr_names[] = {"pos_x", "pos_y"};
    void* pos_ptrs[] = {&(pos->pos_x), &(pos->pos_y)};
    int pos_ptr_count = sizeof(pos_ptrs) / sizeof(void*);
    for (int i = 0; i < pos_ptr_count; i++) {
        if (!pos_ptrs[i]) {
            printf("Error while loading game due to %s pointer.\n", pos_ptr_names[i]);
            sleep(3);
            exit(0);
        }
    }

    // Vérification des pointeurs des quêtes
    if (!npcs) {
        printf("Error while loading game due to npc struct pointer.\n");
        sleep(3);
        exit(0);
    }
    char* npcs_ptr_names[] = {"npc1", "npc2"};
    void* npcs_ptrs[] = {&(npcs->npc1), &(npcs->npc2)};
    int npcs_ptr_count = sizeof(npcs_ptrs) / sizeof(void*);
    for (int i = 0; i < npcs_ptr_count; i++) {
        if (npcs_ptrs[i] == NULL) {
            printf("Error while loading game due to %s pointer.\n", npcs_ptr_names[i]);
            sleep(3);
            exit(0);
        }
    }

    // Tout est en ordre
    sleep(3);
    printf("Everything is good.\n");
    sleep(2);
}
