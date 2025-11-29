#include<stdio.h>

int final(long long n){
    if((n<10)){
        return n;
    }
  else{
 return final(final(n/10)+n%10);
  } 
}
int main(){
long long n;
scanf("%lld",&n);
printf("%d\n",final(n));
    return 0;
}