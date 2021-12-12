#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <immintrin.h>
#include <emmintrin.h>
#define isprint 0

void gemm(double* matA,double* matB,double* matC,const int M,const int N,const int K)
{
	for (int a = 0; a < M; a++){
		for (int b = 0; b < K; b++){
			double sum = 0;
			for (int c = 0; c < N; c++)
				sum += matA[a*N + c] * matB[c*K + b];
			matC[a*K + b] = sum;
		}
	}
}

int main()
{
	clock_t start,end;
	double endtime=0;
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	double *ma=new double[m*n];
	double *mb=new double[k*n];
	double *mc=new double[m*k];

	srand((unsigned)time(0));
	for (int i = 0; i < m*n; i++){		
		ma[i] = (double)rand() / (double)(RAND_MAX)*100;		
	}	
	for (int i = 0; i < n*k; i++){
		mb[i] = (double)rand() / (double)(RAND_MAX)*100;
	}	

	if(isprint){printf("=======================================================================\n");
		printf("矩阵A有%d行%d列 ：\n",m,n);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				printf("%.2f  \t",ma[i*n+j]);
			}
			printf("\n");
		}
		printf("矩阵B有%d行%d列 ：\n",n,k);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < k; j++){
				printf("%.2f  \t",mb[i*k+j]);
			}
			printf("\n");
		}
	}
	
	start=clock();
	gemm(ma,mb,mc,m,n,k);	
	end=clock();
	endtime=(double)(end-start)/CLOCKS_PER_SEC;
	if(isprint){			printf("=======================================================================\n");
		printf("矩阵C有%d行%d列 ：\n",m,k);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < k; j++){
				printf("%.2f  \t",mc[i*k+j]);
			}
			printf("\n");
		}
	}
	printf("GEMM通用矩阵乘法已完成，用时：%f ms.\n",endtime*1000);

	__m256d vec_res = _mm256_setzero_pd();
	__m256d vec_1 = _mm256_setzero_pd();
	__m256d vec_2 = _mm256_setzero_pd();
	start=clock();
	//printf("here1\n");
	for (int a = 0; a < m; a++){
		for (int b = 0; b < n; b++){
			//printf("here2\n");
			vec_1 = _mm256_set1_pd(ma[a*n+b]);
			//printf("here3\n");
			for (int c = 0; c < k; c += 4){
			//printf("m=%d n=%d k=%d a=%d b=%d c=%d a*n+b=%d b*k+c=%d a*k+c=%d\n",m,n,k,a,b,c,a*n+b,b*k+c,a*k+c);
			//printf("%p\n",&mb[b*k+c]);
			//printf("here4\n");											
				vec_2 = _mm256_loadu_pd(&mb[b*k+c]);
				//printf("%p\n",&mb[b*k+c]);
				//printf("here5\n");											
				vec_res = _mm256_loadu_pd(&mc[a*k+c]);	
				//printf("here6\n");
				vec_res = _mm256_add_pd(vec_res ,_mm256_mul_pd(vec_1, vec_2));
				//printf("here7\n");
				_mm256_storeu_pd(&mc[a*k+c], vec_res);
				//printf("here8\n");
			}
		}
	}
	end=clock();
	endtime=(double)(end-start)/CLOCKS_PER_SEC;	
	if(isprint){		printf("=======================================================================\n");
		printf("矩阵C有%d行%d列 ：\n",m,k);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < k; j++){
				printf("%.2f  \t",mc[i*k+j]);
			}
			printf("\n");
		}
	}
	printf("AVX优化矩阵乘法已完成，用时：%f ms.\n",endtime*1000);
	delete(ma);delete(mb);delete(mc);
	
	return 0;
}
