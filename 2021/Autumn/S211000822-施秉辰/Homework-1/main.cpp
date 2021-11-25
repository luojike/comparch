//
//  main.cpp
//  Matrix multiplication
//
//  Created by IceyBlackTea on 2021/10/7.
//

# include <iostream>
# include <ctime>

# define MAX 1000

int matrix_a[MAX][MAX], matrix_b[MAX][MAX];
double matrix_c[MAX][MAX];

void data_reset() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matrix_a[i][j] = 1;
            matrix_b[i][j] = 1;
            matrix_c[i][j] = 0.0;
        }
    }
}

int main(int argc, const char * argv[]) {
    // init
    clock_t start_time, end_time;
    
    int i = 0, j = 0, k = 0;
    int r = 0;
    double sum = 0;
    
    // ijk
    data_reset();
    start_time = clock();
    
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            sum = 0.0;
            
            for (k = 0; k < MAX; k++) {
                sum += matrix_a[i][k] * matrix_b[k][j];
            }
            
            matrix_c[i][j] = sum;
        }
    }
    
    end_time = clock();
    
    std::cout << "ijk cost time: "
              << (double)(end_time - start_time) / CLOCKS_PER_SEC
              << "s" << std::endl;
    
    // jik
    data_reset();
    start_time = clock();
    
    for (j = 0; j < MAX; j++) {
        for (i = 0; i < MAX; i++) {
            sum = 0.0;
            
            for (k = 0; k < MAX; k++) {
                sum += matrix_a[i][k] * matrix_b[k][j];
            }
            
            matrix_c[i][j] = sum;
        }
    }
    
    end_time = clock();
    
    std::cout << "jik cost time: "
              << (double)(end_time - start_time) / CLOCKS_PER_SEC
              << "s" << std::endl;
    
    
    // kij
    data_reset();
    start_time = clock();
    
    for (k = 0; k < MAX; k++) {
        for (i = 0; i < MAX; i++) {
            r = matrix_a[i][k];
            for (j = 0; j < MAX; j++) {
                matrix_c[i][j] += r * matrix_b[k][j];
            }
        }
    }
    
    end_time = clock();
    
    std::cout << "kij cost time: "
              << (double)(end_time - start_time) / CLOCKS_PER_SEC
              << "s" << std::endl;
    
    // ikj
    data_reset();
    start_time = clock();
    
    for (i = 0; i < MAX; i++) {
        for (k = 0; k < MAX; k++) {
            r = matrix_a[i][k];
            for (j = 0; j < MAX; j++) {
                matrix_c[i][j] += r * matrix_b[k][j];
            }
        }
    }
    
    end_time = clock();
    
    std::cout << "ikj cost time: "
              << (double)(end_time - start_time) / CLOCKS_PER_SEC
              << "s" << std::endl;
    
    // jki
    data_reset();
    start_time = clock();
    
    for (j = 0; j < MAX; j++) {
        for (k = 0; k < MAX; k++) {
            r = matrix_b[k][j];
            for (i = 0; i < MAX; i++) {
                matrix_c[i][j] += matrix_a[i][k] * r;
            }
        }
    }
    
    end_time = clock();
    
    std::cout << "jki cost time: "
              << (double)(end_time - start_time) / CLOCKS_PER_SEC
              << "s" << std::endl;
    
    // kji
    data_reset();
    start_time = clock();
    
    for (k = 0; k < MAX; k++) {
        for (j = 0; j < MAX; j++) {
            r = matrix_b[k][j];
            for (i = 0; i < MAX; i++) {
                matrix_c[i][j] += matrix_a[i][k] * r;
            }
        }
    }
    
    
    end_time = clock();
    
    std::cout << "kji cost time: "
              << (double)(end_time - start_time) / CLOCKS_PER_SEC
              << "s" << std::endl;
    
    
    
    return 0;
}
