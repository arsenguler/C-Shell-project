#ifndef _EXESHELLH_
#define _EXESHELLH_

#include "trivialf.c"
#include "rnmocc.c"
#include "shell_run_time.c"
#define clear() printf("\033[H\033[J")
const char * smallerElements = "./smallerElements.sh";
const char * numC = "./numC.sh";

int exe_shell(char **tokens, char** commands, int command_num){
int switchCommand = 0;

if (tokens[0] == NULL) {
// An empty command was entered.
return 1;
}

//Make switch variable equal to command number.
for(int i=0; i<command_num; i++){
if(strcmp(tokens[0], commands[i]) == 0 ){
switchCommand=1+i;
break;
}
}

switch(switchCommand){

case 1:
help();
return 1;

case 2:
Exit();
return 1;

case 3:
clear();
return 1;

case 4:
rnmocc(tokens[1]);

case 5:
shell_run_time(start_t, finish_t, tokens[1]);
return 1;

case 6:
system(smallerElements);
return 1;

case 7:
system(numC);
return 1;

default:
return 0;

}
return 0;
}

#endif