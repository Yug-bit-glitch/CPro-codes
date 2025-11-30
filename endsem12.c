#include <stdio.h>
#include <stdlib.h>

int woman(int n, int *memo)
{
    if (n < 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    if (n == 0)
        return 1;
    int total = woman(n - 1, memo) + woman(n - 2, memo);
    memo[n] = total;
    return memo[n];
}

int main()
{
    int n;
    scanf("%d", &n);

    int *memo = ((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    printf("%d", woman(n, memo));

    free(memo);

    return 0;
}