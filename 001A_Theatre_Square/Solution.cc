#define __STDC_FORMAT_MACROS

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

void readInt64(int64_t *v) {
    scanf("%"SCNd64, v);
}

void printInt64(int64_t v) {
    printf("%"PRId64, v);
}

int64_t divceil(int64_t a, int64_t b) {
    int64_t ans = a / b;
    if ((a % b) != 0) {
        ans++;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int64_t n, m, a;
    readInt64(&n);
    readInt64(&m);
    readInt64(&a);
    int64_t c = divceil(n, a);
    if (m - a > 0) {
        c += divceil(m-a, a) * c;
    }
    printInt64(c);
    printf("\n");
    return 0;
}
