/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstdlib> 
#include <time.h> 

using namespace std;
int matA[5000][5000];
int matB[5000][5000];
mat_multi[][];
int main()
{
	time_t start,end;
	int i,j,k;
	
	start=clock();
	for(i=0;k<5000;i++)
	{
		for(k=0;j<5000;j++)
		{
			for(j=0;i<5000;k++)
			{
				mat_multi[i][j]+=matA[i][k]*matB[k][j];
			}
		}
	}
	end=clock();
	cout<<"Mat Multiplication time is : "<<(end-start)<<"sec"<<endl;
	return 0;
}