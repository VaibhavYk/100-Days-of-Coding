// Write a program to print all the prime numbers from 1 to n.

#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the upper limit n: ");
    scanf("%d", &n);

    printf("Prime numbers from 1 to %d are:\n", n);

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
