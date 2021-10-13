Assignment No:01
ALI MD YOUSUF
LB2021036
.....................

#include<iostream>
#include<cstring>
#include<Windows.h>
constexpr auto MAT_SIZE = 5000;;
using namespace std;

int main() {
	int (*mat)[MAT_SIZE] = new int[MAT_SIZE][MAT_SIZE];
	int (*result)[MAT_SIZE] = new int[MAT_SIZE][MAT_SIZE];
	memset(mat, -1, MAT_SIZE * MAT_SIZE * sizeof(int));
	memset(result, 0, MAT_SIZE * MAT_SIZE * sizeof(int));
	LARGE_INTEGER t1, t2, tc;
	QueryPerformanceFrequency(&tc);
	// funtion 1
	QueryPerformanceCounter(&t1);
	for (size_t i = 0; i < MAT_SIZE; i++)
	{
		for (size_t j = 0; j < MAT_SIZE; j++) {
			for (size_t k = 0; k < MAT_SIZE; k++)
			{
				result[i][j] += mat[i][k] * mat[k][j];
			}
		}
	}
	QueryPerformanceCounter(&t2);
	cout << "time1 = " << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;  // 71.6786

	// function 2
	memset(result, 0, MAT_SIZE * MAT_SIZE * sizeof(int));
	QueryPerformanceCounter(&t1);
	for (size_t j = 0; j < MAT_SIZE; j++)
	{
		for (size_t i = 0; i < MAT_SIZE; i++) {
			for (size_t k = 0; k < MAT_SIZE; k++)
			{
				result[i][j] += mat[i][k] * mat[k][j];
			}
		}
	}
	QueryPerformanceCounter(&t2);
	cout << "time2 = " << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;  // 21.2423

	// function 3
	memset(result, 0, MAT_SIZE * MAT_SIZE * sizeof(int));
	QueryPerformanceCounter(&t1);
	for (size_t k = 0; k < MAT_SIZE; k++)
	{
		for (size_t i = 0; i < MAT_SIZE; i++) {
			for (size_t j = 0; j < MAT_SIZE; j++)
			{
				result[i][j] += mat[i][k] * mat[k][j];
			}
		}
	}
	QueryPerformanceCounter(&t2);
	cout << "time3 = " << (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart << endl;  // 16.9107
}
