#include<stdio.h>
#include<stdlib.h>

int main(){
int n;
scanf("%d",&n);
int *dice =malloc((n+1)*sizeof(int));
dice[1]=0;
dice[2]=1;
dice[3]=4;
for(int i=4;i<=6;i++){
    dice[i]=dice[i-1]+dice[i-2]+dice[i-3];
}
printf("%d",dice[n]%1000000007);
free(dice);
return 0;
}