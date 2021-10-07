#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
const int maxn = 10005;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
void data_maker()
{
    for(int i = 0; i < maxn; i++)
    {
        for(int j = 0; j < maxn; j++)
        {
            a[i][j] = 1;
            b[i][j] = 1;
        }
    }
    return;
}
void c_clear(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c[i][j] = 0;
        }
    }
    return;
}
double run_time(int opt, int n)
{
    int sum,r;
    int i,j,k;
    clock_t start_time, end_time;
    double run_t;
    c_clear(n);
    switch (opt)
        {
            case 1:     // for case ijk&jik
            {
                start_time = clock();
                for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                    {
                        sum = 0;
                        for(k = 0; k < n; k++)
                        {
                            sum += a[i][k]*b[k][j];
                        }
                        c[i][j] = sum;
                    }
                }
                end_time = clock();
                run_t = (double)(end_time - start_time)*1000.0/CLOCKS_PER_SEC;
                break;
            }
            case 2:     // for case kij&ikj
            {
                start_time = clock();
                for(k = 0; k < n; k++)
                {
                    for(i = 0; i < n; i++)
                    {
                        r = a[i][k];
                        for(j = 0; j < n; j++)
                        {
                            c[i][j] += r*b[k][j];
                        }
                    }
                }
                end_time = clock();
                run_t = (double)(end_time - start_time)*1000.0/CLOCKS_PER_SEC;
                break;
            }
            case 3:     // for case jki&kji
            {
                start_time = clock();
                for(j = 0; j < n; j++)
                {
                    for(k = 0; k < n; k++)
                    {
                        r = b[k][k];
                        for(i = 0; i < n; i++)
                        {
                            c[i][j] += a[i][k]*r;
                        }
                    }
                }
                end_time = clock();
                run_t = (double)(end_time - start_time)*1000.0/CLOCKS_PER_SEC;
                break;
            }
            default:
            {
                printf("Mistake with opt.\n");
                break;
            }
        }
    return run_t;
}
void result_display(int n)
{
    printf("For n = %d, results are as follow:\n",n);
    printf("    for case ijk&jik , running time is %f ms.\n",run_time(1, n));
    printf("    for case kij&ikj , running time is %f ms.\n",run_time(2, n));
    printf("    for case jki&kji , running time is %f ms.\n",run_time(3, n));
    printf("\n");
    return;
}
int main()
{
    //freopen("output.txt","w",stdout);
    for(int i = 100; i <= 1000; i+=100)
        result_display(i);
    return 0;
}
