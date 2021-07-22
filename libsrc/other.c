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
