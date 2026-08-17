#include <stdio.h>

int bruteForce(int n) {
    int a = 1, b = 1;
    int sum = 0;

    while (a <= n) {
        if (a % 2 == 0)
            sum += a;

        int c = a + b;
        a = b;
        b = c;
    }

    return sum;
}

int optimized(int n) {
    int e1 = 2, e2 = 8;
    int sum = 0;

    while (e1 <= n) {
        sum += e1;

        int next = 4 * e2 + e1;
        e1 = e2;
        e2 = next;
    }

    return sum;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Brute Force Sum = %d\n", bruteForce(n));
    printf("Optimized Sum = %d\n", optimized(n));

    return 0;
}