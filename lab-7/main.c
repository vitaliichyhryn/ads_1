#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "");

    // initialize arr1 and arr2
    wchar_t arr1[10] = {0};
    wchar_t arr2[10] = {0};
    for (int i = 0; i < 10; i++) {
        arr1[i] = (int)(43 - i);
        arr2[i] = (int)(37 + i);
    }

    // initialize arr3
    wchar_t arr3[10];
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr1[i] == arr2[j]) {
                arr3[i] = arr1[i];
                k++;
            }
        }
    }

    // find product
    wchar_t prod = 1;
    for (int i = 0; i < k; i++) {
        if(arr3[i] > 40) {
            prod *= arr3[i];
        }
    }

    wprintf(L"%d\n%lc\n", prod, prod);

    return 0;
}