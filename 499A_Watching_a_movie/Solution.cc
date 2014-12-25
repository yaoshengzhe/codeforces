#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n, x;
    scanf("%d %d", &n, &x);
    int min_time = 0;
    int cur_pos = 1;
    for (int i=0; i < n; ++i) {
        int start, end;
        scanf("%d %d", &start, &end);
        min_time += ((start - cur_pos) % x);
        min_time += (end - start + 1);
        cur_pos = end + 1;
    }
    printf("%d\n", min_time);
    return 0;
}
