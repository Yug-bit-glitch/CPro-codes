#include<stdio.h>
#include<stdlib.h>

int main(){
int n;
scanf("%d",&n);
int **mat=(int**)malloc(n*sizeof(int*));

for(int i=0;i<n;i++){
    mat[i]=malloc(n*sizeof(int));
    for(int j=0;j<n;j++){
        scanf("%d",&mat[i][j]);
    }
}
for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){  // j starts from i+1 to avoid double swapping
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }

for(int i=0;i<n;i++){
    for(int j=0;j<n/2;j++){
        int temp=mat[i][j];
        mat[i][j]=mat[i][n-1-j];
        mat[i][n-1-j]=temp;
    }
    }
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d",mat[i][j]);
        if(j<n-1){
            printf(" ");
        }
    }
    printf("\n");
}
for(int i=0;i<n;i++){
    free(mat[i]);
}
free(mat);

    return 0;
}
