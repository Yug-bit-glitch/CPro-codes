#include <stdio.h>
#include <stdlib.h>

/*int way(int t, int *a, int *memo, int n)
{
    if (memo[t] != -1)
        return memo[t];
    if (t == 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (t >= a[i])
        {
            ans += memo[t - a[i]];
        }
    }
    memo[t] = ans;
    return memo[t];
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int t;
    scanf("%d", &t);
    int *memo = malloc((t + 1) * sizeof(int));
    for(int i=0;i<=n;i++){
        memo[i]=-1;
    }
    printf("%d",way(t,a,memo,n));
    return 0;
}*/

int man(int n, int target, int idx, int *a)
{
    if (target == 0)
        return 1;
    if (idx == n || target < 0)
        return 0;
    int take = 0;
    if (target >= a[idx])
    {
         take = man(n, target-a[idx], idx, a);
    }
    int skip = man(n, target, idx + 1, a);
    return take + skip;
}
int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int target;
    scanf("%d", &target);
    int count = man(n, target, 0, a);
    printf("%d", count);

    return 0;
}