#define __STDC_FORMAT_MACROS

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define FOR(I, S, E) for(__typeof(S) I=(S); I < (E); ++I)

void readInt64(int64_t *v) {
    scanf("%"SCNd64, v);
}

void printInt64(int64_t v) {
    printf("%"PRId64, v);
}

int score(int p, int t) {
    return max(p / 10 * 3, p - p / 250 * t);
}

int main(int argc, char *argv[]) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int diff = score(a, c) - score(b, d);
    if (diff == 0) {
        printf("Tie\n");
    } else {
        printf("%s\n", diff > 0 ? "Misha" : "Vasya");
    }
    return 0;
}
