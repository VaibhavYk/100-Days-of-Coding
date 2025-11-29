// Find the digit that occurs the most times in an integer number.

#include <stdio.h>

int main() {
    int n, digit, count, max_digit = 0, max_count = 0, i;
    printf("Enter an integer: ");
    scanf("%d", &n);
 
    for (i = 0; i <= 9; i++) {
        int temp = n;
        count = 0;
        while (temp > 0) {
            digit = temp % 10;
            if (digit == i) count++;
            temp /= 10;
        }
        
        if (count >= max_count) {
            max_count = count;
            max_digit = i;
        }
    }
    printf("Most frequent digit: %d\n", max_digit);
    return 0;
   
}
