#ifndef HEADER_H
#define HEADER_H
#include "header.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


#define SIZE 100
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"

typedef struct {

  int pos_x;
  int pos_y;

} Position;

typedef struct {
  int herbs;
  char item1[15];
  char item2[15];
  char item3[15];
} Inventory;

typedef struct {
  char name[70];
  int health;
  Inventory itemsPlayer;
  Position posPlayer;
  int score;
} Player;

void ClearScreen();
int print_game_instructions();
void Introduction(Player* knight);
void initialise_board(int board[SIZE][SIZE]);
void randomizer(int plateau[SIZE][SIZE]);
void print_board(int tab[SIZE][SIZE]);
void print_Overlay(Player *a);
void area_print(int tab[SIZE][SIZE], Player *player);
void move_window(int tab[SIZE][SIZE], Player *player);
void save_game(Player data); 
int show_menu();

#endif
