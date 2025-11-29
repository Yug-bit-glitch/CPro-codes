#include <stdio.h>
#include <stdlib.h>
#define N 1000000007

int grid(int x, int y, int n, char **s, long long **memo)
{
    if (x >= n || y >= n || s[x][y] == '*')
        return 0;
    if (memo[x][y] != -1)
        return memo[x][y];
    if (x == n - 1 && y == n - 1)
        return 1;
    long long a1 = grid(x + 1, y, n, s, memo);
    long long a2 = grid(x, y + 1, n, s, memo);

    memo[x][y] = (a1 + a2) % N;

    return memo[x][y];
}

int main()
{
    int n;
    scanf("%d", &n);
    long long **memo = malloc((n) * sizeof(long long *));
    for (int i = 0; i < n; i++)
    {
        memo[i] = malloc(n*sizeof(long long));
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = -1;
        }
    }
    char **s = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        s[i] = malloc(n * sizeof(char));
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &s[i][j]);
        }
    }

    int result = grid(0, 0, n, s, memo);
    printf("%d\n", result);
    for (int i = 0; i < n; i++)
    {
        free(s[i]);
    }
    free(s);
    for (int i = 0; i < n; i++)
    {
        free(memo[i]);
    }
    free(memo);

    return 0;
}