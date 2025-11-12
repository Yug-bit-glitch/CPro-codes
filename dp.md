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



You said:

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 
int min(int a,int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}
 
int main(){
 
int n,x;
scanf("%d %d",&n,&x);
 
int *a=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
/*to reach a specific coin there can be two ways one is 
to f(x)or f(x-j)+1 we have to make a recursion type relation to minimize it at every step
*/
 
int *dp=malloc((x+1)*sizeof(int));
 
dp[0]=0;
for(int i=1;i<=x;i++){
    dp[i]=INT_MAX;
}
/*
the looping condition keep inner loop from 0 to n-1 cause it is accesing the array 
the outer loop should be keept from 1 to x cause it is filling the dp table 
*/
for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){
        if((a[j]<=i)&&(dp[i-a[j]] != INT_MAX)){
            dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
    }
}
if(dp[x]==INT_MAX){
    printf("-1\n");
}else{
printf("%d",dp[x]);
}
free(dp);
 return 0;
}
