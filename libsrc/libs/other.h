#ifndef OTHER_H
#define OTHER_H

#include "myTerminal.h"
#include "myReadKey.h"

#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#include <signal.h>
#include <sys/time.h>
#include <math.h>

int m_strcmp(char *s1, char *s2);
void printBox();
void wait(float seconds);
void pretty_print(char *str);
void print_date(int *date);
void print_select(int index);
void fix_date(int *date);

#endif