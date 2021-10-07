#include <iostream>
#include <ctime>
#include <windows.h>
#define n 2000
using namespace std;
int seed=11;
int a[n][n],b[n][n],c[n][n]={0};
void initial()
{
	int randomseed;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			randomseed=rand()%seed;
			a[i][j]=randomseed;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			randomseed=rand()%seed;
			b[i][j]=randomseed;
		}
	}
}
void Multiply_ijk(int a[n][n],int b[n][n]) {
	 int sum;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum=0;
			for(int k=0;k<n;k++)
			sum+=a[i][k]*b[k][j];
			
			c[i][j]=sum;
		}
	}
}

void Multiply_kij(int a[n][n],int b[n][n]){
	int r;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			r=a[i][k];
			for(int j=0;j<n;j++)
			c[i][j]+=r*b[k][j];
		}
	}
}


void Multiply_jki(int a[n][n],int b[n][n]){
	long long int r;
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			r=b[k][j];
			for(int i=0;i<n;i++)
			c[i][j]+=a[i][k]*r;
		}
	}
}

int main()
{
	DWORD time_start,time_end;
	initial();
	time_start=GetTickCount();
	Multiply_ijk(a,b);
	time_end=GetTickCount();
	cout<<"ijk所需时间为： "<<(time_end-time_start)<<"ms\n";
	
	time_start=GetTickCount();
	Multiply_kij(a,b);
	time_end=GetTickCount();
	cout<<"kij所需时间为： "<<(time_end-time_start)<<"ms\n";
	
	time_start=GetTickCount();
	Multiply_jki(a,b);
	time_end=GetTickCount();
	cout<<"jki所需时间为： "<<(time_end-time_start)<<"ms\n";
	return 0;
}
