#include<stdio.h>
#include<stdlib.h>
// imp for bit masking 
int main(){
int n;
scanf("%d",&n);

int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}

long long total=0;

for(int i=0;i<n;i++){
scanf("%d",&a[i]);
total+=a[i]*a[i];
}

long long best=llabs(total);
//  way to calculate 2^n
int exp=1<<n;

for(int mask=0;mask<exp;mask++){
    long long sum=0;

    for(int j=0;j<n;j++){
        if(mask & (1<<j))
    }
}

    return 0;
}