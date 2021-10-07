#include<stdio.h>
#include<time.h>
#include <cstdlib>
int MatA[2000][2000];
int MatB[2000][2000];
int MatC[2000][2000];
int main(){
    int i,j,k,sum;
    for(i=0;i<2000;i++)
        for(j=0;j<2000;j++)
            MatA[i][j]=j+1;
    for(i=0;i<2000;i++)
        for(j=0;j<2000;j++)
            MatB[i][j]=2000-j;
    time_t start,end;
    start=time(NULL);
    for(j=0;j<2000;j++)
        for(i=0;i<2000;i++){
            sum=0;
            for(k=0;k<2000;k++)
                sum+=MatA[i][k]*MatB[k][j];
            MatC[i][j]=sum;
        }
    end=time(NULL);
    system("pause");
    return 0;
}

