#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
    long long diff = *(long long*)a - *(long long*)b;
    if(diff < 0) return -1;
    if(diff > 0) return 1;
    return 0;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        long long x;
        scanf("%d %lld",&n,&x);
        long long a[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        
        qsort(a, n, sizeof(long long), cmp);
        
        long long result[n];
        int res_idx = 0;
        int left=0;
        int right=n-1;
        long long sum = 0;
        long long bonus = 0;

        while(left <= right){
            long long next_threshold = (sum/x + 1) * x;
            
            if(sum + a[right] >= next_threshold){
                sum += a[right];
                bonus += a[right];
                result[res_idx++] = a[right];
                right--;
            }
            else{
                sum += a[left];
                result[res_idx++] = a[left];
                left++;
            }
        }

        printf("%lld\n", bonus);
        for(int i=0; i<n; i++){
            printf("%lld", result[i]);
            if(i < n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}