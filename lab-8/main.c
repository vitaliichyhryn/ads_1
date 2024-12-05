#include <stdio.h>
#include <stdlib.h>

int main() {
    const size_t arr1_rows = 7;
    const size_t arr1_cols = 6;

    double **arr1 = (double **)calloc(arr1_rows, sizeof(double *));
    for (size_t i = 0; i < arr1_rows; ++i) {
        for (size_t j = 0; j < arr1_cols; ++j) {
            arr1[i] = (double *)calloc(arr1_rows, sizeof(double));
        }
    }

    double arr2[arr1_rows];

    printf("arr1 init:\n");
    for (size_t i = 0; i < arr1_rows; ++i) {
        for (size_t j = 0; j < arr1_cols; ++j) {
            arr1[i][j] = (double)arc4random_uniform(32) -
                    (double)arc4random_uniform(32) -
                    (double)((double)arc4random_uniform(32) / 100.0);
            printf("%-15.3lf", arr1[i][j]);
        }
        putchar('\n');
    }

    printf("\narr2 init:\n");
    for (size_t i = 0; i < arr1_rows; ++i) {
        arr2[i] = 1;
        printf("%-15.3lf", arr2[i]);
    }
    putchar('\n');

    printf("\narr2 search:\n");
    for (size_t i = 0; i < arr1_rows; ++i) {
        for (size_t j = 0; j < arr1_cols; ++j) {
            if (arr1[i][j] < 0)
                arr2[i] *= arr1[i][j];
        }
        printf("%-15.3lf", arr2[i]);
    }
    putchar('\n');

    size_t gap = arr1_rows / 2;
    while (gap > 0) {
        for (size_t i = gap; i < arr1_rows; ++i) {
            double temp = arr2[i];
            size_t j = i;
            while (j >= gap && arr2[j - gap] < temp) {
                arr2[j] = arr2[j - gap];
                j -= gap;
            }
            arr2[j] = temp;
        }
        gap = gap / 2;
    }

    printf("\narr2 sorted:\n");
    for (int i = 0; i < arr1_rows; ++i) {
        printf("%-15.3lf", arr2[i]);
    }
    putchar('\n');

    for (size_t i = 0; i < arr1_rows; ++i) {
        free(arr1[i]);
    }
    free(arr1);

    return 0;
}