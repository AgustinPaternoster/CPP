#include "bsq.h"

int openFile(char *path, map* m1)
{
    m1->file = fopen(path,"r");
    if(m1->file == NULL)
        return (0);
}

void cpystr(char* line, map* m1, int row)
{
    int i = 0;
    m1->map[row] = malloc(sizeof(char) * m1->columns + 1);
    while(line[i] != '\0')
    {
        m1->map[row][i] = line[i];
        i++;
    }
    m1->map[row][i] = '\0';
}

int minVal(int a, int b, int c)
{
    int result = a;
    if (b < result )
        result = b;
    if (c < result)
        result = c;
    return (result);
}