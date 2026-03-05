#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {12, 5, 7, 3, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
        printf("No second largest element.\n");
    else
        printf("Second largest element: %d\n", second);

    return 0;
}

