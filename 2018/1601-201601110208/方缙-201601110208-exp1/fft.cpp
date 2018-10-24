#include <complex>
#include <cstdio>
#include<time.h>

#define M_PI 3.14159265358979323846 // Pi constant with double precision

using namespace std;

void separate (complex<double>* a, int n) {
    complex<double>* b = new complex<double>[n/2];  // get temp heap storage
    for(int i=0; i<n/2; i++)
        b[i] = a[i*2+1];
    for(int i=0; i<n/2; i++)
        a[i] = a[i*2];
    for(int i=0; i<n/2; i++)
        a[i+n/2] = b[i];
    delete[] b;
}

void fft2 (complex<double>* X, int N) {
    if(N < 2) {
        // bottom of recursion.
        // Do nothing here, because already X[0] = x[0]
    } else {
        separate(X,N);      // all evens to lower half, all odds to upper half
        fft2(X,     N/2);   // recurse even items
        fft2(X+N/2, N/2);   // recurse odd  items
        // combine results of two half recursions
        for(int k=0; k<N/2; k++) {
            complex<double> e = X[k    ];   // even
            complex<double> o = X[k+N/2];   // odd
            // w is the "twiddle-factor"
            complex<double> w = exp( complex<double>(0,-2.*M_PI*k/N) );
            X[k    ] = e + w * o;
            X[k+N/2] = e - w * o;
        }
    }
}

//计算平均运行时间
clock_t calculateTime(complex<double>* X,int N,int times){
    long int sumt=0;
    for(int j=0;j<times;j++){
        clock_t start=clock();
        fft2(X,N);
        clock_t end=clock();
        sumt+=(end-start);
    }
    sumt/=times;
    return sumt;
}


int main () {
    const int nSamples = 512;
    double nSeconds = 1.0;                      // total time for sampling
    double sampleRate = nSamples / nSeconds;    // n Hz = n / second 
    double freqResolution = sampleRate / nSamples; // freq step in FFT result
    complex<double> x[nSamples];                // storage for sample data
    complex<double> X[nSamples];                // storage for FFT answer
    const int nFreqs = 5;
    double freq[nFreqs] = { 2, 5, 11, 17, 29 }; // known freqs for testing
    
    // generate samples for testing
    for(int i=0; i<nSamples; i++) {
        x[i] = complex<double>(0.,0.);
        for(int j=0; j<nFreqs; j++)
            x[i] += sin( 2*M_PI*freq[j]*i/nSamples );
        X[i] = x[i];       
    }
    
    int sam[8]={4,8,16,32,64,128,256,512};  //8个不同数据规模
    printf("Repeat 30 times\n");
    printf("n\tmeanTime\t\n");
    for(int i=0;i<8;i++){
		long int sumt=calculateTime(X,sam[i],30);
        printf("%d\t%ld\n",sam[i],sumt);
	}
    printf("Repeat 50 times\n");
    printf("n\tmeanTime\t\n");
    for(int i=0;i<8;i++){
		long int sumt=calculateTime(X,sam[i],50);
        printf("%d\t%ld\n",sam[i],sumt);
	}
}
 
