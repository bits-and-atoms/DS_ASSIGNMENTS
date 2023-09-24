#include<stdio.h>
int n = 3, m = 3;

int getIndex(int i, int j)
{
    if(i * n + j > n * m - 1) return 0;
    else return (i * n + j);
}

int rotateMatrix(int mat1[], int res[])
{
    for (int i = 0, q = 2; i < n; i++, q--)
    {
        for (int j = 0, p = 0; j < n; j++, p++)
        {
            res[getIndex(p, q)] = mat1[getIndex(i, j)];
        }
    }
}
void displayMatrix(int res[])
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                printf("%d\t", res[getIndex(i,j)]);
            }
            printf("\n");
        }
        printf("\n");
    }
int main()
{
    int mat1[] = {1,2,3,4,5,6,7,8,9};
    int res[n * m];
    rotateMatrix(mat1, res);
    displayMatrix(res);
}