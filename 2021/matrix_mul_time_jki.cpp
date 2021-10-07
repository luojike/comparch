#include <iostream>
#include <ctime>
using namespace std;

int n1 = 50;
float a1[50][50];
float b1[50][50];
float c1[50][50];
int n2 = 100;
float a2[100][100];
float b2[100][100];
float c2[100][100];
int n3 = 150;
float a3[150][150];
float b3[150][150];
float c3[150][150];
int n4 = 200;
float a4[200][200];
float b4[200][200];
float c4[200][200];
int n5 = 250;
float a5[250][250];
float b5[250][250];
float c5[250][250];
int n6 = 300;
float a6[300][300];
float b6[300][300];
float c6[300][300];
int n7 = 350;
float a7[350][350];
float b7[350][350];
float c7[350][350];
int n8 = 500;
float a8[500][500];
float b8[500][500];
float c8[500][500];
int n9 = 1000;
float a9[1000][1000];
float b9[1000][1000];
float c9[1000][1000];
int n10 = 1500;
float a10[1500][1500];
float b10[1500][1500];
float c10[1500][1500];
int n11 = 2000;
float a11[2000][2000];
float b11[2000][2000];
float c11[2000][2000];
int n12 = 2500;
float a12[2500][2500];
float b12[2500][2500];
float c12[2500][2500];
float sum = 0.0;

int main(){
	float r = 0;
	clock_t startTime,endTime;
	startTime = clock();//开始计时 
	for(int j=0;j<n1;j++)
	{
		for(int k=0;k<n1;k++)
		{
			r = b1[k][j];
			for(int i=0;i<n1;i++)
			{
				c1[i][j] += a1[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n1<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n2;j++)
	{
		for(int k=0;k<n2;k++)
		{
			r = b2[k][j];
			for(int i=0;i<n2;i++)
			{
				c2[i][j] += a2[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n2<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n3;j++)
	{
		for(int k=0;k<n3;k++)
		{
			r = b3[k][j];
			for(int i=0;i<n3;i++)
			{
				c3[i][j] += a3[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n3<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n4;j++)
	{
		for(int k=0;k<n4;k++)
		{
			r = b4[k][j];
			for(int i=0;i<n4;i++)
			{
				c4[i][j] += a4[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n4<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n5;j++)
	{
		for(int k=0;k<n5;k++)
		{
			r = b5[k][j];
			for(int i=0;i<n5;i++)
			{
				c5[i][j] += a5[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n5<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n6;j++)
	{
		for(int k=0;k<n6;k++)
		{
			r = b6[k][j];
			for(int i=0;i<n6;i++)
			{
				c6[i][j] += a6[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n6<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n7;j++)
	{
		for(int k=0;k<n7;k++)
		{
			r = b7[k][j];
			for(int i=0;i<n7;i++)
			{
				c7[i][j] += a7[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n7<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n8;j++)
	{
		for(int k=0;k<n8;k++)
		{
			r = b8[k][j];
			for(int i=0;i<n8;i++)
			{
				c8[i][j] += a8[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n8<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n9;j++)
	{
		for(int k=0;k<n9;k++)
		{
			r = b9[k][j];
			for(int i=0;i<n9;i++)
			{
				c9[i][j] += a9[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n9<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n10;j++)
	{
		for(int k=0;k<n10;k++)
		{
			r = b10[k][j];
			for(int i=0;i<n10;i++)
			{
				c10[i][j] += a10[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n10<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n11;j++)
	{
		for(int k=0;k<n11;k++)
		{
			r = b11[k][j];
			for(int i=0;i<n11;i++)
			{
				c11[i][j] += a11[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n11<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    startTime = clock();//开始计时 
	for(int j=0;j<n12;j++)
	{
		for(int k=0;k<n12;k++)
		{
			r = b12[k][j];
			for(int i=0;i<n12;i++)
			{
				c12[i][j] += a12[i][k] * r;
			} 
		}
	}
	endTime = clock();//计时结束
    cout << "The run time for jki which num is "<<n12<<" is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    
    
	return 0;
} 
