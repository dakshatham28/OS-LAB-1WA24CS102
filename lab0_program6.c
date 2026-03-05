#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pos = 2; // delete element at index 2 (third element)

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
    } else {
        for (int i = pos; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        n--; // reduce size

        printf("Array after deletion: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
