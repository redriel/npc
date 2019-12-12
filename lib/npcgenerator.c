#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <unistd.h>
#include <time.h>
#include "npcutils.h"

#define BUFF_SIZE 256

char * pickLine(char * file_path) {
    char *chosen_line = malloc (sizeof (char) * BUFF_SIZE);
    char line[BUFF_SIZE];
    int randomLine = randomizer(file_length(file_path));
    FILE *fp_names = fopen(file_path, "r");

    if (!fp_names) {
        fprintf(stderr, "%s: line %d. Error #%d opening %s: %s.\n", 
        __FILE__, __LINE__, errno, file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; (fgets(line, sizeof line, fp_names) != NULL); i++) {
        if (i == randomLine) {
            fscanf(fp_names, "%s", &line);
            strcpy(chosen_line, line);
        } 
    }

    fclose(fp_names);
    return chosen_line;
}

int pickGender() {
    int gender = randomizer(2);
    return gender;
}