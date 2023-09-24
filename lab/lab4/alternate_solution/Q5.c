#include<stdio.h>

int main()
{
    const m = 3, n = 3;
    int mat[m][n] = {{1,2,3}, {4,5,6}, {7,8,9}};


    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int temp = mat[i][i];
            mat[i][i] = mat[i][n - i - 1];
            mat[i][n - i - 1] = temp;
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}