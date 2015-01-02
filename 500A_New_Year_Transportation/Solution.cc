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

#define MAX 40000
int main(int argc, char *argv[]) {
    int n, t;
    scanf("%d %d", &n, &t);
    int arr[MAX] = {0}; // leave arr[0] unused
    for (int i=1; i < n+1; ++i) {
        scanf("%d", &arr[i]);
    }
    bool visited[MAX] = {false};
    int cur = 1;
    while (!visited[cur]) {
        if (cur == t) {
            printf("YES\n");
            return 0;
        }
        visited[cur] = true;
        cur += arr[cur];
    }
    printf("NO\n");
    return 0;
}
