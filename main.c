#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"

#define PASSWORD_LAB "chunga-changa"
#define day 8
#define month 8
#define year 2001

void signalhandler()
{
}

int main()
{
    //pretty_print("helloasdasdsadasdas");
    //wait(3);
    int date[3] = {30, 5, 1976};
    int index = 2;
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
    print_date(date);
    print_select(index);

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
            if (index < 2)
            {
                index++;
            }
        }
        else if (key == LEFT)
        {
            if (index > 0)
            {
                index--;
            }
        }
        else if (key == UP)
        {
            date[index]++;
        }
        else if (key == DOWN)
        {
            date[index]--;
        }

        else if (key == ENTER)
        {
            if ((day == date[0]) && (month == date[1]) && (year == date[2]))
            {
                break;
            }
        }

        else if (key == LEFT)
        {
            nval.it_interval.tv_sec = 1;
            nval.it_value.tv_sec = 1;
            //sigaction(ITIMER_REAL, &act, NULL);
            setitimer(ITIMER_REAL, &nval, &oval);
            //rk_readKey(&key);
        }
        fix_date(date);
        print_date(date);
        printBox();

        print_select(index);
        mt_gotoXY(10, 2);
        //mt_clearcolor();
        fflush(stdout);
    }

    mt_clearcolor();
    return 0;
}
