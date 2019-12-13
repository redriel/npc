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
    struct npc npc;
    int code = argv_validator(length, arguments);
    if (code > 0) {
        if (code >= 1) {
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
        } if (code == 2) {
            if(strcmp(arguments[2], "male") == 0) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else if (strcmp(arguments[2], "female") == 0) {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            }
        } if (code == 3) {
            strcpy(npc.race, arguments[2]);
        } if (code == 4) {
            strcpy(npc.race, arguments[3]);
            if(strcmp(arguments[2], "male") == 0) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else if(strcmp(arguments[2], "female") == 0) {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            }
        } if (code == 5) {
            message_help();
            exit(EXIT_SUCCESS);
        } if (code == 6) {
            char npc_file_path [BUFF_SIZE_MEDIUM] = SAVED_NPCS_PATH;
            strcat(npc_file_path, npc.name);
            strcat(npc_file_path, " ");
            strcat(npc_file_path, npc.surname);
            strcat(npc_file_path, ".txt");
            save_npc(npc, npc_file_path);
        } if (code == 7) {
            strcpy(npc.race, arguments[2]);
            char npc_file_path [BUFF_SIZE_MEDIUM] = SAVED_NPCS_PATH;
            strcat(npc_file_path, npc.name);
            strcat(npc_file_path, " ");
            strcat(npc_file_path, npc.surname);
            strcat(npc_file_path, ".txt");
            save_npc(npc, npc_file_path);
        } if (code == 8) {
            if(strcmp(arguments[2], "male") == 0) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else if(strcmp(arguments[2], "female") == 0) {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            } char npc_file_path [BUFF_SIZE_MEDIUM] = SAVED_NPCS_PATH;
            strcat(npc_file_path, npc.name);
            strcat(npc_file_path, " ");
            strcat(npc_file_path, npc.surname);
            strcat(npc_file_path, ".txt");
            save_npc(npc, npc_file_path);
        } if (code == 9) {
            strcpy(npc.race, arguments[3]);
            if(strcmp(arguments[2], "male") == 0) {
                strcpy(npc.gender, "male");
                strcpy(npc.pronoun_upper, "He");
                strcpy(npc.pronoun_lower, "he");
            } else if(strcmp(arguments[2], "female") == 0) {
                strcpy(npc.gender, "female");
                strcpy(npc.pronoun_upper, "She");
                strcpy(npc.pronoun_lower, "she");
            } char npc_file_path [BUFF_SIZE_MEDIUM] = SAVED_NPCS_PATH;
            strcat(npc_file_path, npc.name);
            strcat(npc_file_path, " ");
            strcat(npc_file_path, npc.surname);
            strcat(npc_file_path, ".txt");
            save_npc(npc, npc_file_path);
        } return npc;
    } else {
        message_error();
        exit(EXIT_FAILURE);
    }
}

int argv_validator(int length, char * arguments[]) {
    int code = 0;
    if (length == 2 && (strcmp(arguments[1], "g") == 0)) {
        return code = 1;
    } else if (length == 3 && (strcmp(arguments[2], "male") == 0) ||
        length == 3 && (strcmp(arguments[2], "female") == 0)) {
            if(strcmp(arguments[1], "g") == 0) {
            return code = 2;
            } else if (strcmp(arguments[1], "s") == 0) {
                return code = 8;
            } else return code = 0;
    } else if (length == 3 && race_validator(arguments[2]) == 1 ) {
        if (strcmp(arguments[1], "g") == 0) {
            return code = 3;
        } else if (strcmp(arguments[1], "s") == 0) {
            return code = 7;
        } else return code = 0;
    } else if (length == 4 && (strcmp(arguments[2], "male") == 0) && race_validator(arguments[3]) == 1 || 
        length == 4 && (strcmp(arguments[2], "female") == 0) && race_validator(arguments[3]) == 1) {
            if (strcmp(arguments[1], "g") == 0) {
            return code = 4;
        } else if (strcmp(arguments[1], "s") == 0) {
            return code = 9;
        } else return code = 0;
    } else if (length == 2 && (strcmp(arguments[1], "h") == 0)) {
        return code = 5; 
    } else if (length == 2 && (strcmp(arguments[1], "s") == 0)) {
        return code = 6; 
    } else {
        return code = 0;
    }
}

int race_validator(char * race) {
    int result = 0;
    char line[BUFF_SIZE_MEDIUM];
    FILE *fp = fopen(RACES_PATH, "r");
    if (!fp) {
        fprintf(stderr, "%s: line %d. Error #%d opening %s: %s.\n", 
        __FILE__, __LINE__, errno, RACES_PATH, strerror(errno));
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof line, fp) != NULL) {
        if (strcmp(strtok(line, "\n"), race) == 0) {
            result++;
        } 
    }
    fclose(fp);
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
    printf("If you want to generate an NPC, simply type [./npc] follwed by [g]\n");
    printf("If you want to see the options or other details, type [./npc] follwed [h].\n");
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
    printf("Usage:\n");
    printf(">> npc g: you will generate a complete random npc\n");
    printf(">> npc s: you will generate a complete random npc and save it as .txt file under /saved\n");
    printf("\n");
    printf("Options:\n");
    printf("You can fix some elements of your character including gender and race:\n");
    printf(">> npc g male: you will generate a complemete random male NPC\n");
    printf(">> npc s drow: you will save a complete random drow NPC\n");
    printf("\n");
    printf("NOTE: you can fix gender and race togheter, but you have to choose gender first:\n");
    printf(">> npc g male kobold\n");
    printf("\n");
    printf("If your desired race is longer than one word, you should put it quotation marks:\n");
    printf(">> npc s \"white elf\"\n");
    printf("\n");
    printf("You can fully customize races, names, talents and so on. Just edit the files in /sources.");
} 

void save_npc(npc npc, char * file_path){
    FILE * fp;
    fp = fopen (file_path, "w");
    if (!fp) {
            fprintf(stderr, "%s: line %d. Error #%d creating %s: %s.\n", 
            __FILE__, __LINE__, errno, file_path, strerror(errno));
            exit(EXIT_FAILURE);
    }
    fprintf(fp, "You meet a %s %s named %s %s.\n", npc.gender, npc.race, npc.name, npc.surname);
    fprintf(fp, "%s appears %s.\n", npc.name, npc.abilities);
    fprintf(fp, "You notice %s has %s.\n", npc.pronoun_lower, npc.appearance);
    fprintf(fp, "%s tells you %s is a %s.\n", npc.pronoun_upper, npc.pronoun_lower, npc.origins);
    fprintf(fp, "Few knows that %s %s.\n", npc.name, npc.talents);
    fprintf(fp, "%s seems %s.", npc.name, npc.behaviour);
}