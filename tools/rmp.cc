// rmq: Range Minimum Query implementation based on sparse table
#include <math.h>

#include <algorithm>

#define STEP 30 // 2^30, should be adjusted based on data size

void rmqBuild(int *rmq[STEP], int *data, int len) {
    for (int i=1; i <= len; ++i) {
        rmq[i][0] = data[0];
    }

    int k = (int)log2(len);

    for (int j=1; j <= k; ++j) {
        for (int i=1; i + (1 << j) <= len; ++i) {
            rmq[i][j] = std::min(rmq[i][j-1], rmq[i + (1 << (j-1))][j-1]);
        }
    }
}

int rmqFind(int *rmq[STEP], int start, int end) {
    // 2^k <= end - start, end is exclusive
    int k = (int)log2(end - start);
    return std::min(rmq[start][k], rmq[end - (1 << k) - 1][k]);
}
