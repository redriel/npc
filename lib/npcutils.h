#ifndef NPC_UTILS
#define NPC_UTILS
#define BUFF_SIZE 256

typedef struct npc generated_npc;

typedef struct npc{
    char name[BUFF_SIZE];
    char surname[BUFF_SIZE];
    char race[BUFF_SIZE];
    char appearance[BUFF_SIZE];
    char abilities[BUFF_SIZE];
    char talents[BUFF_SIZE];
    char origins[BUFF_SIZE];
    char behaviour[BUFF_SIZE];
    char gender[BUFF_SIZE];
    char pronoun[BUFF_SIZE];
} npc;

int file_length(char * file_path);
int randomizer(int max_value);
struct npc generateNPC(char * arguments[]);
void save_npc(char * file_path);
void message_init();
void message_help();
void message_npc();
#endif