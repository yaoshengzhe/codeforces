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

#define MAX 100100

struct Road {
    int start;
    int end;
    int cost;
};

double combine(int n, int k) {
    if (k > n) {
        return 0.0;
    }
    double ans = 1.0;
    for (int i=0; i < k; ++i) {
        ans *= (n-i);
    }
    for (int i=2; i <= k; ++i) {
        ans /= i;
    }
    return ans;
}
/*
void dfs(map<int, list<pair<int, int> > > &tree, double *probs, int i, int end, int *componentNum, double all, int n) {
    componentNum[i] = 1;
    FOREACH(itr, tree[i]) {
        if (itr->first == end) {
            continue;
        }
        dfs(tree, probs, itr->first, i, componentNum, all, n);
        int v = componentNum[itr->first];
        componentNum[i] += v;
        probs[itr->second] = ((double)v * (n-v)) / all;
    }
} */

void dfs(map<int, list<pair<int, int> > > &tree, double *probs, int *state, int i, int *componentNum, double all, int n) {
    if (state[i] != 0) {
        return;
    }
    componentNum[i] = 1;
    state[i] = 1;
    FOREACH(itr, tree[i]) {
        if (state[itr->first] == 0) {
            dfs(tree, probs, state, itr->first, componentNum, all, n);
            int v = componentNum[itr->first];
            componentNum[i] += v;
            probs[itr->second] = ((double)v * (n-v)) / all;
        }
    }
    state[i] = 2;
}

void find_prob(Road *roads, double *probs, int n) {
    map<int, list<pair<int, int> > > tree;
    FOR (i, 1, n) {
        tree[roads[i].start].push_back(make_pair(roads[i].end, i));
        tree[roads[i].end].push_back(make_pair(roads[i].start, i));
    }
    int componentNum[MAX];
    int state[MAX] = {0};
    dfs(tree, probs, state, 1, componentNum, combine(n, 2), n);
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    Road roads[MAX];
    FOR (i, 1, n) {
        scanf("%d %d %d", &roads[i].start, &roads[i].end, &roads[i].cost);
    }
    int q;
    scanf("%d", &q);
    double ans = 0.0;
    double probs[MAX];

    find_prob(roads, probs, n);

    FOR (i, 1, n) {
        ans += roads[i].cost * probs[i];
    }
    ans *= 3;
    FOR (i, 0, q) {
        int roadId, newCost;
        scanf("%d %d", &roadId, &newCost);
        ans -= (3 * (roads[roadId].cost - newCost) * probs[roadId]);
        roads[roadId].cost = newCost;
        printf("%.10lf\n", ans);
    }
    return 0;
}
