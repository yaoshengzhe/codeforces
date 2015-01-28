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

struct InstrumentCmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int main(int argc, char *argv[]) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<int, int> > instrumentsByDay;
    FOR (i, 1, n+1) {
        int d;
        scanf("%d", &d);
        instrumentsByDay.push_back(make_pair(d, i));
    }
    sort(instrumentsByDay.begin(), instrumentsByDay.end(), InstrumentCmp());
    int ans = 0;
    vector<int> instrumentIds;
    FOREACH (item, instrumentsByDay) {
        k -= item->first;
        if (k >= 0) {
            ans++;
            instrumentIds.push_back(item->second);
        }
    }
    printf("%d\n", ans);
    FOREACH (i, instrumentIds) {
        printf("%d ", *i);
    }
    if (ans > 0) {
        printf("\n");
    }
    return 0;
}
