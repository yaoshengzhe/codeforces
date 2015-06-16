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


#define MAX 2020

int main(int argc, char *argv[]) {
    int n;
    int arr[MAX];
    int acc[MAX] = {0};
    scanf("%d", &n);
    for (int i=0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i=0; i < n; ++i) {
        acc[arr[i]]++;
    }
    for (int i=1; i < MAX; ++i) {
        acc[i] += acc[i-1];
    }
    for (int i=0; i < n; ++i) {
        printf("%d ", n - acc[arr[i]] + 1);
    }
    printf("\n");
    return 0;
}
