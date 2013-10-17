#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

const char UNDEFINED = 'X';
typedef pair<int, int> Bomb;

char get_x_dir(int x) {
    if (x == 0) {
        return UNDEFINED;
    }
    return x > 0 ? 'R' : 'L';
}

char get_y_dir(int y) {
    if (y == 0) {
        return UNDEFINED;
    }
    return y > 0 ? 'U' : 'D';
}

Bomb make_bomb(int x, int y) {
    return make_pair(x, y);
}

bool bomb_cmp (const Bomb a, const Bomb b) {
    return (abs(a.first) + abs(a.second) - abs(b.first) - abs(b.second)) < 0;
}

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    cin.get();
    Bomb *bomb = new Bomb[N];

    int d = 0;
    for (int i=0; i < N; ++i) {
        int x, y;
        cin >> x;
        cin >> y;
        cin.get();
        if (x == 0 || y == 0) {
            ++d;
        }
        bomb[i] = make_bomb(x, y);
    }

    sort(bomb, bomb + N, bomb_cmp);

    cout << (N * 6 -  2 * d) << endl;
    for (int i=0; i < N; ++i) {
        int x = bomb[i].first;
        int y = bomb[i].second;
        char x_dir = get_x_dir(x);
        if (x_dir != UNDEFINED) {
            printf("1 %d %c\n", abs(x), x_dir);
        }
        char y_dir = get_y_dir(y);
        if (y_dir != UNDEFINED) {
            printf("1 %d %c\n", abs(y), y_dir);
        }
        cout << '2' << endl;
        // go back to (0, 0)
        if (x_dir != UNDEFINED) {
            printf("1 %d %c\n", abs(x), get_x_dir(-x));
        }
        if (y_dir != UNDEFINED) {
            printf("1 %d %c\n", abs(y), get_y_dir(-y));
        }
        cout << '3' << endl;
    }
    delete[] bomb;
    return 0;
}
