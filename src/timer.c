#include "header.h"


void timer(Player *knight) {
    if (knight->npcs.timer_start == true) {
        int minutes = knight->quest_seconds / 60;
        int seconds = knight->quest_seconds % 60;

        printf("Time left: %d:%02d\n", minutes, seconds);

        knight->quest_seconds--;

        if (knight->quest_seconds < 0) {
            printf("The time is over, bye bye...");
            sleep(1);
            game_over();
        }
    }
}
