#include<stdio.h>
#include<stdbool.h>
#define k 6
bool isThere(int a , int b, int m[3][k])
{
    bool a1 = false;
    bool b1 = false;
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < k; j++)
        {
            if(i == 0)
            {
                if(m[i][j] == a)
                    a1 = true;
                break;
            }
            if(i == 1)
            {
                if(m[i][j] == b)
                    b1 = true;
                break;
            }
        }
    }
    if (a1 && b1)
        return true;
    return false;
}



void transpose(int m[3][k])
{
    
    for(int j = 0; j < k; j++)
    {
        int temp = m[0][j];
        m[0][j] = m[1][j];
        m[1][j] = temp;
    }
}

void show(int m[3][k])
{
    for(int j = 0; j < k; j++)
    {
        printf("%d\t %d\t %d\n",m[0][j], m[1][j], m[2][j]);
    }
}


int main()
{
    int m1[3][k] = {{0,1,1,2,2,3}, {2,0,3,1,4,3}, {4,3,1,2,5,2}};
    int m2[3][k] = {{0,1,2,3,3,3}, {2,3,5,1,2,3}, {1,3,5,6,9,2}};

    int flag = 0;
    printf("Type 1 for adding and 2 for subtracting: ");
    scanf("%d", &flag);
    for(int j = 0; j < k; j++)
    {
        bool im2 = isThere(m1[0][j], m1[1][j],m2);
        if (im2 && flag == 1)
            printf("%d\t %d\t %d\n",m1[0][j], m1[1][j], m1[2][j] + m2[2][j]);
        else if(im2 && flag == 2)
            printf("%d\t %d\t %d\n",m1[0][j], m1[1][j], m1[2][j] - m2[2][j]);
        else
        {
            printf("%d\t %d\t %d\n",m1[0][j], m1[1][j], m1[2][j]);
            printf("%d\t %d\t %d\n",m2[0][j], m2[1][j], m2[2][j]);
        }
    }

    // printf("Transpose of m1\n");
    // transpose(m1);
    // show(m1);
    return 0;
}