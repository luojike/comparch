#include <iostream>
#include <time.h>
#include <sys/timeb.h>
#include <Windows.h>
#define n 5000
#define max 10000

using namespace std;

double a[n][n];
double b[n][n];
double c[n][n];
double cache[max][max];

//初始化三个数组
void init(){
    for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			a[i][j] = 1 + rand()%(100-1+1);
			b[i][j] = 1 + rand()%(100-1+1);
			c[i][j] = 0.0f;
		}
	}
}

//消除   上一次计算时对数组的读取   对   下一次计算   的影响
void eliminate(){
    for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cache[i][j] = 0;
		}
	}
}

void ijk(){
    for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
}

void ikj(){
    for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			for(int j=0; j<n; j++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
}

void jik(){
    for(int j=0; j<n; j++) {
		for(int i=0; i<n; i++) {
			for(int k=0; k<n; k++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
}

void jki(){
    for(int j=0; j<n; j++) {
		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
}

void kij(){
    for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
}

void kji(){
    for(int k=0; k<n; k++) {
		for(int j=0; j<n; j++) {
			for(int i=0; i<n; i++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
}

//6种计算分别计时
void matrix_multiplication(){
    DWORD start, end;

    //ijk
    eliminate();//消除影响
    start = GetTickCount();
	ijk();
	end = GetTickCount();
	printf("矩阵乘法 (i-j-k) 时间: %0.3lf sec\n", (end-start)/1000.0);

    //ikj
    eliminate();//消除影响
    start = GetTickCount();
	ikj();
	end = GetTickCount();
	printf("矩阵乘法 (i-k-j) 时间: %0.3lf sec\n", (end-start)/1000.0);

    //jik
    eliminate();//消除影响
    start = GetTickCount();
	jik();
	end = GetTickCount();
	printf("矩阵乘法 (j-i-k) 时间: %0.3lf sec\n", (end-start)/1000.0);

    //jki
    eliminate();//消除影响
    start = GetTickCount();
	jki();
	end = GetTickCount();
	printf("矩阵乘法 (j-k-i) 时间: %0.3lf sec\n", (end-start)/1000.0);

    //kij
    eliminate();//消除影响
    start = GetTickCount();
	kij();
	end = GetTickCount();
	printf("矩阵乘法 (k-i-j) 时间: %0.3lf sec\n", (end-start)/1000.0);

    //kji
    eliminate();//消除影响
    start = GetTickCount();
	kji();
	end = GetTickCount();
	printf("矩阵乘法 (k-j-i) 时间: %0.3lf sec\n", (end-start)/1000.0);

}

int main() {
	
	srand((unsigned)time(NULL));
	
    init();

	matrix_multiplication();
	return 0;
}
