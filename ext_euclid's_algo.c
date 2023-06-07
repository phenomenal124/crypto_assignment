#include <stdio.h>

void extendedEuclidean(int a, int b, int *gcd, int *x, int *y) {
    // Base case
    if (a == 0) {
        *gcd = b;
        *x = 0;
        *y = 1;
        return;
    }

    // Recursive call
    int x1, y1;
    extendedEuclidean(b % a, a, gcd, &x1, &y1);

    // Update the coefficients
    *x = y1 - (b / a) * x1;
    *y = x1;
}

int main() {
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    int gcd, x, y;
    extendedEuclidean(a, b, &gcd, &x, &y);

    printf("GCD: %d\n", gcd);
    printf("Coefficients (x, y) satisfying Bézout's identity: (%d, %d)\n", x, y);

    return 0;
}
