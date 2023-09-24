#include<stdio.h>

int getItem(int a[], int i, int j, int m, int n)
{
    if (i >= m || j >= n)
        printf("ERROR\n");
        return;
    int k = i * m + j;
    return a[k];
}

void display(int a[], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t",a[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int assign(int a[], int i, int j, int m, int n, int val)
{
    if (i >= m || j >= n)
        printf("ERROR\n");
        return 0;
    int k = i * m + j;
    a[k] = val;
}

void add(int a[], int b[], int c[], int m , int n)
{
    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum = getItem(a,i,j,m,n) + getItem(b,i,j,m,n);
            assign(c,i,j,m,n,sum);
        }
    }
}

void sub(int a[], int b[], int c[], int m , int n)
{
    int i,j, sum = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum = getItem(a,i,j,m,n) - getItem(b,i,j,m,n);
            assign(c,i,j,m,n,sum);
        }
    }
}

void mul(int a[], int b[], int c[], int m, int n)
{
    int sum;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum = 0;
            for(int k = 0; k < n; k++)
            {
                sum += getItem(a,i,k,m,n) + getItem(b,k,i,m,n);
            }
            assign(c,i,j,m,n,sum);
        }
    }
}

void setZero(int a[], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i * m + j] = 0;
        }
    }
}

int main()
{
    int m = 3, n = 3;
    int a[9] = {1,0,0,0,1,0,0,0,1};
    int b[9] = {1,0,0,0,1,0,0,0,1};
    int c[9] = {0};
    add(a,b,c,m,n);
    display(c,m,n);
    setZero(c,m,n);
    sub(a,b,c,m,n);
    display(c,m,n);
    setZero(c,m,n);
    mul(a,b,c,m,n);
    display(c,m,n);
    setZero(c,m,n);
    return 0;
}