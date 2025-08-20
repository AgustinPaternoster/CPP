#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int columns;
    char**map;
    int lines;
    char emptyCh;
    char obstacleCh;
    char fullCh;

}map;


int getData(char *path, map* m1)
{
    char *line = NULL;
    size_t len;
    __ssize_t n;
    __ssize_t t;
    FILE* map = fopen(path,"r");
    if (map == NULL)
        return (0);
    n = getline(&line,&len,map);
    int i = 0;
    m1->lines = 0;
    while(line[i] > '0' && line[i] <= '9')
    {
        m1->lines = (m1->lines * 10) + (line[i] - 48);
        i++;
    }
    m1->emptyCh = line[++i];
    i++;
    m1->obstacleCh = line[++i];
    i++;
    m1->fullCh = line[++i];
    n = 0;
    while((n = getline(&line,&len,map)) != -1)
    {
        printf("%ld\n", n);
        printf("%s\n", line);
    }
    free(line);
    return (1);
    

}

int main(int arc, char**argv)
{
    map m1;

    char *path = "map.txt";

    if (!getData(path, &m1))
    {
        printf("error");
        return (1);
    }
    return (0);

    // char **mapmalloc()
    // char *lineptr = NULL;
    // size_t len = 0;
    // FILE *map = fopen("map.txt", "r");
    // if (map == NULL)
    // {    
    //     fprintf(stdout,"error\n");
    //     return (1);
    // }
    // ssize_t nread;
    // nread = getline(&lineptr,&len,map);
    // fprintf(stdout," 1_ %s", lineptr);



}