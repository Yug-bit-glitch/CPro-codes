#include <stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
    long long skill_a = *(long long*)a;
    long long skill_b = *(long long*)b;
    if (skill_a < skill_b) return 1;
    if (skill_a > skill_b) return -1;
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
        int count = 0;
        for (int j = n - 1; j >= 1; j--)
        {
            int size = j;
            int min = a[0];
            for (int i = 1; i <= j; i++)
            {
                if (a[i] < min)
                {
                    min = a[i];
                }
            }

            if (size * min >= x)
            {
                count++;
            }
        }
        printf("%d", count);
    }

    return 0;
}