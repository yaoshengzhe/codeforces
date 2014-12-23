#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAX 101

int main(int argc, char *argv[]) {
    int n, m;
    char mat[MAX][MAX] = {0};
    vector<vector<int> > groups;
    groups.push_back(vector<int>());
    scanf("%d %d", &n, &m);
    for (int i=0; i < n; ++i) {
        scanf("%s", mat[i]);
        groups[0].push_back(i);
    }

    int result = 0;
    for (int col=0; col < m; ++col) {
        bool is_sorted = true;
        vector<vector<int> > new_groups;
        for (int i=0; i < groups.size(); ++i) {
            for (int j=1; j < groups[i].size(); ++j) {
                if (mat[groups[i][j]][col] < mat[groups[i][j-1]][col]) {
                    is_sorted = false;
                    break;
                }
            }
            if (!is_sorted) {
                break;
            } else {
                vector<int> new_group;
                for (int j=1; j < groups[i].size(); ++j) {
                    if (mat[groups[i][j]][col] == mat[groups[i][j-1]][col]) {
                        new_group.push_back(groups[i][j-1]);
                    } else {
                        if (new_group.size() > 0) {
                            new_group.push_back(groups[i][j-1]);
                            new_groups.push_back(new_group);
                            new_group.clear();
                        }
                    }
                }
                if (new_group.size() > 0) {
                    new_group.push_back(groups[i][groups[i].size()-1]);
                    new_groups.push_back(new_group);
                }
            }
        }

        if (!is_sorted) {
            ++result;
        } else {
            groups = new_groups;
        }
    }
    printf("%d\n", result);
    return 0;
}
