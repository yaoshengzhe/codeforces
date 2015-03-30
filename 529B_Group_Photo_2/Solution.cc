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

#define MAX 1010

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int w[MAX];
    int h[MAX];
    set<int> heights;
    FOR(i, 0, n) {
        scanf("%d %d", &w[i], &h[i]);
        heights.insert(w[i]);
        heights.insert(h[i]);
    }

    int64_t min_area = -1;
    
    FOREACH(itr, heights) {
        int max_height = *itr;
        int num_flip = 0;
        int64_t total_width = 0;
        bool impossible = false;
        // key is the gain (width - height), value is the number of elements
        map<int, int> gainTable;
        FOR(i, 0, n) {
            if (h[i] > max_height) {
                if (w[i] <= max_height) {
                    total_width += h[i];
                    num_flip++;
                } else {
                    impossible = true;
                    break;
                }
            } else {
                if (w[i] > h[i] && w[i] <= max_height) {
                    int diff = w[i] - h[i];
                    if (gainTable.find(diff) != gainTable.end()) {
                        gainTable[diff]++;
                    } else {
                        gainTable[diff] = 1;
                    }
                }
                total_width += w[i];
            }
        }
        if (impossible) {
            continue;
        }
        if (num_flip > n/2) {
            continue;
        }

        int64_t area = max_height * total_width;
        // printf("max_height: %d, num_flip: %d, total_width: ", max_height, num_flip);
        // printInt64(total_width);
        // printf("\n");

        for (map<int, int >::reverse_iterator itr=gainTable.rbegin(); itr != gainTable.rend(); ++itr) {
            FOR (j, 0, itr->second) {
                if (num_flip >= n/2) {
                    break;
                }
                num_flip++;
                area -= (itr->first * max_height);
            }
            if (num_flip >= n/2) {
                break;
            }
        }
        
        if (min_area < 0 || min_area > area) {
            min_area = area;
        }
    }
    printInt64(min_area);
    printf("\n");
    return 0;
}
