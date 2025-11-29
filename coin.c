#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

int way(int i, int n, int x, int *c, int **memo)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;

    if (memo[i][x] != -1)
        return memo[i][x];
    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        if (x - c[i] >= 0)
        {
            total += way(i, n, x - c[i], c, memo);
        }
        total += way(i + 1, n, x, c, memo);
    }
    memo[x] = total % mod;
    return memo[i][x];
}
int main()
{
    int n, x;
    scanf("%d %d", &n, &x);

    int *c = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    int **memo = malloc((x + 1) * sizeof(int));
    for (int i = 0; i <= x; i++)
    {
        memo[i] = malloc((x + 1) * sizeof(int));
        for (int j = 0; j <= x; j++)
        {
            memo[i][j] = -1;
        }
    }
    printf("%d\n", way(0, n, x, c, memo));

    for (int i = 0; i < n; i++)
        free(memo[i]);
    free(memo);
    free(c);
    return 0;
}