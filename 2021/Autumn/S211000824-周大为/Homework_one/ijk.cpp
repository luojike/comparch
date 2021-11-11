#include <iostream>
#include <cstdlib>
#include "time.h"
using namespace std;

const int n = 700;
double a[n][n], b[n][n], c[n][n];

int main() {
	clock_t start_time, end_time;

	//初始化数组a
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 100 + rand() % 100;
		}
	}

	//初始化数组b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j] + rand() % 10;
		}
	}

	double sum, tol_time;
	start_time = clock(); //开始计时

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0.0;
			for (int k = 0; k < n; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	}

	end_time = clock(); //结束计时
	tol_time = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "This is ijk speaks time :" << tol_time << endl;
	return 0;
}
