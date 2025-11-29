#include <stdio.h>
#include<stdlib.h>
int sho(int n, int *memo)
{
    if (memo[n] != -1)
        return memo[n];
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    long long total = sho(n - 1, memo) + sho(n - 2, memo);
    memo[n] = total % 1000000007;
    return memo[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    int *memo = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    printf("%d", sho(n, memo));
    return 0;
}