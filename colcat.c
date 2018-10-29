/* colcat - lp1.eu */

#ifndef __COLCAT_HEADERS__
#define __COLCAT_HEADERS__

#define BUFFER_SIZE 8192
#define STDIN 0
#define STDOUT 1

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#endif /* __COLCAT__HEADERS__ */
char COLORS[][6] = {
                   "\e[31m",
                   "\e[32m",
                   "\e[33m",
                   "\e[34m",
                   "\e[35m",
                   "\e[36m",
                   "\e[37m",
                   "\e[38m",
                   "\e[39m",
                   "\e[40m"
};


void        print_line(char *buffer) {
  int lines = 0;
  char last_char = 0;

  for (int i = 0; i < strlen(buffer); i++) {
    if (i == 0 || (buffer[i] ==  ' ' && last_char != ' ')) {
      char *color;
      if (lines < 10) { 
        color = COLORS[lines];
      } else {
        color = COLORS[lines - 8];
      }
      write(STDOUT, color, strlen(color));
      lines++;
    }
    last_char = buffer[i];
    write(STDOUT, &buffer[i], 1);
  }
}

void        read_file(FILE* fh, char *filename) {
  int     chars = 0; 
  char    buffer[BUFFER_SIZE];
    
  if(fh < 0) {
    printf("Cannot open %s", filename);
    exit(1);
  }
  while (fgets(buffer, BUFFER_SIZE, fh)) {
    print_line(buffer);
  }
}

int         main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      FILE* fh = fopen(argv[i], "r");
      read_file(fh, argv[i]);
    }
  } else {
    read_file(stdin, "stdin");
  }
}
