#include <stdio.h>
#define m 4
#define n 4
void swap(int a[m][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                int temp=a[i][j];
                a[i][j]=a[i][n-j-1];
                a[i][n-j-1]=temp;
            }
        }
    }
}
void print(int a[m][n]){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}
int main()
{
    int a[m][n]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    print(a);
    swap(a);
    printf("\n");
    print(a);
    return 0;
}
