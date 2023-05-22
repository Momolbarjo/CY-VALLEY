#include "header.h"

void savegame(const int map[SIZE][SIZE], const Player* player, const char* playerName, const char* mapName) {
    savemap(map, mapName);  // Sauvegarder la map dans le fichier nomCarte
    saveplayer(player, playerName);  // Sauvegarder la structure du joueur dans le fichier nomJoueur
}

void savemap(const int map[SIZE][SIZE], const char* fileName) {
    FILE* file = fopen(fileName, "wb");
    if (file != NULL) {
        fwrite(map, sizeof(int), SIZE * SIZE, file);
        fclose(file);
    }
}

void saveplayer(const Player* player, const char* fileName){
    FILE* file = fopen(fileName, "wb");
    if (file != NULL) {
        fwrite(player, sizeof(Player), 1, file);
        fclose(file);
    }
}

void loadgame(int map[SIZE][SIZE], Player* player, const char* playerName, const char* mapName) {
    loadmap(map, mapName);  // Charger la map à partir du fichier nomCarte
    loadplayer(player, playerName);  // Charger la structure du joueur à partir du fichier nomJoueur
}


void loadmap(int map[SIZE][SIZE], const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (file != NULL) {
        fread(map, sizeof(int), SIZE * SIZE, file);
        fclose(file);
    }
}

void loadplayer(Player* player, const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (file != NULL) {
        fread(player, sizeof(Player), 1, file);
        fclose(file);
    }
}
