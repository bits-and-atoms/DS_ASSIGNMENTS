# include<stdio.h>
int main()
{
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int res[3][3];

    for (int i = 0, q = 0; i < 3; i++, q++)
        for (int j = 0, p = 2; j < 3; j++, p--)
            res[p][q] = matrix[i][j];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
            printf("%d\t", res[i][j]);
        printf("\n");
    }
}