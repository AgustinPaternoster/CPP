#include <stdlib.h>
#include <stdio.h>

int minVal(int a, int b, int c)
{
    int result = a;
    if (b < a )
        result = b;
    if (c < b)
        result = c;
    return (result);
}

int main(void)
{
    
    int row = 3;
    int col = 5;
    char*map[] = {"..x..",
                  ".xx..",
                  "..x.."};
    
    int maxVal;
    int colPos;
    int rowPos;
    int **dp;
    dp = malloc(sizeof(int*) * 3);
    for(int i = 0; i < 3; i++)
        dp[i] = malloc(sizeof(int)* 3);
    //completar primera columna
    for(int i = 0; i < row; i++)
        dp[i][0] = map[i][0] == 'x' ? 0 : 1;
    // completar primera fila
    for(int i = 0; i < col; i++)
        dp[0][i] = map[0][i] == 'x' ? 0 : 1;
    //iniciar completado del map
    for(int i = 1; i < row; i++)
        for(int y = 1 ; y < col; y++)
        {
            if (map[i][y] == 'x')
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
    for(int i = 0; i < row; i++)
    {
        for(int y = 0 ; y < col; y++)
            printf("%d",dp[i][y]);
        printf("\n");
    }

    printf("max val: %d \n", maxVal);
    printf("colpos: %d\n", colPos);
    printf("rowpos: %d \n", rowPos);
}
