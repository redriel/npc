#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include "npcutils.h"
#include "npcgenerator.h"
#include "npcpaths.h"

#define BUFF_SIZE 256

int randomizer(int max_value) {
    srand(time(NULL)^(getpid()<<16)) ;
    int r = rand() % max_value;
    return r;
}

int file_length(char * file_path) {
    int lines = 0, ch = 0;
    FILE *fp = fopen(file_path, "r");
    if (!fp) {
        fprintf(stderr, "%s: line %d. Error #%d opening file %s: %s.\n", 
        __FILE__, __LINE__, errno, file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    while(!feof(fp)) {
        ch = fgetc(fp);
        if(ch == '\n') {
            lines++;
        }
    }
    fclose(fp);
    return lines;
}

struct npc generateNPC(char * arguments[]) {
    struct npc npc;
    strcpy(npc.name, pickLine(NAMES_PATH));
    strcpy(npc.surname, pickLine(SURNAMES_PATH));
    strcpy(npc.race, pickLine(RACES_PATH));
    strcpy(npc.abilities, pickLine(ABILITIES_PATH));
    strcpy(npc.appearance, pickLine(APPEARANCES_PATH));
    strcpy(npc.talents, pickLine(TALENTS_PATH));
    strcpy(npc.behaviour, pickLine(BEHAVIOURS_PATH));
    // gnpc.gender = pickGender();
    return npc;
}

void message_init() {
    printf("\n");
    printf("#############################################\n");
    printf("##          NPC RANDOM GENERATOR           ##\n");
    printf("#############################################\n");
    printf("\n");
    printf("         />_________________________________\n");
    printf("[########[]_________________________________>\n");
    printf("         \\>\n");
    printf("\n");
    printf("Welcome to NPC Random Generator.\n");
    printf("If you want to generate an NPC, simply type [npc] follwed by [generate] or [g]\n");
    printf("If you want to see the options or other details, type [npc] follwed by [help] or [h].\n");
}

void message_help() {

}

void message_npc() {

}

void save_npc(char * file_path){

}