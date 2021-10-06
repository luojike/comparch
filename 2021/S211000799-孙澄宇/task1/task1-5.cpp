#include<iostream>
#include<stdlib.h>
#include<ctime>
int ma[5000][5000],mb[5000][5000],mc[5000][5000];
int main(){
	int isprint=0;
	clock_t start,end;
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	srand((unsigned)time(0));
	start=clock();
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			ma[i][j] = rand()%100;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < k; j++){
			mb[i][j] = rand()%100;
		}
	}
	for (int c = 0; c < k; c++) {
  		for (int a = 0; a < m; a++) {
    		for (int b = 0; b < n; b++) {
     			mc[a][c] += ma[a][b] * mb[b][c];
    		}
  		}
	}
	end=clock();
	double wholetime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("The matrix operation time is %f s\n",wholetime);
	if(isprint){
		printf("=======================================================================\n");
		printf("矩阵A有%d行%d列 ：\n",m,n);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				printf("%d  \t",ma[i][j]);
			}
			printf("\n");
		}
		printf("矩阵B有%d行%d列 ：\n",n,k);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < k; j++){
				printf("%d  \t",mb[i][j]);
			}
			printf("\n");
		}
		printf("矩阵C有%d行%d列 ：\n",m,k);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < k; j++){
				printf("%d  \t",mc[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
} 
