#include <stdio.h>
int m=3, n=3;
void transpose(int matrix[3][3])
{

    for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}
void reverseColumns(int a[m][n])
{
    int ind = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = a[j][i];
            a[j][i] = a[ind][i];
            a[ind][i] = temp;
            ind--;
        }
        ind = n - 1;
    }
}
void print(int a[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int a[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    printf("before 90 degree anticlockwise rotation:\n");
    print(a);
    printf("after 90 degree anticlockwise rotation:\n");
    transpose(a);
    reverseColumns(a);
    print(a);
    return 0;
}
