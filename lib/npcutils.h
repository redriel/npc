#ifndef NPC_UTILS
#define NPC_UTILS
#define BUFF_SIZE_SHORT 32
#define BUFF_SIZE_MEDIUM 128
#define BUFF_SIZE_LONG 256

typedef struct npc generated_npc;

typedef struct npc{
    char name[BUFF_SIZE_SHORT];
    char surname[BUFF_SIZE_SHORT];
    char race[BUFF_SIZE_MEDIUM];
    char appearance[BUFF_SIZE_LONG];
    char abilities[BUFF_SIZE_LONG];
    char talents[BUFF_SIZE_LONG];
    char origins[BUFF_SIZE_MEDIUM];
    char behaviour[BUFF_SIZE_MEDIUM];
    char gender[BUFF_SIZE_SHORT];
    char pronoun_upper[BUFF_SIZE_SHORT];
    char pronoun_lower[BUFF_SIZE_SHORT];
} npc;

int file_length(char * file_path);
int randomizer(int max_value);
struct npc generateNPC(int length, char * arguments[]);
void print_npc(npc npc);
int argv_validator(int length, char * arguments[]);
void save_npc(char * file_path);
int race_validator(char * race);
void message_init();
void message_error();
void message_help();
void message_npc();
#endif