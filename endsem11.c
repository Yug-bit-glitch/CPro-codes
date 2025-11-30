#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    long long p1 = *(long long *)a;
    long long p2 = *(long long *)b;
    if (p1 < p2) return -1;
    if (p1 > p2) return 1;
    return 0;
}

int loweridx(long long *arr, long long x, int n)
{
    int low = 0;
    int high = n - 1;
    int idx = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)  // Changed to >= to find LEFTMOST occurrence
        {
            idx = mid;
            high = mid - 1;  // Go left
        }
        else
        {
            low = mid + 1;
        }
    }
    return idx;
}

int upperidx(long long *arr, long long x, int n)
{
    int low = 0;
    int high = n - 1;
    int idx = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)  // Changed to <= to find RIGHTMOST occurrence
        {
            idx = mid;
            low = mid + 1;  // Go right
        }
        else
        {
            high = mid - 1;
        }
    }
    return idx;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    long long *arr = malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(long long), compare);
    
    for (int i = 0; i < q; i++)
    {
        long long x;
        scanf("%lld", &x);
        int left = loweridx(arr, x, n);   // Leftmost position of x
        int right = upperidx(arr, x, n);  // Rightmost position of x

        if (left == -1 || arr[left] != x)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", right - left + 1);  // Now right >= left
        }
    }
    free(arr);
    return 0;
}