#include "header.h"


int print_game_instructions() {
  printf("==========================\n");
  printf("       GAME INSTRUCTIONS\n");
  printf("==========================\n\n");
  printf("- Use the following keys to move your character:\n");
  printf("  'z' - Move Up\n");
  printf("  'q' - Move Left\n");
  printf("  's' - Move Down\n");
  printf("  'd' - Move Right\n\n");
  printf("- Your character is represented by 'P' on the game board.\n\n");
  printf("- 'H' represents a house on the game board. You need a key to enter "
         "the house.\n\n");
  printf("- '@' represents grass on the game board. You can farm on the grass "
         "to collect resources.\n\n");
  printf("- Your character has a health bar represented by a percentage. Your "
         "health decreases when you encounter obstacles or enemies.\n\n");
  printf("- Collect herbs to restore your health. Herbs can be found by "
         "farming on grass or by completing quests.\n\n");
  printf(
      "- Your objective is to explore the game world, collect resources, "
      "complete quests, and interact with NPCs to progress in the game.\n\n");
  printf("- You can save your game progress by choosing the '2' option from "
         "the in-game menu.\n\n");
  printf(
      "- To exit the game, choose the '3' option from the in-game menu.\n\n");
  printf("- Good luck and have fun playing the game!\n\n");
  sleep(6);
  ClearScreen();
  return (0);
}

void Introduction(Player* knight){

   printf("Welcome brave knight...We need you to save our kingdom...But, what's your name ?\n");
      scanf("%s", knight->name);
      printf("%s, save us...please\n", knight->name);
      sleep(3);

}


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

void print_Overlay(Player *a) {
  
  printf("              \u2694  %s  \u2694",a->name);


  int Health_MAX = 100;
  const int Long = 20; // Longueur totale de la barre de vie
  int longHealth =
      (a->health * Long) / Health_MAX; // Longueur de la barre de vie en
                                       // fonction des points de vie actuels

  printf(
      "                                                           Health : [");
  for (int i = 0; i < Long; i++) {
    if (i < longHealth) {
      printf(ANSI_COLOR_RED
             "|" ANSI_COLOR_RESET); // Caractère représentant la vie
    } else {
      printf(" "); // Caractère représentant l'espace vide
    }
  }
  printf("]\n");



  printf("                                                            Score:");

//printf("                                                            \n 5",);
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
        printf("\U0001F9CC ");
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


void move_window(int tab[SIZE][SIZE], Player *player) {
  int score = 0;

  int window_x = player->posPlayer.pos_x -
                 9; // Coordonnée x du coin supérieur gauche de la fenêtre
  int window_y = player->posPlayer.pos_y -
                 9; // Coordonnée y du coin supérieur gauche de la fenêtre

  while (1) {
    // Afficher la fenêtre
    ClearScreen();
    print_Overlay(player);
    printf("\n");
    printf("\n");
    for (int x = window_x; x < window_x + 20; x++) {
      for (int y = window_y; y < window_y + 20; y++) {
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
      } else if (tab[x][y] == 'W') {
        printf("\U0001FAB5 ");
      } else if (tab[x][y] == 'R') {
        printf("\U0001FAA8 ");
      } else if (tab[x][y] == '~') {
        printf("\U0001F381");
      } else if (tab[x][y] == '!') {
        printf("\U0001F9CC ");
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

    // Récupérer la touche frappée par le joueur
    char input;
    input = getchar();
    getchar();
    usleep(550000);
    // Déplacer le joueur en conséquence
    switch (input) {
    case 'z':
      if (player->posPlayer.pos_x > 2) {
        player->posPlayer.pos_x--;
        window_x--;
      }
      break;
    case 'q':
      if (player->posPlayer.pos_y > 2) {
        player->posPlayer.pos_y--;
        window_y--;
      }
      break;
    case 's':
      if (player->posPlayer.pos_x < SIZE - 3) {
        player->posPlayer.pos_x++;
        window_x++;
      }
      break;
    case 'd':
      if (player->posPlayer.pos_y < SIZE - 3) {
        player->posPlayer.pos_y++;
        window_y++;
      }
      break;
    case 'e':
      ClearScreen();
      printf(
          "What do you want to do?\n1.resume\n2.save\n3.Map\n4.Return to the menu\n");
      char choice = getchar();
      getchar(); // Consume the newline character
      if (choice == '1') {

      } else if (choice == '2') {
        ClearScreen();
        printf("Saving...\n");
        sleep(3);
        printf("Game saved!\n");
        sleep(2);
      } else if (choice == '3') {
        ClearScreen();
        area_print(tab,player);
        sleep(3);
      }else if (choice == '4') {
        ClearScreen();
        return 0;
      }
      break;
    default:
      printf("Invalid input.\n");
      getchar();
      break;
    }
  }
}

int show_menu() {
  while (1) {
   printf("\x1b[31m");
    printf("   _____          __      __   _ _                       _    .  ,   .           .  \n");
    printf("  / ____|         \\ \\    / /  | | |                  *  / \\_ *  / \\_      _  *        *   /\\'__        *\n");
    printf(" | |    _   _ _____\\ \\  / /_ _| | | ___ _   _          /    \\  /    \\,   ((        .    _/  /  \\  *'\n");
    printf(" | |   | | | |______\\ \\/ / _` | | |/ _ \\ | | |   .    /\\/\\  /\\/ :' __ \\_  `          _^/   ^/    `--.\n");
    printf(" | |___| |_| |       \\  / (_| | | |  __/ |_| |       /    \\/  \\  _/  \\-'\\      *    /.'   ^_   \\_   .'\\  *\n");
    printf(" \\_____/\\__, |        \\/ \\__,_|_|_|\\___|\\__, |      /\\  .-   `. \\/     \\ /==~=-=~=-=-;.  _/ \\ -. `_/   \\\n");
    printf("        __/ /                           __/ /      /  `-.__ ^   / .-'._'-./=^~_=-=~=^/  _ `--./ .-'  `-  \n");
    printf("       |___/                           |___/      /         `. / /       `.-=-~^=-=^.-'      '-._ `._ \n");
    printf("\x1b[0m");
    
    printf("\033[0;36m");
    printf("\n 1. \033[0m\033[1;33m%s\033[0m\u2694\n ", "New game");
    printf("\033[0;36m");
    printf(" 2. \033[0m\033[1;33m%s\033[0m\U0001F4DC\n", "Keys");
    printf("\033[0;36m");
    printf("    3. \033[0m\033[1;33m%s\033[0m\U0001F6AA\n", "Leave");


    int choice;

    printf("Enter your choice: ");

    scanf("%d", &choice);
    getchar(); // Consume newline character from input buffer

    switch (choice) {
    case 1:

      return 1;

    case 2:
      return 2;

    case 3:
      exit(0);

    default:
      ClearScreen();
      printf("Invalid choice. Please try again.\n");
    }
  }
}
