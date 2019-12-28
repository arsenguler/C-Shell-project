#include "parser.c"
#include "exe_shell.c"
#include "init_shell.c"
#include "rnmocc.c"
#include "shell_run_time.c"
#include "trivialf.c"
#include "shell_read.c"

int exe_shell(char **tokens, char** commands, int command_num);

void init_shell();

char** parser(char **commands, char *args);

int rnmocc(char *filename);

char* shell_read();

void shell_run_time(time_t start_t, time_t finish_t, char * format);

void help();

void Exit();
