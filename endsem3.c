#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int start = 0;
    int end = 0;
    int temp = 0;

    long long max = arr[0];
    long long curr = arr[0];

    for (int i = 0; i < n; i++)
    {

        if (arr[i] + curr < arr[i])
        {
            curr = arr[i];
            temp = i;
        }
        else
        {
            curr = curr + arr[i];
        }

        if (curr > max)
        {
            max = curr;
            start = temp;
            end = i;
        }
    }

    printf("%lld\n", max);
    printf("%d %d", start, end);

    return 0;
}
// getting 85/100 on oj the bug is in for loop start from 1