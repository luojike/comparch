#include<stdio.h>
#include<time.h>
#include <cstdlib>
int MatA[2000][2000];
int MatB[2000][2000];
int MatC[2000][2000];
int main(){
    int i,j,k,r;
    for(i=0;i<2000;i++)
        for(j=0;j<2000;j++)
            MatA[i][j]=j+1;
    for(i=0;i<2000;i++)
        for(j=0;j<2000;j++)
            MatB[i][j]=2000-j;
    time_t start,end;
    start=time(NULL);
    for(k=0;k<2000;k++)
        for(i=0;i<2000;i++){
            r=MatA[i][k];
            for(j=0;j<2000;j++)
                MatC[i][j]+=r*MatB[k][j];
        }
    end=time(NULL);
    system("pause");
    return 0;
}
