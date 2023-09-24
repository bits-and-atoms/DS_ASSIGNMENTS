#include<stdio.h>

void mul(int p, int q, int r, int a[p][q], int b[q][r], int c[p][r])
{
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < r; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < q; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void check(int m, int n, int p, int q, int a[m][n], int b[p][q])
{
    if (m != p || n != q)
    {
        printf("NOT IDEMPOTENT\n");
        return;
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (a[i][j] ^ b[i][j])
            {    
                printf("NOT IDEMPOTENT\n");
                return;
            }
        }
    }
    printf("IDEMPOTENT\n");
}

int main()
{
    int a[3][3] = {1,0,0,0,1,0,0,0,1};
    int c[3][3];
    mul(3,3,3,a,a,c);
    check(3,3,3,3,a,c);
    return 0;
}