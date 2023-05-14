#include "header.h"


int move_window(int tab[SIZE][SIZE], Player *player) {
  int score = 0;

  int window_x = player->posPlayer.pos_x - 9; // Coordonnée x du coin supérieur gauche de la fenêtre
  int window_y = player->posPlayer.pos_y - 9; // Coordonnée y du coin supérieur gauche de la fenêtre

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
    
    char input[2];
    while(getchar() != '\n'); // vide le tampon d'entrée
    fgets(input, 2, stdin);
    usleep(550000);
    if (input[0] == 'i') {
    interaction(tab,player);
} else {
    
    // Déplacer le joueur en conséquence
    switch (input[0]) {
    case 'z':
       if (player->posPlayer.pos_x > 2 && (tab[player->posPlayer.pos_x-1][player->posPlayer.pos_y] == '.' || tab[player->posPlayer.pos_x-1][player->posPlayer.pos_y] == '@')) {
        player->posPlayer.pos_x--;
        window_x--;
        player->score++;
    }
    else if(player->posPlayer.pos_x > 2 && tab[player->posPlayer.pos_x-1][player->posPlayer.pos_y] == 'R') {
        if(tab[player->posPlayer.pos_x-2][player->posPlayer.pos_y] == '.') {
            // Push the box to the new position
            tab[player->posPlayer.pos_x-2][player->posPlayer.pos_y] = 'R';
            tab[player->posPlayer.pos_x-1][player->posPlayer.pos_y] = '.';
            player->posPlayer.pos_x--;
            window_x--;
            player->score+=5;  
        }
    }
      break;
    case 'q':
      if (player->posPlayer.pos_y > 2 && (tab[player->posPlayer.pos_x ][player->posPlayer.pos_y-1]=='.' || tab[player->posPlayer.pos_x ][player->posPlayer.pos_y-1]=='@')) {
        player->posPlayer.pos_y--;
        window_y--;
        player->score++;
      }
      else if(player->posPlayer.pos_x > 2 &&  tab[player->posPlayer.pos_x ][player->posPlayer.pos_y-1]=='R'){
      if(tab[player->posPlayer.pos_x][player->posPlayer.pos_y-2] == '.') {
            // Push the box to the new position
            tab[player->posPlayer.pos_x][player->posPlayer.pos_y-2] = 'R';
            tab[player->posPlayer.pos_x][player->posPlayer.pos_y-1] = '.';
            player->posPlayer.pos_y--;
            window_y--;
            player->score+=5;    
        }
        
      }
      break;
    case 's':
      if (player->posPlayer.pos_x < SIZE - 3 && (tab[player->posPlayer.pos_x+1 ][player->posPlayer.pos_y]=='.' || tab[player->posPlayer.pos_x+1 ][player->posPlayer.pos_y]=='@')) {
        player->posPlayer.pos_x++;
        window_x++;
        player->score++; 
      }
      else if( player->posPlayer.pos_x < SIZE - 3 &&  tab[player->posPlayer.pos_x+1 ][player->posPlayer.pos_y]=='R'){
      if(tab[player->posPlayer.pos_x+2][player->posPlayer.pos_y] == '.') {
            // Push the box to the new position
            tab[player->posPlayer.pos_x+2][player->posPlayer.pos_y] = 'R';
            tab[player->posPlayer.pos_x+1][player->posPlayer.pos_y] = '.';
            player->posPlayer.pos_x++;
            window_x++;
            player->score+=5; 
        }
      }
      break;
    case 'd':
      if (player->posPlayer.pos_y < SIZE - 3 && (tab[player->posPlayer.pos_x ][player->posPlayer.pos_y+1]=='.' || tab[player->posPlayer.pos_x ][player->posPlayer.pos_y+1]=='@')) {
        player->posPlayer.pos_y++;
        window_y++;
        player->score++; 
        
      }
      else if( player->posPlayer.pos_x < SIZE - 3 &&  tab[player->posPlayer.pos_x ][player->posPlayer.pos_y+1]=='R'){
        if(tab[player->posPlayer.pos_x][player->posPlayer.pos_y+2] == '.') {
            // Push the box to the new position
            tab[player->posPlayer.pos_x][player->posPlayer.pos_y+2] = 'R';
            tab[player->posPlayer.pos_x][player->posPlayer.pos_y+1] = '.';
            player->posPlayer.pos_y++;
            window_y++;
            player->score+=5; 
            
        }
      }
      
      break;
      case 'e':
      ClearScreen();
      printf(
          "What do you want to do?\n1.resume\n2.save\n3.Map\n4.Return to the menu\n");
      char choice[2];
    while(getchar() != '\n'); // vide le tampon d'entrée
    fgets(choice, 2, stdin);
     
     switch(choice[0]){
     	
     	case '1':
     	
     	break;
     	
       	case '2':
       	
        ClearScreen();
        printf("Saving...\n");
        sleep(3);
        printf("Game saved!\n");
        sleep(2);
        break;
        
        case '3':
        
        ClearScreen();
        area_print(tab,player);
        sleep(3);
        break;
      
       case '4':
       ClearScreen();
       return 0;  
       }  
    default:
      printf("Invalid input.\n");
      break;
    }
  }
  }
}
