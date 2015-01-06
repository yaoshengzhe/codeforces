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

template <typename T>
vector<T> make_vector(const T &a) {
    vector<T> v;
    v.push_back(a);
    return v;
}

template <typename T>
vector<T> make_vector(const T &a, const T &b) {
    vector<T> v;
    v.push_back(a);
    v.push_back(b);
    return v;
}

void print_vector(const vector<int> &v) {
    for (int i=0; i < v.size(); ++i) {
        printf("%d ", v[i]);
    }
}

int uf_find(int *uf, int x) {
    while (uf[x] != x) {
        int parent = uf[x];
        uf[x] = uf[parent];
        x = parent;
    }
    return x;
}

void uf_union(int *uf, int x, int y) {
    int rootx = uf_find(uf, x);
    int rooty = uf_find(uf, y);
    if (rootx < rooty) {
        uf[rooty] = rootx;
        //        printf("union %d and %d with root %d\n", x, y, rootx);
    } else {
        uf[rootx] = rooty;
        //        printf("union %d and %d with root %d\n", x, y, rooty);
    }
}

#define MAX 400

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int arr[MAX]; // ignore arr[0]
    int uf[MAX];
    char A[MAX][MAX];
    for (int i=1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        uf[i] = i;
    }
    for (int i=1; i <= n; ++i) {
        scanf("%s", &A[i][1]);
    }
    map<int, vector<int> > indexByGroup;
    map<int, vector<int> > dataByGroup;

    for (int i=1; i <= n; ++i) {
        for (int j=i+1; j <= n; ++j) {
            if (A[i][j] == '1') {
                uf_union(uf, i, j);
            }
        }
    }
    for (int i=1; i <= n; ++i) {
        int key = uf_find(uf, i);
        if (indexByGroup.find(key) == indexByGroup.end()) {
            indexByGroup[key] = vector<int>();
            dataByGroup[key] = vector<int>();
        }
        indexByGroup[key].push_back(i);
        dataByGroup[key].push_back(arr[i]);
    }
    for (map<int, vector<int> >::iterator itr=indexByGroup.begin(); itr != indexByGroup.end(); ++itr) {
        //        printf("Group %d: ", itr->first);
        //        print_vector(itr->second);
        //        printf("\n");
        sort(itr->second.begin(), itr->second.end());
    }
    for (map<int, vector<int> >::iterator itr=dataByGroup.begin(); itr != dataByGroup.end(); ++itr) {
        sort(itr->second.begin(), itr->second.end());
    }

    int result[MAX];
    for (int i=1; i <= n; ++i) {
        result[i] = arr[i];
    }
    for (map<int, vector<int> >::iterator itr=indexByGroup.begin(); itr != indexByGroup.end(); ++itr) {
        int key = itr->first;
        vector<int> &vi = itr->second;
        vector<int> &vv = dataByGroup[key];
        for (int i=0; i < vi.size(); ++i) {
            result[vi[i]] = vv[i];
        }
    }
    for (int i=1; i <= n; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
