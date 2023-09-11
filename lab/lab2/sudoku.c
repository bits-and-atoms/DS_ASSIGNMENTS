#include<stdio.h>
#include<stdlib.h>

#define n 9

int freq_check(int freq[01])
{
    for(int i = 1; i < 10; i++)
    {
        if (freq[i] != 1)
            return 1;
    }
    return 0;
}
void checker(int board[n][n])
{
    // for rows
    for(int i = 0; i < n; i++)
    {
        int freq[10] = {0};
        for(int j = 0; j < n; j++)
        {
            freq[board[i][j]] += 1;
        }
        if(freq_check(freq))
        {
            printf("Wrong Solution\n");
            return;
        }
    }

    // for coloumns
    for(int j = 0; j < n; j++)
    {
        int freq[10] = {0};
        for(int i = 0; i < n; i++)
        {
            freq[board[i][j]] += 1;
        }
        if(freq_check(freq))
        {
            printf("Wrong Solution\n");
            return;
        }
    }

    // sub - matrix 9x9
    for(int i = 1; i <= 7; i += 3)
    {
        for(int j = 1; j <= 7; j += 3)
        {
            int freq[10] = {0};
            for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        freq[board[k][l]] += 1;
                    }
                }
            if(freq_check(freq))
            {
                printf("Wrong Solution\n");
                return;
            }
        }
    }

    printf("Correct Solution\n");
}

int main()
{
    int board[n][n]
        = { { 7, 9, 2, 1, 5, 4, 3, 8, 6 },
            { 6, 4, 3, 8, 2, 7, 1, 5, 9 },
            { 8, 5, 1, 3, 9, 6, 7, 2, 4 },
            { 2, 6, 5, 9, 7, 3, 8, 4, 1 },
            { 4, 8, 9, 5, 6, 1, 2, 7, 3 },
            { 3, 1, 7, 4, 8, 2, 9, 6, 5 },
            { 1, 3, 6, 7, 4, 8, 5, 9, 2 },
            { 9, 7, 4, 2, 1, 5, 6, 3, 8 },
            { 5, 2, 8, 6, 3, 9, 4, 1, 7 } };
    
    printf("The board is:\n");
    checker(board);
    return 0;
}