#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007
int main(){
int n,x;
scanf("%d %d",&n,&x);
int*c=malloc(n*sizeof(int));
for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
}
int*dp=malloc((x+1)*sizeof(int));
dp[0]=1;

for(int i=1;i<=x;i++){
    for(int j=0;j<n;j++){if(i-c[j]>=0){
dp[i]=(dp[i]+dp[i-c[j]])%mod;
    }
}
}
printf("%d\n",dp[x]);
    return 0;
}