#ifndef _SHELLREADH_
#define _SHELLREADH_

char* shell_read(){

  int bufsize = 50;
  int position = 0;
  char *buffer = malloc(bufsize*sizeof(char));
  int c;

  while (1) {
    c = getchar();
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;
}
    return NULL; 
}

#endif