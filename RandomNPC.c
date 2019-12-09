#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <unistd.h>
#include <time.h>

// To get the number to insert, just subtract 2 from the number of file lines
#define NUMBER_OF_NAMES 198
#define NUMBER_OF_SURNAMES 973
#define NUMBER_OF_ABILITIES 12
#define NUMBER_OF_APPEREANCES 26
#define NUMBER_OF_TALENTS 20
#define NUMBER_OF_ORIGINS 3
#define NUMBER_OF_RACES 11

#define BUFF_SIZE_SHORT 32
#define BUFF_SIZE_LONG 256

/**
  *
  * @version: 1.0.0
  * @date: 2019/8/12
  * @author: Gabriele Lavorato
  * This program randomly generates a detailed NPC
  */

struct mynpc{
    char name[BUFF_SIZE_SHORT];
    char surname[BUFF_SIZE_SHORT];
    char race[BUFF_SIZE_SHORT];
    char appearance[BUFF_SIZE_LONG];
    char abilities[BUFF_SIZE_LONG];
    char talents[BUFF_SIZE_LONG];
    char origins[BUFF_SIZE_LONG];
    char gender[BUFF_SIZE_SHORT];
} npc;

static char* pickName();

static char* pickSurname();

static char* pickGender();

static char* pickOrigins();

static char* pickTalent();

static char* pickAppearance();

static char* pickAbilities();

static char* pickRace();

static int randomizer(int number);


int main() {

    printf("This is a random NPC generator\n");

    strcpy(npc.name, pickName());
    strcpy(npc.surname, pickSurname());
    strcpy(npc.race, pickRace());
    strcpy(npc.talents, pickTalent());
    strcpy(npc.abilities, pickAbilities());
    strcpy(npc.origins, pickOrigins());
    strcpy(npc.appearance, pickAppearance());
    strcpy(npc.gender, pickGender());

    printf("You meet a %s %s named %s %s.\n", npc.gender, npc.race, npc.name, npc.surname);
    printf("%s seems capable of %s.\n", npc.name, npc.talents);
    printf("The abilities is: %s\n", npc.abilities);
    printf("The origin is: %s\n", npc.origins);
    printf("The appereance is: %s\n", npc.appearance);

    printf("--- End of program ---\n");
    printf("(press any key to exit)");
    getchar();
    exit(EXIT_SUCCESS);
}

static char* pickName() {
    FILE *fp_names = fopen("./sources/names.txt", "r");
    char *name = malloc(BUFF_SIZE_SHORT * sizeof(char));
    char local_name[BUFF_SIZE_SHORT];
    int randomLine = randomizer(NUMBER_OF_NAMES);

    if (!fp_names) {
        fprintf(stderr, "%s: line %d. Error #%d opening file names.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char line[BUFF_SIZE_LONG]; 
    for (count = 0; (fgets(line, sizeof line, fp_names) != NULL); count++) {
        if (count == randomLine) {
            fscanf(fp_names, "%s", &local_name);
            strcpy(name, local_name);
        } 
    }

    fclose(fp_names);
    return name;
}

static char* pickSurname() {
    FILE *fp_surnames = fopen("./sources/surnames.txt", "r");
    char *surname = malloc(BUFF_SIZE_SHORT * sizeof(char));
    char local_surname[BUFF_SIZE_SHORT];
    int randomLine = randomizer(NUMBER_OF_SURNAMES);

    if (!fp_surnames) {
        fprintf(stderr, "%s: line %d. Error #%d opening file surnames.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char line[BUFF_SIZE_LONG]; 
    for (count = 0; (fgets(line, sizeof line, fp_surnames) != NULL); count++) {
        if (count == randomLine) {
            fscanf(fp_surnames, "%s", &local_surname);
            strcpy(surname, local_surname);
        } 
    }

    fclose(fp_surnames);
    return surname;
}

static char* pickAbilities() {
    FILE *fp_abilities = fopen("./sources/abilities.txt", "r");
    char *ability = malloc(BUFF_SIZE_LONG * sizeof(char));
    char local_ability[BUFF_SIZE_LONG];
    int randomLine = randomizer(NUMBER_OF_ABILITIES);

    if (!fp_abilities) {
        fprintf(stderr, "%s: line %d. Error #%d opening file abilities.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char line[BUFF_SIZE_LONG]; 
    for (count = 0; (fgets(local_ability, sizeof local_ability, fp_abilities) != NULL); count++) {
        if (count == randomLine) {
            strtok(local_ability, "\n");
            strcpy(ability, local_ability);
        } 
    }

    fclose(fp_abilities);
    return ability;
}

static char* pickOrigins() {
    FILE *fp_origins = fopen("./sources/origins.txt", "r");
    char *origin = malloc(BUFF_SIZE_LONG * sizeof(char));
    char local_origin[BUFF_SIZE_LONG];
    int randomLine = randomizer(NUMBER_OF_ORIGINS);

    if (!fp_origins) {
        fprintf(stderr, "%s: line %d. Error #%d opening file origins.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char line[BUFF_SIZE_LONG]; 
    for (count = 0; (fgets(line, sizeof line, fp_origins) != NULL); count++) {
        if (count == randomLine) {
            fscanf(fp_origins, "%s", &local_origin);
            strcpy(origin, local_origin);
        } 
    }

    fclose(fp_origins);
    return origin;
}

static char* pickAppearance() {
    FILE *fp_appearance = fopen("./sources/appearance.txt", "r");
    char *appearance = malloc(BUFF_SIZE_SHORT * sizeof(char));
    char local_appearance[BUFF_SIZE_SHORT];
    int randomLine = randomizer(NUMBER_OF_APPEREANCES);

    if (!fp_appearance) {
        fprintf(stderr, "%s: line %d. Error #%d opening file appearance.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char line[BUFF_SIZE_LONG]; 
    for (count = 0; (fgets(local_appearance, sizeof local_appearance, fp_appearance) != NULL); count++) {
        if (count == randomLine) {
            strtok(local_appearance, "\n");
            strcpy(appearance, local_appearance);
        } 
    }

    fclose(fp_appearance);
    return appearance;
}

static char* pickTalent() {
    FILE *fp_talent = fopen("./sources/talents.txt", "r");
    char *talent = malloc(BUFF_SIZE_LONG * sizeof(char));
    char local_talent[BUFF_SIZE_LONG];
    int randomLine = randomizer(NUMBER_OF_TALENTS);

    if (!fp_talent) {
        fprintf(stderr, "%s: line %d. Error #%d opening file talents.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char line[BUFF_SIZE_LONG]; 
    for (count = 0; (fgets(local_talent, sizeof local_talent, fp_talent) != NULL); count++) {
        if (count == randomLine) {
            strtok(local_talent, "\n");
            strcpy(talent, local_talent);
        } 
    }

    fclose(fp_talent);
    return talent;
}

static char* pickRace() {
    FILE *fp_race = fopen("./sources/races.txt", "r");
    char *race = malloc(BUFF_SIZE_LONG * sizeof(char));
    char local_race[BUFF_SIZE_LONG];
    int randomLine = randomizer(NUMBER_OF_TALENTS);

    if (!fp_race) {
        fprintf(stderr, "%s: line %d. Error #%d opening file races.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    int count = 0;
    char line[BUFF_SIZE_LONG]; 
    for (count = 0; (fgets(local_race, sizeof local_race, fp_race) != NULL); count++) {
        if (count == randomLine) {
            strtok(local_race, "\n");
            strcpy(race, local_race);
        } 
    }

    fclose(fp_race);
    return race;
}

static char * pickGender() {
    char *gender = malloc(BUFF_SIZE_SHORT * sizeof(char));
    int _gender = randomizer(1);
    if (_gender) {
        strcpy(gender, "male");
    } else {
        strcpy(gender, "female");
    }
    return gender;
}

static int randomizer(int max_value) {
    srand(time(NULL)^ (getpid()<<16)) ;
    int r = rand() % max_value;
    return r;
}