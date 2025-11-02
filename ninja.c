#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    
    if(n == 0) {
        printf("0");
        return 0;
    }
    if(n == 1) {
        printf("1");
        return 0;
    }
    if(n == 2) {
        printf("2");
        return 0;
    }
    if(n == 3) {
        printf("4");
        return 0;
    }
    
    // Memoization didnt work trying malloc(n+1)
    int *arr=(int*)malloc((n+1)*sizeof(int));
    // Fill array from index 4 to n using recurrence relation
    // arr[i] = arr[i-1] + arr[i-2] + arr[i-3]

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for(int i = 4; i <= n; i++) {
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % 1000000007 ;
    }
    
    printf("%d", arr[n]);


    free(arr);
    return 0;
}