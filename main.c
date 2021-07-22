#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"

#define PASSWORD_LAB "chunga-changa"

int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void signalhandler()
{
}

int main()
{

    struct termios default_options;
    if (tcgetattr(STDIN_FILENO, &default_options) != 0)
    {
        return -1;
    }

    struct sigaction act;
    act.sa_handler = &signalhandler;
    act.sa_flags = SA_RESTART;

    sigemptyset(&act.sa_mask);

    sigaction(SIGALRM, &act, NULL);

    struct itimerval nval, oval;

    //signal(SIGALRM, signalhandler);

    nval.it_interval.tv_sec = 0;
    nval.it_interval.tv_usec = 0;
    nval.it_value.tv_sec = 0;
    nval.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &nval, &oval);

    mt_clrscr();

    setitimer(ITIMER_REAL, &nval, &oval);
    enum keys key;

    enum colors setup_color = blue;
    enum colors currient_color = blue;

    printBox();
    fflush(stdout);
    while (1)
    {

        rk_readKey(&key);
        nval.it_interval.tv_sec = 0;
        nval.it_interval.tv_usec = 0;
        nval.it_value.tv_sec = 0;
        nval.it_value.tv_usec = 0;

        setitimer(ITIMER_REAL, &nval, &oval);
        fflush(stdout);
        if (key == 'q')
        {
            break;
        }
        else if (key == RIGHT)
        {
        }
        else if (key == LEFT)
        {
        }
        else if (key == UP)
        {
        }
        else if (key == DOWN)
        {
        }

        else if (key == ENTER)
        {
            mt_clrscr();
            fflush(stdout);
        }
        else if (key == 'l')
        {
        }
        else if (key == LEFT)
        {
            nval.it_interval.tv_sec = 1;
            nval.it_value.tv_sec = 1;
            //sigaction(ITIMER_REAL, &act, NULL);
            setitimer(ITIMER_REAL, &nval, &oval);
            //rk_readKey(&key);
        }
        else if (key == 's')
        {
        }
        else if (key == 't')
        {
        }
        else if (key == 'i')
        {
        }
        //mt_clearcolor();
    }
    mt_gotoXY(23, 0);
    mt_clearcolor();
    return 0;
}
