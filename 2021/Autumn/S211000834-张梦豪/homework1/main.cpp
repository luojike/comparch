#include <iostream>
#include <time.h>
#include <assert.h>
#include <random>
using namespace std;

const int MAXSIZE = 2000;

double (*A)[MAXSIZE], (*B)[MAXSIZE], (*C)[MAXSIZE];
double sum = 0;
double r = 0;

// random test
void random_num()
{
    default_random_engine e;
    uniform_real_distribution<double> u(1.0, 100.0);
    for (int i = 0; i < 20; i++)
    {
        printf("%lf\n", u(e));
    }
}

// C++ type -- create a random 2-D Arrary
auto GenerateRandomArray(int n, double rangeL, double rangeR)
{
    assert(rangeL <= rangeR);
    auto arr = new double[MAXSIZE][MAXSIZE];
    default_random_engine e(time(NULL));
    uniform_real_distribution<double> u(rangeL, rangeR);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = u(e);
        }
    }
    return arr;
}

// C type -- create a random 2-D Arrary
auto GenerateRandomArray(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);
    auto arr = new double[MAXSIZE][MAXSIZE];
    srand(time(NULL)); // �������
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
    }
    return arr;
}

// test random Arrary
void test01()
{
    A = GenerateRandomArray(MAXSIZE, 1.0, 100.0);
    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
        {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}

// different order by i, j, k
void Marix_ijk()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int j = 0; j < MAXSIZE; j++)
        {
            sum = 0;
            for (int k = 0; k < MAXSIZE; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void Marix_jik()
{
    for (int j = 0; j < MAXSIZE; j++)
    {
        for (int i = 0; i < MAXSIZE; i++)
        {
            sum = 0;
            for (int k = 0; k < MAXSIZE; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void Matrix_kij()
{
    for (int k = 0; k < MAXSIZE; k++)
    {
        for (int i = 0; i < MAXSIZE; i++)
        {
            r = A[i][k];
            for (int j = 0; j < MAXSIZE; j++)
            {
                C[i][j] += r * B[k][j];
            }
        }
    }
}

void Matrix_ikj()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        for (int k = 0; k < MAXSIZE; k++)
        {
            r = A[i][k];
            for (int j = 0; j < MAXSIZE; j++)
            {
                C[i][j] += r * B[k][j];
            }
        }
    }
}

void Matrix_jki()
{
    for (int j = 0; j < MAXSIZE; j++)
    {
        for (int k = 0; k < MAXSIZE; k++)
        {
            r = B[k][j];
            for (int i = 0; i < MAXSIZE; i++)
            {
                C[i][j] += r * A[i][k];
            }
        }
    }
}

void Matrix_kji()
{
    for (int k = 0; k < MAXSIZE; k++)
    {
        for (int j = 0; j < MAXSIZE; j++)
        {
            r = B[k][j];
            for (int i = 0; i < MAXSIZE; i++)
            {
                C[i][j] += r * A[i][k];
            }
        }
    }
}

// calculate the time of function
void CalTime(void (*f)())
{
    clock_t start = clock();
    f();
    clock_t end = clock();
    printf("time = [%.3lf]s\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main()
{
    // create Arrary A * B = C
    A = GenerateRandomArray(MAXSIZE, 1.0, 100.0);
    B = GenerateRandomArray(MAXSIZE, 1.0, 100.0);
    C = GenerateRandomArray(MAXSIZE, 0, 0);

    // calculate the time
    CalTime(Marix_ijk);
    CalTime(Marix_jik);
    CalTime(Matrix_kij);
    CalTime(Matrix_ikj);
    CalTime(Matrix_jki);
    CalTime(Matrix_kji);

    system("pause");
    return 0;
}
