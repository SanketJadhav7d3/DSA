
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high) {
    // choose the last element as pivot element
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // put all the element smaller than pivot to its left
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    // swap the i+1 element with pivot
    swap(&arr[i+1], &arr[high]);

    return i+1;
}

void quicksort(int* arr, int low, int high) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        // to left
        quicksort(arr, low, pi-1);

        // to right
        quicksort(arr, pi+1, high);
    }
}

void displayArray(int* arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; ++i)
        printf("%d  ", arr[i]);
    printf("\n");
}

int main() {

    int arr[] = {3, 492, 39, 29, 59, 39, 34, 20, 103, 40, 20, 10};
    int size = sizeof(arr) / sizeof(int);

    displayArray(arr, size);

    quicksort(arr, 0, size-1);

    displayArray(arr, size);

    return 0;
}
