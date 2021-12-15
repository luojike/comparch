# 作业总结
## 第一次作业 Assignment1
1. 文件说明：
   - [homework1.cpp](Assignment1/homework1.cpp)  作业代码 2000*2000
   - [result.txt](Assignment1/result.txt) 运行结果，代码运行后写入文件
2. 作业结果分析
   - ijk 的方式遍历时，对于matrix2来说，miss的几率很大，因此内存访问时间较长，同理对于jik的方式访问时，对于matrix2来说，matrix2[k][j] miss高
   - kij 的方式和ikj的方式遍历，由于muti和matrix2的miss率均很低，因此时间开销最小
   - 而jki和kji的方式，不仅matrix2和muti miss高，matrix1的miss也很高，故此两中顺序时间开销大
## 论文汇报 [PPT](计算机系统论文汇报.pptx)
