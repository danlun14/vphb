#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"

#define LAB_TIP ""
#define BUF_SIZE 24
#define PASSWORD_LAB "chyort"
#define day 8
#define month 8
#define year 2001

void blink(char *str, int x, int y, int times, float intervalshow, float intervalhide)
{
    int len = strlen(str);
    for (int _times = 0; _times < times; _times++)
    {
        mt_gotoXY(x, y);
        printf("%s", str);
        fflush(stdout);
        wait(intervalshow);
        mt_gotoXY(x, y);
        for (int i = 0; i < len; i++)
            printf(" ");
        fflush(stdout);
        wait(intervalhide);
        fflush(stdout);
    }
}

void hello_words()
{
    pretty_print("Wait please");
    wait(1);
    mt_clrscr();

    pretty_print("Sucsessifuly");
    blink("Sucsessifuly", 1, 1, 5, 0.5, 0.3);
}

int date_selector(int ans_d, int ans_m, int ans_y)
{

    int date[3] = {30, 5, 1976};
    int index = 2;
    int key_index = 0;
    char pass_quit[5] = "quit";
    enum keys key;
    printBox();
    print_date(date);
    print_select(index);

    fflush(stdout);
    while (1)
    {

        rk_readKey(&key);
        fflush(stdout);
        if (key == RIGHT)
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
            if ((ans_d == date[0]) && (ans_m == date[1]) && (ans_y == date[2]))
            {
                break;
            }
        }
        if (key == pass_quit[key_index])
        {
            key_index++;
            if (pass_quit[key_index] == 0)
            {
                return 1;
            }
        }
        else
        {
            key_index = 0;
        }
        fix_date(date);
        print_date(date);
        printBox();

        print_select(index);
        mt_gotoXY(10, 2);
        fflush(stdout);
    }
    return 0;
}

void signalhandler()
{
    //wait(1);
    mt_gotoXY(3, 35);
    printf("TIP: %s", LAB_TIP);
    fflush(stdout);
}

#define COL 11
#define ROW 11

int print_field(int *field, int rows, int cols)
{
    mt_gotoXY(1, 1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (field[j + i * rows] == 0)
            {
                printf("   ");
            }
            else
            {
                additionals_ASKI("aaa");
            }
        }
        printf("\n");
        for (int j = 0; j < cols; j++)
        {
            if (field[j + i * rows] == 0)
            {
                printf("   ");
            }
            else
            {
                additionals_ASKI("aaa");
            }
        }
        printf("\n");
        fflush(stdout);
    }
}

void markPlayer(int index)
{
    int cols = index % COL;
    int rows = index / COL;
    cols *= 3;
    rows *= 2;
    mt_gotoXY(rows + 1, cols + 1);
    mt_setbgcolor(blue);
    printf("   ");
    mt_clearcolor();
    mt_gotoXY(rows + 2, cols + 1);
    mt_setbgcolor(blue);
    printf("   ");
    mt_clearcolor();
}

void markFinish(int index)
{
    int cols = index % COL;
    int rows = index / COL;
    cols *= 3;
    rows *= 2;
    mt_gotoXY(rows + 1, cols + 1);
    mt_setbgcolor(red);
    printf("   ");
    mt_clearcolor();
    mt_gotoXY(rows + 2, cols + 1);
    mt_setbgcolor(red);
    printf("   ");
    mt_clearcolor();
}

void grade_field(int *vector)
{
    for (int i = 0; i < COL * ROW; i++)
    {
        if (vector[i] == 2)
        {
            vector[i] = 0;
        }
    }
}

int labirint()
{
    mt_clrscr();
    enum keys key;
    int _field[11][11] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1},
                          {1, 0, 1, 1, 1, 0, 1, 0, 1, 2, 1},
                          {1, 0, 1, 0, 0, 2, 1, 0, 1, 0, 1},
                          {1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
                          {1, 0, 1, 0, 0, 2, 0, 1, 1, 0, 1},
                          {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
                          {1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1},
                          {1, 0, 1, 0, 1, 1, 2, 1, 0, 0, 1},
                          {1, 0, 0, 0, 0, 0, 0, 2, 1, 0, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int *field_vector = malloc(ROW * COL * sizeof(int));
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            field_vector[j + i * COL] = _field[i][j];
        }
    }
    int pos_index = COL * ROW - ROW - ROW + 1;
    int flag_timer = 0;

    struct sigaction act;
    act.sa_handler = &signalhandler;
    act.sa_flags = SA_RESTART;

    sigemptyset(&act.sa_mask);

    sigaction(SIGALRM, &act, NULL);

    struct itimerval nval, oval;

    char pass_lab[24] = "ch00rt";
    char pass_quit[5] = "quit";
    int pass_index = 0;
    int key_index = 0;
    //signal(SIGALRM, signalhandler);

    nval.it_interval.tv_sec = 200000;
    nval.it_interval.tv_usec = 0;
    nval.it_value.tv_sec = 10;
    nval.it_value.tv_usec = 100;
    print_field(field_vector, ROW, COL);
    markPlayer(pos_index);
    markFinish(20);
    fflush(stdout);
    setitimer(ITIMER_REAL, &nval, &oval);
    while (1)
    {
        rk_readKey(&key);
        fflush(stdout);
        if (key == pass_quit[key_index])
        {
            key_index++;
            if (pass_quit[key_index] == 0)
            {
                return 1;
            }
        }
        else
        {
            key_index = 0;
        }
        if (key == PASSWORD_LAB[pass_index])
        {
            pass_index++;
            if (PASSWORD_LAB[pass_index] == 0)
            {
                grade_field(field_vector);
                pass_index = 0;
            }
        }
        else
        {
            pass_index = 0;
        }

        if (key == RIGHT)
        {
            if (pos_index % COL < COL - 1)
            {
                if (field_vector[pos_index + 1] == 0)
                {
                    pos_index++;
                }
            }
        }
        else if (key == LEFT)
        {
            if (pos_index % COL > 0)
            {
                if (field_vector[pos_index - 1] == 0)
                {
                    pos_index--;
                }
            }
        }
        else if (key == UP)
        {
            if (pos_index >= COL)
            {
                if (field_vector[pos_index - COL] == 0)
                {
                    pos_index -= COL;
                }
            }
        }
        else if (key == DOWN)
        {
            if (pos_index % ROW <= COL * ROW - ROW)
            {
                if (field_vector[pos_index + COL] == 0)
                {
                    pos_index += COL;
                }
            }
        }

        print_field(field_vector, ROW, COL);
        markFinish(20);
        markPlayer(pos_index);

        mt_gotoXY(23, 1);
        fflush(stdout);
        if (pos_index == 20)
        {
            break;
        }
    }
    return 0;
}

int main()
{
    hello_words();

    struct termios default_options;
    if (tcgetattr(STDIN_FILENO, &default_options) != 0)
    {
        return -1;
    }

    mt_clrscr();

    int status = date_selector(day, month, year);
    if (status == 1)
    {
        //return 0;
    }
    enum keys key;
    labirint();
    //mt_clrscr();
    enum colors setup_color = blue;
    enum colors currient_color = blue;

    mt_clearcolor();
    return 0;
}
