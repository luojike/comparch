#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

#define SIZE 5000

clock_t start,tend;
int A[SIZE][SIZE], B[SIZE][SIZE],C[SIZE][SIZE];
 double endtime;
int main() {
    ifstream infile1,infile2;
    infile1.open("matrix1.txt");
    infile2.open("matrix2.txt");
     for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
            infile1>>A[i][j];
            infile2>>B[i][j];
            }
        }   
   int i, j, k;

    /*i,j,k*/

    for(i=0;i<SIZE;i++)
	for(j=0;j<SIZE;j++)
    C[i][j]=0;

    start=clock();
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			for(k=0;k<SIZE;k++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
    tend=clock();
    endtime=(double)(tend-start)/CLOCKS_PER_SEC;
    cout<<"Time of i,j,k:"<<endtime<<endl;

     /*j,i,k*/

    for(i=0;i<SIZE;i++)
	for(j=0;j<SIZE;j++)
    C[i][j]=0;

    start=clock();
	for(j=0;j<SIZE;j++){
		for(i=0;i<SIZE;i++){
			for(k=0;k<SIZE;k++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
    tend=clock();
    endtime=(double)(tend-start)/CLOCKS_PER_SEC;
    cout<<"Time of j,i,k:"<<endtime<<endl;

    /*j,k,i*/
    
    for(i=0;i<SIZE;i++)
	for(j=0;j<SIZE;j++)
    C[i][j]=0;

    start=clock();
	for(j=0;j<SIZE;j++){
		for(k=0;k<SIZE;k++){ 
			for(i=0;i<SIZE;i++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
    tend=clock();
    endtime=(double)(tend-start)/CLOCKS_PER_SEC;
    cout<<"Time of j,k,i:"<<endtime<<endl;

    /*k,j,i*/

    for(i=0;i<SIZE;i++)
	for(j=0;j<SIZE;j++)
    C[i][j]=0;

    start=clock();
	for(k=0;k<SIZE;k++){
		for(j=0;j<SIZE;j++){ 
			for(i=0;i<SIZE;i++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
    tend=clock();
    endtime=(double)(tend-start)/CLOCKS_PER_SEC;
    cout<<"Time of k,j,i:"<<endtime<<endl;

    /*k,i,j*/

    for(i=0;i<SIZE;i++)
	for(j=0;j<SIZE;j++)
    C[i][j]=0;

    start=clock();
	for(k=0;k<SIZE;k++){
		for(i=0;i<SIZE;i++){ 
			for(j=0;j<SIZE;j++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
    tend=clock();
    endtime=(double)(tend-start)/CLOCKS_PER_SEC;
    cout<<"Time of k,i,j:"<<endtime<<endl;

    /*i,k,j*/

    for(i=0;i<SIZE;i++)
	for(j=0;j<SIZE;j++)
    C[i][j]=0;
    
    start=clock();
	for(i=0;i<SIZE;i++){
		for(k=0;k<SIZE;k++){ 
			for(j=0;j<SIZE;j++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
    tend=clock();
    endtime=(double)(tend-start)/CLOCKS_PER_SEC;
    cout<<"Time of i,j,k:"<<endtime<<endl;


	return 0;
}
