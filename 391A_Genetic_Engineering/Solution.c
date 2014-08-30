#include <stdio.h>
#include <string.h>

#define MAX_LEN 110

int main() {
    char dna[MAX_LEN];
    scanf("%s", dna);
    int count = 0;
    int repeat = 1;
    for (int i=1; i < strlen(dna); ++i) {
        if (dna[i] == dna[i-1]) {
            repeat++;
        } else {
            if (repeat % 2 == 0) {
                count++;
            }
            repeat = 1;
        }
    }
    if (repeat % 2 == 0) {
        count++;
    }
    printf("%d\n", count);
    return 0;
}
