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

#define GRID_LEN 501

int findMaxForRow(int *row, int len) {
    int max = 0;
    int curMax = 0;
    for (int i=0; i < len; ++i) {
        if (row[i] == 1) {
            curMax++;
        } else {
            curMax = 0;
        }
        if (max < curMax) {
            max = curMax;
        }
    }
    if (max < curMax) {
        max = curMax;
    }
    return max;
}

int findMax(int *arr, int len) {
    int max = arr[0];
    for (int i=1; i < len; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main(int argc, char *argv[]) {
    int n, m, q;
    int grid[GRID_LEN][GRID_LEN];
    int maxs[GRID_LEN];
    
    scanf("%d %d %d", &n, &m, &q);
    for (int i=0; i < n; ++i) {
        for (int j=0; j < m; ++j) {
            scanf("%d", &grid[i][j]);
        }
        maxs[i] = findMaxForRow(&grid[i][0], m);
    }
    for (int i=0; i < q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        grid[x-1][y-1] = 1 - grid[x-1][y-1];
        maxs[x-1] = findMaxForRow(&grid[x-1][0], m);
        printf("%d\n", findMax(&maxs[0], n));
    }
    return 0;
}
