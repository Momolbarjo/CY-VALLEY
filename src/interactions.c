#include "header.h"

char getch() {
    char buf = 0;
    struct termios old = {0};

    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");

    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");

    if (read(0, &buf, 1) < 0)
        perror ("read()");

    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;

    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");

    return buf;
}

//function that simulate the teleportation of the player on a random place in the map//
void teleporter_interaction(int map[SIZE][SIZE], Player *player) {

  player->dimensions++;

  // Looking for a cell available
  int new_x, new_y;
  do {
    new_x = rand() % (SIZE - 4) + 2;
    new_y = rand() % (SIZE - 4) + 2;
  } while (map[new_x][new_y] != '.' && map[new_x][new_y] != '@');

  // update of the player coordinates
  player->posPlayer.pos_x = new_x;
  player->posPlayer.pos_y = new_y;
}

//The gift  interaction give randomly to the player +500 points of score,a game over...//
void gift_interaction( Player *player){
    int random=rand()%6;
    sleep(1);
    printf("%d",random);


    switch(random){

        case 0:
            player->health+=50;
            break;


        case 1:
            printf("Unlucky");
            fflush(stdout);
            sleep(1);
            game_over();
            break;

        case 2:
            player->score=0;
            break;

        case 3:
            player->itemsPlayer.herbs=0;
            break;

        case 4:
            player->score+=500;
            break;
        
        case 5:
        printf("Lucky You...");
        fflush(stdout);
        sleep(1);
        display_end_screen();
        break; 

    }
}

//This function will check which caractere is above the player and simulate the action associated with this charactere//
int interaction(int board[SIZE][SIZE], Player* knight) {

     if(knight->health<=0){ 
        ClearScreen();
        printf("The ennemy killed you...");
        fflush(stdout);
        sleep(1);  
        game_over();    
        }
    
    if(board[knight->posPlayer.pos_x][knight->posPlayer.pos_y] == '@' && knight->itemsPlayer.herbs <20) {
        knight->itemsPlayer.herbs++;
         board[knight->posPlayer.pos_x][knight->posPlayer.pos_y] = '.';
        
    } 
    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == '*'){

        if (strcmp(knight->itemsPlayer.item1, ".") == 0){
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = '.';
            strcpy(knight->itemsPlayer.item1, "\u2694");
        }

        else if (strcmp(knight->itemsPlayer.item2, ".") == 0){
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = '.';
            strcpy(knight->itemsPlayer.item2, "\u2694");
        }

        else if (strcmp(knight->itemsPlayer.item3, ".") == 0){
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = '.';
            strcpy(knight->itemsPlayer.item3, "\u2694");
        }
    }
    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == '#'){

        if (strcmp(knight->itemsPlayer.item1, ".") == 0){
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = '.';
            strcpy(knight->itemsPlayer.item1, "\U0001F6E1");
        }

        else if (strcmp(knight->itemsPlayer.item2, ".") == 0){
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = '.';
            strcpy(knight->itemsPlayer.item2, "\U0001F6E1");
        }

        else if (strcmp(knight->itemsPlayer.item3, ".") == 0){
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = '.';
            strcpy(knight->itemsPlayer.item3, "\U0001F6E1");
        }
    }

    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == '~'){
        board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = '.';
        
        gift_interaction(knight);
        sleep(2);
    }

    if (board[knight->posPlayer.pos_x - 1][knight->posPlayer.pos_y] == '!') {
        if (strcmp(knight->itemsPlayer.item1, "\u2694") == 0 || strcmp(knight->itemsPlayer.item2, "\u2694") == 0 || strcmp(knight->itemsPlayer.item3, "\u2694") == 0) {
            knight->health -= 30;
            knight->score += 50;
            board[knight->posPlayer.pos_x - 1][knight->posPlayer.pos_y] = '.';
        } else if (strcmp(knight->itemsPlayer.item1, "\u2694") == 0 || strcmp(knight->itemsPlayer.item2, "\u2694") == 0 || strcmp(knight->itemsPlayer.item3, "\u2694") == 0) {
            if (strcmp(knight->itemsPlayer.item1, "\U0001F6E1") == 0 || strcmp(knight->itemsPlayer.item2, "\U0001F6E1") == 0 || strcmp(knight->itemsPlayer.item3, "\U0001F6E1") == 0) {
                knight->health -= 15;
                knight->score += 50;
                board[knight->posPlayer.pos_x - 1][knight->posPlayer.pos_y] = '.';
            } else {
                knight->health -= 30;
                knight->score += 50;
                board[knight->posPlayer.pos_x - 1][knight->posPlayer.pos_y] = '.';
            }
        } else if (strcmp(knight->itemsPlayer.item1, "\U0001F6E1") == 0 || strcmp(knight->itemsPlayer.item2, "\U0001F6E1") == 0 || strcmp(knight->itemsPlayer.item3, "\U0001F6E1") == 0) {
            knight->health -= 15;
        } else {
            knight->health -= 50;
        }
    }


    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == 'T'){
       teleporter_interaction(board,knight);      
    }

    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == 'W' &&(strcmp(knight->itemsPlayer.item1, "\u2694")==0 ||strcmp(knight->itemsPlayer.item2 , "\u2694")==0 || strcmp(knight->itemsPlayer.item3, "\u2694")==0) && knight->itemsPlayer.woods<15 ){ 
        board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] ='.';
        knight->itemsPlayer.woods++;

    }

    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == '^'){
      npc2_quest(board,knight);
    }

    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == '='){
      npc1_quest(board,knight);
    }

    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == 'H' &&(strcmp(knight->itemsPlayer.item1, "\u2694")==0 ||strcmp(knight->itemsPlayer.item2 , "\u2694")==0 || strcmp(knight->itemsPlayer.item3, "\u2694")==0)){
      board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] = 'B';
    }

    return 0;
}
