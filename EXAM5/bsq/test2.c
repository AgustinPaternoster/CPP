#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    
    int y = 0;
    char ** map = malloc(sizeof(char*) * 5);
    for (int i = 0; i < 5; i++)
    {
        map[i] = malloc(sizeof(char) * 11);
        int y = 0;
        while (y < 10)
        {
            map[i][y] = y + 48;
            y++;
        }
        map[i][y] = '\n';
    }
    for (int i = 0; i < 5;i++)
        printf("%s",map[i]);

    return (0);
}
