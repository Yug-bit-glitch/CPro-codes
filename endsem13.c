#include <stdio.h>

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long arr[n];
    long long total = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        total += arr[i];
        if (arr[i] > mx) mx = arr[i];
    }

    long long avg = total / k;          // YOUR IDEA

    long long low = mx;                 // at least max element
    if (avg > low) low = avg;           // you start from average if bigger

    long long high = total;             // worst case all in one group

    while (low < high) {
        long long mid = (low + high) / 2;

        long long curr = 0, used = 1;

        // greedy check: how many groups needed if max sum <= mid
        for (int i = 0; i < n; i++) {
            if (curr + arr[i] <= mid) {
                curr += arr[i];
            } else {
                used++;
                curr = arr[i];
            }
        }

        if (used <= k) {
            high = mid;        // mid works → try smaller
        } else {
            low = mid + 1;     // too small → go higher
        }
    }

    printf("%lld\n", low);
    return 0;
}
