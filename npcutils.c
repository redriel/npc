#include "npcutils.h"
#include <time.h>

static int randomizer(int max_value) {
    srand(time(NULL)^ (getpid()<<16)) ;
    int r = rand() % max_value;
    return r;
}