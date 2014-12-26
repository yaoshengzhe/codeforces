#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    char buf1[12];
    char buf2[12];
    map<string, string> table;
    for (int i=0; i < m; ++i) {
        scanf("%s %s", buf1, buf2);
        string a = buf1;
        string b = buf2;
        string c = a.size() > b.size() ? b : a;
        table[a] = c;
        table[b] = c;
    }
    for (int i=0; i < n; ++i) {
        scanf("%s", buf1);
        string s = buf1;
        if (i <= n-1) {
            printf("%s ", table[s].c_str());
        } else {
            printf("%s\n", table[s].c_str());
        }
    }
    return 0;
}
