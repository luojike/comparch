#include<iostream>
#include <cstdlib>
#include <ctime> 
#define n 2000
#define _for(i,j,k) for(int i=j;i<k;i++)
#define for_(i,j,k)	for(int i=k-1;i>=j;i--)
using namespace std;
int a[n][n];
int b[n][n];
int c[n][n];
int main()
{
	int start,end;
	srand((int)time(0));  // 产生随机种子
    _for(i,0,n)
    _for(j,0,n)
    	{
    	a[i][j]=rand()%20;
		b[i][j]=rand()%20;	
		}
		
	start=clock();	
	_for(i,0,n)	
	_for(j,0,n)
	_for(k,0,n)
	c[i][j]+=a[i][k]*b[k][j];
	end=clock();
	
	cout<<"(ijk) time is: "<<(end-start)/1000.0<<"sec"<<endl;
	
	start=clock();
	_for(i,0,n)	
	_for(k,0,n)
	_for(j,0,n)
	c[i][j]+=a[i][k]*b[k][j];
	end=clock();
	cout<<"(ikj) time is: "<<(end-start)/1000.0<<"sec"<<endl;
	
	start=clock();
	_for(j,0,n)
	_for(i,0,n)	
	_for(k,0,n)
	c[i][j]+=a[i][k]*b[k][j];
	end=clock();
	cout<<"(jik) time is: "<<(end-start)/1000.0<<"sec"<<endl;
	
	start=clock();
	_for(j,0,n)	
	_for(k,0,n)
	_for(i,0,n)
	c[i][j]+=a[i][k]*b[k][j];
	end=clock();
	cout<<"(jki) time is: "<<(end-start)/1000.0<<"sec"<<endl;

	start=clock();
	_for(k,0,n)
	_for(i,0,n)	
	_for(j,0,n)
	c[i][j]+=a[i][k]*b[k][j];
	end=clock();
	cout<<"(kij) time is: "<<(end-start)/1000.0<<"sec"<<endl;
	
	start=clock();
	_for(k,0,n)
	_for(j,0,n)	
	_for(i,0,n)
	c[i][j]+=a[i][k]*b[k][j];
	end=clock();
	cout<<"(kji) time is: "<<(end-start)/1000.0<<"sec";
	
	return 0;
}
