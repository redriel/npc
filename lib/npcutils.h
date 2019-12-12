#ifndef NPC_UTILS
#define NPC_UTILS
int fileLenght(char * file_address);
int randomizer(int max_value);
struct npc generateNPC(char * arguments);
void message_init();
void message_help();
void message_npc();
void save_npc();
#endif