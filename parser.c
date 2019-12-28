#ifndef _PARSERH_
#define _PARSERH_

char** parser(char **commands, char *args){

int tok_size = 10, position = 0;
//tokens to be returned.
char ** tokens = malloc(tok_size * sizeof(char*));
for (int i =0 ; i < tok_size; ++i)
    tokens[i] = malloc(20 * sizeof(char));
char *token = malloc(20*sizeof(char));
if (!tokens) {
    printf("\nallocation error occured during input reading\n");
    return NULL;
  }

if(args == NULL) {
    printf("\nNo arguments provided!\n");
    return NULL;
}

token = strtok(args, " \t\r\n\a");
while (token != NULL) {
if(position>10){
printf("\nToo many arguments! Usage of up to 10 arguments is supported.\n");
return NULL;
}
tokens[position] = token;
position++;
token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;

int flag=0;

//checking first argument to match any of the functions.
for(int i=0; i<7; i++)
if(strcmp(tokens[0], commands[i])==0)
flag=1;
if(!flag){
printf("\nCommand %s can't be found\n", tokens[0]);
return NULL;
}

/*check if first argument matches any of the following functions: exit, help, clear and
it is the only argument provided. */
if(strcmp(tokens[0], commands[0])==0 || strcmp(tokens[0], commands[1])==0 || strcmp(tokens[0], commands[2])==0)
if(position>1){
flag=0;
printf("\nCommand %s requires no arguments\n", tokens[0]);
return NULL;
}

//check if expected arguments for command rnmocc are provided.
if(flag)
if(strcmp(tokens[0], commands[3])==0)
if(position>2){ flag=0; printf("\nCommand -rnmocc- requires only a single file name as argument\n");	return NULL; }


//check if expected arguments for shell_run_time are provided.
if(flag)
if(strcmp(tokens[0], commands[4])==0){
if(strcmp(tokens[1],"seconds")==0 || strcmp(tokens[1],"minutes")==0 || strcmp(tokens[1],"hours")==0){ flag=1; }
else{ flag=0; printf("\nAcceptable arguments for command -shell_run_time- are -seconds-, -minutes-, -hours-.\n"); return NULL; }
}

//check if expectec arguments for smallerElements are provided. 
if(flag)
if(strcmp(tokens[0], commands[5])==0)
if(position>1){ flag=0; printf("\nNo arguments allowed for this command!\n"); return NULL; }


//check if expectef arguments for numC are provided.
if(flag)
if(strcmp(tokens[0], commands[6])==0)
if(position!=2){ flag=0; printf("\nOne argument allowed for this command!\n"); return NULL; }


//return tokens if given arguments are acceptable.
if(flag) return tokens;

//Compiler issues
return NULL;
}

#endif
