#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void part1(const char *filepath);
void part2(const char *filepath);

int main(int argc, char *argv[])
{
    const char *filepath = "input.txt";
    part1(filepath);
    part2(filepath);
    return 0;
}

void part1(const char *filepath)
{
    int i = 0, sum = 0;
    char c, line[64];
    FILE *fp = fopen(filepath, "r");
    while ((c = getc(fp)) != EOF)
    {
        line[i] = c;
        i++;
        if (c == '\n')
        {
            sum += parseLineForDigits(line);
            memset(line, 0, 64);
            i = 0;
        }
    }
    line[i + 1] = '\n';
    sum += parseLineForDigits(line);
    printf("Sum: %d\n", sum);
    fclose(fp);
}

void part2(const char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    int sum = 0;
    const int buff = 64;
    char line[buff];
    while (fgets(line, buff, fp))
    {
        sum += parseLineForDigits2(line);
    }
    printf("Sum: %d\n", sum);
    fclose(fp);
}
