#include "header.h"

void main() {

  int board[SIZE][SIZE];
  Player knight;
  knight.itemsPlayer.herbs = 0;
  knight.health = 100;
  knight.posPlayer.pos_x = SIZE / 2;
  knight.posPlayer.pos_y = SIZE / 2;

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

    } else if (choice == 3) {
        ClearScreen();
    }
  }
}
