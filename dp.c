#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// recursion+memoization

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int mincost(int n, int k, int *h, int *memo)
{
    if (n == 1)
        return 0;

    if (memo[n] != -1)
        return memo[n];

    int ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if(n-i>=1){
        int cost = mincost(n - i, k, h, memo) + abs(h[n - 1] - h[n - 1 - i]);
        ans = min(ans, cost);
        }
    }
    memo[n] = ans;
    return memo[n];
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);

    int *h = malloc(n * sizeof(int));
    int *memo = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }

    printf("%d\n", mincost(n, k, h, memo));

    free(h);
    free(memo);

    return 0;
}
