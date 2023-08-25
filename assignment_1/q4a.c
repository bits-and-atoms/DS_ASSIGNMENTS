//2212020
//SUBHAM MAJUMDER
//TO FIND DIVISION UPTO NTH DECIMAL PLACE
//WITHOUT GMP LIBRARY
//TC O(n) SC O(1)
#include <stdio.h>

void Compute(int x, int y, int n) {
    // Base cases
    if (y == 0) {
        printf("Infinite\n");
        return;
    }
    if (x == 0) {
        printf("0\n");
        return;
    }
    if (n <= 0) {
        // Since n <= 0, no more computation after the decimal
        printf("%d\n", x / y);
        return;
    }

    // for negative numbers
    if (((x > 0) && (y < 0)) || ((x < 0) && (y > 0))) {
        printf("-");
        x = x > 0 ? x : -x;
        y = y > 0 ? y : -y;
    }

    //division
    int d = x / y;

    // Now one by print digits after dot using simple division.
    for (int i = 0; i <= n; i++) {
        printf("%d", d);
        x = x - (y * d);
        if (x == 0)
            break;
        x = x * 10;
        d = x / y;
        if (i == 0)
            printf(".");
    }
    printf("\n");
}

int main() {
    int x = 22, y = 7, n = 19;
    Compute(x, y, n);
    return 0;
}
