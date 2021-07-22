#include "libs/other.h"

void printBox()
{
    mt_clearcolor();

    mt_gotoXY(2, 2);
    additionals_ASKI("lqqqqwqqqqwqqqqqqk");

    mt_gotoXY(3, 2);
    additionals_ASKI("x");
    mt_gotoXY(3, 7);
    additionals_ASKI("x");
    mt_gotoXY(3, 12);
    additionals_ASKI("x");
    mt_gotoXY(3, 19);
    additionals_ASKI("x");

    mt_gotoXY(4, 2);
    additionals_ASKI("x");
    mt_gotoXY(4, 7);
    additionals_ASKI("x");
    mt_gotoXY(4, 12);
    additionals_ASKI("x");
    mt_gotoXY(4, 19);
    additionals_ASKI("x");

    mt_gotoXY(5, 2);
    additionals_ASKI("tq");
    mt_gotoXY(5, 6);
    additionals_ASKI("qnq");
    mt_gotoXY(5, 11);
    additionals_ASKI("qnq");
    mt_gotoXY(5, 18);
    additionals_ASKI("qu");

    mt_gotoXY(6, 2);
    additionals_ASKI("x");
    mt_gotoXY(6, 7);
    additionals_ASKI("x");
    mt_gotoXY(6, 12);
    additionals_ASKI("x");
    mt_gotoXY(6, 19);
    additionals_ASKI("x");

    mt_gotoXY(7, 2);
    additionals_ASKI("x");
    mt_gotoXY(7, 7);
    additionals_ASKI("x");
    mt_gotoXY(7, 12);
    additionals_ASKI("x");
    mt_gotoXY(7, 19);
    additionals_ASKI("x");

    mt_gotoXY(8, 2);
    additionals_ASKI("mqqqqvqqqqvqqqqqqj");
}

void wait(float seconds)
{
    clock_t endwait;

    endwait = clock() + seconds * CLOCKS_PER_SEC;

    while (clock() < endwait)
    {
    }
    return;
}

void pretty_print(char *str)
{
    while (*str != '\0')
    {
        printf("%c", *str);
        str++;
        wait(0.03);
        fflush(stdout);
    }
}

int m_strcmp(char *s1, char *s2)
{
    int check = 0;
    for (int i = 0; isalpha(s1[i]) && isalpha(s2[i]); i++)
    {
        if (s1[i] == s2[i])
        {
            check++;
        }
        else
        {
            check = 0;
            break;
        }
    }

    return check;
}

void print_date(int *date)
{
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //day
    int spec_year = date[2] % 4 == 0 ? 1 : 0;
    if (spec_year == 1)
    {
        days_in_month[1] = 29;
    }
    mt_gotoXY(5, 4);
    printf("%2d", date[0]);
    mt_gotoXY(4, 4);
    if (date[0] > 1)
    {

        printf("%2d", date[0] - 1);
    }
    else
    {
        printf("  ");
    }
    mt_gotoXY(6, 4);
    if (date[0] < days_in_month[date[1] - 1])
    {

        printf("%2d", date[0] + 1);
    }
    else
    {
        printf("  ");
    }
    //month
    mt_gotoXY(5, 9);
    printf("%2d", date[1]);
    mt_gotoXY(4, 9);
    if (date[1] > 1)
    {
        printf("%2d", date[1] - 1);
    }
    else
    {
        printf("  ");
    }
    mt_gotoXY(6, 9);
    if (date[1] < 12)
    {
        printf("%2d", date[1] + 1);
    }
    else
    {
        printf("  ");
    }
    //year
    mt_gotoXY(5, 14);
    printf("%4d", date[2]);
    mt_gotoXY(4, 14);
    if (date[1] > -999)
    {
        printf("%4d", date[2] - 1);
    }
    else
    {
        printf("  ");
    }
    mt_gotoXY(6, 14);
    if (date[1] < 9999)
    {
        printf("%4d", date[2] + 1);
    }
    else
    {
        printf("  ");
    }
}

void print_select(int index)
{
    mt_gotoXY(3, 3);
    printf("    ");
    mt_gotoXY(7, 3);
    printf("    ");
    mt_gotoXY(3, 8);
    printf("    ");
    mt_gotoXY(7, 8);
    printf("    ");
    mt_gotoXY(3, 13);
    printf("      ");
    mt_gotoXY(7, 13);
    printf("      ");
    if (index == 0)
    {
        mt_gotoXY(3, 3);
        additionals_ASKI("j  m");
        mt_gotoXY(7, 3);
        additionals_ASKI("k  l");
    }
    else if (index == 1)
    {
        mt_gotoXY(3, 8);
        additionals_ASKI("j  m");
        mt_gotoXY(7, 8);
        additionals_ASKI("k  l");
    }
    else if (index == 2)
    {
        mt_gotoXY(3, 13);
        additionals_ASKI("j    m");
        mt_gotoXY(7, 13);
        additionals_ASKI("k    l");
    }
    fflush(stdout);
}

void fix_date(int *date)
{
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int spec_year = date[2] % 4 == 0 ? 1 : 0;

    if (date[1] < 1)
    {
        date[1] = 1;
    }
    else if (date[1] > 12)
    {
        date[1] = 12;
    }

    if (spec_year == 1)
    {
        days_in_month[1] = 29;
    }
    if (date[0] < 1)
    {
        date[0] = 1;
    }
    else if (date[0] > days_in_month[date[1] - 1])
    {
        date[0] = days_in_month[date[1] - 1];
    }

    if (date[2] < -999)
    {
        date[2] = -999;
    }
    else if (date[2] > 9999)
    {
        date[2] = 9999;
    }
}