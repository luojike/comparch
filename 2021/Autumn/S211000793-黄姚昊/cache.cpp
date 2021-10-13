#include <iostream>
#include <time.h>
#include <windows.h>
#include <sys/time.h>

#define N 2000
int a[N][N] ={0}, b[N][N] = {0}, c[N][N]={0};

int ijk() {
	

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i+j;
            b[i][j] = i+j;
        }
    }
    time_t start,end;
    start = clock();
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
 
        }
    }
    end = clock();
    printf("ijk time : %0.3lf sec\n",(end-start)/1000.0);
	return 0;

}
int ikj() {
	

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i+j;
            b[i][j] = i+j;
        }
    }
    time_t start,end;
    start = clock();
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            for (j = 0; j < N; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
 
        }
    }
    end = clock();
    printf("ikj time : %0.3lf sec\n",(end-start)/1000.0);
	return 0;

}
int jik() {
	

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i+j;
            b[i][j] = i+j;
        }
    }
    time_t start,end;
    start = clock();
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
 
        }
    }
    end = clock();
    printf("jik time : %0.3lf sec\n",(end-start)/1000.0);
	return 0;

}
int jki() {
	

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i+j;
            b[i][j] = i+j;
        }
    }
    time_t start,end;
    start = clock();
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            for (i = 0; i < N; i++) {
                c[i][j] += a[i][k] * b[k][j];
            }
 
        }
    }
    end = clock();
    printf("jki time : %0.3lf sec\n",(end-start)/1000.0);
	return 0;

}
int kij() {
	

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i+j;
            b[i][j] = i+j;
        }
    }
    time_t start,end;
    start = clock();
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
 
        }
    }
    end = clock();
    printf("kij time : %0.3lf sec\n",(end-start)/1000.0);
	return 0;

}
int kji() {
	

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i+j;
            b[i][j] = i+j;
        }
    }
    time_t start,end;
    start = clock();
    for (k = 0; k < N; k++) {
        for (j = 0; j < N; j++) {
            for (i = 0; i < N; i++) {
                c[i][j] += a[i][k] * b[k][j];
            }
 
        }
    }
    end = clock();
    printf("kji time : %0.3lf sec\n",(end-start)/1000.0);
	return 0;

}



int main(){
    ijk();
    ikj();
    jki();
    jik();
    kij();
    kji();
    return 0;
}