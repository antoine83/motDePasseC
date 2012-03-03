/**
 * \file main.c
 * \brief Programme de saisie de mot de passe.
 * \author Antoine FADDI
 * \version 0.1
 * \date 03 mars 2012
 *
 * Programme de saisie de mot de passe en C..
 *
 */

#include <termios.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "main.h"


/**
* Read password
* @param buff is buffer
*/
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

  /*!< Lecture de la saisie au clavier*/
  fgets(buff, READ_BUFF_SIZE, stdin);

  nb = strlen(buff) - 1;
  if (buff[nb] == '\n')
    buff[nb] = '\0';

  tcsetattr(STDIN_FILENO, TCSADRAIN, &old);
}

/**
 * \brief Program start in.
 */
int main(void)
{
  char  buff[READ_BUFF_SIZE];

  read_password(buff);
  printf("Mon de passe entré: %s\n", buff);
  return 0;
}
