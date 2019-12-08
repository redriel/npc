#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <unistd.h>

/**
  *
  * @version: 1.0.0
  * @date: 2019/8/12
  * @author: Gabriele Lavorato
  * This program randomly generates a detailed NPC
  */

static char* pickName();

static void pickSurname();

static void pickOrigin();

static void pickTalent();

static void pickApparence();

static void pickAbilities();


int main()
{

    
    printf("This is a random NPC generator\n");
    
    char res[30];
    
    strcpy(res, pickName());
    
    printf("The name is: %s\n", res);

    FILE *fp_names = fopen("./sources/names.txt", "r");
    if (!fp_names) {
        fprintf(stderr, "%s: line %d. Error #%d opening file names.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }

    FILE *fp_surnames = fopen("./sources/surnames.txt", "r");
    if (!fp_surnames) {
        fprintf(stderr, "%s: line %d. Error #%d opening file surnames.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }

    FILE *fp_abilities = fopen("./sources/abilities.txt", "r");
    if (!fp_abilities) {
        fprintf(stderr, "%s: line %d. Error #%d opening file abilities.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }

    FILE *fp_talents = fopen("./sources/talents.txt", "r");
    if (!fp_talents) {
        fprintf(stderr, "%s: line %d. Error #%d opening file talents.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }

    FILE *fp_origins = fopen("./sources/origins.txt", "r");
    if (!fp_origins) {
        fprintf(stderr, "%s: line %d. Error #%d opening file origins.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }

    FILE *fp_appearance = fopen("./sources/appearance.txt", "r");
    if (!fp_appearance) {
        fprintf(stderr, "%s: line %d. Error #%d opening file appearance.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }

    fclose(fp_appearance);
    fclose(fp_origins);
    fclose(fp_surnames);
    fclose(fp_abilities);
    fclose(fp_talents);

    printf("--- End of program ---\n");
    printf("(press any key to exit)");
    getchar();
    exit(EXIT_SUCCESS);
}

static char* pickName() {
    FILE *fp_names = fopen("./sources/names.txt", "r");
    int count = 0;
    char *name = malloc(20 * sizeof(char));
    char local_name[20];
    int casual = 2;

    if (!fp_names) {
        fprintf(stderr, "%s: line %d. Error #%d opening file names.txt: %s.\n", 
        __FILE__, __LINE__, errno, strerror(errno));
        getchar();
        exit(EXIT_FAILURE);
    }
    
    char line[256]; /* or other suitable maximum line size */
    for (count = 0; (fgets(line, sizeof line, fp_names) != NULL); count++) {
        if (count == casual) {
            fscanf(fp_names, "%s", &local_name);
            strcpy(name, local_name);
        } 
    }
    
    fclose(fp_names);
    return name;
}
