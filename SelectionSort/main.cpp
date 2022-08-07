
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int arr[] = {3, 4, 2, 6, 4, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // selection sort
    // O (n ^ 2)

    int smaller;
    for (int i = 0; i < n; ++i) {
        smaller = i;
        for (int j = i; j < n; ++j) {
            if (arr[smaller] > arr[j]) {
                smaller = j;
            }
        }
        swap(arr[i], arr[smaller]);
    }

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
