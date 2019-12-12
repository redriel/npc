#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lib/npcutils.h"
#include "lib/npcgenerator.h"

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