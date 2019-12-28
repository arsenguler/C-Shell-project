#ifndef _SHELLRUNTIMEH_
#define _SHELLRUNTIMEH_

extern time_t start_t, finish_t;

void shell_run_time(time_t start_t, time_t finish_t, char * format){
finish_t = time(NULL);
char ** formats = malloc(sizeof(char*)*3);
for(int i=0; i<3; i++)
formats[i]=malloc(sizeof(char)*10);
formats[0] = "seconds";
formats[1] = "minutes";
formats[2] = "hours";
if(strcmp(format, formats[0])==0)
printf("\nThe shell has been running for %f seconds.\n", difftime(start_t, finish_t));
if(strcmp(format, formats[1])==0)
printf("\nThe shell has been running for %f minutes.\n", difftime(start_t, finish_t)/60.0);
if(strcmp(format, formats[2])==0)
printf("\nThe shell has been running for %f hours.\n", difftime(start_t, finish_t)/3600.0);
free(formats);
}

#endif