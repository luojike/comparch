#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

#define n 1000
double a[n][n],b[n][n],c[n][n];


void valueset()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            a[i][j] = j;
            b[i][j] = j;
            c[i][j] = j;
        }
}

double time_of_ijk(){
    double sum;
    clock_t startTime,endTime;
    startTime = clock();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            sum = 0.0;
            for (int k=0; k<n; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }
    endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

double time_of_jik(){
    double sum;
    clock_t startTime,endTime;
    startTime = clock();
    for (int j=0; j<n; j++) {
        for (int i=0; i<n; i++) {
            sum = 0.0;
            for (int k=0; k<n; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }
    endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

double time_of_kij(){
    clock_t startTime,endTime;
    int r;
    startTime = clock();
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            r = a[i][k];
            for (int j=0; j<n; j++)
                c[i][j] += r * b[k][j];
        }
    }
    endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

double time_of_ikj(){
    clock_t startTime,endTime;
    int r;
    startTime = clock();
    for (int i=0; i<n; i++) {
        for (int k=0; k<n; k++) {
            r = a[i][k];
            for (int j=0; j<n; j++)
                c[i][j] += r * b[k][j];
        }
    }
    endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

double time_of_jki(){
    clock_t startTime,endTime;
    int r;
    startTime = clock();
    for (int j=0; j<n; j++) {
        for (int k=0; k<n; k++) {
            r = b[k][j];
            for (int i=0; i<n; i++)
                c[i][j] += a[i][k] * r;
        }
    }
    endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

double time_of_kji(){
    clock_t startTime,endTime;
    int r;
    startTime = clock();
    for (int k=0; k<n; k++) {
        for (int j=0; j<n; j++) {
            r = b[k][j];
            for (int i=0; i<n; i++)
                c[i][j] += a[i][k] * r;
        }
    }
    endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

void display(){

    cout<< "for the size of "<< n << ":" << endl;
    cout<< fixed << setprecision(3) << endl;

    cout << "The run time of ijk is:" << time_of_ijk() << "s" << endl;
    cout << "The run time of jik is:" << time_of_jik() << "s" << endl;

    cout << "The run time of kij is:" << time_of_kij() << "s" << endl;
    cout << "The run time of ikj is:" << time_of_ikj() << "s" << endl;

    cout << "The run time of jki is:" << time_of_jki() << "s" << endl;
    cout << "The run time of kji is:" << time_of_kji() << "s" << endl;
}
int main()
{
    valueset();
    display();
    return 0;
}

