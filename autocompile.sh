#!/bin/bash
gcc -o ./lib/npcutils.o -c ./lib/npcutils.c 
gcc -o ./lib/npcgenerator.o -c ./lib/npcgenerator.c 
gcc -o npc ./npc.c ./lib/npcutils.o ./lib/npcgenerator.o 