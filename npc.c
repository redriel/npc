#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include "lib/npcutils.h"
#include "lib/npcgenerator.h"

#define BUFF_SIZE 256

/**
  *
  * @version: 1.0.0
  * @date: 2019/8/12
  * @author: Gabriele Lavorato
  * This program randomly generates a detailed NPC
  */

int main(int argc, char *argv[]) {
    if(argc < 2) {
        message_init();
        exit(EXIT_SUCCESS);
    } else {
        //int c = fileLenght("./sources/surnames.txt");
        //printf("Number of lines of surname.txt: %d.\n", c);
        struct npc npc = generateNPC(argv);
        printf("You meet a %s named %s %s.\n", npc.race, npc.name, npc.surname);
        printf("%s appears %s.\n", npc.name, npc.abilities);
        // printf("You notice %s has %s.\n", lownoun, npc.appearance);
        // printf("%s tells you %s is a %s.\n", npc.pronoun, lownoun, npc.origins);
        // printf("Few knows that %s %s.\n", npc.name, npc.talents);
        printf("%s seems %s.\n", npc.name, npc.behaviour);
    }

    /*
    char command[BUFF_SIZE_SHORT];
    if (argc > 1){
        strcpy(command, argv[1]);
    }
    if (strcmp(command, "g") == 0 || strcmp(command, "generate") == 0) { 
    strcpy(npc.name, pickName());
    strcpy(npc.surname, pickSurname());
    strcpy(npc.race, pickRace());
    strcpy(npc.talents, pickTalent());
    strcpy(npc.abilities, pickAbilities());
    strcpy(npc.origins, pickOrigins());
    strcpy(npc.appearance, pickAppearance());
    strcpy(npc.behaviour, pickBehaviour());

    char lownoun[BUFF_SIZE_SHORT];
    if (pickGender()) {
        strcpy(npc.gender, "male");
        strcpy(npc.pronoun, "He");
        strcpy(lownoun, "he");
    } else {
        strcpy(npc.gender, "female");
        strcpy(npc.pronoun, "She");
        strcpy(lownoun, "she");
    }
            
    printf("You meet a %s %s named %s %s.\n", npc.gender, npc.race, npc.name, npc.surname);
    printf("%s appears %s.\n", npc.name, npc.abilities);
    printf("You notice %s has %s.\n", lownoun, npc.appearance);
    printf("%s tells you %s is a %s.\n", npc.pronoun, lownoun, npc.origins);
    printf("Few knows that %s %s.\n", npc.name, npc.talents);
    printf("%s seems %s.\n", npc.name, npc.behaviour);
    }
    */
    exit(EXIT_SUCCESS);
}