#include<stdio.h>

    int n = 3, m = 3;
    int getIndex(int i, int j)
    {
        if(i * n + j > n * m - 1) return 0;
        else return (i * n + j);
    }

    void addMatrix(int mat1[], int mat2[], int res[])
    {
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res[getIndex(i,j)] = mat1[getIndex(i,j)] + mat2[getIndex(i,j)];
            }
        }
    }

    void subtractMatrix(int mat1[], int mat2[], int res[])
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                res[getIndex(i,j)] = mat1[getIndex(i,j)] - mat2[getIndex(i,j)];
            }
        }
    }

    void multiplyMatrix(int mat1[], int mat2[], int res[])
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res[getIndex(i,j)] = 0;
                for(int k = 0; k < n; k++)
                {
                    res[getIndex(i, j)] += mat1[getIndex(i,k)] * mat2[getIndex(k,j)];
                }
            }
        }
    }

    void displayMatrix(int res[])
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
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
        int mat2[] = {1,5,3,5,2,4,8,5,3};
        int res[n * m];

        addMatrix(mat1, mat2, res);
        displayMatrix(res);
        multiplyMatrix(mat1, mat2, res);
        displayMatrix(res);
        subtractMatrix(mat1, mat2, res);
        displayMatrix(res);
    }