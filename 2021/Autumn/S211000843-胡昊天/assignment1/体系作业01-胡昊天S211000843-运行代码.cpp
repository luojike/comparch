#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;

const int n=2000;
int h,l,i,j,k,r;
int a[n][n],b[n][n],c[n][n];

int time() {
	for(h=0; h<n; h++) {
		for(l=0; l<n; l++) {
			a[h][l]=rand()%10;
			b[h][l]=rand()%10;
			c[i][j]=0;
		}
	}
	return 0; 
}

int main() {
	double sum;
	clock_t startTime,endTime;
	
	//i-j-k
	time();
	startTime = clock();//计时开始
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			sum = 0.0;
			for(k=0; k<n; k++) {
				sum+=a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	}
	endTime = clock();//计时结束

	cout<<"i-j-k Time:"<<endTime-startTime<<endl;
	
	//k-i-j
	time();
	startTime = clock();//计时开始
	for(k=0; k<n; k++) {
		for(i=0; i<n; i++) {
			r = a[i][k];
			for(j=0; j<n; j++) {
				c[i][j] += r*b[k][j];
			}	
		}
	}
	endTime = clock();//计时结束

	cout<<"k-i-j Time:"<<endTime-startTime<<endl;

	//j-k-i
	time();
	startTime = clock();//计时开始
	for(j=0; j<n; j++) {
		for(k=0; k<n; k++) {
			r = b[k][j];
			for(i=0; i<n; i++) {
				c[i][j] += a[i][k]*r;
			}	
		}
	}
	endTime = clock();//计时结束

	cout<<"j-k-i Time:"<<endTime-startTime<<endl;
	
	//i-k-j
	time();
	startTime = clock();//计时开始
	for (i=0; i<n; i++) {
		for (k=0; k<n; k++) {
			r = a[i][k];
			for (j=0; j<n; j++)
				c[i][j] += r * b[k][j] ; 
		} 
	} 
	endTime = clock();
	cout<<"i-k-j Time:"<<endTime-startTime<<endl;
	
	
	//jik
	time();
	startTime = clock();//计时开始
	for (j=0; j<n; j++) {
		for (i=0; i<n; i++) {
			sum = 0.0;
			for (k=0; k<n; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum; 
		} 
	} 
	endTime = clock();
	cout<<"j-i-k Time:"<<endTime-startTime<<endl;
	
	
	//kji
	time();
	startTime = clock();//计时开始
	for (k=0; k<n; k++) {
		for (j=0; j<n; j++) {
			for (i=0; i<n; i++)
				c[i][j] += a[i][k] * b[k][j]; 
		} 
	} 
	endTime = clock();
	cout<<"k-j-i Time:"<<endTime-startTime<<endl;
	

	return 0;
}
