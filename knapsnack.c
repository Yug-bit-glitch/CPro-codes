#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n, w;
    scanf("%d %d", &n, &w);           // w is the capacity
    int *a = malloc(n * sizeof(int)); // array for weight
    long long *b = malloc(n * sizeof(long long)); // array for value
    for (int i = 0; i < n; i++)
    {
        scanf("%d %lld", &a[i], &b[i]);
    }
    long long dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] <= j)
            {
                dp[i][j] = max(b[i - 1] + dp[i - 1][j - a[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("%lld\n", dp[n][w]);

    free(a);
    free(b);
    return 0;
}