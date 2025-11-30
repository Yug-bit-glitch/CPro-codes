#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *t = malloc((n+1) * sizeof(int));
    t[1]=1;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &t[i]);
    }

    int jump=0;
    int curr=n;

    while(curr!=1){
        curr=t[curr];
        jump++;
    }
    printf("%d",jump);
    free(t);

    return 0;
}