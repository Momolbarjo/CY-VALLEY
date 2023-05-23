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
    printf("\n                                   a. \033[0m\033[1;33m%s\033[0m\u2694\n ", "New game");
    printf("\033[0;36m");
    printf("                                      b. \033[0m\033[1;33m%s\033[0m\U0001F4DC\n", "Keys");
    printf("\033[0;36m");
    printf("                                         c. \033[0m\033[1;33m%s\033[0m\U0001F4BE\n", "Resume game");
    printf("\033[0;36m");
    printf("                                            d. \033[0m\033[1;33m%s\033[0m\U0001F6AA\n", "Leave");


    char choice=getch();
    switch (choice) {
    case 'a':

      return 1;

    case 'b':
      return 2;

    case 'c':
    return 3;

    case 'd':
      exit(0);

    default:
      ClearScreen();
      printf("Invalid choice. Please try again.\n");
    }
  }
}
