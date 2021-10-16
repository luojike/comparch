#include<iostream>
#include<stdio.h>
#include<time.h>
#include<cmath>
using namespace std;


#define ROW 1500;
#define COL 1500;

void matrixRand(int** A,int rows,int cols) {
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = rand() % 100; //取[0-100)之间随机数
        }
    }

}
void ijk(int **A,int **B,int row,int col,int** res) {

    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            for (int k = 0; k < col; k++) {
          
                res[i][j] += A[i][k] * B[k][j];
            }
}
void ikj(int** A, int** B, int row, int col, int** res) {

    for (int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            for (int j = 0; j < row; j++) {
               
                res[i][j] += A[i][k] * B[k][j];
            }
}
void jik(int** A, int** B, int row, int col, int** res) {

    for (int j = 0; j < row; j++)
        for (int i = 0; i < row; i++)
            for (int k = 0; k < col; k++) {
              
                res[i][j] += A[i][k] * B[k][j];
            }
}
void jki(int** A, int** B, int row, int col, int** res) {
  
    for (int j = 0; j < row; j++)
            for (int k = 0; k < col; k++)
                for (int i = 0; i < row; i++) {
                
                    res[i][j] += A[i][k] * B[k][j];
                }
}
void kij(int** A, int** B, int row, int col, int** res) {
    for (int k = 0; k < col; k++)
        for (int i = 0; i < row; i++)
            for (int j = 0; j < row; j++) {
                
                res[i][j] += A[i][k] * B[k][j];
            }
}
void kji(int** A, int** B, int row, int col, int** res) {
        
            for (int k = 0; k < col; k++)
                for (int j = 0; j < row; j++)
                    for (int i = 0; i < row; i++) {
 
                        res[i][j] += A[i][k] * B[k][j];
                    }
}

int main() {

    clock_t start, end;
    double endTime;
    int num_rows = ROW;
    int num_cols = COL;
    int** res = new int* [num_rows];
    int** A = new int* [num_rows];
    for (int i = 0; i < num_rows; i++) {
        res[i] = new int[num_cols];
        A[i] = new int[num_cols];
        for (int j = 0; j < num_cols; j++) {
            res[i][j] = 0;
            A[i][j] = 0;
        }
    }

    matrixRand(A, num_rows, num_cols);

    int** B = A;

    start = clock();
    ijk(A,B,num_rows,num_cols,res);
    end = clock();
    endTime = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "ijk Total time : " << endTime << " s" << endl;

    start = clock();
    ikj(A, B, num_rows, num_cols, res);
    end = clock();
    endTime = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "ikj Total time : " << endTime << " s" << endl;

    start = clock();
    jki(A, B, num_rows, num_cols, res);
    end = clock();
    endTime = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "jki Total time : " << endTime << " s" << endl;

    start = clock();
    jik(A, B, num_rows, num_cols, res);
    end = clock();
    endTime = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "jik Total time : " << endTime << " s" << endl;

    start = clock();
    kij(A, B, num_rows, num_cols, res);
    end = clock();
    endTime = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "kij Total time : " << endTime << " s" << endl;

    start = clock();
    kji(A, B, num_rows, num_cols, res);
    end = clock();
    endTime = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "kji Total time : " << endTime << " s" << endl;


	return 0;
}
