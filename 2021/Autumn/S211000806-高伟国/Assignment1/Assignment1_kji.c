#include<stdio.h>
#include<time.h>
int A[5000][5000];
int B[5000][5000];
int C[5000][5000];
int main(){
    int i,j,k,r;
    for(i=0;i<5000;i++)
        for(j=0;j<5000;j++)
            A[i][j]=j+1;
    for(i=0;i<5000;i++)
        for(j=0;j<5000;j++)
            B[i][j]=5000-j;
    time_t start,end;
    start=time(NULL);
    for(k=0;k<5000;k++)
        for(j=0;j<5000;j++){
            r=B[k][j];
            for(i=0;i<5000;i++)
                C[i][j]+=A[i][k]*r;
        }
    end=time(NULL);
    system("pause");
    return 0;
}
