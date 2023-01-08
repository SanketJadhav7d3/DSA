
#include <stdio.h>


void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 0)
        return;

    tower_of_hanoi(n-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from , to);
    tower_of_hanoi(n-1, aux, to, from);
}

int main() {
    tower_of_hanoi(10, 'A', 'B', 'C');

    return 0;
}
