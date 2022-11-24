
#include <stdio.h>

int ackermann(int m, int n) {
    if (m == 0) 
        return n + 1;
    if (m > 0 && n == 0)
        return ackermann(m-1, 1);
    if (m > 0 && n > 0)
        return ackermann(m-1, ackermann(m, n-1));
}

int main() {
    int result = ackermann(3, 4);
    printf("Result: %d\n", result);
    return 0;
}
