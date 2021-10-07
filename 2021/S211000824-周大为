#include <iostream>
#include <cstdlib>
#include "time.h"
using namespace std;
const int n = 700;
double a[n][n], b[n][n], c[n][n];

int main() {
	clock_t start_time, end_time;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 100 + rand() % 100;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j] + rand() % 10;
		}
	}

	double sum, tol_time;
	start_time = clock();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0.0;
			for (int k = 0; k < n; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	}
	end_time = clock();

	tol_time = double(end_time - start_time) / CLOCKS_PER_SEC;

	cout << tol_time << endl;
	return 0;

}
