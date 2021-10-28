/*矩阵乘法*/
#include <iostream>
#include <cstdlib> 
#include <time.h> 
#define N 1000

using namespace std;
int matrix1[N][N];
int matrix2[N][N];
int matrix_multiple[N][N];

int main()
{
	time_t start,end;
	int i,j,k;
	/*生成1-100之间的随机数，初始化矩阵*/
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			matrix1[i][j]=1+rand()%100;
			matrix2[i][j]=1+rand()%100;
			matrix_multiple[i][j]=0;
		}
	}
	/*ijk*/
	start=clock();
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				matrix_multiple[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	end=clock();
	cout<<"Matrix multiply (ijk) runtime is: "<<(end-start)/1000.0<<"sec"<<endl;
	/*ikj*/
	start=clock();
	for(i=0;i<N;i++)
	{
		for(k=0;k<N;k++)
		{
			for(j=0;j<N;j++)
			{
				matrix_multiple[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	end=clock();
	cout<<"Matrix multiply (ikj) runtime is: "<<(end-start)/1000.0<<"sec"<<endl;
	/*jik*/
	start=clock();
	for(j=0;j<N;j++)
	{
		for(i=0;i<N;i++)
		{
			for(k=0;k<N;k++)
			{
				matrix_multiple[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	end=clock();
	cout<<"Matrix multiply (jik) runtime is: "<<(end-start)/1000.0<<"sec"<<endl;
	/*jki*/
	start=clock();
	for(j=0;j<N;j++)
	{
		for(k=0;k<N;k++)
		{
			for(i=0;i<N;i++)
			{
				matrix_multiple[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	end=clock();
	cout<<"Matrix multiply (jki) runtime is: "<<(end-start)/1000.0<<"sec"<<endl;
	/*kij*/
	start=clock();
	for(k=0;k<N;k++)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				matrix_multiple[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	end=clock();
	cout<<"Matrix multiply (kij) runtime is: "<<(end-start)/1000.0<<"sec"<<endl;
	/*kji*/
	start=clock();
	for(k=0;k<N;k++)
	{
		for(j=0;j<N;j++)
		{
			for(i=0;i<N;i++)
			{
				matrix_multiple[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}
	end=clock();
	cout<<"Matrix multiply (kji) runtime is: "<<(end-start)/1000.0<<"sec"<<endl;
	return 0;
}
