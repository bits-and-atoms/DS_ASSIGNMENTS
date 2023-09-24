#include<stdio.h>

int main()
{
    const m = 3, n = 3;
    double mat[m][n] = {{1,2,3}, {4,5,6}, {7,8,9}};
    double rows[3] = {0};
    double colmns[3] = {0};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            rows[i] += mat[i][j];
            colmns[i] += mat[j][i];
        }
    }
    for(int i = 0; i < m; i ++)
        printf("%lf\t", rows[i]);
    printf("\n");
    for(int j = 0; j < n; j++)
        printf("%lf\t", colmns[j]);
    return 0;
}