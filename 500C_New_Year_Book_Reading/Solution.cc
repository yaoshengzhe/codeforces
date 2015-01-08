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

#define MAX 1010

int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    int w[MAX], b[MAX];
    FOR (i, 0, n) { scanf("%d", &w[i]); }
    FOR (i, 0, m) { scanf("%d", &b[i]); }
    list<int> s;
    set<int> books; // books that has been read
    int ans = 0;
    int sumSofar = 0;
    FOR (i, 0, m) {
        if (books.find(b[i]) == books.end()) {
            ans += sumSofar;
            books.insert(b[i]);
            s.push_front(b[i]);
            sumSofar += w[b[i]-1];
        } else {
            FOREACH (j, s) {
                if (*j == b[i]) {
                    s.erase(j);
                    s.push_front(b[i]);
                    break;
                }
                ans += w[*j-1];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
