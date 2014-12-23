#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

int bsearch(int *arr, int start, int end, int val) {
    int pos = -1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == val) {
            pos = mid;
            end = mid;
        } else if (arr[mid] < val) {
            start = mid+1;
        } else {
            end = mid;
        }
    }
    return pos;
}

struct Cmp {
    bool operator()(const pair<int, int>&a, const pair<int, int>&b) const {
        if (a.first < b.first) {
            return true;
        } else if (a.first == b.first && a.second < b.second) {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int a[MAX] = {0};
    int b[MAX] = {0};
    for (int i=0; i < n; ++i) {
        int v = 0;
        scanf("%d", &v);
        if (v == 1) {
            a[i] = 1;
        } else {
            b[i] = 1;
        }
    }

    for (int i=1; i < n; ++i) {
        a[i] += a[i-1];
        b[i] += b[i-1];
    }

    vector<pair<int, int> > results;

    for (int t=1; t <= n; ++t) {
        int k = 0;
        int error = 0;
        int a_win = 0;
        int b_win = 0;
        int s = 0;
        while (k < n) {
            int pos_a = bsearch(a, k, n, k == 0 ? t : (a[k-1] + t));
            int pos_b = bsearch(b, k, n, k == 0 ? t : (b[k-1] + t));
            // printf("t = %d, k = %d, pos_a = %d, pos_b = %d\n", t, k, pos_a, pos_b);
            if (pos_a == pos_b) {
                error = -1;
                break;
            }
            if (pos_a == -1 || (pos_b != -1 && pos_a > pos_b)) {
                b_win++;
                k = pos_b+1;
            } else {
                a_win++;
                k = pos_a+1;
            }
            int max = a_win > b_win ? a_win : b_win;
            if (k < n) {
                s = max + 1;
            } else { // k == n
                if (a_win < s && b_win < s) {
                    error = -1;
                } else {
                    s = s > max ? s : max;
                }
            }
        }
        if (error == 0) {
            results.push_back(make_pair(s, t));
        }
    }
    sort(results.begin(), results.end(), Cmp());
    printf("%lu\n", results.size());
    for (int i=0; i < results.size(); ++i) {
        printf("%d %d\n", results[i].first, results[i].second);
    }
    return 0;
}
