#include "header.h"

int main() {

  open_website_part(3); // Ouverture d'une URL
  int board[SIZE][SIZE];
  Player knight;
  Position player_position;
  Inventory player_inventory;
  Quests player_quests;
  Secure_Boot(&knight, &player_inventory, &player_position, &player_quests);

  while (1) {
    int choice = show_menu();
    if (choice == 1) {
      ClearScreen();
      Introduction(&knight);
      initialise_board(board);
      randomizer(board);
      move_window(board, &knight);
    } else if (choice == 2) {
      ClearScreen();
      print_game_instructions();

    }
    else if (choice == 3) {
      ClearScreen();
      chargerPartie(board,&knight, "partie.bin", "carte.bin");
      move_window(board, &knight);
    }
  }
  return 0;
}

