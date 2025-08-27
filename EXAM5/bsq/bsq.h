#ifndef _BSQ_H_
#define _BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int columns;
    char**map;
    char characters[3]; // 0 -empt / 1 - obst / 2 - full 
    FILE* file;
}map;

int openFile(char *path, map* m1);
void cpystr(char* line, map* m1, int col);
int minVal(int a, int b, int c);
int ftisprint(char c);
int fillChar(char *str , int count, map *m1);
void printMap(map* m1, int maxValue, int row , int colum);
void clean(map* m1);

#endif