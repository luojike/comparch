#include<iostream>
#include<vector>
#include <windows.h>
#include <fstream>
#include <time.h> 
using namespace std;

int n=2000; 
int i=0,j=0,k=0;
int temp;

//计算ijk的函数 
vector<vector<int> >  multi_ijk(vector<vector<int> > &ve1, vector<vector<int> > &ve2,int n){
	vector<vector<int> > ve(n,vector<int>(n,0) ) ;//定义新数组用于保存计算结果	
	for (i = 0; i < n; ++i)
	for (j = 0; j < n; ++j){
		temp = 0;
		for (k = 0; k < n; ++k){
			
			temp += ve1[i][k] * ve2[k][j];
		}
		ve[i][j] = temp;
	}
	return ve;
}

//计算kij的函数 
vector<vector<int> >  multi_kij(vector<vector<int> > &ve1, vector<vector<int> > &ve2,int n){
	vector<vector<int> > ve(n,vector<int>(n,0) ) ;//定义新数组用于保存计算结果	
	for (k = 0; k < n; ++k)
	for (i = 0; i < n; ++i){
		temp = ve1[i][k];
		for ( j = 0; j < n; ++j){
			
			ve[i][j] += temp * ve2[k][j];
		}
	}
	return ve;
}

//计算jki的函数 
vector<vector<int> >  multi_jki(vector<vector<int> > &ve1, vector<vector<int> > &ve2,int n){
	vector<vector<int> > ve(n,vector<int>(n,0) ) ;//定义新数组用于保存计算结果	
	for (j = 0; j < n; ++j)
	for (k = 0; k < n; ++k){
		temp = ve2[k][j];
		for (i = 0; i < n; ++i){
			
			ve[i][j]+= ve1[i][k]*temp;
		}
	}
	return ve;
}

//计算ikj的函数 
vector<vector<int> >  multi_ikj(vector<vector<int> > &ve1, vector<vector<int> > &ve2,int n){
	vector<vector<int> > ve(n,vector<int>(n,0) ) ;//定义新数组用于保存计算结果	
	for (i = 0; i < n; ++i)
	for (k = 0; k < n; ++k){
		temp = ve1[i][k];
		for (j = 0; j < n; ++j){
			
			ve[i][j] += temp *ve2[k][j];
		}
	}
	return ve;
}

//计算jik的函数 
vector<vector<int> >  multi_jik(vector<vector<int> > &ve1, vector<vector<int> > &ve2,int n){
	vector<vector<int> > ve(n,vector<int>(n,0) ) ;//定义新数组用于保存计算结果	
	for (j = 0; j < n; ++j)
	for (i = 0; i < n; ++i){
		temp = 0;
		for (k = 0; k < n; ++k){
			
			temp += ve1[i][k]*ve2[k][j];
		}
		ve[i][j] = temp;
	}
	return ve;
}

//计算kji的函数 
vector<vector<int> >  multi_kji(vector<vector<int> > &ve1, vector<vector<int> > &ve2,int n){
	vector<vector<int> > ve(n,vector<int>(n,0) ) ;//定义新数组用于保存计算结果	
	for (k = 0; k < n; ++k)
	for (j = 0; j < n; ++j){
		temp=ve2[k][j];
		for (i = 0; i < n; ++i){
				ve[i][j]+=ve1[i][k]*temp;
		}
	}
	return ve;
}

int main(){
	//初始化矩阵 
	vector<vector<int> >  ve1(n, vector<int>(n));
	for (i = 0; i < n;++i)
	for (j = 0; j < n; ++j)
		ve1[i][j]=rand()%10;
	vector<vector<int> >  ve2(n, vector<int>(n));
	for (i = 0; i < n; ++i)
	for (j = 0; j < n; ++j)
		ve2[i][j]=rand()%10;
	vector<vector<int> > ve; 
	
	cout<<"========孙旻聿-S211000805========"<<endl;
	
	//定义开始结束时间 
	DWORD Start, End;
	
	//ijk 
	Start = GetTickCount();
	ve = multi_ijk(ve1, ve2,n);
	End = GetTickCount();
	cout<<"【ijk】: "<<End-Start<<"ms"<<endl;

	//kij
	Start = GetTickCount();
	ve = multi_kij(ve1, ve2,n);
	End = GetTickCount();
	cout<<"【kij】: "<<End-Start<<"ms"<<endl;
	
	//jki
	Start = GetTickCount();
	ve = multi_jki(ve1, ve2,n);
	End = GetTickCount();
	cout<<"【jki】: "<<End-Start<<"ms"<<endl;
	
	//ikj
	Start = GetTickCount();
	ve = multi_ikj(ve1, ve2,n);
	End = GetTickCount();
	cout<<"【ikj】: "<<End-Start<<"ms"<<endl;
	
	//jik
	Start = GetTickCount();
	ve = multi_jik(ve1, ve2,n);
	End = GetTickCount();
	cout<<"【jik】: "<<End-Start<<"ms"<<endl;
	
	//kji
	Start = GetTickCount();
	ve = multi_kji(ve1, ve2,n);
	End = GetTickCount();
	cout<<"【kji】: "<<End-Start<<"ms"<<endl;
	
	return 0;
}
