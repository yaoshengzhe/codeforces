#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int a[MAX];
    for (int i=0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int max_diff_one = 0;
    int min_diff_two = a[n-1];

    for (int i=1; i < n-1; ++i) {
        int diff_one = a[i] - a[i-1];
        if (max_diff_one < diff_one) {
            max_diff_one = diff_one;
        }
        int diff_two = a[i+1] - a[i-1];
        if (min_diff_two > diff_two) {
            min_diff_two = diff_two;
        }
    }
    // a[n-1] - a[n-2]
    if (max_diff_one < a[n-1] - a[n-2]) {
        max_diff_one = a[n-1] - a[n-2];
    }

    int min_difficulty = max_diff_one > min_diff_two ? max_diff_one : min_diff_two;
    printf("%d\n", min_difficulty);
    return 0;
}
