#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    long a, b;
    scanf("%ld %ld", &a, &b);
    if (a == b) {
        printf("infinity\n");
    } else {
        long c = a - b;
        long result = 0;
        for (long i=1; i <= (long)sqrt(c); ++i) {
            if (c % i == 0) {
                // printf("%ld * %ld, ", i, c/i);
                int j = c / i;
                if (i > b) {
                    result++;
                }
                if (i != j && j > b) {
                    result++;
                }
            }
        }
        printf("%ld\n", result);
    }
    return 0;
}
