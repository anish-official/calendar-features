#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <stdarg.h>
char *find_day(int, int , int);
int leap_year_check(int);
int odd_day_count(int, int, int );
int day_30_array[] = {4, 6, 9, 11};
void main_menu();
int day_31_array[] = {1, 3, 5, 7, 8, 10, 12};
int main()
{
    return 0;
}
char *find_day(int day, int month, int year)
{
    /* char ret = (char *) malloc(10); */
        /* using Formulae F=k+ [(13*m-1)/5] +D+ [D/4] +[C/4]-2*C where
                                ZELLER'S RULE 
    k is  the day of the month.
    m is the month number.
    D is the last two digits of the year.
    C is the first two digits of the year. */

    int day_number, last_2_digits_year = year % 100, first_2_digits_year = year / 100;
    day_number = day + ((13*month-1)/5) + last_2_digits_year + (last_2_digits_year / 4) + (first_2_digits_year / 4) - 2 * first_2_digits_year;
    day_number %= 7;
/*     switch (day_number)
    {
    case 0:
        ret = "SUNDAY";
        break;
    case 1:
        ret = "MONDAY";
        break;
    case 2:
        ret = "TUESDAY";
        break;
    case 3:
        ret = "WEDNESDAY";
        break;
    case 4:
        ret = "THURSDAY";
        break;
    case 5:
        ret = "FRIDAY";
        break;
    case 6:
        ret = "SATURDAY";
        break;
    default:
        ret = "ERROR";
        break;
    } */
    return day_number;
}
int leap_year_check(int year)
{
    /*
    if leap year return true 
    if != leap year return false
    */
    int ret = false;
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    else
    {
        if (year % 4 == 0)
        {
            ret = true;
        }
        else
        {
            ret = false;
        }
    }
    return ret;
}