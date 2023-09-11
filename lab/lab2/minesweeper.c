#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define m 5
#define n 5

void _init_(int board[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
}

void bombs_placement(int board[m][n], int k)
{
    int i, j;
    i = (rand() + clock()) % m;
    j = (rand() + clock()) % n;

    int p; // k number of bombs

    for (p = 0; p < k; p++)
    {
        while (board[i][j] == -1)
        {
            i = (rand() ^ clock()) % m;
            j = (rand() ^ clock()) % n;
        }
        board[i][j] = -1;
    }
}

int check(i, j)
{
    if (i >= 0 && j < n)
        return 1;
    return 0;
}

int adder(int i, int j, int board[m][n])
{
    if (board[i][j] == -1)
        return 1;
    return 0;
}

void hints(int board[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = 0;
            if (board[i][j] != -1)
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (check(k,l))
                            c += adder(k, l, board);
                    }
                }

                board[i][j] = c;
            }
        }
    }
}

void show(int board[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// driver code

int main()
{
    int k = (m * n) / 4;
    int board[m][n];

    _init_(board);
    bombs_placement(board, k);
    printf("The bombs in the board is:\n");
    show(board);
    hints(board);
    printf("The board with hints are:\n");
    show(board);
    return 0;
}