# 实验报告

## 实验名称（测量FFT程序执行时间）

班级 学号 姓名

## 实验目标

测量FFT程序运行时间，确定其时间复杂度。

## 实验要求

* 采用C/C++编写程序
* 根据自己的机器配置选择合适的输入数据大小 n，至少要测试多个不同的 n (参见思考题)
* 对于相同的 n，建议重复测量30次取平均值作为测量结果 (参见思考题)
* 对测量结果进行分析，确定FFT程序的时间复杂度
* 回答思考题，答案加入到实验报告叙述中合适位置

## 思考题

1. 分析FFT程序的时间复杂度，得到执行时间相对于数据规模 n 的具体公式
2. 根据上一点中的分析，至少要测试多少不同的 n 来确定执行时间公式中的未知数？
3. 重复30次测量然后取平均有什么统计学的依据？

## 实验内容

### FFT算法代码

FFT的算法可以参考[这里](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm)。

'''c++
/* fft.cpp
 * 
 * This is a KISS implementation of
 * the Cooley-Tukey recursive FFT algorithm.
 * This works, and is visibly clear about what is happening where.
 *
 * To compile this with the GNU/GCC compiler:
 * g++ -o fft fft.cpp -lm
 *
 * To run the compiled version from a *nix command line:
 * ./fft
 *
 */
#include <complex>
#include <cstdio>


#define M_PI 3.14159265358979323846 // Pi constant with double precision

using namespace std;

// separate even/odd elements to lower/upper halves of array respectively.
// Due to Butterfly combinations, this turns out to be the simplest way 
// to get the job done without clobbering the wrong elements.
void separate (complex<double>* a, int n) {
    complex<double>* b = new complex<double>[n/2];  // get temp heap storage
    for(int i=0; i<n/2; i++)    // copy all odd elements to heap storage
        b[i] = a[i*2+1];
    for(int i=0; i<n/2; i++)    // copy all even elements to lower-half of a[]
        a[i] = a[i*2];
    for(int i=0; i<n/2; i++)    // copy all odd (from heap) to upper-half of a[]
        a[i+n/2] = b[i];
    delete[] b;                 // delete heap storage
}

// N must be a power-of-2, or bad things will happen.
// Currently no check for this condition.
//
// N input samples in X[] are FFT'd and results left in X[].
// Because of Nyquist theorem, N samples means 
// only first N/2 FFT results in X[] are the answer.
// (upper half of X[] is a reflection with no new information).
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

// simple test program
int main () {
    const int nSamples = 64;
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
        // sum several known sinusoids into x[]
        for(int j=0; j<nFreqs; j++)
            x[i] += sin( 2*M_PI*freq[j]*i/nSamples );
        X[i] = x[i];        // copy into X[] for FFT work & result
    }
    // compute fft for this data
    fft2(X,nSamples);
    
    printf("  n\tx[]\tX[]\tf\n");       // header line
    // loop to print values
    for(int i=0; i<nSamples; i++) {
        printf("% 3d\t%+.3f\t%+.3f\t%g\n",
            i, x[i].real(), abs(X[i]), i*freqResolution );
    }
}

// eof
C# Example Code
A C# translation of the C++ Code above:

using System;
using System.Numerics;

class FT
{
    public Complex[] x;                // storage for sample data
    public Complex[] X;                // storage for FFT answer

     // separate even/odd elements to lower/upper halves of array respectively.
    // Due to Butterfly combinations, this turns out to be the simplest way 
    // to get the job done without clobbering the wrong elements.
    void Separate(ref Complex[] a, int m, int n)
    {
        Complex[] b = new Complex[(n - m) / 2];
        for (int i = 0; i < (n - m) / 2; i++)    // copy all odd elements to b
            b[i] = a[m + i * 2 + 1];
        for (int i = 0; i < (n - m) / 2; i++)    // copy all even elements to lower-half of a
            a[m + i] = a[m + i * 2];
        for (int i = 0; i < (n - m) / 2; i++)    // copy all odd (from b) to upper-half of a[]
            a[m + i + (n - m) / 2] = b[i];
    }

    void FFT2(ref Complex[] X, int m, int n) // m: the first element of the array X
                                             // n - 1: the last element of the array X
    {
        if (n - m < 2)
        {
            // bottom of recursion.
            // Do nothing here, because already X[0] = x[0]
        }
        else
        {
            Separate(ref X, m, n);      // all evens to lower half, all odds to upper half
            FFT2(ref X, m, m + (n - m) / 2);   // recurse even items
            FFT2(ref X, m + (n - m) / 2, n);   // recurse odd  items                                               
            for (int k = 0; k < (n - m) / 2; k++)// combine results of two half recursions
            {
                Complex e = X[m + k];   // even
                Complex o = X[m + k + (n - m) / 2];   // odd                                                      
                Complex w = Complex.Exp(new Complex(0, -2 * Math.PI * k / (n - m))); // w is the "twiddle-factor"
                X[m + k] = e + w * o;
                X[m + k + (n - m) / 2] = e - w * o;
            }
        }
    }
    double signal(double t)
    {
        double[] freq = { 2, 5, 11, 17, 29 }; // known freqs for testing
        double sum = 0;
        for (int j = 0; j < freq.GetLength(0); j++) // sum several known sinusoids into x[]
            sum += Math.Sin(2 * Math.PI * freq[j] * t);
        return sum;
    }

    void Fill()
    {
        // generate samples for testing
        int N = x.Length;
        for (int i = 0; i < N; i++)
        {
            x[i] = signal((double)i / N);
            X[i] = x[i];  // copy into X[] for FFT work & result
        }
    }

    public FT(int N)
    {
        x = new Complex[N];                // storage for sample data
        X = new Complex[N];                // storage for FFT answer
        Fill();        
        FFT2(ref X, 0, N);
    }
}

class Program
{
    static void Main()
    {
        int N = 64;
        FT ft = new FT(N);
        Console.WriteLine("  n\tx[]\tX[]\tf");
        for (int i = 0; i < N; i++)
        {
            Console.WriteLine(i.ToString() + "\t" + ft.x[i].Real.ToString("0.###") + "\t"
                + Complex.Abs(ft.X[i]).ToString("0.###") + "\t" + i);
        }
        Console.ReadKey();
    }
}
'''

### FFT程序时间复杂度分析

通过分析FFT算法代码，可以得到该FFT算法的时间复杂度具体公式为：

![公式1 执行时间](./equation_time.png)

其中*n*为数据大小，未知数有：

1. *a*
2. *b*
3. *c*
4. *d*


## 测试

### 测试平台

在如下机器上进行了测试：

| 部件     | 配置             | 备注   |
| :--------|:----------------:| :-----:|
| CPU      | core i5-6500U    |        |
| 内存     | DDR3 4GB         |        |
| 操作系统 | Ubuntu 18.04 LTS | 中文版 |


### 测试记录

FFT程序的测试输入文件请见[这里](./test.input)。

FFT程序运行过程的截图如下：

FFT程序的输出

![图1 测试执行时间](./perf_ls.png)


## 分析和结论

从测试记录来看，FFT程序的执行时间随数据规模增大而增大，其时间复杂度为......

