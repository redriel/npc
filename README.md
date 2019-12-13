# NPC Random Generator

Hi! This is a quick guide about NPC Random Generator, a C program that can generate over 2 billions different NPCs. Every element of the NPCs (names, races, talents) is **fully customizable** by simply editing some txt files. 
Good reading :)


## Installing

You can install the program using the bash script I wrote, called `autocompile`, or simply run your favourite C compiler (in my case, `gcc`) with these 3 commands:
```
>> gcc -o ./lib/npcutils.o -c ./lib/npcutils.c 
>> gcc -o ./lib/npcgenerator.o -c ./lib/npcgenerator.c 
>> gcc -o npc ./npc.c ./lib/npcutils.o ./lib/npcgenerator.o 
```
## Usage

Run the command `npc` to read the program introduction. You can digit 

> `npc h`

to see all the details and info about how to use this generator.

Run `npc g` to generate a fully random.
Run `npc s` to generate an NPC and save the results in a txt file.

You can even fix some elemtens during the creation of the npc: for example, you can run 

> `npc g female kobold` 

to generate a random female kobold NPC.

## Customize the generator

You can freely edit every file inside `/sources` to create your own generator. Don't worry about the formatting, just insert at least one line for every file and one item for every row.