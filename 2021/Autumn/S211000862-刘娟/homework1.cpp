/*
* @Author: apelj
* @Date:   2021-9-29 16:54:41
* @Last Modified by:   apelj
* @Last Modified time: 2021-9-30 12:08:37
*/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
// M1_m*n  * M2_n*m  -> M_m*m
class matrixMutiple {
private:
	int **matrix1;
	int **matrix2;
	int **muti;
	int col;
	int row;
public:
	matrixMutiple(int m, int n) {
		row = m ;
		col = n ;
		matrix1 = new int *[row];
		matrix2 = new int *[col];
		muti = new int *[row];
		for (int i = 0; i < row; i++) {
			matrix1[i] = new int[col];
			muti[i] = new int[row];
		}
		for(int i = 0; i < col; i++) {
			matrix2[i] = new int[row];
		}
		for(int i = 0; i < row; i++)
			for(int j = 0; j < row; j++)
				muti [i][j] = 0;


	}
	void matrixRand() {
		time_t t;
		srand((unsigned) time(&t));
		for(int i = 0; i < row ; i++) {
			for(int j = 0; j < col; j++) {
				matrix1[i][j] = rand() % 100; //取[0-100)之间随机数
				matrix2[j][i] = rand() % 100;
			}
		}

	}
	~matrixMutiple() {
		for(int i = 0; i < row; i++) {
			delete []matrix1[i];
			delete []muti[i];
		}
		for(int i = 0; i < col; i++) {
			delete []matrix2[i];
		}
		delete []matrix1;
		delete []matrix2;
		delete []muti;
	}

	void ijk() {
		for(int i = 0; i < row; i++)
			for(int j = 0; j < row; j++)
				for(int k = 0; k < col; k++)
					muti[i][j] += matrix1[i][k] * matrix2[k][j];
	}
	void ikj() {
		for(int i = 0; i < row; i++)
			for(int k = 0; k < col; k++)
				for(int j = 0; j < row; j++)
					muti[i][j] += matrix1[i][k] * matrix2[k][j];
	}
	void jik() {
		for(int j = 0; j < row; j++)
			for(int i = 0; i < row; i++)
				for(int k = 0; k < col; k++)
					muti[i][j] += matrix1[i][k] * matrix2[k][j];
	}
	void jki() {
		for(int j = 0; j < row; j++)
			for(int k = 0; k < col; k++)
				for(int i = 0; i < row; i++)muti[i][j] += matrix1[i][k] * matrix2[k][j];
	}
	void kij() {
		for(int k = 0; k < col; k++)
			for(int i = 0; i < row; i++)
				for(int j = 0; j < row; j++)
					muti[i][j] += matrix1[i][k] * matrix2[k][j];
	}
	void kji() {
		for(int k = 0; k < col; k++)
			for(int j = 0; j < row; j++)
				for(int i = 0; i < row; i++)
					muti[i][j] += matrix1[i][k] * matrix2[k][j];
	}
	void print() {
		for(int i = 0; i < row; i++) {
			cout << endl;
			for(int j = 0; j < col; j++)
				cout << matrix1[i][j] << ' ';
		}
		for(int i = 0; i < col; i++) {
			cout << endl;
			for(int j = 0; j < row; j++)
				cout << matrix2[i][j] << ' ';
		}
		for(int i = 0; i < row; i++) {
			cout << endl;
			for(int j = 0; j < row; j++)
				cout << muti[i][j] << ' ';
		}

	}
};
matrixMutiple m1(2000, 2000);
int main() {
	m1.matrixRand();
	clock_t start, end;
	double endTime;
	std::ofstream fout("result.txt"); 

	start = clock();
	m1.ijk();
	end  = clock();
	endTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "ijk Total time : " << endTime  << " s" << endl;
	fout << "ijk Total time : " << endTime  << " s" << endl;


	start = clock();
	m1.ikj();
	end  = clock();
	endTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "ikj Total time : " << endTime  << " s" << endl;
	fout << "ikj Total time : " << endTime  << " s" << endl;

	start = clock();
	m1.jik();
	end  = clock();
	endTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "jik Total time : " << endTime  << " s" << endl;
	fout << "jik Total time : " << endTime  << " s" << endl;
	start = clock();

	m1.jki();
	end  = clock();
	endTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "jki Total time : " << endTime  << " s" << endl;
	fout << "jki Total time : " << endTime  << " s" << endl;

	start = clock();
	m1.kij();
	end  = clock();
	endTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "kij Total time : " << endTime  << " s" << endl;
	fout << "kij Total time : " << endTime  << " s" << endl; start = clock();

	m1.kji();
	end  = clock();
	endTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "kji Total time : " << endTime  << " s" << endl;
	fout << "kji Total time : " << endTime  << " s" << endl;

	fout.close();
	//m1.print();


}
