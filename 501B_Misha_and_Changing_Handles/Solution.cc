#define __STDC_FORMAT_MACROS

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <list>
#include <iostream>
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
    int q;
    scanf("%d", &q);
    map<string, string> oldNames;
    map<string, string> newNames;
    FOR(i, 0, q) {
        string a, b;
        cin >> a >> b;
        if (newNames.find(a) != newNames.end()) {
            string w = newNames[a];
            oldNames[w] = b;
            newNames[b] = w;
        } else {
            oldNames[a] = b;
            newNames[b] = a;
        }
    }
    printf("%lu\n", oldNames.size());
    FOREACH(i, oldNames) {
        printf("%s %s\n", i->first.c_str(), i->second.c_str());
    }
    return 0;
}
