#include <stdio.h>
#include <time.h>

int a[2000][2000] = {{1},{3},{5},{7},{9},{6}};
int b[2000][2000] = {1,2,4,3,7};
int sum[2000][2000];

void main(){
    clock_t start,end;

    // i-j-k的顺序取指令
    start = clock();
    for(int i = 0 ; i<2000 ; i++){
        for(int j = 0; j<2000 ; j++){
            for(int k = 0; k<2000 ; k++){
                sum[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    end = clock();
    printf("i-j-k'time is %fs\n",(double)(end-start)/CLK_TCK);

    // i-k-j的顺序取指令
    start = clock();
    for(int i = 0 ; i<2000 ;i++){
        for(int k = 0; k<2000 ; k++){
            for(int j = 0; j<2000 ; j++ ){
                sum[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    end = clock();
    printf("i-k-j'time is %fs\n",(double)(end-start)/CLK_TCK);

    // j-i-k的顺序取指令
    start = clock();
    for(int j = 0 ; j<2000 ; j++){
        for(int i = 0; i<2000 ; i++){
            for(int k = 0; k<2000 ; k++ ){
                sum[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    end = clock();
    printf("j-i-k'time is %fs\n",(double)(end-start)/CLK_TCK);

    // j-k-i的顺序取指令
    start = clock();
    for(int j = 0 ; j<2000 ; j++){
        for(int k = 0; k<2000 ; k++){
            for(int i = 0; i<2000 ; i++ ){
                sum[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    end = clock();
    printf("j-k-i'time is %fs\n",(double)(end-start)/CLK_TCK);

    // k-i-j的顺序取指令
    start = clock();
    for(int k = 0 ; k<2000 ; k++){
        for(int i = 0; i<2000 ; i++){
            for(int j = 0; j<2000 ; j++ ){
                sum[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    end = clock();
    printf("k-i-j'time is %fs\n",(double)(end-start)/CLK_TCK);

    // k-j-i的顺序取指令
    start = clock();
    for(int k = 0 ; k<2000 ; k++){
        for(int j = 0; j<2000 ; j++){
            for(int i = 0; i<2000 ; i++ ){
                sum[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    end = clock();
    printf("k-j-i'time is %fs\n",(double)(end-start)/CLK_TCK);

}