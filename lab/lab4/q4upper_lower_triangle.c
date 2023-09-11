#include <stdio.h>
#define m 3
#define n 3
void uppertri(int a[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                printf("%d ",a[i][j]);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}
void lowtri(int a[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i>=j){
                printf("%d ",a[i][j]);
            }
        }
        printf("\n");
    }
}
void principaldiagonal(int a[m][n]){
    for(int i=0;i<m;i++){
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                printf("%d ",a[i][j]);

            }
            else{
                printf("  ");
            }
        }
        printf("\n");
        
    }
}
void secondaryprincipaldiagonal(int a[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i+j==n-1){
            printf("%d ",a[i][j]);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}
int main()
{
    int a[m][n]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    lowtri(a);
    printf("\n");
    uppertri(a);
    printf("\n");
    printf("principal diagonal matrix\n");
    principaldiagonal(a);
     printf(" secondary principal diagonal matrix\n");
     secondaryprincipaldiagonal(a);
    return 0;
}
