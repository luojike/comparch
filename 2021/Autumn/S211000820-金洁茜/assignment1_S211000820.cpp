#include <time.h>
#include <iostream>
#include <sys/timeb.h>
#include <Windows.h>
#define n 5000


using namespace std;
double a[n][n];
double b[n][n];
double c[n][n];


int main() {
	time_t start, end;
	int i,j,k;
	srand((unsigned)time(NULL));
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			a[i][j] = (double)rand()/(RAND_MAX);
			b[i][j] = (double)rand()/(RAND_MAX);
			c[i][j] = 0.0f;
		}
	}

    //ijk
	start = clock();
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			for(k=0; k<n; k++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
	end = clock();
	printf("matrix multiply (ijk) time: %0.3lf sec\n", (end-start)/1000.0);

    //ikj
    start = clock();
	for(i=0; i<n; i++) {
		for(k=0; k<n; k++) {
			for(j=0; j<n; j++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
	end = clock();
	printf("matrix multiply (ikj) time: %0.3lf sec\n", (end-start)/1000.0);

    //jik
    start = clock();
	for(j=0; j<n; j++) {
		for(i=0; i<n; i++) {
			for(k=0; k<n; k++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
	end = clock();
	printf("matrix multiply (jik) time: %0.3lf sec\n", (end-start)/1000.0);

    //jki
    start = clock();
	for(j=0; j<n; j++) {
		for(k=0; k<n; k++) {
			for(i=0; i<n; i++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
	end = clock();
    printf("matrix multiply (jki) time: %0.3lf sec\n", (end-start)/1000.0);

    //kij
    start = clock();
	for(k=0; k<n; k++) {
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
	end = clock();
    printf("matrix multiply (kij) time: %0.3lf sec\n", (end-start)/1000.0);

    //kji
    start = clock();
	for(k=0; k<n; k++) {
		for(j=0; j<n; j++) {
			for(i=0; i<n; i++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j] ;
			}
		}
	}
	end = clock();
    printf("matrix multiply (kji) time: %0.3lf sec\n", (end-start)/1000.0);

	return 0;
}
