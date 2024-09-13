#include "header.h"

//move_window display the game window that make sure to move following the movement of the player//
int move_window(int map[SIZE][SIZE], Player *player) {
while (1) {
  int window_x = player->posPlayer.pos_x - 15; // x-coordinate of the top-left corner of the window
  int window_y = player->posPlayer.pos_y -25; // y-coordinate of the top-left corner of the window

  
    // display the window
    ClearScreen();
    print_Overlay(player);
    printf("\n");
    printf("\n");
    timer(player);
    printf("\n");
    for (int x = window_x; x < window_x + 30; x++) {
      for (int y = window_y; y < window_y + 50; y++) {
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
      } else if (map[x][y] == 'W') {
        printf("\U0001FAB5 ");
      } else if (map[x][y] == 'R') {
        printf("\U0001FAA8 ");
      } else if (map[x][y] == '~') {
        printf("\U0001F381");
      } else if (map[x][y] == '!') {
        printf("\U0001F9DF ");
      } else if (map[x][y] == 'H') {
        printf("\U0001F3E1");
      } else if (map[x][y] == 'T') {
        printf("\U0001F300");
      } else if (map[x][y] == 'B') {
        printf("\U0001F3DA");
      } else if (map[x][y] == 'X') {
        printf("\U0001F30A");
      } else if (map[x][y] == '%') {
        printf(".");
      } else {
        printf("%c ", map[x][y]);
      }
    }else {
          printf("  "); 
        }
      }
      printf("\n");
    }
   
    char input=getch();
    if (input == 'i') {
    interaction(map,player);
} else {
    
    // Move the window accordling and make the play stay at the center
    switch (input) {
    case 'z':
       if (player->posPlayer.pos_x > 2 && (map[player->posPlayer.pos_x-1][player->posPlayer.pos_y] == '.' || map[player->posPlayer.pos_x-1][player->posPlayer.pos_y] == '@')) {
        player->posPlayer.pos_x--;
        window_x--;
        player->score++;
    }
    else if(player->posPlayer.pos_x > 2 && map[player->posPlayer.pos_x-1][player->posPlayer.pos_y] == 'R') {
        if(map[player->posPlayer.pos_x-2][player->posPlayer.pos_y] == '.') {
            
            map[player->posPlayer.pos_x-2][player->posPlayer.pos_y] = 'R';
            map[player->posPlayer.pos_x-1][player->posPlayer.pos_y] = '.';
            player->posPlayer.pos_x--;
            window_x--;
            player->score+=5;  
        }
    }
      break;
    case 'q':
      if (player->posPlayer.pos_y > 2 && (map[player->posPlayer.pos_x ][player->posPlayer.pos_y-1]=='.' || map[player->posPlayer.pos_x ][player->posPlayer.pos_y-1]=='@')) {
        player->posPlayer.pos_y--;
        window_y--;
        player->score++;
      }
      else if(player->posPlayer.pos_x > 2 &&  map[player->posPlayer.pos_x ][player->posPlayer.pos_y-1]=='R'){
      if(map[player->posPlayer.pos_x][player->posPlayer.pos_y-2] == '.') {
            
            map[player->posPlayer.pos_x][player->posPlayer.pos_y-2] = 'R';
            map[player->posPlayer.pos_x][player->posPlayer.pos_y-1] = '.';
            player->posPlayer.pos_y--;
            window_y--;
            player->score+=5;    
        }
        
      }
      break;
    case 's':
      if (player->posPlayer.pos_x < SIZE - 3 && (map[player->posPlayer.pos_x+1 ][player->posPlayer.pos_y]=='.' || map[player->posPlayer.pos_x+1 ][player->posPlayer.pos_y]=='@')) {
        player->posPlayer.pos_x++;
        window_x++;
        player->score++; 
      }
      else if( player->posPlayer.pos_x < SIZE - 3 &&  map[player->posPlayer.pos_x+1 ][player->posPlayer.pos_y]=='R'){
      if(map[player->posPlayer.pos_x+2][player->posPlayer.pos_y] == '.') {
            // Push the box represented by the rock to the new position
            map[player->posPlayer.pos_x+2][player->posPlayer.pos_y] = 'R';
            map[player->posPlayer.pos_x+1][player->posPlayer.pos_y] = '.';
            player->posPlayer.pos_x++;
            window_x++;
            player->score+=5; 
        }
      }
      break;
    case 'd':
      if (player->posPlayer.pos_y < SIZE - 3 && (map[player->posPlayer.pos_x ][player->posPlayer.pos_y+1]=='.' || map[player->posPlayer.pos_x ][player->posPlayer.pos_y+1]=='@')) {
        player->posPlayer.pos_y++;
        window_y++;
        player->score++; 
        
      }
      else if( player->posPlayer.pos_x < SIZE - 3 &&  map[player->posPlayer.pos_x ][player->posPlayer.pos_y+1]=='R'){
        if(map[player->posPlayer.pos_x][player->posPlayer.pos_y+2] == '.') {
           
            map[player->posPlayer.pos_x][player->posPlayer.pos_y+2] = 'R';
            map[player->posPlayer.pos_x][player->posPlayer.pos_y+1] = '.';
            player->posPlayer.pos_y++;
            window_y++;
            player->score+=5; 
            
        }
      }
      
      break;
      case 'e':
      ClearScreen();
      printf("What do you want to do?\n\na.resume\nb.save\nc.Map\nd.Return to the menu\n"); //display a menu and wait the input of the player//
      char choice=getch();
     
     switch(choice){
     	
     	  case 'a':
     	
     	  break;
     	
       	case 'b':
       	
        ClearScreen();
        printf("Saving...\n");
        sleep(1);
        savegame(map, player, "game.bin", "map.bin");
        printf("Game saved!\n");
        sleep(2);
        break;
        
        case 'c':
        
        ClearScreen();
        area_print(map,player);
        sleep(3);
        break;
      
       case 'd':
       ClearScreen();
       return 0;  
       }  
      default:
      printf("Invalid input.\n");
      break;
    }
   }
  }
  return 0;
}
