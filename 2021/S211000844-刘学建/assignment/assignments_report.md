# assignments_report

## 重要文件说明

1. output_MY_MMult.m结果比较文件。其中首行标识符type代表矩阵乘法实现类型、size代表方阵大小、time代表相应类型的矩阵乘法实现所需时间（单位为s）、diff代表误差。

## 运行说明

1. 首先执行指令make cleanall删除不必要文件，接下来执行指令make run运行6个不同的矩阵乘法实现类型并将结果保存至output_MY_MMult.m结果比较文件中。

## 结果比较

time(ikj) or time(kij) << time(ijk) or time(jik) < time(jki) or time(kji)