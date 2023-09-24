#include<stdio.h>
#include<stdlib.h>
const int n = 3;
void printspiral(int **mat, int i, int j, int m, int n)
{
    if (m < i) return;

    for (int x = i; x < m; x++)
    {
        printf("%d\t", mat[j][x]);
    }
    for (int x = j + 1; x < n; x++)
    {
        printf("%d\t", mat[x][m - 1]);
    }
    for (int x = m - 2; x >= i; x--)
    {
        printf("%d\t", mat[n - 1][x]);
    }
    for (int x = n - 2; x > j; x--)
    {
        printf("%d\t", mat[x][j]);
    }
    printspiral(mat, i + 1, j + 1, m - 1, n - 1);
}

int main()
{
    int** mat = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        mat[i] = (int*) malloc(n * sizeof(int));
    }
    int p = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) {mat[i][j] = p; p++;}
    }
    printspiral(mat, 0, 0, n, n);
}