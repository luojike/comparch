#include <fstream>
#include<iostream>
#include <ctime>
using namespace std;

double a[2000][2000],b[2000][2000],c[2000][2000];

int main()
{
    clock_t start,end;
    int i,j,k;
    double t,sum;

    char ina[11]="inputa.txt";
	ifstream infile(ina,ios::in);
 	if(!infile)
  	{	
	  	cerr<<ina<<endl;
  		exit(1);
  	}
    for(i=0;i<2000;i++)
    {
        for(j=0;j<2000;j++)
        {
            infile>>t;
            a[i][j]=t;
        }
    }
  	infile.close();

    char inb[11]="inputb.txt";
	ifstream infileb(inb,ios::in);
 	if(!infileb)
  	{	
	  	cerr<<inb<<endl;
  		exit(1);
  	}
    for(i=0;i<2000;i++)
    {
        for(j=0;j<2000;j++)
        {
            infileb>>t;
            b[i][j]=t;
        }
    }
  	infileb.close();

    start=clock();
  	
    for(i=0;i<2000;i++)
    {
        for(j=0;j<2000;j++)
        {
            sum=0.0;
            for(k=0;k<2000;k++) sum+=a[i][k] * b[k][j];
            c[i][j]=sum;
        }
    }

  	end=clock();
  	cout<<"i-j-k time is: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;

    return 0;
}