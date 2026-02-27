#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int s = arr[0];
    int pos = 0; // Initialize to 0 because s starts at index 0

    for (int i = 0; i < 10; i++) {
        if (arr[i] < s) {
            s = arr[i];
            pos = i;
        }
    }

    printf("The smallest number is %d and position is %d\n", s, pos);
    return 0;
}