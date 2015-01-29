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
#include <string>
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

int main(int argc, char *argv[]) {
    int64_t r, x, y, x1, y1;
    readInt64(&r); readInt64(&x); readInt64(&y); readInt64(&x1); readInt64(&y1);
    // 2r * t <= dist - 2r
    // 2r * (t+1) <= dist
    // 4r^2 * (t+1)^2 <= distSquare
    int64_t distSquare = (x - x1)*(x-x1) + (y-y1)*(y-y1);
    double dist = sqrt(distSquare);
    double t = dist / (2*r) - 1;
    int64_t diff = ((int64_t)t+1) * ((int64_t)t+1) * 4 * r * r;
    //printf("dist = %lf, t = %lf, (int)t = %d\n", dist, t, (int)t);
    //printf("distSquare = ");
    //printInt64(distSquare);
    //printf("\n");
    //printf("diff = ");
    //printInt64(diff);
    //printf("\n");

    if (distSquare == 0) {
        printf("0\n");
    } else if (4*r*r == distSquare) {
        printf("1\n");
    } else if (t <= 0 || distSquare == diff) {
        printf("%d\n", (int)t + 1);
    } else {
        printf("%d\n", (int)t + 2);
    }
    return 0;
}
