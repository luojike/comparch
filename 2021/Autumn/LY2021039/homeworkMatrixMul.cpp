#include<iostream>
#include<cstring>
#include<Windows.h>
constexpr auto MAT_SIZE = 2000;;
using namespace std;

int main() {
	int(*mat)[MAT_SIZE] = new int[MAT_SIZE][MAT_SIZE];
	int(*result)[MAT_SIZE] = new int[MAT_SIZE][MAT_SIZE];
	memset(mat, -1, MAT_SIZE * MAT_SIZE * sizeof(int));
	memset(result, 0, MAT_SIZE * MAT_SIZE * sizeof(int));
	LARGE_INTEGER time1, time2, timecounter;
	QueryPerformanceFrequency(&timecounter);

	// ijk funtion
	QueryPerformanceCounter(&time1);
	for (size_t i = 0; i < MAT_SIZE; i++)
	{
		for (size_t j = 0; j < MAT_SIZE; j++) {
			for (size_t k = 0; k < MAT_SIZE; k++)
			{
				result[i][j] += mat[i][k] * mat[k][j];
			}
		}
	}
	QueryPerformanceCounter(&time2);
	cout << "time for ijk function = " << (double)(time2.QuadPart - time1.QuadPart) / (double)timecounter.QuadPart << endl;  

	// jik function 
	memset(result, 0, MAT_SIZE * MAT_SIZE * sizeof(int));
	QueryPerformanceCounter(&time1);
	for (size_t j = 0; j < MAT_SIZE; j++)
	{
		for (size_t i = 0; i < MAT_SIZE; i++) {
			for (size_t k = 0; k < MAT_SIZE; k++)
			{
				result[i][j] += mat[i][k] * mat[k][j];
			}
		}
	}
	QueryPerformanceCounter(&time2);
	cout << "time for jik function = " << (double)(time2.QuadPart - time1.QuadPart) / (double)timecounter.QuadPart << endl;  

	// kij function
	memset(result, 0, MAT_SIZE * MAT_SIZE * sizeof(int));
	QueryPerformanceCounter(&time1);
	for (size_t k = 0; k < MAT_SIZE; k++)
	{
		for (size_t i = 0; i < MAT_SIZE; i++) {
			for (size_t j = 0; j < MAT_SIZE; j++)
			{
				result[i][j] += mat[i][k] * mat[k][j];
			}
		}
	}
	QueryPerformanceCounter(&time2);
	cout << "time for kij function= " << (double)(time2.QuadPart - time1.QuadPart) / (double)timecounter.QuadPart << endl;  
}