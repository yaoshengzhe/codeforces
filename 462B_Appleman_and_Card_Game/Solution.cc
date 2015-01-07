#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 30

typedef long long int bigint;

typedef struct Node {
    int count;
    char ch;
} Node;

int my_cmp(const void *a, const void *b) {
    return ((Node *)b)->count - ((Node *)a)->count;
}

int main() {
    int n, k;
    Node str[MAX_LEN];
    for (int i=0; i < 26; ++i) {
        str[i].count = 0;
        str[i].ch = 'A' + i;
    }

    scanf("%d %d", &n, &k);
    char *buf = (char*)malloc(sizeof(char) * n + 10);
    scanf("%s", buf);
    char *p = buf;
    while (*p) {
        str[*p - 'A'].count++;
        p++;
    }
    free(buf);

    qsort((void*)str, 26, sizeof(Node), my_cmp);
    bigint result = 0;
    for (int i=0; i < 26; ++i) {
        if (k >= str[i].count) {
            k -= str[i].count;
            result += ((bigint) str[i].count) * str[i].count;
        } else if (k > 0) {
            result += ((bigint)k) * k;
            break;
        }
    }
    printf("%I64d\n", result);
    return 0;
}
