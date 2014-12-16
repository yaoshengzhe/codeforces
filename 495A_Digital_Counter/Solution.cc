#include <stdio.h>
#include <stdlib.h>

int table[10] = {
    2, // 0: 8
    7, // 1: 0, 3, 4, 7, 8, 9
    2, // 2: 8
    3, // 3: 8, 9
    3, // 4: 8, 9
    4, // 5: 6, 8, 9
    2, // 6: 8
    5, // 7: 0, 3, 8, 9
    1, // 8:
    2, // 9: 8
};

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    printf("%d\n", table[n/10] * table[n%10]);
    return 0;
}
