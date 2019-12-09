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
#define NUMBER_OF_RACES 5

#define BUFF_SIZE_SHORT 32
#define BUFF_SIZE_LONG 256

/**
  *
  * @version: 1.0.0
  * @date: 2019/8/12
  * @author: Gabriele Lavorato
  * This program randomly generates a detailed NPC
  */



static char* pickName();

static char* pickSurname();

static char* pickOrigins();

static char* pickTalent();

static char* pickAppearance();

static char* pickAbilities();

static int randomizer(int number);


int main() {

    printf("This is a random NPC generator\n");
    
    char res[30];
    strcpy(res, pickName());
    printf("The name is: %s\n", res);

    strcpy(res, pickSurname());
    printf("The surname is: %s\n", res);

    strcpy(res, pickTalent());
    printf("The talent is: %s\n", res);

    strcpy(res, pickAbilities());
    printf("The abilities is: %s\n", res);

    strcpy(res, pickOrigins());
    printf("The origin is: %s\n", res);

    strcpy(res, pickAppearance());
    printf("The appereance is: %s\n", res);

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
            // fscanf(fp_talent, "%s", &local_talent);
            // fputs(local_talent, stdout);
            strtok(local_talent, "\n");
            strcpy(talent, local_talent);
        } 
    }

    fclose(fp_talent);
    return talent;
}

static int randomizer(int max_value) {
    srand(time(NULL)^ (getpid()<<16)) ;
    int r = rand() % max_value;
    return r;
}