
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef long long BIGINT;

struct Solution {
    BIGINT num_of_factors;
    string optimal_route;
};

BIGINT count_factor(BIGINT num, int factor) {
    BIGINT c = 0;
    while (num > 0 && num % factor == 0) {
        c += 1;
        num /= factor;
    }
    return c;
}

string optimal_route(char **trace_table, int N) {
    int i, j;
    i = j = N - 1;
    stringstream route;
    while (!(i == 0 && j == 0)) {
        char r = trace_table[i][j];
        route << r;
        if (r == 'R') {
            j -= 1;
        } else {
            i -= 1;
        }
    }
    string result = route.str();
    return string(result.rbegin(), result.rend());
}

Solution solve(BIGINT **data, int N, int factor) {
    char **trace_table = new char*[N];
    for (int i=0; i < N; ++i) {
        trace_table[i] = new char[N];
    }

    BIGINT *table = new BIGINT[N];

    for (int i=0; i < N; ++i) {
        table[i] = count_factor(data[0][i], factor);
    }

    for (int i=1; i < N; ++i) {
        table[i] += table[i-1];
        trace_table[0][i] = 'R';
    }

    for (int i=1; i < N; ++i) {
        table[0] += count_factor(data[i][0], factor);
        trace_table[i][0] = 'D';
        for (int j=1; j < N; ++j) {
            BIGINT f = count_factor(data[i][j], factor);
            if (table[j-1] > table[j]) {
                table[j] += f;
                trace_table[i][j] = 'D';
            } else {
                table[j] = table[j-1] + f;
                trace_table[i][j] = 'R';
            }
        }
    }

    Solution s;
    s.num_of_factors = table[N-1];
    s.optimal_route = optimal_route(trace_table, N);

    for (int i=0; i < N; ++i) {
        delete[] trace_table[i];
    }
    delete[] trace_table;
    delete[] table;
    return s;
}

Solution solve(BIGINT **data, int N) {
    Solution s;
    s.num_of_factors = -1;
    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            if (data[i][j] == 0) {
                s.num_of_factors = 1;
                stringstream ss;
                for (int k=0; k < j; ++k) {
                    ss << 'R';
                }
                for (int k=0; k < N-1; ++k) {
                    ss << 'D';
                }
                for (int k=0; k < N - j - 1; ++k) {
                    ss << 'R';
                }
                s.optimal_route = ss.str();
                return s;
            }
        }
    }
    return s;
}

int main(int argc, char *argv[]) {
    int N;
    cin >> N;

    BIGINT **data = new BIGINT*[N];

    for (int i=0; i < N; ++i) {
        data[i] = new BIGINT[N];
    }

    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            cin >> data[i][j];
        }
    }

    Solution a = solve(data, N, 2);
    Solution b = solve(data, N, 5);
    Solution ans;
    if (a.num_of_factors > b.num_of_factors) {
        ans = b;
    } else {
        ans = a;
    }

	// Special case, matrix may contain 0
    if (ans.num_of_factors > 1) {
        Solution x = solve(data, N);
        if (x.num_of_factors > 0) {
            ans = x;
        }
    }

    cout << ans.num_of_factors << endl;
    cout << ans.optimal_route << endl;

    for (int i=0; i < N; ++i) {
        delete[] data[i];
    }
    delete[] data;
    return 0;
}
