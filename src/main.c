#include <termios.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "main.h"

#define READ_BUFF_SIZE  42

void read_password(char *buff)
{
  struct termios        old;
  struct termios        new;
  int                   nb;

  buff[0] = '\0';
  tcgetattr(STDIN_FILENO, &old);
  bcopy(&old, &new, sizeof(struct termios));
  new.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO, TCSADRAIN, &new);
  fgets(buff, READ_BUFF_SIZE, stdin);
  nb = strlen(buff) - 1;
  if (buff[nb] == '\n')
    buff[nb] = '\0';
  tcsetattr(STDIN_FILENO, TCSADRAIN, &old);
}

int main(void)
{
  char  buff[READ_BUFF_SIZE];

  read_password(buff);
  printf("Mon pass entré: %s\n", buff);
  return 0;
}
