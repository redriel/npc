#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include "npcutils.h"
#include "npcgenerator.h"

#define BUFF_SIZE_SHORT 32
#define BUFF_SIZE_LONG 256

typedef struct npc generated_npc;

typedef struct npc{
    char name[BUFF_SIZE_SHORT];
    char surname[BUFF_SIZE_SHORT];
    char race[BUFF_SIZE_SHORT];
    char appearance[BUFF_SIZE_LONG];
    char abilities[BUFF_SIZE_LONG];
    char talents[BUFF_SIZE_LONG];
    char origins[BUFF_SIZE_LONG];
    char behaviour[BUFF_SIZE_LONG];
    char gender[BUFF_SIZE_SHORT];
    char pronoun[BUFF_SIZE_SHORT];
    char vibes[BUFF_SIZE_LONG];
} npc;

int randomizer(int max_value) {
    srand(time(NULL)^(getpid()<<16)) ;
    int r = rand() % max_value;
    return r;
}

int fileLenght(char * file_address) {
    int lines = 0, ch = 0;
    FILE *fp = fopen(file_address, "r");
    if (!fp) {
        fprintf(stderr, "%s: line %d. Error #%d opening file %s: %s.\n", 
        __FILE__, __LINE__, errno, file_address, strerror(errno));
        exit(EXIT_FAILURE);
    }
    while(!feof(fp)) {
        ch = fgetc(fp);
        if(ch == '\n') {
            lines++;
        }
    }
    return lines;
}

struct npc generateNPC(char * arguments) {
    struct npc generated_npc;
    return generated_npc;
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

void save_npc(){

}