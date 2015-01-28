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

#define MAX 20

int find(char *s, int len, int p[MAX][MAX], int i, int j, int *pos, char *c) {
    if (i >= j) {
        return 0;
    }
    if (p[i][j] > 0) {
        return p[i][j];
    }
    if (s[i] == s[j]) {
        return find(s, len, p, i+1, j-1, pos, c);
    }
    int a = find(s, len, p, i+1, j, pos, c);
    int b = find(s, len, p, i, j-1, pos, c);
    if (a < b) {
        *pos = j+1;
        *c = s[i];
        return a + 1;
    } else {
        *pos = i;
        *c = s[j];
        return b + 1;
    }
}

int main(int argc, char *argv[]) {
    char s[MAX];
    scanf("%s", s);
    int len = strlen(s);
    int pos = len/2;
    char c = s[pos];
    int p[MAX][MAX];
    memset(p, -1, sizeof(int) * MAX * MAX);
    int ans = find(s, len, p, 0, len-1, &pos, &c);
    if (ans <= 1) {
        FOR (i, 0, pos) {
            printf("%c", s[i]);
        }
        printf("%c", c);
        FOR(i, pos, len) {
            printf("%c", s[i]);
        }
        printf("\n");
    } else {
        printf("NA\n");
    }
    return 0;
}
