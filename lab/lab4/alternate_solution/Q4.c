#include<stdio.h>

int main()
{
    const m = 3, n = 3;
    int mat[m][n] = {{1,2,3}, {4,5,6}, {7,8,9}};

    printf("Upper triangular\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i <= j)
                printf("%d\t", mat[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }

    printf("Lower Trianglular\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i > j)
                printf("%d\t", mat[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }

    printf("Principal diag\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if ( i == j )
                printf("%d\t", mat[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }
    
    printf("Secondary diag\n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if ( i + j == n - 1 )
                printf("%d\t", mat[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }
    
    return 0;
}