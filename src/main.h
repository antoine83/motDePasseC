#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stddef.h>

#define READ_BUFF_SIZE  42	/*!< Maximum of character */

char *affSpeed[] = {
    "B0",
    "B50",
    "B75",
    "B110",
    "B134",
    "B150",
    "B200",
    "B300",
    "B600",
    "B1200",
    "B1800",
    "B2400",
    "B4800",
    "B9600",
    "B19200",
    "B38400",
    "B57600",
    "B115200",
    "B230400"
    };

void read_password(char *buff);
void afficheSpeed(struct termios *tmpConf);

#endif // MAIN_H_INCLUDED
