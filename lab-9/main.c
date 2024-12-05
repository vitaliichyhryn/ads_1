#include <stdio.h>
#include <stdlib.h>

int main() {
    const int m = 4, n = 3;
    float mx[m][n];

    // get mx
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("enter mx[%i][%i]: ", i, j);
            scanf("%f", &mx[i][j]);
        }
    }

    // get min, min_i and min_j
    int min_i = 0;
    int min_j = 0;
    float min = mx[min_i][min_j];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mx[i][j] < min) {
                min = mx[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }

    // print min, min_i and min_j
    printf("min is mx[%i][%i] and equals to %.2f\n", min_i, min_j, min);

    // get und_diag_avg
    int und_diag_num = 0;
    float und_diag_sum = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            und_diag_sum += mx[i][j];
            ++und_diag_num;
        }
    }
    float und_diag_avg = und_diag_sum / (float)und_diag_num;

    // get is_greater
    bool is_greater = min > und_diag_avg;

    // print is_greater
    if (is_greater) {
        printf("%.3f is greater than %.3f\n", min, und_diag_avg);
    } else {
        printf("%.3f is smaller than %.3f\n", min, und_diag_avg);
    }

    return EXIT_SUCCESS;
}