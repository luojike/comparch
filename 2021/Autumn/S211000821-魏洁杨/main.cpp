//
//  main.cpp
//  test
//
//  Created by 魏洁杨 on 2021/6/4.
//  Copyright © 2021 魏洁杨. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;

void getRandomMatrix(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = rand() % n;
        }
    }
}

void printMatrix(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void checkMatrix_ijk(int **a, int **b, int **c, int n){
    clock_t startTime, endTime;
    startTime = clock();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    endTime = clock();
    cout<<"ijk - "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

void checkMatrix_ikj(int **a, int **b, int **c, int n){
    clock_t startTime, endTime;
    startTime = clock();
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    endTime = clock();
    cout<<"ikj - "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

void checkMatrix_jik(int **a, int **b, int **c, int n){
    clock_t startTime, endTime;
    startTime = clock();
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    endTime = clock();
    cout<<"jik - "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

void checkMatrix_jki(int **a, int **b, int **c, int n){
    clock_t startTime, endTime;
    startTime = clock();
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    endTime = clock();
    cout<<"jki - "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

void checkMatrix_kij(int **a, int **b, int **c, int n){
    clock_t startTime, endTime;
    startTime = clock();
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    endTime = clock();
    cout<<"kij - "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

void checkMatrix_kji(int **a, int **b, int **c, int n){
    clock_t startTime, endTime;
    startTime = clock();
    for(int k = 0; k < n; k++){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    endTime = clock();
    cout<<"kji - "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
}

void initMatrix(int **a, int **b, int **c, int n){
    for(int i = 0; i < n; i++){
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new int[n];
    }
    
    // 初始化数组
    getRandomMatrix(a, n);
    getRandomMatrix(b, n);
    getRandomMatrix(c, n);
}


int main(int argc, char * argv[]) {
    cout<<"hello"<<endl;
    int NUM = 1000;
    int **a = new int *[NUM];
    int **b = new int *[NUM];
    int **c = new int *[NUM];
    initMatrix(a, b, c, NUM);
    
    cout<<"start check "<<NUM<<endl;
    checkMatrix_ijk(a, b, c, NUM);
    checkMatrix_ikj(a, b, c, NUM);
    checkMatrix_jik(a, b, c, NUM);
    checkMatrix_jki(a, b, c, NUM);
    checkMatrix_kij(a, b, c, NUM);
    checkMatrix_kji(a, b, c, NUM);
    cout<<endl;
    
    NUM = 5000;
    int **aa = new int *[NUM];
    int **bb = new int *[NUM];
    int **cc = new int *[NUM];
    initMatrix(aa, bb, cc, NUM);
 
    cout<<"start check "<<NUM<<endl;
    checkMatrix_ijk(aa, bb, cc, NUM);
    checkMatrix_ikj(aa, bb, cc, NUM);
    checkMatrix_jik(aa, bb, cc, NUM);
    checkMatrix_jki(aa, bb, cc, NUM);
    checkMatrix_kij(aa, bb, cc, NUM);
    checkMatrix_kji(aa, bb, cc, NUM);
    cout<<endl;

    return 0;
}
