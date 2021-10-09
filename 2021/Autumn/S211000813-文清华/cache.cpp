#include <iostream>
#include <ctime>
#include <fstream>
#define n 5000
using namespace std;

int A[n][n], B[n][n], C[n][n];

void ijk(int A[n][n], int B[n][n], int C[n][n])
{
    int i, j, k;
    int sum;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum = 0;
            for (k = 0; k < n; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] += sum;
        }
    }
}

void jik(int A[n][n], int B[n][n], int C[n][n])
{
    int i, j, k;
    int sum;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (k = 0; k < n; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] += sum;
        }
    }
}

void jki(int A[n][n], int B[n][n], int C[n][n])
{
    int i, j, k;
    int r;
    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            r = B[k][j];
            for (i = 0; i < n; i++)
            {
                C[i][j] += A[i][k] * r;
            }
        }
    }
}

void kji(int A[n][n], int B[n][n], int C[n][n])
{
    int i, j, k;
    int r;
    for (k = 0; k < n; k++)
    {
        for (j = 0; j < n; j++)
        {
            r = B[k][j];
            for (i = 0; i < n; i++)
            {
                C[i][j] += A[i][k] * r;
            }
        }
    }
}

void kij(int A[n][n], int B[n][n], int C[n][n])
{
    int i, j, k;
    int r;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            r = A[i][k];
            for (j = 0; j < n; j++)
            {
                C[i][j] += r * B[k][j];
            }
        }
    }
}

void ikj(int A[n][n], int B[n][n], int C[n][n])
{
    int i, j, k;
    int r;
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < n; k++)
        {
            r = A[i][k];
            for (j = 0; j < n; j++)
            {
                C[i][j] += A[i][k] * r;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ifstream inputfile1("a.txt", ios::in);
    ifstream inputfile2("b.txt", ios::in);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            inputfile1 >> A[i][j];
            inputfile2 >> B[i][j];
        }
    }
    inputfile1.close();
    inputfile2.close();
    ofstream outputfile("result.txt", ios::out | ios::app);
    clock_t start, end;

    start = clock();
    ijk(A, B, C);
    end = clock();
    outputfile << "ijk_time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    start = clock();
    jik(A, B, C);
    end = clock();
    outputfile << "jik_time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    start = clock();
    jki(A, B, C);
    end = clock();
    outputfile << "jki_time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    start = clock();
    kji(A, B, C);
    end = clock();
    outputfile << "kji_time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    start = clock();
    kij(A, B, C);
    end = clock();
    outputfile << "kij_time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    start = clock();
    ikj(A, B, C);
    end = clock();
    outputfile << "ikj_time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;
    
    outputfile.close();
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // } 
    return 0;
}
