#include<stdio.h>
#include<stdlib.h>

int main(void){
int n;
scanf("%d",&n);

int*chase=(int*)malloc((n+1)*sizeof(int));

chase[1]=1;
chase[2]=2;

for(int i=3;i<=n;i++){
    chase[i]=chase[i-1]+chase[i-2];
}
printf("%d",chase[n]);
free(chase);
}