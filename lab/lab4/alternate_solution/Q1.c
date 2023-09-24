#include<stdio.h>

void swap(int *a, int *b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void rotate_anti(int m, int n, int mat[m][n])
{
    // reverse the order
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n / 2; j++)
        {   
            swap(&mat[i][j], &mat[i][n - j - 1]);
        }
    }

    //transpose
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {   
            int temp = mat[i][j];
            mat[j][i] = mat[i][j];
            mat[i][j] = temp;
        }
    }
}

void show(int m, int n, int mat[m][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {   
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int mat[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    printf("Initially: \n");
    show(3,3,mat);
    rotate_anti(3,3,mat);
    printf("Rotate\n");
    show(3,3,mat);
    return 0;
}