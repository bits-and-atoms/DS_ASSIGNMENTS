#include<stdio.h>

void swap(int *a , int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

}
void transpose(int n, int a[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // a[i][j]  = a[i][j] ^ a[j][i];
            // a[j][i]  = a[i][j] ^ a[j][i];
            // a[i][j]  = a[i][j] ^ a[j][i];
            swap(&a[i][j], &a[j][i]);
        }
    }
}

void exchange(int n, int a[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n / 2; j++)
        {
            if(i != j)
            {
                // a[i][j]  = a[i][j] ^ a[i][n - j - 1];
                // a[i][n - j - 1]  = a[i][j] ^ a[i][n - j - 1];
                // a[i][j]  = a[i][j] ^ a[i][n - j - 1];
                swap(&a[i][j], &a[i][n - j - 1]);
            }
        }
    }
}

void show(int n, int a[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int a[3][3] = {{1,2,3}, {4,5,6},{7,8,9}};
    int n = 3;
    transpose(n,a);
    exchange(n,a);
    show(n,a);

    return 0;
}