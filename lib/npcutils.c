#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include "npcutils.h"
#include "npcgenerator.h"
#include "npcpaths.h"

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

struct npc generateNPC(int length, char * arguments[]) {
    int code = argv_validator(length, arguments); 
    if (code > 0) {
        if (code == 1) {
            struct npc npc;
            strcpy(npc.name, pickLine(NAMES_PATH));
            strcpy(npc.surname, pickLine(SURNAMES_PATH));
            strcpy(npc.race, arguments[3]);
            strcpy(npc.abilities, pickLine(ABILITIES_PATH));
            strcpy(npc.appearance, pickLine(APPEARANCES_PATH));
            strcpy(npc.talents, pickLine(TALENTS_PATH));
            strcpy(npc.origins, pickLine(ORIGINS_PATH));
            strcpy(npc.behaviour, pickLine(BEHAVIOURS_PATH));
            if(strcmp(arguments[2], "male") == 0) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            }
            return npc;
        } else if (code == 2) {
            struct npc npc;
            strcpy(npc.name, pickLine(NAMES_PATH));
            strcpy(npc.surname, pickLine(SURNAMES_PATH));
            strcpy(npc.race, arguments[2]);
            strcpy(npc.abilities, pickLine(ABILITIES_PATH));
            strcpy(npc.appearance, pickLine(APPEARANCES_PATH));
            strcpy(npc.talents, pickLine(TALENTS_PATH));
            strcpy(npc.origins, pickLine(ORIGINS_PATH));
            strcpy(npc.behaviour, pickLine(BEHAVIOURS_PATH));
            if(pickGender()) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            }
            return npc;
        } else if (code == 3) {
            struct npc npc;
            strcpy(npc.name, pickLine(NAMES_PATH));
            strcpy(npc.surname, pickLine(SURNAMES_PATH));
            strcpy(npc.race, pickLine(RACES_PATH));
            strcpy(npc.abilities, pickLine(ABILITIES_PATH));
            strcpy(npc.appearance, pickLine(APPEARANCES_PATH));
            strcpy(npc.talents, pickLine(TALENTS_PATH));
            strcpy(npc.origins, pickLine(ORIGINS_PATH));
            strcpy(npc.behaviour, pickLine(BEHAVIOURS_PATH));
            if(strcmp(arguments[2], "male") == 0) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            }
            return npc;
        } else if (code == 4) {
           struct npc npc;
            strcpy(npc.name, pickLine(NAMES_PATH));
            strcpy(npc.surname, pickLine(SURNAMES_PATH));
            strcpy(npc.race, pickLine(RACES_PATH));
            strcpy(npc.abilities, pickLine(ABILITIES_PATH));
            strcpy(npc.appearance, pickLine(APPEARANCES_PATH));
            strcpy(npc.talents, pickLine(TALENTS_PATH));
            strcpy(npc.origins, pickLine(ORIGINS_PATH));
            strcpy(npc.behaviour, pickLine(BEHAVIOURS_PATH));
            if(pickGender()) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            }
            return npc; 
        } else {
            message_error();
            exit(EXIT_FAILURE);
        }
    } else {
        message_error();
        exit(EXIT_FAILURE);
    }
}

int argv_validator(int length, char * arguments[]) {
    int code = 0;
    printf("here4\n");
    if (strcmp(arguments[1], "g") == 0 && 
    strcmp(arguments[2], "male") == 0 || //@TODO: modify the logic expression!
    strcmp(arguments[2], "female") == 0 &&
    race_validator(arguments[3])) {
        code = 1;
        printf("here5\n");
    } else if (strcmp(arguments[1], "g") == 0 && 
    race_validator(arguments[2])) {
        code = 2;
    } else if (strcmp(arguments[1], "g") == 0 && 
    strcmp(arguments[2], "male") == 0 || 
    strcmp(arguments[2], "female")) {
        code = 3;
    } else if (strcmp(arguments[1], "g")) {
        code = 4;
    }
    printf("code is :%d\n", code);
    return code;
}

int race_validator(char * race) {
    printf("here1\n");
    int result = 0;
    char * line = NULL;
    FILE *fp = fopen(RACES_PATH, "r");
    if (!fp) {
        fprintf(stderr, "%s: line %d. Error #%d opening %s: %s.\n", 
        __FILE__, __LINE__, errno, RACES_PATH, strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("here2\n");
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("here2.5\n");
        if (strcmp(line, "race") == 0) {
            printf("here2.7\n");
            result++;
        } 
    }
    /*
    for (int i = 0; (fgets(line, sizeof line, fp) != NULL); i++) {
        if (strcmp(line, race) == 0) {
            result++;
        } 
    }*/
    fclose(fp);
    printf("here3\n");
    return result;
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

void print_npc(npc npc) {
    printf("You meet a %s %s named %s %s.\n", npc.gender, npc.race, npc.name, npc.surname);
    printf("%s appears %s.\n", npc.name, npc.abilities);
    printf("You notice %s has %s.\n", npc.pronoun_lower, npc.appearance);
    printf("%s tells you %s is a %s.\n", npc.pronoun_upper, npc.pronoun_lower, npc.origins);
    printf("Few knows that %s %s.\n", npc.name, npc.talents);
    printf("%s seems %s.\n", npc.name, npc.behaviour);
}

void message_error() {
    printf("ERROR: invalid argument.");
}

void message_help() {
    // to define
}

void message_npc() {
    // to define
}

void save_npc(char * file_path){
    // to define
}