#ifndef MYREADKEY_H
#define MYREADKEY_H
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// F5     F6     UP   DOWN LEFT RIGHT
// \E[15~ \E[17~ \E[A \E[B \E[D \E[C

enum keys
{
    ENTER = 10,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    OTHER,
    MINUS,
    PLUS
};

//a f g i j k l m n o p q r s t u v w x y z { | } ~
//▒ ° ± ␋ ┘ ┐ ┌ └ ┼ ⎺ ⎻ ─ ⎼ ⎽ ├ ┤ ┴ ┬ │ ≤ ≥ π ≠ £ ·

int rk_readKey(enum keys *key);
int rk_mytermsave();
int rk_mytermrestore();
int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);
int additionals_ASKI(char *str);
#endif