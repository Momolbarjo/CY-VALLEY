#include "header.h"


//function that simulate the teleportation of the player on a random place in the map//
void teleporter_interaction(int map[SIZE][SIZE], Player *player) {
  int teleporter_x = player->posPlayer.pos_x;
  int teleporter_y = player->posPlayer.pos_y + 1;

  player->dimensions++;

    // player teleportation
  player->posPlayer.pos_x = rand() % (SIZE - 4) + 2;
  player->posPlayer.pos_y = rand() % (SIZE - 4) + 2;
  
}


//Npc2 quest which consist to take 3 teleporter//
void npc2_quest(Player* knight) {
   int secret_posx=knight->posPlayer.pos_x-3;
   int secret_posy=knight->posPlayer.pos_y+5;

   setbuf(stdout, NULL);//disable the buffer in order to force display
   //step 1:
   if(knight->dimensions!=3 && knight->npcs.npc2_step1==false){
        printf("Hello... brave knight,when you will  cross 3 dimensions,come back...");
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
        printf("\u2192 + \u2192 + \u2192 + \u2192 + \u2191 + \u2191 +\u2191 ...");
        sleep(2);
        if(knight->posPlayer.pos_x==secret_posx && knight->posPlayer.pos_y==secret_posy){
            knight->npcs.npc2_step2=true;
            sleep(1);
        }

        fflush(stdout);  
   }//step2 done:
   else if (knight->npcs.npc2_step2==true){
        printf("Impressive...");
        sleep(2);
        fflush(stdout);
   }
}

//npc2 shop in which the player can be stronger//
void npc2_shop(Player* knight){

    printf("Tutu");
}



//The gift  interaction give randomly to the player +500 points of score,a game over...//
void gift_interaction(int map[SIZE][SIZE], Player *player){
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
        
        gift_interaction(board,knight);
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
      npc2_quest(knight);
    }


    return 0;
}

