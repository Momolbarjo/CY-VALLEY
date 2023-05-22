#include "header.h"


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


//Npc2 quest which consist to take 3 teleporter//
void npc2_quest(int map[SIZE][SIZE], Player* knight) {
   int secret_posx=knight->posPlayer.pos_x-3;
   int secret_posy=knight->posPlayer.pos_y+5;

   setbuf(stdout, NULL);//disable the buffer in order to force display
   //step 1:
   if(knight->dimensions!=3 && knight->npcs.npc2_step1==false){
        printf("Hello... brave knight,when you will  cross 3 dimensions,come back...");
        knight->npcs.timer_start=true;
        sleep(2);
        fflush(stdout);
   }//step1 done:
   else if (knight->npcs.npc2_step1==false && knight->dimensions==3){
        printf("Well played...");
        knight->npcs.npc2_step1=true;
        sleep(2);//step 2:
        fflush(stdout);
   }

   if( knight->npcs.npc2_step1==true && knight->npcs.npc2_step2==false){
        printf("\u2192 + \u2192 + \u2192 + \u2192 + \u2192 + \u2191 +\u2191+\u2191 ...");
        sleep(2);
        if(map[knight->posPlayer.pos_x][knight->posPlayer.pos_y]==map[secret_posx][secret_posy] || map[knight->posPlayer.pos_x][knight->posPlayer.pos_y]==map[secret_posx-1][secret_posy] ){
            knight->npcs.npc2_step2=true;
            sleep(1);
        }

        fflush(stdout);  
   }//step2 done:
   else if (knight->npcs.npc2_step2==true){
        knight->npcs.timer_start=false;
        printf("Impressive...");
        sleep(2);
        npc2_shop(knight);
        fflush(stdout);
   }
}

//npc2 shop in which the player can be stronger//
void npc2_shop(Player* knight){

    int shop = 1;

    while (shop) {
        printf("Welcome to my shop, what do you want?\n");
        printf("1. buy items\n");
        printf("2. leave the shop\n");
        

        int choice;
        scanf("%d", &choice);
        ClearScreen();

        switch (choice) {
        
            case 1:
                printf("what do you want to buy?\n");
                printf("1. potion of 20  health points (cost : 5\U0001F33F )\n");
                printf("2. +200 score points (cost : 5\U0001F33F  + 3\U0001FAB5)\n");
                printf("3. END_GAME (cost : 2500 points )\n");
                


                int buyItem;
                scanf("%d", &buyItem);
                ClearScreen();

                switch (buyItem) {
                    case 1:
                        if (knight->itemsPlayer.herbs >= 5) {
                            knight->itemsPlayer.herbs -= 5;
                            knight->health+=20;
                            printf("You've got + 20 health points ! \n");
                        } else {
                            printf("You dont have enough \U0001F33F ...\n");
                        }
                        break;

                    case 2:
                        if (knight->itemsPlayer.herbs >= 5 && knight->itemsPlayer.woods >= 3 ) {
                            knight->itemsPlayer.herbs -= 5;
                            knight->itemsPlayer.woods -= 3;
                            knight->score+=200;
                            printf("You've got + 200  score points! \n");
                        } else {
                            printf("You dont have enough resources...\n");
                        }
                        break;

                    case 3:
                        if (knight->score >= 2500) {
                            knight->score-= 2500;
                            printf("Well played, you win thanks to you score points!\n");
                        } else {
                            printf("You dont have enough score points ...\n");
                        }
                        break;

                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;

            case 2:
                shop = 0;
                printf("You are leaving the shop...\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void npc1_quest(int map[SIZE][SIZE], Player* knight){
    if(knight->npcs.npc2_step2==true){
        printf("I was waiting you... we need you to kill the threat...But are you ready?Y/N");
        char choice=getchar();
        
        switch(choice){

            case 'Y':
            //Dragon_fight();
            break;

            case 'N':
            printf("Come back when you feel ready...");
            sleep(1);
            break;

            default:
            printf("I don't understand what you are trying to say...");
            sleep(1);
            break;

        }


    }
    else{
        printf("Too early...");
        sleep(1);
        fflush(stdout);
    }
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
            player->health-=50;
            break;

        case 2:
            game_over();
            break;

        case 3:
            player->score=0;
            break;

        case 4:
            player->itemsPlayer.herbs=0;
            break;

        case 5:
            player->score+=500;
            break;

    }
}

//This function will check which caractere is above the player and simulate the action associated with this charactere//
int interaction(int board[SIZE][SIZE], Player* knight) {
    
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

    if(board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y] == '!'){
        if(strcmp(knight->itemsPlayer.item1, "\u2694")==0 ||strcmp(knight->itemsPlayer.item2 , "\u2694")==0 || strcmp(knight->itemsPlayer.item3, "\u2694")==0){
            knight->health-=30;
            knight->score+=50;
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y]='.';
        }
        else if((strcmp(knight->itemsPlayer.item1, "\u2694")==0 ||strcmp(knight->itemsPlayer.item2 , "\u2694")==0 || strcmp(knight->itemsPlayer.item3, "\u2694")==0)&&(strcmp(knight->itemsPlayer.item1, "\U0001F6E1")==0 ||strcmp(knight->itemsPlayer.item2 , "\U0001F6E1")==0 || strcmp(knight->itemsPlayer.item3, "\U0001F6E1")==0)) {
            knight->health-=15;
            knight->score+=50;
            board[knight->posPlayer.pos_x-1][knight->posPlayer.pos_y]='.';
        } 
        else if(strcmp(knight->itemsPlayer.item1, "\U0001F6E1")==0 ||strcmp(knight->itemsPlayer.item2 , "\U0001F6E1")==0 || strcmp(knight->itemsPlayer.item3, "\U0001F6E1")==0){
            knight->health-=15;
        }
        else{
                
              knight->health-=50;
        
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
