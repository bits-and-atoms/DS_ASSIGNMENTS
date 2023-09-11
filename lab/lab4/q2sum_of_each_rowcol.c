#include <stdio.h>
#define n 3
#define m 3
void sumrow(double a[m][n],int x){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=a[x][i];
    }
    printf("sum of row %d is %lf\n",x,sum);
}
void sumcolumn(double a[m][n],int x){
    double sum=0;
    for(int j=0;j<n;j++){
        sum+=a[j][x];
    }
    printf("sum of column %d is %lf\n",x,sum);
}
int main()
{
    double a[m][n]={
        {1,2,3},
        {4.2,5,6},
        {7,8,9}
    };
    for(int i=0;i<m;i++){
        sumrow(a,i);
    }
    for(int i=0;i<n;i++){
        sumcolumn(a,i);
    }
    return 0;
}
