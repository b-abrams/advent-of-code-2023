#include <stdio.h>
#include <string.h>
#include "utils.h"

typedef struct strnum
{
    const char *strrep;
    const unsigned int strval;
} strnum;

unsigned int isDigit(const char c)
{
    return (c >= 48 && c <= 57);
}

unsigned int charToDigit(const char c)
{
    return c - 48;
}

int parseLineForDigits(const char *line)
{
    const char *runner = line;
    int digit1 = -1, digit2 = -1;
    while (*runner != '\n')
    {
        if (isDigit(*runner))
        {
            if (digit1 < 0)
            {
                digit1 = charToDigit(*runner);
            }
            digit2 = charToDigit(*runner);
        }
        runner++;
    }
    return digit1 * 10 + digit2;
}

int parseLineForDigits2(const char *line)
{
    int d1 = -1, d2 = -1;
    const char *ptr = line;

    const strnum reps[] = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}};

    while (*ptr != '\0')
    {
        for (int i = 0; i < 9; i++)
        {
            if (strncmp(ptr, reps[i].strrep, strlen(reps[i].strrep)) == 0)
            {
                if (d1 < 0)
                {
                    d1 = reps[i].strval;
                }
                d2 = reps[i].strval;
            }
            else if (isDigit(*ptr))
            {
                if (d1 < 0)
                {
                    d1 = charToDigit(*ptr);
                }
                d2 = charToDigit(*ptr);
            }
        }
        ptr++;
    }

    return d1 * 10 + d2;
}