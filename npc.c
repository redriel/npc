#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
<<<<<<< HEAD
#include <unistd.h>
#include <unistd.h>
#include <time.h>

// To get the number to insert, just subtract 2 from the number of file lines
#define NUMBER_OF_NAMES 198
#define NUMBER_OF_SURNAMES 973
#define NUMBER_OF_ABILITIES 12
#define NUMBER_OF_APPEREANCES 23
#define NUMBER_OF_TALENTS 21
#define NUMBER_OF_ORIGINS 20
#define NUMBER_OF_RACES 11
#define NUMBER_OF_BEHAVIOURS 11

#define BUFF_SIZE_SHORT 32
#define BUFF_SIZE_LONG 256
=======
#include "lib/npcutils.h"
#include "lib/npcgenerator.h"
>>>>>>> develop

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
        exit(EXIT_FAILURE);
    } else {
        struct npc npc = generateNPC(argc, argv);
        print_npc(npc);
        exit(EXIT_SUCCESS);
    }
}