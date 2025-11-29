#include<stdio.h>

int n;
char str[100];

void f(int idx,int open,int close){
    if(idx==2*n){
        printf("%s\n",str);
    }
    if(open<n){
        str[idx]='(';
        f(idx+1,open+1,close);
    }
    if(open>close){
        str[idx]=')';
        f(idx+1,open,close+1);
    }
}
int main(){
scanf("%d",&n);
f(0,0,0);
return 0;
}
