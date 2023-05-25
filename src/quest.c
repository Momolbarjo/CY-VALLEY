#include "header.h"

//Npc2 quest which consist to take 3 teleporter//
void npc2_quest(int map[SIZE][SIZE], Player* knight) {
   int secret_posx=knight->posPlayer.pos_x-3;
   int secret_posy=knight->posPlayer.pos_y+5;

   setbuf(stdout, NULL);//disable the buffer in order to force display
   //step 1:
   if(knight->dimensions<3 && knight->npcs.npc2_step1==false){
        printf("Hello... brave knight,when you will  cross at least 3 dimensions,come back...");
        knight->npcs.timer_start=true;
        sleep(2);
        fflush(stdout);
   }//step1 done:
   else if (knight->npcs.npc2_step1==false && knight->dimensions>=3){
        printf("Well played...");
        knight->npcs.npc2_step1=true;
        knight->npcs.timer_start=true;
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
       const char* text = "  _______     __     _____ _                 \n"
                        " / ____\\ \\   / /    / ____| |                \n"
                       "| |     \\ \\_/ /____| (___ | |__   ___  _ __  \n"
                       "| |      \\   /______\\___ \\| '_ \\ / _ \\| '_ \\ \n"
                       "| |____   | |       ____) | | | | (_) | |_) |\n"
                       " \\_____|  |_|      |_____/|_| |_|\\___/| .__/ \n"
                       "                                      | |    \n"
                       "                                      |_|    \n";



    while (shop) {
        ClearScreen();
         printf("%s", text);
        printf("a. buy items\n");
        printf("b. leave the shop\n");
        

        char choice=getch();
        ClearScreen();

        switch (choice) {
        
            case 'a':
                printf("what do you want to buy?\n");
                printf("a. potion of 20  health points (cost : 5\U0001F33F )\n");
                printf("b. +200 score points (cost : 5\U0001F33F  + 3\U0001FAB5)\n");
                printf("c. END_GAME (cost : 2500 points )\n");
                


                char buyItem=getch();
                ClearScreen();

                switch (buyItem) {
                    case 'a':
                        if (knight->itemsPlayer.herbs >= 5) {
                            knight->itemsPlayer.herbs -= 5;
                            knight->health+=20;
                            printf("You've got + 20 health points ! \n");
                        } else {
                            printf("You dont have enough \U0001F33F ...\n");
                        }
                        break;

                    case 'b':
                        if (knight->itemsPlayer.herbs >= 5 && knight->itemsPlayer.woods >= 3 ) {
                            knight->itemsPlayer.herbs -= 5;
                            knight->itemsPlayer.woods -= 3;
                            knight->score+=200;
                            printf("You've got + 200  score points! \n");
                        } else {
                            printf("You dont have enough resources...\n");
                        }
                        break;

                    case 'c':
                        if (knight->score >= 2500) {
                            knight->score-= 2500;
                            printf("Well played, you win thanks to you score points!\n");
                            void display_end_screen();
                        } else {
                            printf("You dont have enough score points ...\n");
                        }
                        break;

                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;

            case 'b':
                shop = 0;
                printf("You are leaving the shop...\n");
                break;

            	default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void npc1_quest(int map[SIZE][SIZE], Player* knight) {

    const char* npc1_quest_text = "    _______     __        _                 _                  \n"
                              "  / ____\\ \\   / /       | |               | |                 \n"
                              " | |     \\ \\_/ /_____ __| |_   _____ _ __ | |_ _   _ _ __ ___ \n"
                              " | |      \\   /______/ _` \\ \\ / / _ \\ '_ \\| __| | | | '__/ _ \\\n"
                              " | |____   | |      | (_| |\\ V /  __/ | | | |_| |_| | | |  __/\n"
                              "  \\_____|  |_|       \\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___|\n";
    
    if (knight->npcs.npc2_step2 == true) {
        ClearScreen();
        printf("%s\n",npc1_quest_text);
        printf("Who are you?\n");
        printf("a. A knight who is going to save us.\n");
        printf("b. You, who are you?\n");
        char choice = getch();
        
        switch (choice) {
            case 'a':
                printf("Haha, so funny... Poor little guy, you were looking for the threat, but it is in front of you right now...\n");
                printf("Now, what are you going to do?\n");
                printf("1. Fight back\n");
                printf("2. Run away\n");
                choice = getch();

                switch (choice) {
                    case '1':
                        printf("You decided to fight back...\n");
                        printf("The enemy attacks you!\n");
                        sleep(1);
                        printf("Choose your action:\n");
                        printf("1. Attack\n");
                        printf("2. Defend\n");
                        choice = getch();

                        switch (choice) {
                            case '1':
                            if (strcmp(knight->itemsPlayer.item1, "\u2694") == 0 || strcmp(knight->itemsPlayer.item2, "\u2694") == 0 || strcmp(knight->itemsPlayer.item3, "\u2694") == 0){
                                printf("You attack the enemy with your sword!\n");
                                sleep(1);
                                printf("You defeated the enemy and saved the village!\n");
                                sleep(1);
                                display_end_screen();
                            }
                            else{
                                printf("You don't have the sword...The ennemy killed you...");
                                sleep(1);
                                game_over();
                            }
                                break;

                            case '2':
                                printf("You defend yourself against the enemy's attack!\n");
                                sleep(1);
                                printf("The enemy overpowers you and defeats you...\n");
                                sleep(1);
                                game_over();

                                break;

                            default:
                                printf("Invalid choice.\n");
                                break;
                        }
                        break;

                    case '2':
                        printf("You chose to run away...\n");
                        printf("As you turn around, you trip and fall...\n");
                        sleep(1);
                        printf("The enemy catches up to you and attacks...\n");
                        sleep(1);
                        printf("You were unable to escape and the enemy defeats you...\n");
                        sleep(1);
                        game_over();
                        break;

                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;

            case 'b':
                printf("Come back when you feel ready...\n");
                sleep(1);
                break;

            default:
                printf("I don't understand what you are trying to say...\n");
                sleep(1);
                break;
        }
    }
    else {
        printf("Too early...\n");
        sleep(1);
    }
}
