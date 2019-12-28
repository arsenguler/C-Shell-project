#ifndef _INITSHELLH_
#define _INITSHELLH_

#define clear() printf("\033[H\033[J")

void init_shell(){
clear();
printf("\n\n\n--------------- Baran & Arsen 's Shell ---------------\n\n\n");
printf("Type -help- (without -) to see available commands\n");
}

#endif