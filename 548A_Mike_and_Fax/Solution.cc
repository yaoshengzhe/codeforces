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

#define MAXLEN 1010

int main(int argc, char *argv[]) {
    char s[MAXLEN];
    int k;
    scanf("%s %d", s, &k);
    int len = strlen(s);
    if (len % k != 0) {
        printf("NO\n");
        return 0;
    }
    int chunkLen = len / k;
    for (int i=0; i < len; i += chunkLen) {
        int start = i;
        int end = start + chunkLen - 1;
        while (start < end) {
            if (s[start++] != s[end--]) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
