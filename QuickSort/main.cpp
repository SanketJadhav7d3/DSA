
#include <iostream>
using namespace std;

void swap(int* a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {

    // pointer for the greater element
    int i = low - 1;
    // pivot point
    int pivot = arr[high];

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;

            // swap the element at j with the previous greater element
            swap(&arr[j], &arr[i]);
        }
        // swap the pivot point with 
        swap(&arr[i + 1], &arr[high]);
    }

    // return the partition
    return i;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // recursive call to left 
        quicksort(arr, low, pi - 1);

        // recursive call to right
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {34, 54, 34, 34, 69, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);

    for (auto i: arr)
        cout << i << " ";
    cout << "\n";

    return 0;
}
