#include <stdio.h>
#include <stdlib.h>

long long compare(long long a, long long b)
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
    int n;
    scanf("%d", &n);
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }
    long long dp[n][n];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = a[i];
    }

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length; i++)
        {
            int j = i + length - 1;

            dp[i][j] = compare(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    long long ans = (total + dp[0][n - 1]) / 2;
    printf("%lld", ans);
    return 0;
}
