/*
Calculating fibonacci series using recursion
*/

#include <iostream>
using namespace std;

int fibonacci_recursive(int n) {
    if (n < 0)
        return - 1;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cout << fibonacci_recursive(n) << " ";

    return 0;
}
