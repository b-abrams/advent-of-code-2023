#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Part 1
int gameIsPossible(const char *line);
// Part 2
void setMinimumCubeValues(const char *line, int *minCubeValueStorage);
// Helper Function
int isDigit(const char c);

int main()
{
    const char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");

    char *line = NULL;
    size_t buff = 0;

    int currentGame = 1, sum = 0, cubeSum = 0;
    int minCubeValueStorage[] = {0, 0, 0};

    while ((getline(&line, &buff, fp)) != -1)
    {
        if (gameIsPossible(line))
        {
            sum += currentGame;
        }
        setMinimumCubeValues(line, minCubeValueStorage);
        cubeSum += minCubeValueStorage[0] * minCubeValueStorage[1] * minCubeValueStorage[2];
        memset(minCubeValueStorage, 0, sizeof(int) * 3);
        currentGame++;
    }

    printf("Sum of Possible Games: %d\n", sum);
    printf("Cube Sum of Games: %d\n", cubeSum);
    return 0;
}

int gameIsPossible(const char *line)
{
    char *ptr = strstr(line, ":");
    int maxValues[] = {12, 13, 14};
    int currentValues[] = {0, 0, 0};

    int currentNum = 0, onColor = 0;
    while (*ptr != '\0')
    {
        if (*ptr == ';' || *(ptr + 1) == '\0')
        {
            for (int i = 0; i < 3; i++)
            {
                if (currentValues[i] > maxValues[i])
                {
                    return 0;
                }
            }
            memset(currentValues, 0, sizeof(int) * 3);
        }
        else if (isDigit(*ptr))
        {
            if (currentNum)
                currentNum *= 10;
            currentNum += *ptr - 48;
        }
        else if (!onColor && *ptr == 'r')
        {
            currentValues[0] = currentNum;
            currentNum = 0;
            onColor = 1;
        }
        else if (!onColor && *ptr == 'g')
        {
            currentValues[1] = currentNum;
            currentNum = 0;
            onColor = 1;
        }
        else if (!onColor && *ptr == 'b')
        {
            currentValues[2] = currentNum;
            currentNum = 0;
            onColor = 1;
        }
        else if (*ptr == ' ')
        {
            onColor = 0;
        }
        ptr++;
    }
    return 1;
}

void setMinimumCubeValues(const char *line, int *minCubeValueStorage)
{
    char *ptr = strstr(line, ":");
    int currentValues[] = {0, 0, 0};

    int currentNum = 0, onColor = 0;
    while (*ptr != '\0')
    {
        if (*ptr == ';' || *(ptr + 1) == '\0')
        {
            for (int i = 0; i < 3; i++)
            {
                if (currentValues[i] > minCubeValueStorage[i])
                {
                    minCubeValueStorage[i] = currentValues[i];
                }
            }
            memset(currentValues, 0, sizeof(int) * 3);
        }
        else if (isDigit(*ptr))
        {
            if (currentNum)
                currentNum *= 10;
            currentNum += *ptr - 48;
        }
        else if (!onColor && *ptr == 'r')
        {
            currentValues[0] = currentNum;
            currentNum = 0;
            onColor = 1;
        }
        else if (!onColor && *ptr == 'g')
        {
            currentValues[1] = currentNum;
            currentNum = 0;
            onColor = 1;
        }
        else if (!onColor && *ptr == 'b')
        {
            currentValues[2] = currentNum;
            currentNum = 0;
            onColor = 1;
        }
        else if (*ptr == ' ')
        {
            onColor = 0;
        }
        ptr++;
    }
}

int isDigit(const char c)
{
    return c >= 48 && c <= 57;
}