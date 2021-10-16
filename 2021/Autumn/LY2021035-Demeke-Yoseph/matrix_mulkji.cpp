#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
const int N = 2000;
int a[N][N];
int b[N][N];
long long c[N][N];



// i-j-k
void fun1(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){

            for(int k = 0; k < N; k++){
                c[i][j] += a[i][k] * b[k][j];
            }


        }
    }
}

// i-k-j
void fun2(){
    for(int i = 0 ; i < N ; i++){
        for(int k = 0 ; k < N ; k++){
            for(int j = 0; j < N; j++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// j-i-k
void fun3(){
    for(int j = 0; j < N; j++){
        for(int i = 0 ; i < N ; i++){
            for(int k = 0; k < N; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


int main() {
    fill(a[0],a[0] + N * N,1);
    fill(b[0],b[0] + N * N,1);
    fill(c[0],c[0] + N * N,0);;
    clock_t start_time,end_time;

    // i-j-k
    start_time = clock();
    fun1();
    end_time = clock();
    cout << "The i-j-k run time is: " <<
    (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

    // i-k-j
    start_time = clock();
    fun2();
    end_time = clock();
    cout << "The i-k-j run time is: " <<
         (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

    // j-i-k
    start_time = clock();
    fun3();
    end_time = clock();
    cout << "The j-i-k run time is: " <<
         (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;


    return 0;
}