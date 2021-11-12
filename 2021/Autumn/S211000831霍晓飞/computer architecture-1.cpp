#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h> 
using namespace std;
const int n=2000;
int a[n][n],b[n][n],c[n][n];
int copya[n][n],copyb[n][n];
void random(){
	srand(time(0));   // 随机种子
	for (int i=0;i<n;i++){
	 	for (int j=0;j<n;j++){
		  	a[i][j]=rand()%10;   //产生随机数
		  	b[i][j]=rand()%10;
		  	c[i][j]=0;
		}
	}
	ofstream outfile;
	outfile.open("myfile.txt");
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		  	outfile<<a[i][j]<<' ';   //产生随机数
		  	copya[i][j]=a[i][j];
		}
		outfile<<endl;
	}
	outfile<<endl;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
		  	outfile<<b[i][j]<<' ';   //产生随机数
		  	copyb[i][j]=b[i][j];
		}
		outfile<<endl;
	}
	outfile.close();
}
void reset(){
	for (int i=0;i<n;i++){
	 	for (int j=0;j<n;j++){
		  	a[i][j]=copya[i][j];   //产生随机数
		  	b[i][j]=copyb[i][j];
		  	c[i][j]=0;
		}
	}
}
int main(){
	int i,j,sum,k,r;
	random();
	//ijk
	DWORD Start, End;
	Start = GetTickCount();
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			sum = 0.0;
			for (k=0; k<n; k++) 
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	}
	End = GetTickCount();
	cout<<"ijk: "<<End-Start<<"ms"<<endl;
	
	
	//kij
	reset();
	Start = GetTickCount();
	for (k=0; k<n; k++) {
		for (i=0; i<n; i++) {
			r = a[i][k];
			for (j=0; j<n; j++)
				c[i][j] += r * b[k][j];
		} 
	}
	End = GetTickCount();
	cout<<"kij: "<<End-Start<<"ms"<<endl;
	
	
	//jki
	reset();
	Start = GetTickCount();
	for (j=0; j<n; j++) {
		for (k=0; k<n; k++) {
			r = b[k][j];
			for (i=0; i<n; i++)
				c[i][j] += a[i][k] * r; 
		} 
	}
	End = GetTickCount();
	cout<<"jki: "<<End-Start<<"ms"<<endl;
	
	
	//ikj
	reset();
	Start = GetTickCount();
	for (i=0; i<n; i++) {
		for (k=0; k<n; k++) {
			r = a[i][k];
			for (j=0; j<n; j++)
				c[i][j] += r * b[k][j] ; 
		} 
	} 
	End = GetTickCount();
	cout<<"ikj: "<<End-Start<<"ms"<<endl;
	
	
	//jik
	reset();
	Start = GetTickCount();
	for (j=0; j<n; j++) {
		for (i=0; i<n; i++) {
			sum = 0.0;
			for (k=0; k<n; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum; 
		} 
	} 
	End = GetTickCount();
	cout<<"jik: "<<End-Start<<"ms"<<endl;
	
	
	//kji
	reset();
	Start = GetTickCount();
	for (k=0; k<n; k++) {
		for (j=0; j<n; j++) {
			for (i=0; i<n; i++)
				c[i][j] += a[i][k] * b[k][j]; 
		} 
	} 
	End = GetTickCount();
	cout<<"kji: "<<End-Start<<"ms"<<endl;
} 
