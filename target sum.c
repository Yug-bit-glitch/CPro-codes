#include <stdio.h>

int canReachTarget(int arr[], int n, int idx, int currentSum, int target) {
    // Base case: if we've processed all numbers
    if (idx == n) {
        return currentSum == target;
    }
    
    // Recursive case: try adding or subtracting the current number
    // Try adding the current number
    if (canReachTarget(arr, n, idx + 1, currentSum + arr[idx], target)) {
        return 1;
    }
    
    // Try subtracting the current number
    if (canReachTarget(arr, n, idx + 1, currentSum - arr[idx], target)) {
        return 1;
    }
    
    return 0;
}

int main() {
    int n, x;
    
    // Read N and X
    scanf("%d %d", &n, &x);
    
    // Read array elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Start recursion with first element (can be + or -)
    int result = canReachTarget(arr, n, 1, arr[0], x) || 
                 canReachTarget(arr, n, 1, -arr[0], x);
    
    if (result) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
