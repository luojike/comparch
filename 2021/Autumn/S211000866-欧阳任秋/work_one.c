#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#define N 5000   // rows and columns of matrix A and matrix B

void ijk_MatrixMultiply(int *matrixA, int *matrixB, int *matrixC){
    int temp;
    int i, j, k;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            temp = 0;
            for(k = 0; k < N; k++){
                temp += matrixA[i*N+k] * matrixB[k*N+j];
            }
            matrixC[i*N+j] = temp;
        }
}

void ikj_MatrixMultiply(int *matrixA, int *matrixB, int *matrixC){
    int temp;
    int i, j, k;
    for(i = 0; i < N; i++)
        for(k = 0; k < N; k++){
            temp = 0;
            for(j = 0; j < N; j++){
                temp += matrixA[i*N+k] * matrixB[k*N+j];
            }
            matrixC[i*N+j] = temp;
        }
}

void jik_MatrixMultiply(int *matrixA, int *matrixB, int *matrixC){
    int temp;
    int i, j, k;
    for(j = 0; j < N; j++)
        for(i = 0; i < N; i++){
            temp = 0;
            for(k = 0; k < N; k++){
                temp += matrixA[i*N+k] * matrixB[k*N+j];
            }
            matrixC[i*N+j] = temp;
        }
}

void jki_MatrixMultiply(int *matrixA, int *matrixB, int *matrixC){
    int temp;
    int i, j, k;
    for(j = 0; j < N; j++)
        for(k = 0; k < N; k++){
            temp = 0;
            for(i = 0; i < N; i++){
                temp += matrixA[i*N+k] * matrixB[k*N+j];
            }
            matrixC[i*N+j] = temp;
        }
}

void kij_MatrixMultiply(int *matrixA, int *matrixB, int *matrixC){
    int temp;
    int i, j, k;
    for(k = 0; k < N; k++)
        for(i = 0; i < N; i++){
            temp = 0;
            for(j = 0; j < N; j++){
                temp += matrixA[i*N+k] * matrixB[k*N+j];
            }
            matrixC[i*N+j] = temp;
        }
}

void kji_MatrixMultiply(int *matrixA, int *matrixB, int *matrixC){
    int temp;
    int i, j, k;
    for(k = 0; k < N; k++)
        for(j = 0; j < N; j++){
            temp = 0;
            for(i = 0; i < N; i++){
                temp += matrixA[i*N+k] * matrixB[k*N+j];
            }
            matrixC[i*N+j] = temp;
        }
}

int main(void){
    struct timeval time_begin, time_end;

    int *matrix_A;
    int *matrix_B;
    int *matrix_C;

    matrix_A = (int*)malloc(sizeof(int)*N*N);
    matrix_B = (int*)malloc(sizeof(int)*N*N);
    matrix_C = (int*)malloc(sizeof(int)*N*N);
    
    srand((unsigned int)time(NULL));
    for(int i=0; i<N; i++)
        for(int j=0; j< N; j++)
            matrix_A [i*N+j] = rand()%10;
    for(int i=0; i<N; i++)
        for(int j=0; j< N; j++)
            matrix_B [i*N+j] = rand()%10;
    
    gettimeofday(&time_begin,NULL);
    ijk_MatrixMultiply(matrix_A,matrix_B,matrix_C);
    gettimeofday(&time_end,NULL);
    printf("Running time of order ijk is %ld s\n",time_end.tv_sec-time_begin.tv_sec);

    gettimeofday(&time_begin,NULL);
    ikj_MatrixMultiply(matrix_A,matrix_B,matrix_C);
    gettimeofday(&time_end,NULL);
    printf("Running time of order ikj is %ld s\n",time_end.tv_sec-time_begin.tv_sec);

    gettimeofday(&time_begin,NULL);
    jik_MatrixMultiply(matrix_A,matrix_B,matrix_C);
    gettimeofday(&time_end,NULL);
    printf("Running time of order jik is %ld s\n",time_end.tv_sec-time_begin.tv_sec);

    gettimeofday(&time_begin,NULL);
    jki_MatrixMultiply(matrix_A,matrix_B,matrix_C);
    gettimeofday(&time_end,NULL);
    printf("Running time of order jki is %ld s\n",time_end.tv_sec-time_begin.tv_sec);

    gettimeofday(&time_begin,NULL);
    kij_MatrixMultiply(matrix_A,matrix_B,matrix_C);
    gettimeofday(&time_end,NULL);
    printf("Running time of order kij is %ld s\n",time_end.tv_sec-time_begin.tv_sec);

    gettimeofday(&time_begin,NULL);
    kji_MatrixMultiply(matrix_A,matrix_B,matrix_C);
    gettimeofday(&time_end,NULL);
    printf("Running time of order kji is %ld s\n",time_end.tv_sec-time_begin.tv_sec);
    
    free(matrix_A);
    free(matrix_B);
    free(matrix_C);
    
    return 0;

}