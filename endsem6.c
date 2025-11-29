#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    long long p1 = *(long long *)a;
    long long p2 = *(long long *)b;
    // Sort in descending order
    if (p1 > p2) return -1;
    if (p1 < p2) return 1;
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        long long x;
        scanf("%d %lld", &n, &x);
        long long a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        qsort(a, n, sizeof(long long), compare);
        
        int count = 0;
        int j = 0;
        
        while (j < n)
        {
            int team_size = 0;
            long long min_skill = a[j];
            
            while (j < n)
            {
                team_size++;
                min_skill = a[j];
                j++;
                
                if ((long long)team_size * min_skill >= x)
                {
                    count++;
                    break;
                }
            }
        }
        
        printf("%d\n", count);
    }

    return 0;
}