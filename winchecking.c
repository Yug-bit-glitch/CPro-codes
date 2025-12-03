#include "winchecking.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 24

int memo[N][N];

bool repeat(int x, int y, player *pl)
{
    node *temp = pl->moves;
    while (temp != NULL)
    {
        if (temp->x == x && temp->y == y)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool check(int x, int y, int n, player *pl)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        return false;
    }
    
    if (repeat(x, y, pl) == false)
    {
        return false;
    }

    if (pl->identifier == 'A' && y == n - 1)
    {
        return true;
    }
    if (pl->identifier == 'B' && x == n - 1)
    {
        return true;
    }
    if (memo[x][y] != -1)
    {
        return memo[x][y];
    }
    
    memo[x][y] = 0;
    
    if (check(x + 2, y + 1, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    if (check(x + 2, y - 1, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    if (check(x - 2, y + 1, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    if (check(x - 2, y - 1, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    if (check(x + 1, y + 2, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    if (check(x + 1, y - 2, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    if (check(x - 1, y + 2, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    if (check(x - 1, y - 2, n, pl))
    {
        memo[x][y] = 1;
        return true;
    }
    
    return false;
}

bool checkwin(int n, player *pl)
{
    if (pl->moves == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            memo[i][j] = -1;
        }
    }

    node *temp = pl->moves;
    while (temp != NULL)
    {
        if (pl->identifier == 'A' && temp->y == 0)
        {
            if (check(temp->x, temp->y, n, pl))
            {
                return true;
            }
        }
        else if (pl->identifier == 'B' && temp->x == 0)
        {
            if (check(temp->x, temp->y, n, pl))
            {
                return true;
            }
        }
        temp = temp->next;
    }

    return false;
}