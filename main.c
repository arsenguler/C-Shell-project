#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include "builtinf.h"

time_t start_t, finish_t;

int main(int argc, char **argv){

start_t = time(NULL);
//Creating Array of Commands
const int command_count = 7;
char **commands = malloc(command_count*sizeof(char*));
for(int i=0; i<command_count; i++)
commands[i] = malloc(sizeof(char)*20);
if(commands==NULL){
printf("\nAllocation failed!\n");
exit(EXIT_FAILURE);
}
commands[0] = "help";
commands[1] = "Exit";
commands[2] = "clear";
commands[3] = "rnmocc";
commands[4] = "shell_run_time";
commands[5] = "smallerElements";
commands[6] = "numC";

char **tokens = malloc (5 * sizeof(char*));
for(int i=0; i<5; i++)
tokens[i]=malloc(sizeof(char)*20);
if(tokens==NULL){
printf("\nAllocation failed!\n");
exit(EXIT_FAILURE);
}

//String readed from terminal
char *read = malloc(50*sizeof(char));
if(read==NULL){
printf("\nAllocation failed\n");
exit(EXIT_FAILURE);
}

//Initializing shell
init_shell();

//Main loop
do{
//Signature of our shell
printf("£ ");
read=shell_read();
tokens=parser(commands, read);
//Checking if arguments parsed corretly.
if(tokens != NULL){
//Executing commands if arguments are matched
exe_shell(tokens, commands, command_count);}
} while(1);
//Exit loop and the shell if command "Exit" is called
return EXIT_SUCCESS;

}
