//SUBHAM MAJUMER
//2212020
#include<stdio.h>
void tosparse(int n,int a[n][n]){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]){
                cnt++;
            }
        }
    }
    int mk[cnt][3];
    int ind=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]){
                mk[ind][0]=i;
                mk[ind][1]=j;
                mk[ind][2]=a[i][j];
                ind++;
            }
        }
    }
    printf("\n");
    for(int i=0;i<ind;i++){
        for(int j=0;j<3;j++){
            printf("%d ",mk[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void add(int n,int a[n][n],int b[n][n]){
    int c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("\naddition is :\n");
    tosparse(n,c);
}
void sub(int n,int a[n][n],int b[n][n]){
    int c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    printf("subtraction is :\n");
    tosparse(n,c);
}
void mul(int n,int a[n][n],int b[n][n]){
    int c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];   
            }
        }
    }
    printf("\nmultiplication is : \n");
    tosparse(n,c);
}
void powermul(int n,int a[n][n],int b[n][n]){
    int c[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];   
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=c[i][j];
        }
    }
}
void power(int n,int a[n][n],int p){
    if(p==0 || p==1) return;
    int b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=a[i][j];
        }
    }
    power(n,a,p/2);
    powermul(n,a,a);
    if(p%2) powermul(n,a,b);
}
int main(){
    int a[3][3]={{1,2,10},
                 {1,4,12},
                 {3,3,5}};
    int b[3][3]={{1,3,8},
                {2,4,23},
                {3,3,9}};
    int x[5][5],y[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            x[i][j]=0,y[i][j]=0;
        }
    }
    for(int i=0;i<3;i++){
        x[a[i][0]][a[i][1]]+=a[i][2];
    }
    for(int i=0;i<3;i++){
        y[b[i][0]][b[i][1]]+=b[i][2];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
    add(5,x,y);
    sub(5,x,y);
    mul(5,x,y);
    power(5,x,4);
    printf("power is :\n");
    tosparse(5,x);
    return 0;
}