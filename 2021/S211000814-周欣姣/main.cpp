//
//  main.cpp
//  CA
//
//  Created by Apple on 2021/9/29.
//  Copyright 漏 2021 apple. All rights reserved.
//

#include <iostream>
#include<ctime>
using namespace std;
const int n=2000;
int a[n][n],b[n][n],c[n][n];
void myrandom(){
    for (int i=0;i<n;i++){
         for (int j=0;j<n;j++){
              a[i][j]=rand();
              b[i][j]=rand();
              c[i][j]=0;
        }
    }
}
int main(){
    int i,j,sum,k,r;
    //ijk
    clock_t startTime,endTime;
    startTime = clock();
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            sum = 0.0;
            for (k=0; k<n; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }
    endTime = clock();
    cout<<"ijk: "<< "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
    
    //jik
    startTime = clock();
    for (j=0; j<n; j++) {
        for (i=0; i<n; i++) {
            sum = 0.0;
            for (k=0; k<n; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }
    endTime = clock();
    cout<<"jik: "<< "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
    
    
    //kij
    startTime = clock();
    for (k=0; k<n; k++) {
        for (i=0; i<n; i++) {
            r = a[i][k];
            for (j=0; j<n; j++)
                c[i][j] += r * b[k][j];
        }
    }
    endTime = clock();
    cout<<"kij: "<< "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
    
    //ikj
    startTime = clock();
    for (i=0; i<n; i++) {
        for (k=0; k<n; k++) {
            r = a[i][k];
            for (j=0; j<n; j++)
                c[i][j] += r * b[k][j] ;
        }
    }
    endTime = clock();
    cout<<"ikj: "<< "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
    
    
    
    //jki
    startTime = clock();
    for (j=0; j<n; j++) {
        for (k=0; k<n; k++) {
            r = b[k][j];
            for (i=0; i<n; i++)
                c[i][j] += a[i][k] * r;
        }
    }
    endTime = clock();
    cout<<"jki: "<< "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
    
    
    
    //kji
    startTime = clock();
    for (k=0; k<n; k++) {
        for (j=0; j<n; j++) {
            for (i=0; i<n; i++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    endTime = clock();
    cout<<"kji: "<< "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" <<endl;
}
