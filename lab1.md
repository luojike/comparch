# 实验报告

## 实验名称（测量FFT程序执行时间）

班级智能1602 学号201608010708 姓名田宗杭

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
   a*n*logn+(b/3)*n+2^(1/2)*c*logn+d
2. 根据上一点中的分析，至少要测试多少不同的 n 来确定执行时间公式中的未知数？
   设立了四种不同的未知数，所以需要列四种不同的方程，也就是需要四种不同的n
3. 重复30次测量然后取平均有什么统计学的依据？
   因为测量总是或多或少会存在些误差，不论是人工测量还是机器测量，
   人工测量会存在诸如读数等方面的误差，机器测量也会存在机械故障或者耗损等方面导致的误差，
   所以为了减少因为误差对数据结果造成的影响，多是采用多次重复测量取平均值来表示测量结果
## 实验内容

### FFT算法代码

FFT的算法可以参考[这里](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm)。

```c++
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
```

### FFT程序时间复杂度分析


将x(n)分解为偶数与奇数的两个序列之和，即
x1(n)和x2(n)的长度都是N／2，x1(n)是偶数序列，x2(n)是奇数序列，则
其中X1(k)和X2(k)分别为x1(n)和x2(n)的N／2点DFT。由于X1(k)和X2(k)均以N／2为周期，且WN k+N/2=-WN k
依此类推，经过m-1次分解，最后将N点DFT分解为N／2个两点DFT。
FFT算法的原理是通过许多小的更加容易进行的变换去实现大规模的变换，
降低了运算要求，提高了与运算速度。FFT不是DFT的近似运算，它们完全是等效的。

通过分析FFT算法代码，可以得到该FFT算法的时间复杂度具体公式为：
      a*n*logn+(b/3)*n+2^(1/2)*c*logn+d
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
| CPU      | core i7-6600U    |        |
| 内存     | DDR4 16GB         |        |
| 操作系统 | Ubuntu 16.04 LTS | 虚拟机 |


### 测试记录

FFT程序的测试输入文件请见[这里](./test.input)。

FFT程序运行过程的截图如下：
./test1.png

FFT程序的输出
./test1.png ./test2.png ./test3.png ./test4.png ./test5.png ./test6.png ./test7.png ./test8.png ./test9.png ./test10.png ./test11.png ./test12.png  ./test13.png ./test14.png      

![图1 测试执行时间](./perf_ls.png)


## 分析和结论

从测试记录来看，FFT程序的执行时间随数据规模增大而增大，其时间复杂度为Θ(n*logn)
然而，FFT在实际应用中往往需求很高的效率，虽然都是O(n*logn)的时间复杂度，
但是在递归的实现算法中，隐含的常数更大

