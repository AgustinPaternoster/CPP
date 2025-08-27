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
    while(i < m1->columns)
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

int ftisprint(char c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

int fillChar(char *str , int count, map *m1)
{
    int charNb = 0;
    int i = count;
    while(str[i] != '\n')
    {
        if (str[i] == 32)
        {
            i++;
            continue;
        }
        if(!ftisprint(str[i]))
            return (0);
        m1->characters[charNb++] = str[i++];
    }
    return(1);
}

void clean(map* m1)
{
    for(int i = 0 ; i < m1->row; i++)
        free(m1->map[i]);
    free(m1->map);
    fclose(m1->file);
}

int checkErrors(map *m1)
{

}