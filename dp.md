codes using memoization and recursion
#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007



int way(int n,int *memo){
    if(n==0)return 1;
    if(n<0)return 0;
    if(memo[n] != -1)return memo[n];

    long long sum =0;
   for(int i=1;i<=6;i++){
    sum=(sum+ way(n-i,memo)) % mod;
   }
   memo[n]=sum;
  return memo[n];
}

int main() {
    int n;
    scanf("%d", &n);

    int *memo = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) memo[i] = -1;

    printf("%d\n", way(n, memo));

    free(memo);
    return 0;
}
