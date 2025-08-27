#include "bsq.h"


int getData(char *path, map* m1)
{
    char *line = NULL;
    size_t len;
    __ssize_t n;
    __ssize_t t;
    n = getline(&line,&len,m1->file);
    int i = 0;
    m1->row = 0;
    while(line[i] >= '0' && line[i] <= '9')
    {
        m1->row = (m1->row * 10) + (line[i] - 48);
        i++;
    }
    if (i < 1)
        return (free(line), 0);
    if (n > i + 7)
        return(free(line), 0);
    if (!fillChar(line, i , m1))
        return(free(line), 0);
    int checkSizerow = 0;
    i = 0;
    while((n = getline(&line,&len,m1->file)) != -1)
    {
        if(!checkSizerow)
        {
            m1->columns = n -1;
            m1->map = malloc(sizeof(char*) * m1->columns);
            checkSizerow = 1;
        }
        if(n - 1 != m1->columns)
        {
            for(int y = 0 ; y <i; y++)
                free(m1->map[y]);
            free(m1->map);
            return(free(line), 0);
        }
        cpystr(line,m1,i);
        i++;
    }
    free(line);
    return (1);
}

void findSquare(map *m1)
{
    int maxVal = 0;
    int colPos = 0;
    int rowPos = 0;
    int **dp = malloc(sizeof(int*) * m1->row);
    // proteger malloc
    for(int i = 0; i < m1->row; i++)
        dp[i] = malloc(sizeof(int)* m1->columns);
    for(int i = 0; i < m1->row; i++)
        dp[i][0] = m1->map[i][0] == m1->characters[1] ? 0 : 1;;
    for(int i = 0; i < m1->columns; i++)
        dp[0][i] = m1->map[0][i] == m1->characters[1] ? 0 : 1;
    for(int i = 1; i < m1->row; i++)
        for(int y = 1 ; y < m1->columns; y++)
        {
            if (m1->map[i][y] == m1->characters[1])
                dp[i][y] = 0;
            else
            {
                dp[i][y] = 1 + minVal(dp[i -1][y],dp[i][y - 1], dp[i -1][y - 1]);
                if(dp[i][y] > maxVal)
                {
                    maxVal = dp[i][y];
                    colPos = y;
                    rowPos = i;
                }
            }
        }

    printMap(m1,maxVal,rowPos,colPos);
    for (int i = 0; i < m1->row; i++)
    {
        free(dp[i]);
    }
    free(dp);
}

void printMap(map* m1, int maxValue, int row , int colum)
{
    
    for (int i = 0; i < m1->row; i++)
        for (int y = 0; y < m1->columns; y++)
        {
            if((i > (row - maxValue) && i <= row) && (y > (colum - maxValue) && y <= colum))
                m1->map[i][y] = m1->characters[2];
        }
    for (int i = 0; i < m1->row; i++)
        fprintf(stdout,"%s\n", m1->map[i]);
}


int main(int arc, char**argv)
{
    map m1;
    int arg = 1;

    // char *path = "map2.txt";

    // if (!openFile(path, &m1))
    // {
    //     printf("File error");
    //     return (1);
    // }
    // if (!getData(path, &m1))
    // {
    //     printf("error");
    //     return (1);
    // }
    // findSquare(&m1);

    if (arc < 2)
    {
        if (!openFile(argv[arg], &m1))
        {
            printf("File error\n");
        }
        return(0);
    }
    while(arg < arc)
    {
        if (!openFile(argv[arg], &m1))
        {
            printf("File error\n");
            arg++;
            if(arg < arc)
                fprintf(stdout,"\n");
            continue;
            // return (1);
        }
        if (!getData(argv[arg], &m1))
        {
            printf("error\n");
            arg++;
            if(arg < arc)
                fprintf(stdout,"\n");
            continue;
            // return (1);
        }
        findSquare(&m1);
        arg++;
        if(arg < arc)
            fprintf(stdout,"\n");
        clean(&m1);

    }
    return (0);



}