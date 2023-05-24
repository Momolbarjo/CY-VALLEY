#include "header.h"
//fileExists check is a save exist. 
bool fileExists(const char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (file != NULL) {
        fclose(file);
        return true;
    }
}

void savegame(const int map[SIZE][SIZE], const Player* player, const char* playerName, const char* mapName) {
    savemap(map, mapName);  // save the map in the  mapName file
    saveplayer(player, playerName);  // save the player structure in the playerName file
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
    
     if (!fileExists(mapName) || !fileExists(playerName)) {
        printf("No save.\n");
        exit(0);
    }
    
    loadmap(map, mapName);  // loading the map using the mapname file
    loadplayer(player, playerName);  // loading the player structure using the playerName file

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

void deleteMapSaveFile(const char* fileName) {
    int status = remove(fileName);    
}

// Fonction pour supprimer le fichier de sauvegarde du joueur
void deletePlayerSaveFile(const char* fileName) {
    int status = remove(fileName);
    
}
// Function to delete the save
void deleteSaveFiles(const char* mapFileName, const char* playerFileName) {
    deleteMapSaveFile(mapFileName);
    deletePlayerSaveFile(playerFileName);
}
