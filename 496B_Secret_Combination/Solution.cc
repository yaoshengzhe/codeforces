#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

int main(int argc, char *argv[]) {
    int n;
    char digits[MAX] = {0};
    char min_num[MAX] = {0};
    scanf("%d", &n);
    scanf("%s", digits);
    min_num[n] = '\0';
    digits[n] = '\0';
    strcpy(min_num, digits);
    // try to make each digit to 0 and get the smallest combination
    for (int i=0; i < n; ++i) {
        int d = digits[i] - '0';
        int inc_times = (10 - d) % 10;
        char candidate[MAX] = {0};
        int k = 1; // pos to candidate
        candidate[0] = '0';
        for (int j=i+1; j < n; ++j) {
            candidate[k++] = ((digits[j] - '0' + inc_times) % 10) + '0';
        }
        for (int j=0; j < i; ++j) {
            candidate[k++] = ((digits[j] - '0' + inc_times) % 10) + '0';
        }
        candidate[n] = '\0';
        if (strcmp(candidate, min_num) < 0) {
            strcpy(min_num, candidate);
        }
    }
    // result must be started with 0
    printf("%s\n", min_num);
    return 0;
}
